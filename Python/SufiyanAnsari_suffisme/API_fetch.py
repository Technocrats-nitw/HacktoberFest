'''
	This code snippets can be used to get API response in properly indented manner.
	pip install requests if not already added
'''

import requests		# pip install requests urllib3 idna
import json

# function return json respone of the request made
def API_Response(request):
	API_url = request
	reponse = requests.get(API_url)
	return reponse.json()

# this function beautifies the json response
def Beautify_JSON(reponse):
	print(json.dumps(reponse, indent=4 ))

# driver program	
if __name__ == '__main__':
	# valid URL for fetching API - endpoint
	request = 'https://technocrats.pythonanywhere.com/api/doctor'

	reponse = API_Response(request)
	Beautify_JSON(reponse)
