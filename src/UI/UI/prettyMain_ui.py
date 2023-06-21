# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'prettyMain.ui'
##
## Created by: Qt User Interface Compiler version 6.5.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QComboBox, QLabel, QLineEdit,
    QPushButton, QSizePolicy, QWidget)
import res_rc

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(945, 949)
        self.widget = QWidget(Form)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(0, 0, 600, 800))
        self.prettyBack = QLabel(self.widget)
        self.prettyBack.setObjectName(u"prettyBack")
        self.prettyBack.setGeometry(QRect(0, 0, 600, 800))
        self.prettyBack.setStyleSheet(u"border-image: url(:/images/PianoHero.png);\n"
"border-radius:20px;")
        self.uploadButt = QPushButton(self.widget)
        self.uploadButt.setObjectName(u"uploadButt")
        self.uploadButt.setGeometry(QRect(50, 130, 500, 75))
        font = QFont()
        font.setFamilies([u"Franklin Gothic Demi"])
        font.setPointSize(30)
        self.uploadButt.setFont(font)
        self.uploadButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")
        self.pathFile = QLineEdit(self.widget)
        self.pathFile.setObjectName(u"pathFile")
        self.pathFile.setGeometry(QRect(50, 220, 500, 75))
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pathFile.sizePolicy().hasHeightForWidth())
        self.pathFile.setSizePolicy(sizePolicy)
        font1 = QFont()
        font1.setPointSize(30)
        self.pathFile.setFont(font1)
        self.pathFile.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(0, 0, 0, 255);\n"
"padding-bottom:7px;")
        self.listOfExercises = QComboBox(self.widget)
        self.listOfExercises.addItem("")
        self.listOfExercises.setObjectName(u"listOfExercises")
        self.listOfExercises.setGeometry(QRect(50, 310, 350, 75))
        self.listOfExercises.setFont(font1)
        self.listOfExercises.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(0, 0, 0, 255);\n"
"padding-bottom:7px;\n"
"")
        self.evaluateButt = QPushButton(self.widget)
        self.evaluateButt.setObjectName(u"evaluateButt")
        self.evaluateButt.setGeometry(QRect(200, 520, 200, 75))
        self.evaluateButt.setFont(font)
        self.evaluateButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")
        self.label = QLabel(self.widget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(200, 50, 211, 50))
        self.label.setStyleSheet(u"background-image: url(:/images/GuitarTrainer.png);")
        self.playButt = QPushButton(self.widget)
        self.playButt.setObjectName(u"playButt")
        self.playButt.setGeometry(QRect(425, 310, 100, 75))
        self.playButt.setFont(font)
        self.playButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")

        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.prettyBack.setText(QCoreApplication.translate("Form", u"TextLabel", None))
        self.uploadButt.setText(QCoreApplication.translate("Form", u"upload file", None))
        self.pathFile.setText("")
        self.listOfExercises.setItemText(0, QCoreApplication.translate("Form", u"ex1", None))

        self.evaluateButt.setText(QCoreApplication.translate("Form", u"evaluate", None))
        self.label.setText("")
        self.playButt.setText(QCoreApplication.translate("Form", u"play", None))
    # retranslateUi

