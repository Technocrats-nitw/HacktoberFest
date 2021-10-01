from django.contrib.auth import logout as django_logout
from rest_framework.permissions import IsAuthenticated
from django.core.exceptions import ObjectDoesNotExist
from rest_framework import generics
from rest_framework.generics import *
from rest_framework import status
from rest_framework import response
from rest_framework.views import APIView
from django.conf import settings

class LogoutView(APIView):
    permission_classes = (IsAuthenticated,)

    def logout(self, request):
        try:
            request.user.auth_token.delete()
        except (AttributeError, ObjectDoesNotExist):
            pass
        if getattr(settings, 'REST_SESSION_LOGIN', True):
            django_logout(request)

        response = Response({"detail": ("Successfully logged out.")},
                            status=status.HTTP_200_OK)
        return response
    
    def post(self, request, *args, **kwargs):
        return self.logout(request)
