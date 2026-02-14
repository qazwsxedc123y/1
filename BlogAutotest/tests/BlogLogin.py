import time
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from BlogAutotest.common.Utils import BlogDriver

class BlogLogin:
    url = ""
    driver = ""

    def __init__(self):
        self.url = "http://47.108.157.13:8090/blog_login.html"
        self.driver = BlogDriver.driver
        self.driver.get(self.url)

    # 成功登陆的测试用例
    def LoginSucTest(self):
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("zhangsan")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123456")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        # 检测是否登录成功
        # 检查方式是查看是否有昵称
        time.sleep(2)
        self.driver.find_element(By.CSS_SELECTOR, "body > div.container > div.left > div > h3")
        # 返回到登陆页面
        self.driver.back()

    def LoginFailTest(self):
        # 错误账号 正确密码
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("xixi")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123456")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        time.sleep(1)
        # 出现弹窗
        alter = self.driver.switch_to.alert
        alter.accept()

        # 正确账号 错误密码
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("zhangsan")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        time.sleep(1)
        # 出现弹窗
        alter = self.driver.switch_to.alert
        alter.accept()

        # 错误账号 错误密码
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

        self.driver.find_element(By.CSS_SELECTOR, "#username").send_keys("wasdasd")
        self.driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        time.sleep(1)
        # 出现弹窗
        alter = self.driver.switch_to.alert
        alter.accept()
        self.driver.find_element(By.CSS_SELECTOR, "#username").clear()
        self.driver.find_element(By.CSS_SELECTOR, "#password").clear()

    def LoginWriteTest(self):
        # 测试未登录状态下点击“写博客”按钮
        self.driver.find_element(By.CSS_SELECTOR, "body > div.nav > a:nth-child(5)").click()
        self.driver.find_element(By.CSS_SELECTOR, "#title").send_keys("未登录状态下")
        self.driver.find_element(By.CSS_SELECTOR, "#submit").click()
        # 实际没有发布成功
        # 发现小bug
        # 登录状态下查看以下
        # 暂时不知怎末查看
        self.driver.back()

login = BlogLogin()
login.LoginSucTest()
login.LoginFailTest()
login.LoginWriteTest()

