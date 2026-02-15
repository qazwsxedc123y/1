from selenium.webdriver.common.by import By

from BlogLogin import BlogLogin
from BlogList import BlogList
from BlogDetail import BlogDeail
from BlogEdit import BlogEdit


from BlogAutotest.common.Utils import BlogDriver

if __name__ == "__main__":
    BlogLogin().LoginWriteTest()
    BlogLogin().LoginFailTest()
    BlogLogin().LoginSucTest()
    # 登陆成功之后就可以调用博客首页测试首页的用例（登陆状态）
    BlogList().ListTestByLogin()
    # 未登录状态测试博客列表页
    BlogList().ListTestByNo_Login()

    # 要在再次登录
    BlogLogin().LoginSucTest()
    # 登录状态下检测博客详情页
    BlogDeail().DetailTestByLogin()

    # 测试博客编辑页
    BlogEdit().EditSucTestByLogin()
    BlogEdit().EditFailTestByLogin()
    BlogEdit().EditTestByLogin()

    #指定浏览器的退出
    BlogDriver.driver.quit()