package org.meowcat.mirai.desktop.data

import javafx.scene.image.Image
import net.mamoe.mirai.contact.Group
import net.mamoe.mirai.event.events.GroupMessagePostSendEvent
import net.mamoe.mirai.message.GroupMessageEvent
import net.mamoe.mirai.message.MessageReceipt
import net.mamoe.mirai.message.data.OnlineMessageSource
import java.util.*


//TODO 配置文件
data class Config(var boolean: Boolean)

fun avatar(url: String):Image{
    return Image(url,
            24.0,
            24.0,
            true,
            false,
            true)
}

fun liteImage(img:String):Image{
    val image = Image(img)
    return if (image.width > 300||image.height > 300){
        Image(img,
                image.width/4,
                image.height/4,
                false,
                false,
                true)
    }else{
        image
    }

}