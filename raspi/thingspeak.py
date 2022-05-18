import requests
base_url = "https://api.thingspeak.com/update?"
hum = 100
temp = 50
key = "4SJ44N81Z0HZMVNH"
param = "&field1=" + str(hum) + "&field2=" + str(temp)
url = base_url + "api_key=" + key + param
result = requests.get(url)
print(result.text)
