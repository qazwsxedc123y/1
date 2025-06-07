# 使用列表保存学生信息
import os
import sys

import time

students = []


# 设计菜单
def meun() :
    print(" 1. 新增学生信息")
    print(" 2. 显示所有同学信息")
    print(" 3. 根据名字查找学生信息")
    print(" 4. 删除学生信息")
    print(" 0. 退出程序")
    choice = input(" 请输入您的选择: ")
    return int(choice)


# 插入
def insert() :
    print("[[新增成员]] 开始")
    studentId = input("请输入学生的学号：")
    name = input("请输入学生的姓名：")
    while True :
        gender = input("请输入学生的性别：")
        if gender not in ["男", "女"]:
            print("输入的性别有误，请重新输入！")
        else :
            break
    ClassName = input("请输入学生的班级：")
    student = {
        'studentId': studentId,
        'name': name,
        'gender': gender,
        'className': ClassName
    }
    global students
    students.append(student)
    print("新增学生成员成功！")
    save()


# 打印全部
def show() :
    print("[[显示所有学生信息]] 开始")
    for student in students :
        print(f"学生号：{student['studentId']}，姓名：{student['name']}, 性别：{student['gender']}，班级：{student['className']}")
    print(f"显示完毕，经统计一共{len(students)}名学生。")


# 查找
def find() :
    print("[[查找学生]] 开始!")
    name = input("请输入要查找的同学姓名: ")
    count = 0
    for student in students :
        if student['name'] == name :
            print(f"学生号：{student['studentId']}，姓名：{student['name']}, 性别：{student['gender']}，班级：{student['className']}")
            count += 1
    print(f"[查找学生] 完毕! 共查找到 {count} 条记录!")


# 删除
def delete() :
    print("[[查找学生]] 开始!")
    studentId = input("请输入要删除的同学学号: ")
    count = 0
    for student in students :
        if student['studentId'] == studentId :
            print(f"正在删除学生{student['name']}的信息")
            students.remove(student)
            count += 1
            time.sleep(1)
            print(f"学生{student['name']}的信息删除完毕")
    print(f"[删除学生] 完毕! 共删除 {count} 条记录!")
    save()


def save() :
    with open("E:/code//py//student//record.txt", "w", encoding="utf-8") as file :
        for student in students :
            file.write(f"{student['studentId']}\t{student['name']}\t{student['gender']}\t{student['className']}\n")
        print(f"[存档成功] 共存储了 {len(students)} 条记录!")


def load() :
    # 如果存档文件不存在, 则跳过读档环节
    if not os.path.exists("E:/code//py//student//record.txt"):
        return

    # 先清空全局变量里的数据
    global students
    students = []
    with open("E:/code//py//student//record.txt", "r", encoding="utf-8") as file :
        for line in file :
            # 去除末尾的换行符
            line = line.strip()
            tokens = line.split("\t")
            if len(tokens) < 4:
                print(f"文件格式有误! line={line}")
                continue
            student = {
                'studentId': tokens[0],
                'name': tokens[1],
                'gender': tokens[2],
                'className': tokens[3]
            }
            students.append(student)
        print(f"[读档成功] 共读取了 {len(students)} 条记录!")


# 主体
def main() :
    load()
    print('+--------------------------+')
    print('|                          |')
    print('|   欢迎来带学生管理系统!     |')
    print('|                          |')
    print('+--------------------------+')
    while True :
        choice = meun()
        if choice == 0 :
            sys.exit()
        elif choice == 1 :
            insert()
        elif choice == 2 :
            show()
        elif choice == 3 :
            find()
        elif choice == 4 :
            delete()
        else :
            print("您的输入有误，请重新输入！")


main()