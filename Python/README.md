## PYTHON

Team Technocrats welcome you to contribute your snippets and working codes with us.
Read the Contributing Guidelines and get yourself added to the list of contributors.

Quick Recap for contributing.

- Make a new folder with name `YourName_username` (For example: SufiyanAnsari_suffisme)
- If already existing then simply head over it, don't create it everytime
- Then add your file there with the proper name showing the basic functionality of that code you are sharing, For example: `API_fetch.py` clearly shows a py file for fetching data via API

**IMPORTANT** : Add a README.md file explaining about your python code in brief or detail OR make your python code documented i.e. at the top add a block comment telling about your program and add comments wherever necessary

An example of proper code:

```python
'''
	This code snippets can be used to get API response in properly indented manner.
	pip install requests if not already added
'''

import requests		# pip install requests urllib3 idna
import json

# function return json respone of the request made
def API_Response(request_url):
	reponse = requests.get(request_url)
	return reponse.json()

# this function beautifies the json response
def Beautify_JSON(reponse):
	print(json.dumps(reponse, indent=4 ))

# driver program	
if __name__ == '__main__':
	# valid URL for fetching API - endpoint
	request_url = 'https://technocrats.pythonanywhere.com/api/doctor'

	reponse = API_Response(request_url)
	Beautify_JSON(reponse)

```
