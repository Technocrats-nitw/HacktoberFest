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
