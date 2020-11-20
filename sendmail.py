#!/usr/bin/env python
# coding=utf-8
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
import json

def get_user_info():
    with open('user.json', 'r')as info: #使用json来获得对应的信息(API接口)
        return json.loads(info.read())
#添加对应邮箱所在
server = smtplib.SMTP('smtp.qq.com')
userinfo = get_user_info()

server.login(userinfo['user'],userinfo['password'])

message = "这是一个测试邮件"

msg = MIMEMultipart()
content = MIMEText(message)


file = MIMEApplication(open('a.txt', 'rb').read())

file.add_header("content-disposition","attachment",filename = 'b.txt')

msg.attach(file)
msg.attach(comtent)
msg['Subject']="测试附件"
msg['From']= userinfo['user']
msg['To'] = userinfo['user']

server.sendmail(userinfo['user'],userinfo['user'],msg.as_string())


