'''
  Python Script to monitor disk space and send an email in case threshold reached(gmail as provider)
  
  • To send a message we are going to use smtplib library to dispatch it to SMTP server
  Go to this link and select Turn On : https://www.google.com/settings/security/lesssecureapps
  
  
'''

import subprocess
import smtplib
from email.mime.text import MIMEText
threshold = 40
partition = “/”
def report_via_email():
 msg = MIMEText(“Server running out of disk space”)

 msg[“Subject”] = “Low disk space warning”
 msg[“From”] = “your memail”
 msg[“To”] = “receiver email”
  
 with smtplib.SMTP(“smtp.gmail.com”, 587) as server:
 server.ehlo()
 server.starttls()
 server.login(“gmail_user”,”gmail_password)
 server.sendmail(“admin@example.com”,”test@gmail.com”,msg.as_string())
  
def send_mail_and_check():
 df = subprocess.Popen([“df”,”-h”], stdout=subprocess.PIPE)
 for line in df.stdout:
 splitline = line.decode().split()
 if splitline[5] == partition:
 if int(splitline[4][:-1]) > threshold:
 report_via_email()

send_mail_and_check()
