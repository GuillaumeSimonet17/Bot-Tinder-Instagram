from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
import time
import random
import pandas as pd
from selenium.webdriver import ActionChains
from selenium.webdriver.common.action_chains import ActionChains
import subprocess
from subprocess import call

DIV_BIO = "//div[@class='Px(16px) Py(12px) Us(t) C($c-ds-text-secondary) BreakWord Whs(pl) Typs(body-1-regular)']/div"
OPEN_PROFIL = '//span[text()="Ouvrir le profil"]'
BACK = '//span[text()="Retour"]'
LIKE = '//span[text()="Like"]'
DISLIKE = '//span[text()="Non"]'
PICS_SCROLL = "//div[@class='profileCard__slider Pos(a) Expand D(f) Ov(h) Us(n) keen-slider']"
NAME = "//h1[@class='Typs(display-1-strong) Fxs(1) Fxw(w) Pend(8px) M(0) D(i)']"
PROFIL_CARD = "//div[@class='Bgc($c-ds-background-primary) Fxg(1) Z(1) Pb(100px)']"
LATER = '//span[text()="Peut-être plus tard"]'
NO_THANKS = '//div[text()="Non merci"]'

path = '/usr/local/bin/chromedriver'
service = Service(executable_path=path)
website = 'https://tinder.com/app/recs'
options = Options()
options.add_experimental_option("debuggerAddress", "localhost:9222")
driver = webdriver.Chrome(service=service, options=options)
driver.get(website)
time.sleep(7)

x = 0
y = 0
data_concat = []
nbr_of_swipes = 200

def info():
    info_button = driver.find_element(by='xpath', value=OPEN_PROFIL)
    driver.execute_script("arguments[0].click();", info_button)

def scrap(data, name):
    name_div = driver.find_element(by='xpath', value=NAME)
    name = name_div.text

    if len(driver.find_elements(by='xpath', value=DIV_BIO)) > 0:
        bio_div = driver.find_element(by='xpath', value=DIV_BIO)
        data.append(bio_div.text)
        if "@" in bio_div.text:
            print("@ Found!")
            return 1
        elif name in bio_div.text:
            print("name Found!")
            return 1
        elif "insta" in bio_div.text:
            print("insta Found!")
            return 1
        elif "Instagram" in bio_div.text:
            print("Instagram Found!")
            return 1
        elif "instagram" in bio_div.text:
            print("instagram Found!")
            return 1
        elif "Insta" in bio_div.text:
            print("Insta Found!")
            return 1
        elif "Ig" in bio_div.text:
            print("Ig Found!")
            return 1
        elif "ig" in bio_div.text:
            print("ig Found!")
            return 1
        elif "IG" in bio_div.text:
            print("IG Found!")
            return 1
        else:
            return 0

def back():
    back_button = driver.find_element(by='xpath', value=BACK)
    driver.execute_script("arguments[0].click();", back_button)


def ft_pics_scroll():
    pics = random.randint(0, 3)
    pics_scroll = driver.find_element(by="xpath", value=PICS_SCROLL)
    for i in range(pics):
        x_random = random.uniform(1, 150)
        y_random = random.uniform(150, 200)
        actionChains = ActionChains(driver)
        actionChains.move_to_element_with_offset(pics_scroll, x_random, y_random).click().perform()
        nb = random.uniform(0.5, 3)
        time.sleep(nb)


for i in range(nbr_of_swipes):

    nb = random.uniform(0, 1)
    time.sleep(nb)

    if len(driver.find_elements(by='xpath', value=LATER)) > 0:
        later_button = driver.find_element(by='xpath', value=LATER)
        driver.execute_script("arguments[0].click();", later_button)
    if len(driver.find_elements(by='xpath', value=NO_THANKS)) > 0:
        no_thanks_button = driver.find_element(by='xpath', value=NO_THANKS)
        driver.execute_script("arguments[0].click();", no_thanks_button)

    time.sleep(2)


    # CLICK ON INFO
    if len(driver.find_elements(by='xpath', value=OPEN_PROFIL)) > 0:
        b = 1
    else:
        b = 0
    while (b == 0):
        time.sleep(2)
        if len(driver.find_elements(by='xpath', value=OPEN_PROFIL)) > 0:
            b = 1
        else:
            b = 0
    info()


    # SCRAP
    data = []
    name = ""
    if scrap(data, name) == 1:
        y = y + 1
    else:
        data = []


    # profil_card = driver.find_element(by='xpath', value=PROFIL_CARD)
    # driver.execute_script("arguments[0].scrollToView();", profil_card)


    # PICS_SCROLL - optionnel
    nb = random.uniform(0, 10)
    if nb < 4:
        ft_pics_scroll()


    # PICS_SCROLL - optionnel
    nb = random.uniform(1, 10)
    if nb < 2:
        back()


    nb = random.uniform(0, 100)
    if nb < 2:
        dislike_button = driver.find_element(by='xpath', value=DISLIKE)
        driver.execute_script("arguments[0].click();", dislike_button)
    else:
        like_button = driver.find_element(by='xpath', value=LIKE)
        driver.execute_script("arguments[0].click();", like_button)


    # DATA_CONCAT
    data_concat += data
    data = []

    df = pd.DataFrame({'data': data_concat})
    df.to_csv('tinder_data.txt', index=False)
    x = x + 1


print("en tout = " + str(x))
print("ig trouvés = " + str(y))


# COMPILER LE C
file = subprocess.run(["make"])
call(["./read", "args", "to", "read"])
