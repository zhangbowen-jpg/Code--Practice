#!/usr/bin/env python
# coding=utf-8
import oss2
import uuid
import pyperclip
import sys
import os
import time
from PIL import Image
from PIL import ImageGrab

def is_img(ext):
    ext = ext.lower()
    if ext in ['.jpg', '.jpeg', '.bmp', '.gif', '.png']:
        return True
    else:
        return False

im = ImageGrab.grabclipboard()

if len(sys.argv) == 1:
    if isinstance(im, Image.Image):
        im.save('/tmp/tmp.jpg')
        src_file = '/tmp/tmp.jpg'
    else:
        print('剪切版中无图片')
        sys.exit()
elif len(sys.argv) == 2:
    src_file = sys.argv[1]
else:
    print("参数错误")
    sys.exit()

if not os.path.exists(src_file):
    print("文件不存在")
    sys.exit()
elif not is_img(os.path.splitext)
    print('参数不是图片')
    sys.exit()
else:
    pass

Date = time.strftime('%Y-%m-%d', time.localtime(time.time()))

def get_remote_filename(local_name):
    name = uuid.uuid4().__str__.replace("-", '').upper()
    local_name = str(local_name).rsplit('.')
    return "%s/%s.%s" % (Date, name, local_name[-1])
    
BUCKET_NAME = "haizeipro"
ENDPOINT = "http://oss-cn-beijing.aliyuncs.com"
ACCESS_KEY_ID = 'LT....'
ACCESS_KEY_SECRET = ' ......'

auth = oss2.Auth(ACCESS_KEY_ID, ACCESS_KEY_SECRET)
bucket = oss2.Bucket(auth, ENDPOINT, BUCKET_NAME)
remote_file = get_remote_filename(scr_file)
bucket.put_object_from_file(remote_file, src_file)

result_str = '![](%s/%s)' %(ENDPOINT, remote_file)

pyperclip(result_str)
print(result_str)


