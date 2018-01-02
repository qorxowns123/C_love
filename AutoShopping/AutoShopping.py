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

    # 태그를 통한 이름 가져오기aaa
    CoPangItemNameList = []
    getTagInfo = getParser.find_all("div", {"class" : "name"})
    for loopidx in range(0, getTagInfo.__len__()):
        CoPangItemNameList.append(getTagInfo[loopidx].text)

    # 태그를 통한 가격 가져오기
    CoPangItemPriceList = []
    getTagInfo = getParser.find_all("strong", {"class": "price-value"})
    for loopidx in range(0, getTagInfo.__len__()):
        CoPangItemPriceList.append(getTagInfo[loopidx].text)
        
    # 태그를 통한 이미지 가져오기
    dirName = '.\Image\Coupang'
    if not os.path.isdir('.\Image'):
        os.mkdir('.\Image')
    if not os.path.isdir(dirName):
        os.mkdir(dirName)

    CoPangItemImgList = []
    getTagInfo = getParser.find_all("dt", {"class": "image"})

    for loopidx in range(0, getTagInfo.__len__()):
        imageName = getTagInfo[loopidx].contents[1].attrs['src']
        imageWebAddr = 'http:' + imageName
        driver.get(imageWebAddr)
        # 이미지 저장하기 전에 폴더 만들어 놓고 하기
        fileName = dirName + '\Image' + str(loopidx) + '.png'
        CoPangItemImgList.append(fileName)
        driver.save_screenshot(fileName)

    driver.close()

    return (CoPangItemNameList, CoPangItemPriceList, CoPangItemImgList)


