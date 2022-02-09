from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
import os, time
import shutil

# LTE Italy credentials
username = "davide.parpinello"
password = "rfKQApNPDAC8"

chrome_options = Options()
chrome_options.add_argument("download.default_directory=" + os.getcwd())
chrome_options.add_argument("--headless")



# initialize the Chrome driver
driver = webdriver.Chrome(options=chrome_options)

# head to lte italy login page
driver.get("https://lteitaly.it/it/login.php")
driver.find_element(By.CLASS_NAME, 'ucp-cookiebanner-button').click()
# find username/email field and send the username itself to the input field
driver.find_element(By.ID, "username").send_keys(username)
# find password input field and insert password as well
driver.find_element(By.ID, "passwort").send_keys(password)
# click login button
driver.find_element(By.CSS_SELECTOR, 'form button').click()

element = WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CLASS_NAME, "database")))

driver.get("https://lteitaly.it/it/export.php?provider=tim&type=csv")
time.sleep(5)

driver.close()

shutil.move("tim_20211125_lteitaly.csv", "./utils/tim_20211125_lteitaly.csv")
