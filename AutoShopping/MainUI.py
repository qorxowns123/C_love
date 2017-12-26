import sys
from PyQt5.QtWidgets import *

class MyWindow(QMainWindow, QWidget):

    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        self.setGeometry(15, 50, 1900, 950)
    
        # 검색어 입력 그룹박스
        self.SearchInfo = QGroupBox(self)
        self.SearchInfo.move(15, 10)
        self.SearchInfo.resize(360, 115)
        self.SearchInfo.setTitle('검색어 입력')

        # 검색어 입력 텍스트 박스
        self.SearchBox = QLineEdit(self.SearchInfo)
        self.SearchBox.move(10, 42)
        self.SearchBox.resize(245, 30)
        self.SearchBox.setFocus()

        self.TapGroupBox = QGroupBox(self)
        self.TapGroupBox.move(20, 140)
        self.TapGroupBox.resize(1850, 800)

        # 탭 설정
        self.layout = QVBoxLayout(self.TapGroupBox)
        self.tabs = QTabWidget()

        self.tab1 = QWidget()
        self.tab2 = QWidget()
        self.tab3 = QWidget()
        self.tabs.resize(300, 200)

        self.tabs.addTab(self.tab1, "쿠팡")
        self.tabs.addTab(self.tab2, "티몬")
        self.tabs.addTab(self.tab3, "위메프")

        self.tab1.layout = QVBoxLayout(self)
        self.tab1.setLayout(self.tab1.layout)
        self.layout.addWidget(self.tabs)
        self.setLayout(self.layout)

        self.tableWidget = QTableWidget()
        self.tableWidget.setRowCount(4)
        self.tableWidget.setColumnCount(2)
        self.tableWidget.setItem(0, 0, QTableWidgetItem("aaa"))
        self.tableWidget.move(0, 0)



if __name__ == "__main__":
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    app.exec_()
