# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'resultsui.ui'
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
from PySide6.QtWidgets import (QApplication, QGridLayout, QLabel, QLineEdit,
    QPushButton, QSizePolicy, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(419, 153)
        self.gridLayout = QGridLayout(Form)
        self.gridLayout.setObjectName(u"gridLayout")
        self.evaluation = QLineEdit(Form)
        self.evaluation.setObjectName(u"evaluation")

        self.gridLayout.addWidget(self.evaluation, 5, 0, 1, 1)

        self.label = QLabel(Form)
        self.label.setObjectName(u"label")

        self.gridLayout.addWidget(self.label, 4, 0, 1, 1)

        self.resultsTitle = QLineEdit(Form)
        self.resultsTitle.setObjectName(u"resultsTitle")

        self.gridLayout.addWidget(self.resultsTitle, 1, 0, 1, 1)

        self.menuButt = QPushButton(Form)
        self.menuButt.setObjectName(u"menuButt")

        self.gridLayout.addWidget(self.menuButt, 0, 0, 1, 1)


        self.retranslateUi(Form)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.label.setText(QCoreApplication.translate("Form", u"TextLabel", None))
        self.menuButt.setText(QCoreApplication.translate("Form", u"menu", None))
    # retranslateUi

