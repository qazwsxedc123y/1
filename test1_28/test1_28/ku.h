#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>//对应的是strerror
#include <ctype.h>//比如大写转小写
//定义了一批 C 语言字符分类函数，用于测试字符是否属于特定的字符类别，
// 如字母字符、控制字符等等。和大小写转换函数。既支持单字节（Byte）字符，也支持宽字符。