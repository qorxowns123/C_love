import sys
from PyQt5.QtWidgets import *
from selenium import webdriver
import AutoShopping

class MyWindow(QMainWindow, QWidget):

    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        self.setGeometry(15, 50, 1900, 950)
    
        # 검색어 입력 그룹박스
        self.SearchInfo = QGroupBox(self)
        self.SearchInfo.move(20, 10)
        self.SearchInfo.resize(1850, 115)
        self.SearchInfo.setTitle('검색어 입력')

        # 검색어 입력 텍스트 박스
        self.SearchBox = QLineEdit(self.SearchInfo)
        self.SearchBox.move(10, 42)
        self.SearchBox.resize(245, 30)
        self.SearchBox.setFocus()

        # 검색 버튼
        self.SearchBtn = QPushButton(self.SearchInfo)
        self.SearchBtn.move(254, 41)
        self.SearchBtn.resize(50, 32)
        self.SearchBtn.setText('검색')
        self.SearchBtn.clicked.connect(self.clicked_make_btn)
        self.SearchBtn.setAutoDefault(True)

        # 탭 그룹박스
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

        # 테이블 설정(table1)
        setNameList = ["상품명", "가격", "링크"]
        self.tableWidget1 = QTableWidget(self.tab1)
        self.tableWidget1.setRowCount(30)
        self.tableWidget1.setColumnCount(3)
        self.tableWidget1.setHorizontalHeaderLabels(setNameList)
        self.tableWidget1.resize(1824, 760)
        self.tableWidget1.move(0, 0)

        # 테이블 설정(table2)
        self.tableWidget2 = QTableWidget(self.tab2)
        self.tableWidget2.setRowCount(30)
        self.tableWidget2.setColumnCount(3)
        self.tableWidget2.setHorizontalHeaderLabels(setNameList)
        self.tableWidget2.resize(1824, 760)
        self.tableWidget2.move(0, 0)

        # 테이블 설정(table3)
        self.tableWidget3 = QTableWidget(self.tab3)
        self.tableWidget3.setRowCount(30)
        self.tableWidget3.setColumnCount(3)
        self.tableWidget3.setHorizontalHeaderLabels(setNameList)
        self.tableWidget3.resize(1824, 760)
        self.tableWidget3.move(0, 0)


    def clicked_make_btn(self):
        [CouPangItemNameList, CouPangItemPriceList, CoPangItemLinkList] = AutoShopping.AutoCoupang(self.SearchBox.text())
        self.ItemLinkList = CoPangItemLinkList
        for loopidx in range(0, CouPangItemNameList.__len__()):
            self.tableWidget1.setItem(loopidx, 0, QTableWidgetItem(CouPangItemNameList[loopidx]))
            self.tableWidget1.setItem(loopidx, 1, QTableWidgetItem(CouPangItemPriceList[loopidx] + '원'))
            # 링크를 열기 위한 버튼 생성
            self.btn1 = QPushButton('Link')
            self.btn1.clicked.connect(self.clicked_link_btn)
            self.tableWidget1.setCellWidget(loopidx, 2, self.btn1)

        self.tableWidget1.resizeColumnsToContents()
        self.tableWidget1.resizeRowsToContents()
        self.tableWidget1.setEditTriggers(QAbstractItemView.NoEditTriggers)

    def clicked_link_btn(self):
        button = qApp.focusWidget()
        index = self.tableWidget1.indexAt(button.pos())
        if index.isValid():
            driver = webdriver.Chrome('chromedriver.exe')
            driver.get(self.ItemLinkList[index.row()])




if __name__ == "__main__":
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    app.exec_()
