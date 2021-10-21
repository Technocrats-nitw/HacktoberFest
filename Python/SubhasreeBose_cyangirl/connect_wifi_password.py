'''
    This script can be used to connect Wi-Fi with password from the list of Wi-Fi available
    Note: "pip install pywifi" is required
'''


import subprocess
import getpass
import time
from pywifi import PyWiFi  # pip install pywifi
from pywifi import const
from pywifi import Profile


def connect_wifi_with_password(ssid, password):
    # function to connect to Wi-Fi with Password

    wifi = PyWiFi()
    iface = wifi.interfaces()[0]
    iface.disconnect()  # disconnects from the current Wi-Fi if any
    time.sleep(2)

    profile = Profile()  # adding new Profile for given Wi-Fi
    profile.ssid = ssid
    profile.auth = const.AUTH_ALG_OPEN
    profile.akm.append(const.AKM_TYPE_WPA2PSK)
    profile.cipher = const.CIPHER_TYPE_CCMP
    profile.key = password

    print("\nConnecting to WiFi....")
    iface.connect(iface.add_network_profile(profile))
    time.sleep(5)

    if iface.status() == const.IFACE_CONNECTED:
        print("\t>> Connected Successfully!")
    else:
        print("\t>> Failed to Connect!")


def list_wifi():  # list all the Wi-Fis
    wifi = PyWiFi()
    iface = wifi.interfaces()[0]
    iface.scan()
    print("\n Scanning the Wi-Fi available...")
    time.sleep(3)

    networks = iface.scan_results()
    if len(networks) < 1:
        print("Failed to Retrieve Wi-Fi data. Please check Wi-Fi mode.")
        return False

    ssids = list(set([networks[i].ssid for i in range(len(networks))]))
    for i in range(len(ssids)):
        print(f"[{i+1}] {ssids[i]}")

    return ssids


def main():  # main function
    ssids = list_wifi()
    if ssids:
        choice = input("\nPlease enter your choice number : \n\t>> ").strip()
        if not(choice.isdigit() and 1 <= int(choice) <= len(ssids)):
            print("Wrong Choice Entered. Exiting...")
            return False

        print(f"\nYou Selected: {ssids[int(choice) - 1]}")
        password = getpass.getpass()
        connect_wifi_with_password(ssids[int(choice)-1], password)


if __name__ == "__main__":
    main()
