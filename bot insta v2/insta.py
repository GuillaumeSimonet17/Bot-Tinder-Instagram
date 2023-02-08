from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
import time
import random
import sys

FOLLOW_BUTTON = "//div[text()='Suivre']"
CONTACTER = "//div[text()='Contacter']"
TEXT_AREA = "//textarea[@placeholder='Votre message…']"
SEND_BUTTON = "//button[text()='Envoyer']"
PROFIL_NON_EXISTANT = "//h2[text()='Cette page n’est malheureusement pas disponible.']"

path = '/usr/local/bin/chromedriver'
service = Service(executable_path=path)
website = 'https://www.instagram.com/direct/inbox/'

options = Options()
options.add_experimental_option("debuggerAddress", "localhost:9222")

driver = webdriver.Chrome(service=service, options=options)
driver.get(website)

fd_in = open("new_tinder_data.txt", "r")
fd_out = open("await_to_accept.txt", "a")
Lines = fd_in.readlines()
count = 0 

for line in Lines:

    count += 1
    profil = line
    page_profil = 'https://www.instagram.com/{}/'.format(profil)
    driver.get(page_profil)

    time.sleep(5)

    if len(driver.find_elements(by='xpath', value=PROFIL_NON_EXISTANT)) == 0:
        if len(driver.find_elements(by="xpath", value=CONTACTER)) > 0:
            contact_button = driver.find_element(by="xpath", value=CONTACTER)
            driver.execute_script("arguments[0].click();", contact_button)
            time.sleep(6)
            kill = -1
            while len(driver.find_elements(by="xpath", value=TEXT_AREA)) == 0:
                if kill == 1:
                    sys.exit()
                print("waiting...")
                time.sleep(600)
                kill = kill + 1
            if len(driver.find_elements(by="xpath", value=TEXT_AREA)) > 0:
                input_1 = driver.find_element(by="xpath", value=TEXT_AREA)
                input_1.send_keys("Tu sais ce qui est intéressant avec ta photo de profil ?")
                send_button = driver.find_element(by="xpath", value=SEND_BUTTON)
                driver.execute_script('arguments[0].click();', send_button)
        else:
            time.sleep(2)
            follow_button = driver.find_element(by='xpath', value=FOLLOW_BUTTON)
            time.sleep(2)
            driver.execute_script("arguments[0].click();", follow_button)
            time.sleep(2)
            if len(driver.find_elements(by="xpath", value=CONTACTER)) > 0:
                contact_button = driver.find_element(by="xpath", value=CONTACTER)
                driver.execute_script("arguments[0].click();", contact_button)
                time.sleep(6)
                if len(driver.find_elements(by="xpath", value=TEXT_AREA)) > 0:
                    input_1 = driver.find_element(by="xpath", value=TEXT_AREA)
                    input_1.send_keys("Tu sais ce qui est intéressant avec ta photo de profil ?")
                    send_button = driver.find_element(by="xpath", value=SEND_BUTTON)
                    driver.execute_script('arguments[0].click();', send_button)
            else:
                fd_out.write(profil)
        
    
    nb = random.uniform(1, 4)
    time.sleep(nb)

fd_out.close()
fd_in.close()
