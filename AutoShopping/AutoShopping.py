from selenium import webdriver
from bs4 import BeautifulSoup


def AutoCopang(driver, keyword):
    # 쿠팡 접속
    driver.get('https://www.coupang.com/')
    # 검색어 입력
    driver.find_element_by_name('q').send_keys(keyword)
    driver.close()

if __name__ == "__main__":
    mainKeyword = '로봇청소기'
    driver = webdriver.Chrome('chromedriver.exe')
    driver = AutoCopang(driver, mainKeyword)

