package org.meowcat.mirai.desktop.css

import javafx.scene.Cursor
import javafx.scene.layout.BorderStrokeStyle
import javafx.scene.paint.Color.rgb
import javafx.scene.text.FontWeight
import javafx.scene.text.TextAlignment
import tornadofx.*

class DefaultStyle: Stylesheet(){
    companion object {
        val root by cssclass()
        val Button by cssclass()
        val ButtonHover by cssclass()
        val ButtonRadiusLarge by cssclass()
        val ButtonRadiusNormal by cssclass()
        val DefaultTheme by cssclass()
        val DarkTheme by cssclass()

    }
    init {
        //全局字体样式
        root{
            fontSize = 14.px
        }
        //全局按钮样式
        Button{
            textAlignment = TextAlignment.CENTER
            prefHeight = 38.px
            padding = box(5.px,10.px)
            borderStyle = MultiValue<BorderStrokeStyle>().apply {
                add(BorderStrokeStyle.NONE)
            }
            cursor = Cursor.HAND
        }
        //鼠标覆盖按钮效果
        ButtonHover{
            fontWeight = FontWeight.BOLD
            opacity = 0.8
        }
        //边框正常弧度按钮
        ButtonRadiusNormal{
            borderRadius.add(box(2.px))
            backgroundRadius.add(box(2.px))
        }
        //边框圆角按钮
        ButtonRadiusLarge{
            borderRadius.add(box(5.px))
            backgroundRadius.add(box(5.px))
        }
        DefaultTheme{
            backgroundColor += c("#fff")
            borderColor.add(box(c("#E6E6E6")))
        }
        DarkTheme{
            backgroundColor += rgb(40,43,51)
        }


    }
}

