import datetime
import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from webdriver_manager.chrome import ChromeDriverManager
#编写自动化脚本，具体步骤
#1.打开浏览器----驱动管理
ChromeIns=ChromeDriverManager().install()
###创建谷歌浏览器驱动对象
driver=webdriver.Chrome(service=Service(ChromeIns))
wait = WebDriverWait(driver, 10)
#2.输入百度网址：https://www.baidu.com（网址一定要完整，不要写成www.baidu.com)
driver.get("https://www.baidu.com")
time.sleep(2)
#5.关闭浏览器
driver.quit()

