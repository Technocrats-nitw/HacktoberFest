import requests		# pip install requests urllib3 idna
import json

def API_Response(request):
	API_url = request
	reponse = requests.get(API_url)
	return reponse.json()

def Beautify_JSON(reponse):
	print(json.dumps(reponse, indent=4 ))

if __name__ == '__main__':
	# valid URL for fetching API - endpoint
	request = 'https://technocrats.pythonanywhere.com/api/doctor'

	reponse = API_Response(request)
	Beautify_JSON(reponse)
