import time
import datetime
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
#驱动程序管理的⾃动化
#创建驱动对象
#1.打开浏览器
driver =webdriver.Edge()
# driver = webdriver.Chrome(service=ChromeService(ChromeDriverManager().install()))
#2.输⼊百度⽹址:https://www.baidu.com
driver.get("https://www.baidu.com")
# #3、找到输⼊框并输⼊“迪丽热巴”
# driver.find_element(By.CSS_SELECTOR,"#kw").send_keys("迪丽热巴")
# #4、找到“百度⼀下”按钮并点击
# driver.find_element(By.CSS_SELECTOR,"#su").click()
# text = driver.find_element(By.XPATH, "chat-submit-button").text
# print(text)
#5、关闭浏览器

# url = driver.current_url

# driver.maximize_window()
# driver.minimize_window()
# driver.fullscreen()
# driver.save_screenshot("baidu.png")
# filename = "auto_test" + datetime.datetime.now().strftime("%Y%m%d-%H%M%S") + ".png"
# driver.save_screenshot('../image' + filename)
# driver.close()

alert = driver.switch_to.alert
alert.accept()
alert.dismiss()
alert.send_keys("<PASSWORD>")
alert.accept()
driver.quit()
