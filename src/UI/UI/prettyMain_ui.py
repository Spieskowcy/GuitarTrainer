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
        Form.resize(450, 550)
        self.widget = QWidget(Form)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(40, 40, 370, 480))
        self.prettyBack = QLabel(self.widget)
        self.prettyBack.setObjectName(u"prettyBack")
        self.prettyBack.setGeometry(QRect(35, 30, 300, 420))
        self.prettyBack.setStyleSheet(u"border-image: url(:/images/PianoHero.png);\n"
"border-radius:20px;")
        self.uploadButt = QPushButton(self.widget)
        self.uploadButt.setObjectName(u"uploadButt")
        self.uploadButt.setGeometry(QRect(80, 140, 200, 25))
        font = QFont()
        font.setFamilies([u"Franklin Gothic Demi"])
        font.setPointSize(11)
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
        self.pathFile.setGeometry(QRect(80, 170, 200, 20))
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pathFile.sizePolicy().hasHeightForWidth())
        self.pathFile.setSizePolicy(sizePolicy)
        self.pathFile.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(0, 0, 0, 255);\n"
"padding-bottom:7px;")
        self.listOfExercises = QComboBox(self.widget)
        self.listOfExercises.addItem("")
        self.listOfExercises.addItem("")
        self.listOfExercises.setObjectName(u"listOfExercises")
        self.listOfExercises.setGeometry(QRect(80, 210, 200, 20))
        self.listOfExercises.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(0, 0, 0, 255);\n"
"padding-bottom:7px;\n"
"")
        self.evaluateButt = QPushButton(self.widget)
        self.evaluateButt.setObjectName(u"evaluateButt")
        self.evaluateButt.setGeometry(QRect(80, 260, 200, 23))
        self.evaluateButt.setFont(font)
        self.evaluateButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")
        self.label_2 = QLabel(self.widget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(110, 60, 241, 71))
        font1 = QFont()
        font1.setFamilies([u"Niagara Engraved"])
        font1.setPointSize(48)
        self.label_2.setFont(font1)
        self.label_2.setStyleSheet(u"color:rgba(255, 255, 255,210 );")

        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.prettyBack.setText(QCoreApplication.translate("Form", u"TextLabel", None))
        self.uploadButt.setText(QCoreApplication.translate("Form", u"upload file", None))
        self.pathFile.setText("")
        self.listOfExercises.setItemText(0, QCoreApplication.translate("Form", u"pitch", None))
        self.listOfExercises.setItemText(1, QCoreApplication.translate("Form", u"loudness", None))

        self.evaluateButt.setText(QCoreApplication.translate("Form", u"evaluate", None))
        self.label_2.setText(QCoreApplication.translate("Form", u"Welcome!", None))
    # retranslateUi

