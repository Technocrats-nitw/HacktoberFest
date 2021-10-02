from django.db import models
from django.contrib.auth.models import User
from PIL import Image
from .utils import *

# Create your models here.
class Profile(models.Model):
    user = models.OneToOneField(User,related_name='profile',on_delete=models.CASCADE)
    profile_pic = models.ImageField(upload_to='profile_pics/',blank=True)

    def __str__(self):
        return self.user.username

    def save(self, *args, **kwargs):
        super().save()
        if self.profile_pic:
            image = Image.open(self.profile_pic.path)
            image = make_square(image)
            image.save(self.profile_pic.path)