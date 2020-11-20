#!/usr/bin/env python
# coding=utf-8
from urllib import request
from bs4 import BeautifulSoup
url = "http://www.baidu.com"

html = request.urlopen(url)

bs = BeautifulSoup(html, 'html.parser')
#.parser 代表解析器
jgwab = bs.find('a',id='jgwab')

zi=bs.find('p',class_='sub-title')

#加_代表class是属性

print(zi.text)
print(jgwab.text)

file = open('./a.txt', 'w')

file.write(jgwab.text)

file.close()


#print(html.read().decode('UTF-8'))
#读取html 解码
