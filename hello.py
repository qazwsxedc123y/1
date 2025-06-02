#avg = (67.5 + 89.0 + 12.9 + 32.2) / 4
#total = (67.5 - avg) ** 2 + (89.0 - avg) ** 2 + (12.9 - avg) ** 2 + (32.2 - avg) ** 2
#ret = total / 3
#print(ret)
#print(type(ret))
'''
print("hello world")
e = 'hello world "zhangsan"'
print(e)
print(len(e))
'''
# 使用三引号

# f = ''''hello 'world' "zhangsan h h h"' '''
# print(f)

# a = "hello"

# b = "world"

# print(a + " " + b)

# a = 10
# print(type(a))
#
# a = 10.0
# print(type(a))
#
# a = "hello world"
# print(type(a))

# a:int = 10
# print(f"a = {a}")
# b = 10;


# e = "hello world"
# print(len(e))
# 字符串不可以与整形/浮点数相加，只可以与字符串相加
# python没有字符的概念，只有字符串

# 动态类型

# a = 10
# print(a ,f"type(a) = {type(a)}")
#
# a = 10.0
# print(a ,f"type(a) = {type(a)}")
#
# a = "hello world"
# print(a ,f"type(a) = {type(a)}")

# 但是输入的接受的返回值是字符串类型

# a = input("请输入第一个数")
# b = input("请输入第二个数")
# c = input("请输入第三个数")
# print(type(a))
# print(f"第一个数：{a},第二个数：{b},第三个数{c}")
# print(a,b,c)


# / 中不能用 0 作为除数，否则会抛出异常

# print(10 / 0)

# # 整数 / 整数 结果可能是小数. 而不会截断
#
# print(10 / 4)
#
# # % 不是 "百分数", 而是求余数
# print(10 % 4)
#
# # ** 是求乘方. 不光能算整数次方, 还能算小数次方
# print(2 ** 2)
# print(2 ** 0.5)
# print(2 ** -0.5)
#
# # // 是取整除法(也叫地板除). 整数除以整数, 结果还是整数(舍弃小数部分, 并向下取整. 不是四舍五入
#
# print(10 // 4)
# print(-10 // 4)

# a = 10
# b = 20
#
# print(a < b)
# print(a >= b)
# print(a != b)

# # 直接使用 == 或者 != 即可对字符串内容判定相等. (这一点和 C / Java 不同).
#
# a = 'hello'
# b = 'world'
# c = 'hello'
#
# print(a == b)
# print(a != c)
# print(a == c)

# # 浮点数不精准问题
#
# a = 0.1
# b = 0.2
# c = 0.3
# print(a + b) # 0.30000000000000004
# print(a + b == 0.3)
# d = a + b
# print(-0.0000001 < d - c < 0.0000001)

# # 逻辑运算
#
# # and or not
#
# a = True
# b = False
# print(a and b)
# print(a or b)
# print(not a)
# print(not b)
# print(a and (not b))

# 短路求值

# # 对于 and, 如果左侧表达式为 False, 则整体一定为 False, 右侧表达式不再执行.
# print(10 > 20 and 10 / 0 == 1)
# # 对于 or, 如果左侧表达式为 True, 则整体一定为 True, 右侧表达式不再执行
# print(10 < 20 or 10 / 0 == 1)

# 上述代码没有抛出异常, 说明右侧的除以 0 操作没有真正执行.

# # 多元赋值
#
# a, b = 10 , 20
# print(a ,b)
#
# # 巧用与交换两值
# a ,b = b ,a
# print(a ,b)

# 复合赋值运算符
# 使用之前要先初始化

# a = 10
# a += 1
# print(a)
# a -= 1
# print(a)

# Python 中没有 ++ ， -- 的操作， ++ 会被识别位两个正数符号， -- 被识别为两个负数符号
# 负负得正

# 也可以但可读性差
a = 10; b = 20
print(a)