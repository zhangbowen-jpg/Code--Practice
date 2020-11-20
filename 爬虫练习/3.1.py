#!/usr/bin/env python
# coding=utf-8

from selenium import webdriver
import time 
import os

class CodeSpider:
    url = ""
    cookie_file = './cookie'
    data_path = './data'
    class_name = ''
    class_url = []
    num = 0;


    def __init__(self, class_name = "Python", url = "https://www.jisuanke.com/course/788"):
        print('__init__')
        self.class_name = class_name
        self.url = url
        driver = webdriver.Chrome()
        driver.set_page_load_timeout(10)
        driver.get("https://www.jisuanke.com")

        with open(self.cookie_file, "r") as f:
            for line in f:
                name, value, domain, path = line.strip().split('\t')
                cookie = {"value": value, "domain": domain, "name": name, "path": path}
                driver.add_cookie(cookie)

        driver.get(self.url)
        time.sleep(1)
        self.driver = driver


    def gen_url(self):
        self.driver.refresh()
        chapter = self.driver.find_elements_by_css_selector("[class='jsk-list jsk-list-striped lessons']")
        for x in chapters:
            lessons = x.find_elements_by_tag_name('li')
            for y in lessons:
                spans = y.find_elements_by_tag_name('span')
                if spans[0].get_attribute('title') == '已完成' and spans[0].get_attribute('class') == "lesson-icon-challenge":
                    self.lesson_url.append({"name":spans[1].get_attribute('title'), "url": y.find_element_by_tag_name('a').get_attribute('href')})

    def save_code(self, num, filename, url):
        js_code = "window.open(\"%s\")" % url
        self.driver.execute_script(js_code)
        handles = self.driver.window_handles
        self.driver.swtich_to.window(handles[1])
        code = self.driver.find_element_by_tag_name('pre')
        file_path = "%s/%s" % (self.data_path, self.class_name)
        if not os.path.exists(file_path):
            os.makedirs(file_path)
        file_path = "%s/%d.%s.py" % (file_path, num, filename)

        with open(file_path, 'w') as f:
            f.write(code.text)
            f.close()

        self.driver.close()
        self.driver_switch_to.window(handles[0])


    def get_code(self):
        cnt = 0;
        for i in self.lesson_url:
            self.driver.get(i['url'])
            time.sleep(1)
            continue_ = self.driver.find_elements_by_css_selector('[class="jsk-btn jsk-link-muted"]')
            if len(continue_):
                continue_[0].click()
            time.sleep(1)
            his = self.driver.find_element_by_id('submit-history-trigger')
            his.click()
            time.sleep(1)
            submit_list = self.driver.find_element_by_tag_name('tbody')
            for x in submit_list.find_elements_by_tag_name('tr'):
                success_list = x.find_elements_by_css_selector('[class="jsk-text-success"]')
                if len(success_list):
                    code_url = x.find_element_by_tag_name('a').get_attribute('href')
                    cnt = cnt + 1
                    break
                self.save_code(cnt, i['name'], code_url)



    def destory(self):
        self.driver.quit()

    def auto(self):
        self.gen_url()
        self.get_code()
        self.destory()

        def __del__(self):
            print('__del__')


