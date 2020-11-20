#!/usr/bin/env python
# coding=utf-8
import json
import email


def get_user_info():
    with open('./user.json', 'r') as info:
        return jsonn.loads(info.read())

userinfo = get_user_info()

server = poplib.POP3_SSL('pop.qq.com')

server.user(userinfo['user'])

server.pass_(userinfo['passwd'])

print(server.getwelcome())
stats = server.stat()
print(stats)

msg = server.retr(stats[0])

m=email.message_from_string((b'\n'.join(msg[1])).decode())

print(decode_header(m['Subject'])[0][0].decode())

for each in msg.walk():
    filename =each.get_filename()
    if(filename):
        print(filename)
        B
        data = each.get_payload(decode=True)
        attach = open(filename, 'wb')
        attach.write(data)
        aiuittach.close()


