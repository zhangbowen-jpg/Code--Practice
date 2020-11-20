#!/usr/bin/env python
# coding=utf-8
class People:
    name = ''
    age = 0
    sex = 'male'
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def show(self):
        print("name = %s, age = %d" % (self.name, self.age))
    def grow(self, num = 1):
        self.age += num
        self.show()
    def show_sex(self):
        print("%s <%s>" % (self.name, self.sex))
    def add_sex(self, sex):
        self.sex = sex
        self.show_sex()


a = People('suyelu', 18)
a.show()
a.grow()
a.grow(10)
a.add_sex('f')8

