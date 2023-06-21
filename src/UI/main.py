import sys

from PySide6 import QtGui, QtCore
from PySide6.QtGui import QPicture, QPainter, QFont, QColor
from PySide6.QtWidgets import QStackedWidget, QApplication, QMainWindow, QWidget, QPushButton, QLineEdit, QFileDialog, \
    QComboBox, QLabel, QMessageBox, QFrame
from PySide6.QtUiTools import QUiLoader
from PySide6.QtCore import Slot, Qt
from PySide6.QtCharts import QBarSet, QChartView, QValueAxis, QBarCategoryAxis, QChart, QBarSeries
import UI.images.res2
import UI.images.res
import wave
import pyaudio
import bundle_pb2
import os
import subprocess

results = [100,100,100]

class ResultsScreen(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)

        # init widgets
        self.window = QWidget()
        self.window.menuButt = QPushButton()
        self.window.resultsTitle = QLineEdit()
        self.window.prettyBack = QLabel()
        self.window.chartView = QWidget()
        self.chart_view = QChartView()

        # load ui
        loader = QUiLoader()
        self.window = loader.load(r"UI/prettyResults.ui", self)

        # connect signals
        self.window.menuButt.clicked.connect(self.menu_onclick)

        # change widgets properties
        self.window.prettyBack.setAutoFillBackground(True)


    def create_chart(self, p, r, l):
        set_0 = QBarSet("pitch")
        set_1 = QBarSet("rhythm")
        set_2 = QBarSet("length")

        set_0.append([p])
        set_1.append([r])
        set_2.append([l])

        series = QBarSeries()
        series.append(set_0)
        series.append(set_1)
        series.append(set_2)

        chart = QChart()
        chart.addSeries(series)
        chart.setAnimationOptions(QChart.SeriesAnimations)

        categories = ["your score"]
        axis_x = QBarCategoryAxis()
        axis_x.append(categories)
        chart.addAxis(axis_x, Qt.AlignBottom)
        series.attachAxis(axis_x)

        axis_y = QValueAxis()
        axis_y.setRange(0, 100)
        chart.addAxis(axis_y, Qt.AlignLeft)
        series.attachAxis(axis_y)

        chart.legend().setVisible(True)
        chart.legend().setAlignment(Qt.AlignBottom)
        chart.legend().setBackgroundVisible(False)
        chart.setBackgroundVisible(False)

        # Set font size
        font = QFont("Arial")
        font.setPixelSize(25)
        chart.legend().setFont(font)

        # Set font color
        font_color = QColor(255, 255, 255)
        axis_x.setLabelsBrush(font_color)
        axis_y.setLabelsBrush(font_color)

        # Set font size
        axis_x.setLabelsFont(font)
        axis_y.setLabelsFont(font)

        chart.legend().setLabelColor(font_color)

        self.chart_view = QChartView(chart)
        self.chart_view.setRenderHint(QPainter.Antialiasing)
        self.chart_view.setGeometry(50, 0, 500, 400)

        # Set background color to transparent
        self.chart_view.setStyleSheet("background-color: transparent;")

        self.chart_view.setParent(self.window.chartView)

    @Slot()
    def menu_onclick(self):
        self.chart_view.setParent(None)
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
        self.window.playButt = QPushButton()

        # load ui
        loader = QUiLoader()
        self.window = loader.load(r"UI/prettyMain.ui", self)

        self.window.listOfExercises.clear()
        for ex in exercises:
            self.window.listOfExercises.addItem(ex.title)
        # connect signals
        self.window.uploadButt.clicked.connect(self.on_upload)
        self.window.evaluateButt.clicked.connect(self.on_evaluate)
        self.window.playButt.clicked.connect(self.on_play)

        # change widgets properties
        self.window.pathFile.setReadOnly(True)

    @Slot()
    def on_upload(self):
        self.window.pathFile.setText(self.openFileNameDialog())

    def openFileNameDialog(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        fileName, _ = QFileDialog.getOpenFileName(self, "QFileDialog.getOpenFileName()", "",
                                                  "*.wav", options=options)
        if fileName:
            return fileName
        
    def on_play(self):
        # Open the .wav file
        path = bundle_path + exercises[self.window.listOfExercises.currentIndex()].wavFile
        wav_file = wave.open(path, 'rb')

        # Initialize PyAudio
        audio = pyaudio.PyAudio()

        # Open a stream to play the audio
        stream = audio.open(format=audio.get_format_from_width(wav_file.getsampwidth()),
                            channels=wav_file.getnchannels(),
                            rate=wav_file.getframerate(),
                            output=True)

        # Read and play the audio in chunks
        chunk_size = 1024
        data = wav_file.readframes(chunk_size)
        while data:
            stream.write(data)
            data = wav_file.readframes(chunk_size)

        # Close the stream and terminate PyAudio
        stream.stop_stream()
        stream.close()
        audio.terminate()
        wav_file.close()


    def on_evaluate(self):
        if self.window.pathFile.text():
        #     proc = subprocess.Popen(["../GuitarTrainer", "c", self.window.pathFile.text(),exercises[self.window.listOfExercises.currentIndex()].file], stdout=subprocess.PIPE)
        #     for i in range(2):
        #         results[i] = int(float(proc.stdout.readline())* 100)
        #     print(results)

            win2.create_chart(results[0], results[1], results[2])

            widget.setCurrentWidget(widget.widget(widget.currentIndex() + 1))
        else:
            msgBox = QMessageBox()
            msgBox.setText("File not attached")
            msgBox.setWindowTitle("Error")
            msgBox.setStandardButtons(QMessageBox.Ok)
            msgBox.exec()


bundle_path = "./"
files = [f for f in os.listdir(bundle_path) if f.endswith('.bnd')]
print(os.listdir(bundle_path))
print(files)
exercises = []
for f in files:
    with open(f, "rb") as file:
        bundle = bundle_pb2.Bundle()
        bundle.ParseFromString(file.read())
        print(bundle)
        for e in bundle.exercises:
            exercises.append(e)
# QMessageBox
# if __name__ == '__main__':
#
print(exercises)

app = QApplication(sys.argv)
# ex = App()
win = MainWindow()
win2 = ResultsScreen()

widget = QStackedWidget()
widget.addWidget(win)
widget.addWidget(win2)
widget.setFixedWidth(600)
widget.setFixedHeight(800)
widget.setWindowFlag(Qt.FramelessWindowHint)
widget.setAttribute(Qt.WA_TranslucentBackground)
widget.show()

sys.exit(app.exec())
