# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainWindow.ui'
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
from PySide6.QtWidgets import (QApplication, QComboBox, QGridLayout, QLineEdit,
    QPushButton, QSizePolicy, QVBoxLayout, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(285, 259)
        self.gridLayout = QGridLayout(Form)
        self.gridLayout.setObjectName(u"gridLayout")
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.listOfExercises = QComboBox(Form)
        self.listOfExercises.addItem("")
        self.listOfExercises.addItem("")
        self.listOfExercises.setObjectName(u"listOfExercises")

        self.verticalLayout.addWidget(self.listOfExercises)


        self.gridLayout.addLayout(self.verticalLayout, 0, 1, 1, 1)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.pathFile = QLineEdit(Form)
        self.pathFile.setObjectName(u"pathFile")
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.pathFile.sizePolicy().hasHeightForWidth())
        self.pathFile.setSizePolicy(sizePolicy)

        self.verticalLayout_2.addWidget(self.pathFile)

        self.uploadButt = QPushButton(Form)
        self.uploadButt.setObjectName(u"uploadButt")

        self.verticalLayout_2.addWidget(self.uploadButt)


        self.gridLayout.addLayout(self.verticalLayout_2, 0, 0, 1, 1)

        self.verticalLayout_3 = QVBoxLayout()
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.evaluateButt = QPushButton(Form)
        self.evaluateButt.setObjectName(u"evaluateButt")

        self.verticalLayout_3.addWidget(self.evaluateButt)

        self.widget = QWidget(Form)
        self.widget.setObjectName(u"widget")

        self.verticalLayout_3.addWidget(self.widget)


        self.gridLayout.addLayout(self.verticalLayout_3, 1, 0, 1, 2)


        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.listOfExercises.setItemText(0, QCoreApplication.translate("Form", u"pitch", None))
        self.listOfExercises.setItemText(1, QCoreApplication.translate("Form", u"loudness", None))

        self.uploadButt.setText(QCoreApplication.translate("Form", u"upload file", None))
        self.evaluateButt.setText(QCoreApplication.translate("Form", u"evaluate", None))
    # retranslateUi

