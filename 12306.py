#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

from selenium import webdriver
import time
url = 'https://kyfw.12306.cn/otn/leftTicket/init?linktypeid=dc'

driver = webdriver.Chrome()
driver.get(url)

start = driver.find_element_by_xpath('//*[@id="fromStationText"]')
#选中要检查部分，右键检查并copy为xpath文件
start.click()
time.sleep(1)
start.send_keys("哈尔滨")
time.sleep(1)
select = driver.find_element_by_xpath('//*[@id="citem_0"]')
select.click()


end = driver.find_element_by_xpath('//*[@id="toStationText"]')
end.click()
time.sleep(1)
end.send_keys("上海")
time.sleep(1)
select = driver.find_element_by_xpath('//*[@id="citem_0"]')
select.click()


#因为12306反爬虫将日期调成只读，所以将只读标签去掉。
js = 'document.getElementById("train_date").removeAttribute("readonly");'
driver.execute_script(js)

date_s = driver.find_element_by_xpath('//*[@id="train_date"]')
date_s.clear()
date_s.send_keys("2019-07-13")

#date = time.strftime('%Y-%m-%d', time.localtime(time.time()))
##print(date)


search = driver.find_element_by_xpath('//*[@id="query_ticket"]')
search.click()

