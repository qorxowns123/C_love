from bs4 import BeautifulSoup

'''
쿠팡 함수
'''

def AutoCoupang(driver, keyword):

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

    return (CoPangItemNameList, CoPangItemPriceList, CoPangItemLinkList)

'''
티몬 함수
'''

def AutoTiMon(driver, keyword):

    # 티몬 접속
    driver.get('http://www.ticketmonster.co.kr/home')

    # 검색어 입력
    # 쿠팡의 경우에는 data-value의 값이 세팅되어 있으면 그 값을 우선으로 하여 검색하기 때문에
    # 이 값을 바꿔줘야 함
    ele = driver.find_element_by_xpath('//*[@id="top_srch"]')
    driver.execute_script("arguments[0].setAttribute('data-value',arguments[1])", ele, keyword)

    # 검색버튼 클릭
    driver.find_element_by_xpath('//*[@id="srchbar2"]/form/fieldset/button/i').click()

    # 웹페이지 소스 추출
    getHtml = driver.page_source

    # HTML 소스 읽어오기
    getParser = BeautifulSoup(getHtml, 'html.parser')

    # 태그를 통한 이름 가져오기
    TiMonItemNameList = []
    getTagInfo = getParser.find_all("strong", {"class": "deal_item_title"})
    for loopidx in range(0, getTagInfo.__len__()):
        ReplaceText = getTagInfo[loopidx].text.replace("\n", "")
        ReplaceText = ReplaceText.replace("\t", "")
        TiMonItemNameList.append(ReplaceText)

    # 태그를 통한 가격 가져오기
    TiMonItemPriceList = []
    getTagInfo = getParser.find_all("span", {"class": "deal_item_price"})
    for loopidx in range(0, getTagInfo.__len__()):
        ReplaceText = getTagInfo[loopidx].text.replace("\n", "")
        ReplaceText = ReplaceText.replace("\t", "")
        # 할인 가격인 경우, 4,500원9,990원 이런식으로 나옴
        FindStr = ReplaceText.find('원')
        ReplaceText = ReplaceText[0:FindStr+1]
        TiMonItemPriceList.append(ReplaceText)
        
    # 태그를 통한 상품 링크 가져오기
    TiMonItemLinkList = []
    getTagInfo = getParser.find_all("div", {"class": "deal_item_thumb"})
    for loopidx in range(0, getTagInfo.__len__()):
        TiMonItemLinkList.append(getTagInfo[loopidx].parent.attrs['href'])

    return (TiMonItemNameList, TiMonItemPriceList, TiMonItemLinkList)


'''
위메프 함수
'''

def AutoWeMape(driver, keyword):

    # 위메프 접속
    driver.get('http://www.wemakeprice.com')
    # 검색어 입력
    driver.find_element_by_name('search_keyword').send_keys(keyword)
    # 검색 버튼 클릭
    driver.find_element_by_xpath('/html/body/div[3]/div[4]/div/div[1]/form/fieldset/div/div/span/button').click()
    # 웹페이지 소스 추출
    getHtml = driver.page_source

    # HTML 소스 읽어오기
    getParser = BeautifulSoup(getHtml, 'html.parser')

    WeMapeItemNameList = []
    # 태그를 통한 이름 가져오기
    getTagInfo = getParser.find_all("strong", {"class": "tit_desc"})
    for loopidx in range(0, getTagInfo.__len__()):
        WeMapeItemNameList.append(getTagInfo[loopidx].text)

    WeMapeItemPriceList = []
    # 태그를 통한 가격 가져오기
    getTagInfo = getParser.find_all("span", {"class": "sale"})
    for loopidx in range(0, getTagInfo.__len__()):
        SetPriceText = getTagInfo[loopidx].text.replace("~", "")
        SetPriceText = SetPriceText.replace("外", "")
        WeMapeItemPriceList.append(SetPriceText)

    WeMapeItemLinkList = []
    # 태그를 통한 링크 가져오기
    getTagInfo = getParser.find_all("span", {"class": "link type03"})
    for loopidx in range(0, getTagInfo.__len__()):
        SetLinkText = getTagInfo[loopidx].contents[1].attrs['href']
        WeMapeItemLinkList.append(SetLinkText)

    return (WeMapeItemNameList, WeMapeItemPriceList, WeMapeItemLinkList)




