# def add(a, b) :
#     return a + b
#
#
# print(add(1, 2))
# print(add(1, 2))


# 计算1 - 100 的和
#
# def sum(a, b = 100):
#     sum = 0
#     for i in range(a, b+1):
#         sum += i
#     return sum
#
#
# print(sum(1, 100))
# print(sum(b = 100, a = 1))
# print(sum(1))

# def getpoint() :
#     x = 10
#     y = 20
#     return x,y
#
#
# a, b = getpoint()
# _, m = getpoint()
# print(a,b)
# print(_,m)
# print(_)
# print(type(_))


# # 列表
#
# # 创建
# alist1 = []
# alist2 = list()
#
# print(type(alist1))
# print(type(alist2))
#
# alist3 = [1, 2, 3, 4]
# print(alist3)
# alist4 = list((5,6,7,8))
# print(alist4)
#
# print(alist3[2])
# print(alist3)
# print(alist3[-1])
# print(alist3[:-1])
# print(alist3[1:-1])
# print(alist3[1:-1:2])
# print(alist3[::-1])
#
# for elem in alist3:
#     print(elem)
#
# for i in range(0,len(alist3)):
#     print(alist3[i])


# alist = [1, 2, 3, 4]
# alist.insert(1, 'hello')
# print(alist)
# alist.pop() # 删尾部
# print(alist)
# alist.pop(0)
# print(alist)
# alist.index(3)
# print(alist)
# blist = [5,6,7,8]
# print(alist + blist)
# alist.extend(blist)
# print(alist)


# 元组

atuple = ()
atuple = tuple()

# 不可以修改

# 键值对

a = {}
b = dict()
print(type(a))
print(type(b))

a = {2:'id', 3:'hello'}
print(a[2])
# print(a[1]) # 没有抛异常
print('2' in a)
print(2 in a)
a[1] = 'name'
print(a)
a[2] = 'name'
print(a)
a.pop(1)
print(a)

print(a.keys())
print(a.values())
print(a.items())
for key,value in a.items():
    print(key, value)
