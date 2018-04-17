import sys
from PyQt5.QtWidgets import *
from selenium import webdriver
import AutoShopping
'''
정렬 기능 넣기
1. 아이템 이름 정렬
2. 가격 정렬
'''

class MyWindow(QMainWindow, QWidget):

    def __init__(self):
        super().__init__()
        self.setupUI()

    def setupUI(self):
        # self.setGeometry(15, 50, 1900, 950)
        self.setGeometry(15, 50, 850, 950)

        TextBoxIndex = [25, 42, 0]

        # 검색어 입력 텍스트 박스
        self.SearchBox = QLineEdit(self)
        self.SearchBox.move(TextBoxIndex[0], TextBoxIndex[1])
        self.SearchBox.resize(242, 30)
        self.SearchBox.setFocus()

        TextBoxIndex[2] = TextBoxIndex[0] + 245

        # 검색 버튼
        self.SearchBtn = QPushButton(self)
        self.SearchBtn.move(TextBoxIndex[2], 41)
        self.SearchBtn.resize(50, 32)
        self.SearchBtn.setText('검색')
        self.SearchBtn.clicked.connect(self.clicked_make_btn)
        self.SearchBtn.setAutoDefault(True)

        # 탭 그룹박스
        self.TapGroupBox = QGroupBox(self)
        self.TapGroupBox.move(20, 95)
        self.TapGroupBox.resize(800, 800)

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

        setRowCountNum = 50

        # 테이블 설정(table1)
        setNameList = ["상품명", "가격", "링크"]
        self.tableWidget1 = QTableWidget(self.tab1)
        self.tableWidget1.setRowCount(setRowCountNum)
        self.tableWidget1.setColumnCount(3)
        self.tableWidget1.setHorizontalHeaderLabels(setNameList)
        self.tableWidget1.resize(1824, 760)
        self.tableWidget1.move(0, 0)

        # 테이블 설정(table2)
        self.tableWidget2 = QTableWidget(self.tab2)
        self.tableWidget2.setRowCount(setRowCountNum)
        self.tableWidget2.setColumnCount(3)
        self.tableWidget2.setHorizontalHeaderLabels(setNameList)
        self.tableWidget2.resize(1824, 760)
        self.tableWidget2.move(0, 0)

        # 테이블 설정(table3)
        self.tableWidget3 = QTableWidget(self.tab3)
        self.tableWidget3.setRowCount(setRowCountNum)
        self.tableWidget3.setColumnCount(3)
        self.tableWidget3.setHorizontalHeaderLabels(setNameList)
        self.tableWidget3.resize(1824, 760)
        self.tableWidget3.move(0, 0)

        # Status Bar
        self.statusBar = QStatusBar(self)
        self.setStatusBar(self.statusBar)
        self.statusBar.showMessage('Ready')
        
        # 웹 드라이버 실행
        self.driver = webdriver.PhantomJS('phantomjs.exe')
        #self.driver = webdriver.Chrome('chromedriver.exe')

    def clicked_make_btn(self):
        # 쿠팡 함수 호출
        self.statusBar.showMessage('쿠팡에서 정보를 가져오고 있습니다...')
        [CouPangItemNameList, CouPangItemPriceList, CoPangItemLinkList] = AutoShopping.AutoCoupang(self.driver, self.SearchBox.text())

        # 티몬 함수 호출
        self.statusBar.showMessage('티몬에서 정보를 가져오고 있습니다...')
        [TiMonItemNameList, TiMonItemPriceList, TiMonItemLinkList] = AutoShopping.AutoTiMon(self.driver, self.SearchBox.text())
        
        # 위메프 함수 호출
        self.statusBar.showMessage('위메프에서 정보를 가져오고 있습니다...')
        [WeMapeItemNameList, WeMapeItemPriceList, WeMapeItemLinkList] = AutoShopping.AutoWeMape(self.driver, self.SearchBox.text())

        self.driver.quit()

        self.statusBar.showMessage('Ready')

        # 쿠팡 링크 버튼 구현
        self.CouPangLinkBttn = CoPangItemLinkList
        for loopidx in range(0, CouPangItemNameList.__len__()):
            self.tableWidget1.setItem(loopidx, 0, QTableWidgetItem(CouPangItemNameList[loopidx]))
            self.tableWidget1.setItem(loopidx, 1, QTableWidgetItem(CouPangItemPriceList[loopidx] + '원'))
            # 링크를 열기 위한 버튼 생성
            self.btn1 = QPushButton('Link')
            self.btn1.clicked.connect(self.clicked_CouPanglink_btn)
            self.tableWidget1.setCellWidget(loopidx, 2, self.btn1)

        self.tableWidget1.resizeColumnsToContents()
        self.tableWidget1.resizeRowsToContents()
        self.tableWidget1.setEditTriggers(QAbstractItemView.NoEditTriggers)
        
        # 티몬 링크 버튼 구현
        self.TiMonLinkBttn = TiMonItemLinkList
        for loopidx in range(0, TiMonItemLinkList.__len__()):
            self.tableWidget2.setItem(loopidx, 0, QTableWidgetItem(TiMonItemNameList[loopidx]))
            self.tableWidget2.setItem(loopidx, 1, QTableWidgetItem(TiMonItemPriceList[loopidx]))
            # 링크를 열기 위한 버튼 생성
            self.btn2 = QPushButton('Link')
            self.btn2.clicked.connect(self.clicked_TiMonlink_btn)
            self.tableWidget2.setCellWidget(loopidx, 2, self.btn2)

        self.tableWidget2.resizeColumnsToContents()
        self.tableWidget2.resizeRowsToContents()
        self.tableWidget2.setEditTriggers(QAbstractItemView.NoEditTriggers)

        # 위메프 링크 버튼 구현
        self.WeMapeBttn = WeMapeItemLinkList
        for loopidx in range(0, WeMapeItemLinkList.__len__()):
            self.tableWidget3.setItem(loopidx, 0, QTableWidgetItem(WeMapeItemNameList[loopidx]))
            self.tableWidget3.setItem(loopidx, 1, QTableWidgetItem(WeMapeItemPriceList[loopidx]))
            # 링크를 열기 위한 버튼 생성
            self.btn3 = QPushButton('Link')
            self.btn3.clicked.connect(self.clicked_WeMapelink_btn)
            self.tableWidget3.setCellWidget(loopidx, 2, self.btn3)

        self.tableWidget3.resizeColumnsToContents()
        self.tableWidget3.resizeRowsToContents()
        self.tableWidget3.setEditTriggers(QAbstractItemView.NoEditTriggers)

    # 쿠팡 버튼 클릭 시..
    def clicked_CouPanglink_btn(self):
        button = qApp.focusWidget()
        index = self.tableWidget1.indexAt(button.pos())
        if index.isValid():
            self.driver = webdriver.Chrome('chromedriver.exe')
            self.driver.get(self.CouPangLinkBttn[index.row()])

    # 티몬 버튼 클릭 시..
    def clicked_TiMonlink_btn(self):
        button = qApp.focusWidget()
        index = self.tableWidget2.indexAt(button.pos())
        if index.isValid():
            self.driver = webdriver.Chrome('chromedriver.exe')
            self.driver.get(self.TiMonLinkBttn[index.row()])
            
    # 위메프 버튼 클릭 시..
    def clicked_WeMapelink_btn(self):
        button = qApp.focusWidget()
        index = self.tableWidget3.indexAt(button.pos())
        if index.isValid():
            self.driver = webdriver.Chrome('chromedriver.exe')
            self.driver.get(self.WeMapeBttn[index.row()])


if __name__ == "__main__":
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    app.exec_()
    app.exit(0)

