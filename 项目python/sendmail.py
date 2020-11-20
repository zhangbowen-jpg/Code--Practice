#!/usr/bin/env python
# coding=utf-8

import smtplib
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.header import Header

mail_host="smtp.qq.com"
mail_user="823809800@qq.com"
mail_pass="jqhicjxsjhvsbeie"

sender = '823809800@qq.com'
receivers = ['suyelu@126.com']

message = MIMEMultipart('related')
message['From'] = Header("张博文", 'utf-8')
message['To'] = Header("suyelu", 'utf-8')

subject = '张博文'
message['Subject'] = Header(subject, 'utf-8')

msgAlternative = MIMEMultipart('alternative')
message.attach(msgAlternative)

mail_msg ="""
<p>Python 邮件发送测试...</p>
<p><a href="http://www.baidu.com">百度一下链接</a></p>
<p><img src = "cid:image1"></p>
"""
msgAlternative.attach(MIMEText(mail_msg, 'html', 'utf-8'))

fp = open('百度.png', 'rb')
msgImage = MIMEImage(fp.read())
fp.close()

msgImage.add_header('Content-ID', '<image1>')
message.attach(msgImage)

add1 = MIMEText(open('code.pdf', 'rb').read(), 'base64', 'utf-8')
add1["Content-Type"] = 'application/octet-stream'
add1["Content-Disposition"] = 'attachment; filename="code.pdf"'
message.attach(add1)

mail_msg2 = """
<p>Python 邮件发送测试...</p>
<p><a href="http://www.baidu.com">百度一下链接</a></p>
"""

add2 = MIMEText(mail_msg2, 'html', 'utf-8')
add2["Content-Type"] = 'application/octet-stream'
add2["Content-Disposition"] = 'attachment; filename="baidu.html"'
message.attach(add2)

add3 = MIMEText(open('code2.pdf', 'rb').read(), 'base64', 'utf-8')
add3["Content-Type"] = 'application/octet-stream'
add3["Content-Disposition"] = 'attachment; filename="code2.pdf"'
message.attach(add3)

try: 
    Object = smtplib.SMTP()
    Object.connect(mail_host, 25)
    Object.login(mail_user,mail_pass)
    Object.sendmail(sender, receivers, message.as_string())
    print("邮件发送成功")
except smtplib.SMTPException:
    print("Error : 无法发送邮件")


## 使用   wget + 网址 命令 来获取网页html。
