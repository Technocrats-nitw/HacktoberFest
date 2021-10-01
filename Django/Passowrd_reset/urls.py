from django.contrib import admin
from django.urls import path,include
from django.contrib.auth import views as auth_view
from webapp import views
urlpatterns = [
    path('password_reset/',views.password_reset_request,name='password_reset'),
    path('password_reset/done/', auth_view.PasswordResetDoneView.as_view(template_name='password/password_reset_done.html'), name='password_reset_done'),
    path('reset/<uidb64>/<token>/', auth_view.PasswordResetConfirmView.as_view(template_name="password/password_reset_confirm.html"), name='password_reset_confirm'),
    path('reset/done/', auth_view.PasswordResetCompleteView.as_view(template_name='password/password_reset_complete.html'), name='password_reset_complete'),
]
