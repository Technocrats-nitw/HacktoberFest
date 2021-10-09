from django.db import models
from typing import Text
# Create your models here.
from django.utils import timezone
from django.urls import reverse
from django.db.models.deletion import DO_NOTHING

class Post(models.Model):   
    author = models.ForeignKey('auth.User',on_delete=DO_NOTHING)
    title =models.CharField(max_length=200)
    text = models.TextField()
    create_date = models.DateTimeField(default=timezone.now)
    published_date = models.DateTimeField(null=True,blank=True)
    
    def publish(self):
         self.published_date = timezone.now()
         self.save()
         
    def approve_comments(self):
        return self.comments.filter(approved_comment=True)
    
    def get_absolute_url(self):
        return reverse("post_detail",kwargs={'pk':self.pk})
    
    def __str__(self):
        return self.title
    

class Comment(models.Model):
    post=models.ForeignKey('blogging.post',related_name='comments',on_delete=DO_NOTHING)
    author=models.CharField(max_length=200)
    text = models.TextField()
    create_date = models.DateTimeField(default=timezone.now)
    approved_comment = models.BooleanField(default=False)
    
    def approve(self):
        self.approved_comment = True
        self.save()
    
    def get_absolute_url(self):
        return reverse('post_list')
    
    def __str__(self):
        return self.text