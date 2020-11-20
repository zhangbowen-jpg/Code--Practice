#!/usr/bin/env python
# coding=utf-8

from urllib import request
from bs4 import BeautifulSoup


def load_page(url):
    user_agent = 'User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36'
#从不同地方登陆 user_agent 不同
    headers = {'User_Agent' : user_agent}
    req = request.Request(url, headers = headers)
    response = request.urlopen(req)
    return response.read()


def write_to_file(filename, soup_text):
    f = open(filename, 'w')
    for each in soup_text.find_all('p'):
        f.write(each.text)
        f.write('\n')
    f.close()


def spider(url, chapter):
    html = load_page(url)
    bs = BeautifulSoup(html, 'html.parser')
    chapter_name = bs.find('h1').text
    print(chapter_name)
    soup_text = bs.find('div', class_ = 'chapter_content')
    path = './data/'
    filename = path + str(chapter) + ".%s.txt" % chapter_name
    write_to_file(filename, soup_text)


if __name__ == "__main__":
    base_url = 'http://shicimingju.com/book/sanguoyanyi/'
    for chapter in range(1, 121):       #左闭右开
        url = base_url + str(chapter) + '.html'
        spider(url, chapter)
