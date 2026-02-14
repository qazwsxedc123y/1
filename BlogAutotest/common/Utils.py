import datetime
import os.path
import sys

from selenium import webdriver
from webdriver_manager.microsoft import EdgeChromiumDriverManager

class Driver:
    driver = ""
    def __init__(self):
        self.driver = webdriver.Edge()

BlogDriver = Driver()
