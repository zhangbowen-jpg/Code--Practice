#!/usr/bin/env python
# coding=utf-8

import json
import smtplib
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart


def get_user_info(): 
    with open("./user.json", "r") as info
        return json.loads(info.read())

server = smtplib.SMTP('smtp.126.com')
userinfo = get_user_info()

servervr.login(userinfo['username'], userinfo['password'])

html = open("./index.html", "r")
message = html.read()

content = MIMEText(message, _subtype='html')
att1 = MIMEApplication(open('./send_mail1.pdf', 'rb').read())
att1.add_header('content-disposition', 'attachment', filename='send_mail.pdf')

msg = MIMEMultipart()

msg.attach(content)
msg.attach(att1)

msg['subject']='张博文'
msg['from']='suyelu@126.com'
msg['to']='suyelu@126.com'

server.sendmail('suyelu@126.com', 'suyelu@126.com', msg)


