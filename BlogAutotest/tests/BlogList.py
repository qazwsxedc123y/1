import time

from selenium.webdriver.chrome import webdriver
from selenium.webdriver.common.by import By

from BlogAutotest.common.Utils import BlogDriver

class BlogList:
    url = ""
    driver = ""
    def __init__(self):
        self.url = "http://47.108.157.13:8090/blog_list.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)
    #测试首页(登录情况下）
    def ListTestByLogin(self):
        # 检测个人信息
        # 检测头像
        time.sleep(4)
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > img").click()
        # 检测昵称
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > h3").click()
        # 检测GitHub地址
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > a").click()
        # 点击元素，如果成功，则表示可以
        time.sleep(2)
        self.driver.find_element(By.CSS_SELECTOR, "#git-readme > div > div.file_title.d-flex-between.file_readme_title > div.left-box > div").click()
        self.driver.back()
        # 检测文章、分类
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > div:nth-child(4) > span:nth-child(1)").click()
        self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > div:nth-child(4) > span:nth-child(2)").click()
        e1 = self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > div:nth-child(5) > span:nth-child(1)")
        e1.click()
        num1 = e1.text
        e2 = self.driver.find_element(By.CSS_SELECTOR,"body > div.container > div.left > div > div:nth-child(5) > span:nth-child(2)")
        e2.click()
        num2 = e2.text
        assert int(num1) == 2 and int(num2) == 1

        # 测试博客列表
        # 检测博客标题
        time.sleep(5)
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.right > div:nth-child(1) > div.title")
        # 检测博客发表时间
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.right > div:nth-child(1) > div.date")
        # 检测博客内容
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.right > div:nth-child(1) > div.desc")
        # 检测博客“查看全文“按钮
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.right > div:nth-child(1) > a").click()
        # 看受否有编辑按钮
        time.sleep(2)
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.right > div > div.operating > button:nth-child(1)").click()
        self.driver.back()
        self.driver.back()

        # 检查上导航
        # 检查主页按钮
        time.sleep(2)
        self.driver.find_element(By.CSS_SELECTOR,"body > div.nav > a:nth-child(4)")
        # 检查写博客按钮
        self.driver.find_element(By.CSS_SELECTOR,"body > div.nav > a:nth-child(5)")
        # 检查注销按钮
        self.driver.find_element(By.CSS_SELECTOR,"body > div.nav > a:nth-child(6)").click()
        self.driver.find_element(By.CSS_SELECTOR,"#username").click()

    # 测试首页(未登录情况下）
    # 点击注销后，在直接看受否可以进入
    # 这个测试在其登录状态下测试之后
    def ListTestByNo_Login(self):
        self.driver.get(self.url)
        time.sleep(2)
        self.driver.find_element(By.CSS_SELECTOR, "#username").click()




