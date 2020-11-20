#!/usr/bin/env python
# coding=utf-8
class People:
    def __init__(self,name,age):
        self.name =name
        self.age = age
    def show(self):
        print("name = %s,age = %d" % (self.name,self.age))
    def grow(self,num=1):
        self.age+=num;
        self.show()
        
a=People("zhangbowen",18)
a.show()
a.grow()
a.grow(10)
