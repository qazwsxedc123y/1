import time

from selenium.webdriver.chrome import webdriver
from selenium.webdriver.common.by import By

from BlogAutotest.common.Utils import BlogDriver

#测试博客详情页
class BlogDeail:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://47.108.157.13:8090/blog_detail.html?blogId=58519"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)
    #登陆状态下博客详情页的测试
    def DetailTestByLogin(self):
        self.driver.get(self.url)
        time.sleep(2)

        #检查标题
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.title")
        #检查时间
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.date")
        #检查内容
        self.driver.find_element(By.CSS_SELECTOR,"#h2-u5728u8FD9u91CCu5199u4E0Bu4E00u7BC7u535Au5BA2")
        # 编辑删除按钮
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.operating > button:nth-child(1)")
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.right > div > div.operating > button:nth-child(2)")
        #屏幕截图
        BlogDriver.getScreeShot()

    def DetailTestByNO_Login(self):
        self.driver.find_element(By.CSS_SELECTOR, "#username").click()