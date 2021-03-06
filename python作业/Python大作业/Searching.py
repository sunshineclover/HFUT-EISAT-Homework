# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Searching.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import QPalette, QBrush, QPixmap
from PyQt5.QtWidgets import QApplication, QMainWindow

import sys
from temp import *

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("查询动画")
        MainWindow.resize(960, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.OK = QtWidgets.QPushButton(self.centralwidget)
        self.OK.setGeometry(QtCore.QRect(80, 130, 92, 28))
        self.OK.setObjectName("OK")
        self.Clear = QtWidgets.QPushButton(self.centralwidget)
        self.Clear.setGeometry(QtCore.QRect(200, 130, 92, 28))
        self.Clear.setObjectName("Clear")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(90, 40, 191, 21))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(50, 200, 72, 15))
        self.label_2.setObjectName("label_2")
        self.ResultText = QtWidgets.QTextBrowser(self.centralwidget)
        self.ResultText.setGeometry(QtCore.QRect(50, 230, 441, 311))
        self.ResultText.setObjectName("ResultText")
        self.SearchingText = QtWidgets.QLineEdit(self.centralwidget)
        self.SearchingText.setGeometry(QtCore.QRect(70, 70, 231, 51))
        self.SearchingText.setObjectName("SearchingText")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 960, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.OK.clicked.connect(self.SearchingFunction)
        self.Clear.clicked.connect(self.ClearFunction)


        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.OK.setText(_translate("MainWindow", "确定"))
        self.Clear.setText(_translate("MainWindow", "清空"))
        self.label.setText(_translate("MainWindow", "请输入想要搜索的动画名称"))
        self.label_2.setText(_translate("MainWindow", "输出结果"))


    def SearchingFunction(self):
        AnimeName = self.SearchingText.text()
        self.ResultText.setText(AnimeName)
        print("输入的动画名是:", AnimeName)

    def ClearFunction(self):
        self.SearchingText.clear()
        print("清空完毕啦！")



class CustomUI(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(CustomUI, self).__init__(parent)
        self.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    cutomUI = CustomUI()
    palette = QPalette()
    palette.setBrush(QPalette.Background, QBrush(QPixmap("6.png")))
    cutomUI.setPalette(palette)
    cutomUI.show()
    sys.exit(app.exec_())
