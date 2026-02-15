import datetime
import os.path
import sys

from selenium import webdriver
from webdriver_manager.microsoft import EdgeChromiumDriverManager

class Driver:
    driver = ""
    def __init__(self):
        self.driver = webdriver.Edge()

    def getScreeShot(self):
        #创建屏幕截图
        #图片文件名称：./2026-02-15-173456-173456.png
        direname = datetime.datetime.now().strftime("%Y-%m-%d")
        # 判断dirname文件夹是否已经存在，若不存在则创建文件夹
        # ../images/2026-02-15-173456
        if not os.path.exists("../images/" + direname):
            os.mkdir("../images/" + direname)
        # 2026-02-15-173456.png
        # 图片路径:../images/调用方法-2026-02-15/2026-02-15-173456.png
        # 图片路径:../images/LoginSucTest-2026-02-15/2026-02-15-173456.png
        # 图片路径:../images/LoginFailTest-2026-02-15/2026-02-15-173456.png
        filename = sys._getframe().f_back.f_code.co_name + "-" + datetime.datetime.now().strftime("%Y-%m-%d-%H%M%S") + ".png"
        self.driver.save_screenshot("../images/" + direname + "/" + filename)

BlogDriver = Driver()
