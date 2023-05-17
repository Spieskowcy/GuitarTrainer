# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'prettyResults.ui'
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
from PySide6.QtWidgets import (QApplication, QLabel, QLineEdit, QPushButton,
    QSizePolicy, QWidget)
import res2_rc

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
        self.menuButt = QPushButton(self.widget)
        self.menuButt.setObjectName(u"menuButt")
        self.menuButt.setGeometry(QRect(150, 310, 50, 25))
        font = QFont()
        font.setFamilies([u"Franklin Gothic Demi"])
        font.setPointSize(11)
        self.menuButt.setFont(font)
        self.menuButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")
        self.evaluation = QLineEdit(self.widget)
        self.evaluation.setObjectName(u"evaluation")
        self.evaluation.setGeometry(QRect(80, 260, 200, 20))
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.evaluation.sizePolicy().hasHeightForWidth())
        self.evaluation.setSizePolicy(sizePolicy)
        self.evaluation.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(0, 0, 0, 255);\n"
"padding-bottom:7px;")
        self.label_2 = QLabel(self.widget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(130, 40, 201, 81))
        font1 = QFont()
        font1.setFamilies([u"Niagara Engraved"])
        font1.setPointSize(48)
        self.label_2.setFont(font1)
        self.label_2.setStyleSheet(u"color:rgba(255, 255, 255,210 );")
        self.label_3 = QLabel(self.widget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(280, 110, 401, 54))
        self.label_4 = QLabel(self.widget)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(80, 130, 200, 100))
        self.label_4.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
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
        self.menuButt.setText(QCoreApplication.translate("Form", u"menu", None))
        self.evaluation.setText("")
        self.label_2.setText(QCoreApplication.translate("Form", u"Results", None))
        self.label_3.setText(QCoreApplication.translate("Form", u"TextLabel", None))
        self.label_4.setText("")
    # retranslateUi

