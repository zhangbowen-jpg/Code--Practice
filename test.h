/*************************************************************************
	> File Name: test.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月26日 星期四 19时54分01秒
 ************************************************************************/
#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) void a##b()
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");

int RUN_ALL_TESTS();

#endif
