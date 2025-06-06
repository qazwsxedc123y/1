import datetime

# # 活了7743天
# date1 = datetime.datetime(2004,3,25)
# date2 = datetime.datetime(2025,6,6)
# print(date2 - date1)


# class Solution(object):
#     def reverseWords(self, message):
#         # 先以空格分开
#         tokens = message.split()
#         # 反转
#         tokens.reverse()
#         return ' '.join(tokens)
#
#     def reverseMessage(self, message):
#         """
#         :type message: str
#         :rtype: str
#         """
#         return self.reverseWords(message)
#
#
#
# class Solution(object):
#     def rotateString(self, s, goal):
#         """
#         :type s: str
#         :type goal: str
#         :rtype: bool
#         """
#         return len(s) == len(goal) and s in goal + goal
#
#
# class Solution(object):
#     def countPrefixes(self, words, s):
#         """
#         :type words: List[str]
#         :type s: str
#         :rtype: int
#         """
#         ret = 0
#         for word in words:
#             if s.startswith(word):
#                 ret += 1
#
#         return ret


# E:\code\py

# 简易everything
# import os
#
# inputpath = input('请输入待搜索路径: ')
# pattern = input('请输入待搜索关键词: ')
#
# for paht, dirname, filename in os.walk(inputpath):
#     for f in filename:
#         if pattern in f:
#             print(f'{paht}/{f}')
#
# import qrcode
# import base64
# # img = qrcode.make("http://google.com")
# # img.save("test.png")
#
#
# # 方法 1：使用原始字符串（推荐）
# with open(r"E:\照片\49.jpg", "rb") as image_file:
#     base64_data = base64.b64encode(image_file.read()).decode("utf-8")
# #
# # # 方法 2：转义反斜杠
# with open("E:\\照片\\49.jpg", "rb") as image_file:
#     base64_data = base64.b64encode(image_file.read()).decode("utf-8")
# # # 1. 读取图片并转为 Base64
# # with open("E:\照片\49.jpg", "rb") as image_file:
# #     base64_data = base64.b64encode(image_file.read()).decode("utf-8")
#
# # 2. 生成二维码，内容为 data URI（格式：data:image/jpeg;base64,XXXX）
# data_uri = f"data:image/jpeg;base64,{base64_data}"
# qr = qrcode.make(data_uri)
# qr.save("embedded_image.png")


# import base64
# import qrcode
#
# try:
#     # 读取图片并转为 Base64
#     with open("E:\\照片\\28.jpg", "rb") as image_file:
#         image_data = image_file.read()
#
#     # 检查图片大小（建议 < 1MB）
#     if len(image_data) > 1_000_000:  # 1MB
#         print("警告：图片太大，可能导致二维码无法扫描！")
#
#     base64_data = base64.b64encode(image_data).decode("utf-8")
#
#     # 生成 Data URI（格式：data:image/jpeg;base64,XXXX）
#     data_uri = f"data:image/jpeg;base64,{base64_data}"
#
#     # 生成二维码
#     qr = qrcode.make(data_uri)
#     qr.save("embedded_image.png")
#     print("✅ 二维码生成成功！保存为 embedded_image.png")
#
# except Exception as e:
#     print(f"❌ 发生错误：{e}")