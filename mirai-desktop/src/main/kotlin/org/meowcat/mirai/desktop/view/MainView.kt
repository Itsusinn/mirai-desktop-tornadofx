package org.meowcat.mirai.desktop.view

import javafx.scene.image.Image
import kotlinx.coroutines.*
import net.mamoe.mirai.Bot
import net.mamoe.mirai.contact.Friend
import net.mamoe.mirai.contact.Group
import org.meowcat.mirai.desktop.controller.BotController
import org.meowcat.mirai.desktop.data.avatar
import tornadofx.*

class MainView:View(){

    private val controller:BotController by inject()
    private val bot: Bot = controller.bot

    init {
        title = "MainView"
        setStageIcon(Image("icon/logo.jpg"))
    }

    override val root = borderpane {
        center = drawer{
            val friendsList = ArrayList<Friend>().asObservable()
            val groupsList = ArrayList<Group>().asObservable()
            GlobalScope.launch {
                controller.loginStatus.join()
                bot.friends.forEach {
                    friendsList += it
                }
                bot.groups.forEach {
                    groupsList += it
                }


            }
            item("Messages"){
                //TODO 显示最近消息
            }
            item("Friends"){

                listview(friendsList){
                    cellFormat {
                        graphic = cache(it.id) {
                            form {
                                fieldset {
                                    field("Avatar") {
                                        imageview(avatar(it.avatarUrl))
                                    }
                                    field("Name") {
                                        label(it.nick)
                                    }
                                    field("ID") {
                                        label(it.id.toString())
                                    }
                                }
                            }
                        }
                        onDoubleClick {
                            //TODO 私聊窗
                        }
                    }
                }
            }
            item("Group"){
                listview(groupsList) {
                    cellFormat {
                        onDoubleClick {
                            find<GroupChat>(mapOf(GroupChat::target to it)).openWindow()
                        }
                        graphic = cache(it.id){
                            form {
                                fieldset {
                                    field("Avatar") {
                                        imageview(Image(
                                                it.avatarUrl,
                                                32.0,
                                                32.0,
                                                true,
                                                true))
                                    }
                                    field("Name") {
                                        label(it.name)
                                    }
                                    field ("Owner"){
                                        label(it.owner.nick)
                                    }
                                    field("ID") {
                                        label(it.id.toString())
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        top = menubar {
            menu("Settings"){
                item("Nothing")
            }

        }
    }
}