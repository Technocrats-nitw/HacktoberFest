from selenium import webdriver #import selenium web driver
from selenium.webdriver.common.action_chains import ActionChains #actions chains are used to perform actions by the driver
from selenium.webdriver.common.keys import Keys
import time
import random

date,month,year = input('Enter date (DD/MM/YYYY) : ').split('/')    #first we take the date of travel from the use
print(date,month,year)

oneway = False if input('Do you want a Return flight too? (Y/N): ').lower() == 'y' else True

if not oneway:
    date_r,month_r,year_r = input('Enter return date (DD/MM/YYYY) : ').split('/')

driver=webdriver.Firefox(executable_path="C://selenium/geckodriver.exe") #attaching geckodriver to automate through firefox
driver.get('https://www.expedia.co.in/Flights')
time.sleep(5)

#this element here returns the field of "FROM" city in the travel website
element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[1]/div/div[1]/div/div/div/div/div[1]/button')
action = ActionChains(driver).click(on_element = element).perform()
time.sleep(2)
element = driver.find_element_by_xpath('//*[@id="location-field-leg1-origin"]')
element.send_keys('California')
element.send_keys(Keys.RETURN)


time.sleep(1)
#this element here returns the field of "TO" city in the travel website
element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[1]/div/div[2]/div/div/div/div/div[1]/button')
action = ActionChains(driver).click(on_element = element).perform()
time.sleep(2)
element = driver.find_element_by_xpath('//*[@id="location-field-leg1-destination"]')
element.send_keys('Miami')
element.send_keys(Keys.RETURN)


time.sleep(2)

months = {	
    '01':'January',
    '02':'February',
    '03':'March',
    '04':'April',
    '05':'May',
    '06':'June',
    '07':'July',
    '08':'August',
    '09':'September',
    '10':'October',
    '11':'November',
    '12':'December'
}

short_month = {
    'January'  :'Jan',
    'February' :'Feb',
    'March'    :'Mar',
    'April'    :'Apr',
    'May'      :'May',
    'June'     :'Jun',
    'July'     :'Jul',
    'August'   :'Aug',
    'September':'Sep',
    'October'  :'Oct',
    'November' :'Nov',
    'December' :'Dec'
}

required_month = months[month]+' '+year

#in the website it is required to change the date in these formats only.

if not oneway:
    required_month_return = months[month_r]+' '+year_r

time.sleep(2)

if oneway: #this is for oneway booking

    element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/ul/div[1]/li[2]/a')
    action = ActionChains(driver).click(on_element = element).perform() #this is for oneway

    element = driver.find_element_by_xpath('//*[@id="d1-btn"]')
    action = ActionChains(driver).click(on_element = element).perform()

    element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[2]/div[2]/div[2]/div/div/div/div/div[2]/div/div[2]/div[2]/div[1]/h2')
    month_button = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[2]/div[2]/div[2]/div/div/div/div/div[2]/div/div[2]/div[1]/button[2]')

    while element.text != required_month:
        month_button.click()
        element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[2]/div[2]/div[2]/div/div/div/div/div[2]/div/div[2]/div[2]/div[1]/h2')
        time.sleep(2)

    elements = driver.find_elements_by_xpath("//table[@class='uitk-date-picker-weeks']//tbody//tr")
    for row in elements:
        list = row.find_elements_by_xpath("./td/button")
        for button in list:
            if button.get_attribute('aria-label') == date+' '+short_month[months[month]]+' '+year:
                button.click()
                break   

    element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[2]/div[2]/div[2]/div/div/div/div/div[2]/div/div[3]/button')
    action = ActionChains(driver).click(on_element = element).perform()  #this is to click date

else: #this is for 2 way bookinh

    element = driver.find_element_by_xpath('//*[@id="d1-btn"]')
    element.click() #for start date

    element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[2]/div/div/div[1]/div/div[2]/div/div[2]/div[2]/div[1]/h2')
    month_button = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[2]/div/div/div[1]/div/div[2]/div/div[2]/div[1]/button[2]')

    while element.text != required_month:
        month_button.click()
        element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[2]/div/div/div[1]/div/div[2]/div/div[2]/div[2]/div[1]/h2')
        time.sleep(2)

    elements = driver.find_elements_by_xpath("//table[@class='uitk-date-picker-weeks']//tbody//tr")
    for row in elements:
        list = row.find_elements_by_xpath("./td/button")
        for button in list:
            if button.get_attribute('aria-label') == date+' '+short_month[months[month]]+' '+year:
                button.click()
                break   
            if button.get_attribute('aria-label') == date_r+' '+short_month[months[month_r]]+' '+year_r:
                button.click()
                break

    element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[2]/div[1]/div[1]/div[2]/div[2]/div/div/div[1]/div/div[2]/div/div[3]/button')
    element.click()  #this is to click "done" in date




element = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div/div[1]/div[1]/div/div/div/form/div[3]/div/button')
action = ActionChains(driver).click(on_element = element).perform() #this is for search button

time.sleep(10)

#driver.close()
