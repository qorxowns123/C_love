from selenium import webdriver
from bs4 import BeautifulSoup
import os


def AutoCoupang(keyword):

    driver = webdriver.PhantomJS('phantomjs.exe')
    # 쿠팡 접속
    driver.get('https://www.coupang.com/')
    # 검색어 입력
    driver.find_element_by_name('q').send_keys(keyword)
    # 검색 버튼 클릭
    driver.find_element_by_xpath('//*[@id="headerSearchBtn"]').click()
    # 웹페이지 소스 추출
    getHtml = driver.page_source

    # HTML 소스 읽어오기
    getParser = BeautifulSoup(getHtml, 'html.parser')

    # 태그를 통한 이름 가져오기
    CoPangItemNameList = []
    getTagInfo = getParser.find_all("div", {"class" : "name"})
    for loopidx in range(0, getTagInfo.__len__()):
        CoPangItemNameList.append(getTagInfo[loopidx].text)

    # 태그를 통한 가격 가져오기
    CoPangItemPriceList = []
    getTagInfo = getParser.find_all("strong", {"class": "price-value"})

    for loopidx in range(0, getTagInfo.__len__()):
        if not getTagInfo[loopidx].text:
            CoPangItemPriceList.append("품절")
        else:
            CoPangItemPriceList.append(getTagInfo[loopidx].text)

    # 태그를 통한 상품 링크 가져오기
    CoPangItemLinkList = []
    getTagInfo = driver.find_elements_by_class_name("search-product")
    for loopidx in range(0, getTagInfo.__len__()):
        CoPangItemLinkList.append(getTagInfo[loopidx].find_element_by_css_selector('a').get_attribute("href"))

    driver.close()

    return (CoPangItemNameList, CoPangItemPriceList, CoPangItemLinkList)


