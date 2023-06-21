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
from PySide6.QtWidgets import (QApplication, QLabel, QPushButton, QSizePolicy,
    QWidget)
import res2_rc

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(952, 903)
        self.widget = QWidget(Form)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(0, 0, 600, 800))
        self.prettyBack = QLabel(self.widget)
        self.prettyBack.setObjectName(u"prettyBack")
        self.prettyBack.setGeometry(QRect(0, 0, 600, 800))
        self.prettyBack.setStyleSheet(u"border-image: url(:/images/PianoHero.png);\n"
"border-radius:20px;")
        self.menuButt = QPushButton(self.widget)
        self.menuButt.setObjectName(u"menuButt")
        self.menuButt.setGeometry(QRect(200, 520, 200, 75))
        font = QFont()
        font.setFamilies([u"Franklin Gothic Demi"])
        font.setPointSize(30)
        self.menuButt.setFont(font)
        self.menuButt.setStyleSheet(u"bacground-color:rgba(0, 0, 0, 0);\n"
"border:2px solid rgba(255, 222, 175, 0.8);\n"
"color:rgba(255, 255, 255, 230);\n"
"padding-bottom:7px;\n"
"border-radius:5px;\n"
"\n"
"")
        self.label = QLabel(self.widget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(244, 50, 115, 50))
        self.label.setStyleSheet(u"background-image: url(:/images/Results.png);")
        self.chartView = QWidget(self.widget)
        self.chartView.setObjectName(u"chartView")
        self.chartView.setGeometry(QRect(0, 100, 601, 371))

        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.prettyBack.setText("")
        self.menuButt.setText(QCoreApplication.translate("Form", u"menu", None))
        self.label.setText("")
    # retranslateUi

