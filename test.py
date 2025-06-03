# 按序打印

# print("1")
# print("2")
# print("3")

# print("你是选择认真敲代码，还是摆烂")
# print("认真敲代码：1")
# print("摆烂：0")
# choice = int(input("请输入你的选择"))
# if choice == 1:
#     print("容易找到工作")
# else :
#     print("毕业即失业")


# choice = int(input("请输入一个数字(1-5):"))
# if choice == 1:
#     print("你输入的是1")
# elif choice == 2:
#     print("你输入的是2")
# elif choice == 3:
#     print("你输入的是3")
# elif choice == 4:
#     print("你输入的是4")
# elif choice == 5 :
#     print("你输入的是5")
# else :
#     print("输入的数字非法")

# 判断输入的是奇数还是偶数

# # py计算取模规则
# # a % b = a - b * floor(a / b)
#
# # -19 % 2
# # -19 / 2 = -9.5
# # floor(-9.5) = -10  向下取整
# # -19 - 2 * -10 = 1
#
# a = int(input("请输入一个数字: "))
# if a % 2 == 0 :
#     print("偶数")
# else :
#     print("奇数")


# # 判断整数的正负
# a = int(input("请输入一个数字: "))
# if a > 0 :
#     print("正数")
# elif a < 0 :
#     print("负数")
# else :
#     print("为 0 ")

# # 判断是否为闰年
# # 4年一闰，百年不闰， 400年一闰
#
# year = int(input("请输入一个年份: "))
# if year % 400 == 0 or (year % 4 == 0 and year % 100 != 0) :
#     print("闰年")
# else :
#     print("平年")


# # 空语句
#
# a = int(input("请输入一个数字: "))
# if a == 1 :
#     # 什么也不做
#     pass
# else :
#     print("不是1")


# # 打印 1 - 10
#
# num = 1
# while num <= 10 :
#     print(num)
#     num = num + 1


# # 计算1 - 100的和
#
# num = 1
# thesum = 0
# while num <= 100 :
#     thesum += num
#     num += 1
# print(thesum)


# # 计算 5 的阶乘
#
# ret = 1
# num = 1
# while num <= 5 :
#     ret *= num
#     num += 1
# print(ret)


# # 计算 1！+ 2！+ 3！+ 4！+ 5！
#
# ret = 0
# num = 1
# tmp = 1
# while num <= 5 :
#     tmp *= num
#     ret += tmp
#     num += 1
# print(ret)

# 打印1-10

# for i in range(1, 11) :
#     print(i)

# range(10) 表示 range(0, 10)

# for i in range(10) :
#     print(i) 打印 0 - 9


# 打印 2 4 6 8 10

# for i in range(2, 11, 2) :
#     print(i)


# # 打印10 - 1
#
# for i in range(10, 0, -1):
#     print(i)


# # 求 1 - 100 的和
# ret = 0
# for i in range(1, 101) :
#     ret += i
# print(ret)


# continue 与 break

# for i in range(1, 6) :
#     if i == 3 :
#         print("第三个包子有虫子，不吃")
#         continue
#     print(f"吃完第{i}个包子了")

# for i in range(1, 6) :
#     if i == 3 :
#         print("第三个包子有半个虫子，差评，不吃了")
#         break
#     print(f"吃完第{i}个包子了")


# # 计算输入的数字的平均值，最后以；号为结尾
#
# count = 0
# sum = 0
# while True :
#     num = input("请输入一个整数: ")
#     print(type(num))
#     if num == ";" :
#         print(type(num))
#         break
#     sum += int(num)
#     count += 1
#     print(type(num))
# print(f"平均值为 ： {sum / count}")