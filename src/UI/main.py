import sys

from PySide6 import QtGui, QtCore
from PySide6.QtGui import QPicture
from PySide6.QtWidgets import QStackedWidget, QApplication, QMainWindow, QWidget, QPushButton, QLineEdit, QFileDialog, \
    QComboBox, QLabel
from PySide6.QtUiTools import QUiLoader
from PySide6.QtCore import Slot, Qt


class ResultsScreen(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        # init widgets
        self.window = QWidget()
        self.window.menuButt = QPushButton()
        self.window.resultsTitle = QLineEdit()
        self.window.evaluation = QLineEdit()
        self.window.prettyBack = QLabel()

        # load ui
        loader = QUiLoader()
        self.window = loader.load("UI\\prettyResults.ui", self)

        # connect signals
        self.window.menuButt.clicked.connect(self.menu_onclick)

        # change widgets properties
        self.window.evaluation.setReadOnly(True)
        self.window.prettyBack.setAutoFillBackground(True)
        self.window.prettyBack.setStyleSheet("border-image: url(:/images/PianoHero.png)")
        pixmap = QtGui.QPixmap('images/PianoHero.png')
        self.window.prettyBack.setPixmap(pixmap)
        self.window.setWindowFlag(Qt.FramelessWindowHint)
        # self.show()

    @Slot()
    def menu_onclick(self):
        widget.setCurrentWidget(widget.widget(widget.currentIndex() - 1))


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        # init widgets
        self.window = QWidget()
        self.window.uploadButt = QPushButton()
        self.window.evaluateButt = QPushButton()
        self.window.pathFile = QLineEdit()
        self.window.listOfExercises = QComboBox()
        self.window.prettyBack = QLabel()

        # load ui
        loader = QUiLoader()
        self.window = loader.load("UI\\prettyMain.ui", self)

        # connect signals
        self.window.uploadButt.clicked.connect(self.on_upload)
        self.window.evaluateButt.clicked.connect(self.on_evaluate)

        # change widgets properties
        self.window.pathFile.setReadOnly(True)
        #self.window.prettyBack.setAutoFillBackground(True)
        #self.window.prettyBack.setPicture(QPicture("/images/PianoHero.png"))
        pixmap = QtGui.QPixmap('images/PianoHero.png')
        self.window.prettyBack.setPixmap(pixmap)
        #self.window.prettyBack.setStyleSheet("border-radius:20px;")

        self.window.setWindowFlag(Qt.FramelessWindowHint)
        # self.show()

    @Slot()
    def on_upload(self):
        self.window.pathFile.setText(self.openFileNameDialog())

    def openFileNameDialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self, "QFileDialog.getOpenFileName()", "",
                                                  "All Files (*);;Python Files (*.py)", options=options)
        if fileName:
            return fileName

    def on_evaluate(self):
        if self.window.pathFile.text():
            widget.setCurrentWidget(widget.widget(widget.currentIndex() + 1))


# if __name__ == '__main__':
# bundle_path = "."
# files = [f for f in listdir(bundle_path) if isfile(join(bundle_path, f)) and f.endswith('.bnd')]
# exercises = []
# for f in files:
#     with open(f, "rb") as file:
#         bundle = bundle_pb2.Bundle()
#         bundle.ParseFromString(file.read())
#         print(bundle)
#         for e in bundle.exercises:
#             exercises.append(e)
#
# print(exercises)

app = QApplication(sys.argv)
# ex = App()
win = MainWindow()
win2 = ResultsScreen()

widget = QStackedWidget()
widget.addWidget(win)
widget.addWidget(win2)
widget.setFixedWidth(450)
widget.setFixedHeight(550)
widget.setWindowFlag(Qt.FramelessWindowHint)
widget.show()

sys.exit(app.exec())
