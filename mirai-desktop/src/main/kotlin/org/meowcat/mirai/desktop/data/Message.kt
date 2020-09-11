package org.meowcat.mirai.desktop.data

import javafx.scene.image.Image
import net.mamoe.mirai.contact.nameCardOrNick
import net.mamoe.mirai.event.events.GroupMessagePostSendEvent
import net.mamoe.mirai.event.events.source
import net.mamoe.mirai.message.FriendMessageEvent
import net.mamoe.mirai.message.GroupMessageEvent
import net.mamoe.mirai.message.data.MessageChain

class MetaMessage(val avatar:Image,val nick:String,val msg:MessageChain,val id:Int) {
    companion object Factory{
        fun create(event: GroupMessagePostSendEvent): MetaMessage {
            event.apply {
                return MetaMessage(
                        avatar(bot.selfQQ.avatarUrl),
                        target.botAsMember.nameCardOrNick,
                        message,
                        source!!.id)
            }
        }
        fun create(event: GroupMessageEvent): MetaMessage {
            event.apply {
                return MetaMessage(
                        avatar(sender.avatarUrl),
                        sender.nameCardOrNick,
                        message,
                        source.id)
            }
        }

        fun create(event: FriendMessageEvent): MetaMessage? {
            event.apply {
                return MetaMessage(
                        avatar(friend.avatarUrl),
                        sender.nameCardOrNick,
                        message,source.id)
            }
        }
    }
}