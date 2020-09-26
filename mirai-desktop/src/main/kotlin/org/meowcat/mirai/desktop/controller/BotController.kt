package org.meowcat.mirai.desktop.controller

import org.meowcat.mirai.desktop.data.MetaMessage
import javafx.collections.ObservableList
import kotlinx.coroutines.*
import kotlinx.coroutines.javafx.JavaFx
import net.mamoe.mirai.Bot
import net.mamoe.mirai.contact.Friend
import net.mamoe.mirai.contact.Group
import net.mamoe.mirai.event.events.GroupMessagePostSendEvent
import net.mamoe.mirai.event.subscribeAlways
import net.mamoe.mirai.message.FriendMessageEvent
import net.mamoe.mirai.message.GroupMessageEvent
import net.mamoe.mirai.utils.SilentLogger
import tornadofx.Controller
import tornadofx.asObservable
import kotlin.coroutines.CoroutineContext


class BotController: Controller(),CoroutineScope {

    lateinit var bot:Bot
    lateinit var loginStatus:Job
    private val groupMessageListMap = HashMap<Group, ObservableList<MetaMessage>>()
    private val friendMessageListMap = HashMap<Friend, ObservableList<MetaMessage>>()

    override val coroutineContext: CoroutineContext
        get() = Dispatchers.JavaFx

    //非阻塞登录机器人并返回bot实例
    fun login(account: Long, password: String): Bot {
        return Bot(account, password){
            // 覆盖默认的配置
            fileBasedDeviceInfo("device.json") // 使用 "device.json" 保存设备信息
            networkLoggerSupplier = { SilentLogger } // 禁用网络层输出
        }.also {
            bot = it
            loginStatus = launch {
                it.login()
            }
        }
    }

    //发送消息 contact是group或者friend的父类
    fun sendMessage(target: Group, content: String):Job{
        return launch {
             target.sendMessage(content)
        }
    }

    //订阅并记录所有消息
    fun subscribeMessage():Job{
        return launch {

            bot.groups.forEach {
                groupMessageListMap[it] = ArrayList<MetaMessage>().asObservable()
            }
            bot.friends.forEach {
                friendMessageListMap[it] = ArrayList<MetaMessage>().asObservable()
            }

            //好友变动
//            bot.subscribeAlways<FriendAddEvent>(Dispatchers.JavaFx){
//                friendMessageListMap[friend.id] = ArrayList<FriendMessageEvent>().asObservable()
//            }

            //手动指定subscribe的dispatcher 否者会引起javafx 并发检测进而报错
            bot.subscribeAlways<GroupMessagePostSendEvent>(Dispatchers.JavaFx) {
                groupMessageListMap[target]!!.add(MetaMessage.create(this))
            }
            bot.subscribeAlways<GroupMessageEvent>(Dispatchers.JavaFx) {
                groupMessageListMap[group]!!.add(MetaMessage.create(this))
            }
            bot.subscribeAlways<FriendMessageEvent>(Dispatchers.JavaFx) {
                friendMessageListMap[friend]!!.add(MetaMessage.create(this))
            }
        }
    }

    fun getMessageList(target: Group):ObservableList<MetaMessage>{
        return groupMessageListMap[target]!!
    }
    fun getMessageList(target: Friend):ObservableList<MetaMessage>{
        return friendMessageListMap[target]!!
    }
}

