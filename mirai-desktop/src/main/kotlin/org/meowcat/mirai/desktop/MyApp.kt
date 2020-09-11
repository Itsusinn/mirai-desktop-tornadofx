package org.meowcat.mirai.desktop


import org.meowcat.mirai.desktop.css.DefaultStyle
import org.meowcat.mirai.desktop.view.LoginView
import tornadofx.App


class MyApp() : App(LoginView::class, DefaultStyle::class)