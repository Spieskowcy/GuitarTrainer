import sys
from PyQt5.QtWidgets import QHBoxLayout, QComboBox, QApplication, QWidget, QPushButton, QFileDialog, QInputDialog, QLineEdit
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot


class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 button - pythonspot.com'
        self.left = 10
        self.top = 10
        self.width = 320
        self.height = 200
        self.size = app.primaryScreen().size()
        self.initUI()
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        
        upload = QPushButton('upload recording', self)
        exercises = QPushButton('see exercises', self)
        evaluate = QPushButton('evaluate', self)
        upload.setGeometry(50,75,100,50)
        exercises.setGeometry(170,75,100,50)

        evaluate.setGeometry(100,120,100,50)
        upload.clicked.connect(self.on_upload)
        self.textbox = QLineEdit(self)
        self.textbox.move(20, 20)
        self.textbox.resize(280,40)
        self.textbox.setReadOnly(True)

        combobox = QComboBox()
        combobox.addItems(['One', 'Two', 'Three', 'Four'])
        combobox.setGeometry(100,200,100,50)
        
        layout = QHBoxLayout()
        layout.addWidget(combobox)
        layout.addItem(self.textbox)
        layout.addItem(upload)
        layout.addItem(evaluate)
        self.setLayout(layout)
        self.show()

    @pyqtSlot()
    def on_upload(self):
        self.textbox.setText(self.openFileNameDialog())
        
    def openFileNameDialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self,"QFileDialog.getOpenFileName()", "","All Files (*);;Python Files (*.py)", options=options)
        if fileName:
            return fileName
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())