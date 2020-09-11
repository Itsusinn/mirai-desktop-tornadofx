package org.meowcat.mirai.desktop.view

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.javafx.JavaFx
import kotlinx.coroutines.launch
import net.mamoe.mirai.contact.Group
import net.mamoe.mirai.message.data.*
import org.meowcat.mirai.desktop.controller.BotController
import org.meowcat.mirai.desktop.data.*
import tornadofx.*
import kotlin.coroutines.CoroutineContext

//群聊对话框 远离抽象
class GroupChat: Fragment(), CoroutineScope {

    private val controller: BotController by inject()
    val target: Group by param()

    override val coroutineContext: CoroutineContext
        get() = Dispatchers.JavaFx

    init {
        setStageIcon(avatar(target.avatarUrl))
        title = target.name
    }


    override val root = borderpane {

        //底部发送消息
        bottom = hbox {
            val inputField = textfield()
            button("Send") {
                action {
                    controller.sendMessage(target,inputField.text)
                    inputField.text = ""
                }
            }
        }
        //中心是滚动显示消息
        //TODO 缓存头像
        center = listview(controller.getMessageList(target)) {
            cellFormat { metaMessage ->
                graphic = cache(metaMessage.id){
                    hbox {
                        imageview(metaMessage.avatar)
                        text("${metaMessage.nick}:")
                        launch {
                            metaMessage.msg.forEach {msg ->
                                if (msg is Image){
                                    imageview(liteImage(msg.queryUrl()))
                                }else if(msg is PlainText){
                                    text(msg.content)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}