from django.shortcuts import render , redirect

from django.contrib.auth.models import User

from .models import Profile
import random

import http.client

from django.conf import settings
from django.contrib.auth import authenticate, login

# Create your views here.


def send_otp(mobile , otp):
    print("FUNCTION CALLED")
    
    from twilio.rest import Client

    client = Client("ACe2ef31a4d09f9846afcd486586495973", "8d2e36f767db9c4948d5ad81a03e933d")

    number="+91"+str(mobile)
    names="User"

    
    m=("Hello {} your otp is ".format(names))+otp
    client.messages.create(to=number, 
                            from_="+13092711496", 
                            body=(m))

def login_attempt(request):
    if request.method == 'POST':
        mobile = request.POST.get('mobile')
        
        user = Profile.objects.filter(mobile = mobile).first()
        
        if user is None:
            context = {'message' : 'User not found' , 'class' : 'danger' }
            return render(request,'login.html' , context)
        
        otp = str(random.randint(100000 , 999999))
        user.otp = otp
        user.save()
        send_otp(mobile , otp)
        request.session['mobile'] = mobile
        return redirect('login_otp')        
    return render(request,'login.html')


def login_otp(request):
    mobile = request.session['mobile']
    context = {'mobile':mobile}
    if request.method == 'POST':
        otp = request.POST.get('otp')
        profile = Profile.objects.filter(mobile=mobile).first()
        
        if otp == profile.otp:
            user = User.objects.get(id = profile.user.id)
            login(request , user)
            return redirect('home')
        else:
            context = {'message' : 'Wrong OTP' , 'class' : 'danger','mobile':mobile }
            return render(request,'login_otp.html' , context)
    
    return render(request,'login_otp.html' , context)
    
    

def register(request):
    if request.method == 'POST':
        email = request.POST.get('email')
        name = request.POST.get('name')
        mobile = request.POST.get('mobile')
        
        check_user = User.objects.filter(email = email).first()
        check_profile = Profile.objects.filter(mobile = mobile).first()
        
        if check_user or check_profile:
            context = {'message' : 'User already exists' , 'class' : 'danger' }
            return render(request,'register.html' , context)
            
        user = User(email = email , first_name = name)
        user.save()
        otp = str(random.randint(1000 , 9999))
        profile = Profile(user = user , mobile=mobile , otp = otp) 
        profile.save()
        send_otp(mobile, otp)
        request.session['mobile'] = mobile
        return redirect('otp')
    return render(request,'register.html')

def otp(request):
    mobile = request.session['mobile']
    context = {'mobile':mobile}
    if request.method == 'POST':
        otp = request.POST.get('otp')
        profile = Profile.objects.filter(mobile=mobile).first()
        
        if otp == profile.otp:
            return redirect('home')
        else:
            print('Wrong')
            
            context = {'message' : 'Wrong OTP' , 'class' : 'danger','mobile':mobile }
            return render(request,'otp.html' , context)
            
        
    return render(request,'otp.html' , context)