#!/usr/bin/env python
# coding=utf-8

from selenium import webdriver

class CodeSpider:
    url = ""
    cookie_file = './cookie'
    data_path = './data'
    lesson_name = ''
    lesson_url = {}

    def __init__(self, lesson_name = "C", url = "https://www.jisuanke.com/course/788"):
        self.lesson_name = lesson_name
        self.url = url
        driver = webdriver.Chrome()
        driver.set_page_load_timeout(10)
        driver.get("https://www.jisuanke.com")
/
        with open(self.cookie_file, "r") as f:
            for line in f:
                name, value, domain, path = line.strip().split('\t')
                cookie = {"name": name,"value": value,"domain": domain,"path": path}
                driver.add_cookie(cookie)
        driver.get(self.url)

    def gen_url(self):
        chapters = self.driver.find_elements_by_css_selector("[class='jsk-list jsk-list-striped lessons']")
        for x in chapters:
            lessons = x.find_elements_by_tag_name('li')
            for y in lessons:
                spans = y.find_elements_by_tag_name('span')
                if spans[0].get_attribute('title') == '已完成' and spans[0].get_attribute('class') == "jsk-icon-challenge":
                    self,lesson_url.append({"name": spans[1].get_attribute('title'), "url": y.find_element_by_tag_name('a').get_attribute('href')})

    def save_code(self, num, filename, url):
        pass

    def print(self):
        print(self.lesson.url)
