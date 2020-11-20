## Python 爬虫

诞生较早，与互联网同步发展，搜索引擎就是使用网络爬虫在网站上爬取资源，建立索引

在大数据架构中，数据收集与数据存储占据了及位重要的比例，是大数据的核心基础，而爬虫在这两大核心技术中，占了很大比例，其具备主动、自动化的特点。

### urllib介绍

这是python的一个内建模块

使用urllib提供的函数urlopen产生一个请求报文，执行后得到一个响应报文

通过调用响应对象的方法read可以将对象的body属性以文本的方式读出。

### BeautifulSoup介绍

BeautifulSoup是一个可以从HTML或XML文件中提取数据的python库

Beautifulsoup将一个复杂的HTML文档转换成一个复杂的数性结构，每一个节点都是python的对象，归纳为Tag，BeautifulSoup，NavigableString，Comment死中

BeautifulSoup对象：BeautifulSoup程序的入口对象

​	三种构造方法： 1.传入HTML代码片段

​								 2.传入完整的HTML文档

​								 3.传入指定的网页文件

Tag对象

​		1.使用BeautifulSoup将XML或HTML文档实例化后，本质上是将输入的字符串内容生成树状层及关系结构的Tag集合

​		2.Tag有很多属性和方法，但最为重要的是name和attribute

​		3.其中attribute是一个字典

