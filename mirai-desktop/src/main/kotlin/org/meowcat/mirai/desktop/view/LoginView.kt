package org.meowcat.mirai.desktop.view

import javafx.scene.control.PasswordField
import javafx.scene.control.TextField
import javafx.scene.image.Image
import kotlinx.coroutines.*
import kotlinx.coroutines.javafx.JavaFx
import org.meowcat.mirai.desktop.controller.BotController
import tornadofx.*

class LoginView : View() {


    private val controller: BotController by inject()
    private lateinit var accountInputField: TextField
    private lateinit var passwordInputField: PasswordField
    init {
        title = "Mirai Login"
        setStageIcon(Image("icon/logo.jpg"))
    }

    override val root =vbox{
        form{
            fieldset {
                field("Account") {
                    accountInputField = textfield()
                }
                field("Password") {
                    passwordInputField = passwordfield()
                }
                field {
                    button("Log in") {
                        action {
                            GlobalScope.launch {
                                controller.login(accountInputField.text.toLong(),passwordInputField.text)
                                controller.loginStatus.join()
                                if (controller.bot.isOnline){
                                    controller.subscribeMessage()
                                    withContext(Dispatchers.JavaFx){
                                        replaceWith(MainView::class,
                                                ViewTransition.Slide(0.3.seconds, ViewTransition.Direction.LEFT))
                                    }
                                }
                            }
                        }
                    }
                    //TODO remember-me
                }
            }
        }
    }
}