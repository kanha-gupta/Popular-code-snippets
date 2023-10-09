#This is a snippet for basic django commands that are used quite often and are mandatory in every django project.
#Before going forward with the commands below you should have the completed the following setup:
# 1. Creating a new Django project: django-admin startproject project_name
# 2. Creating a new Django app within a project: python manage.py startapp app_name
# 3. Running the development server: python manage.py runserver
# 4. Creating database tables based on models: python manage.py migrate
# 5. Creating a superuser for the admin site: python manage.py createsuperuser

# Defining a model in Django:
from django.db import models

class MyModel(models.Model):
    field1 = models.CharField(max_length=100)
    field2 = models.IntegerField()

# Creating a URL pattern in Django:
from django.urls import path
from . import views

urlpatterns = [
    path('route/', views.my_view, name='my_view'),
]

#Defining a view in Django:
from django.http import HttpResponse

def my_view(request):
    return HttpResponse("Hello, World!")

# Rendering a template in a view:
from django.shortcuts import render

def my_view(request):
    return render(request, 'my_template.html')

# Passing data from a view to a template:
def my_view(request):
    variable = "Some value"
    return render(request, 'my_template.html', {'variable': variable})

# Querying objects from the database:
from .models import MyModel #.models is the models.py file
objects = MyModel.objects.all()

# Filtering objects based on certain conditions:
objects = MyModel.objects.filter(field1='value')

#Ordering objects based on a field:
objects = MyModel.objects.order_by('field1')

#Limiting the number of objects returned:
objects = MyModel.objects.all()[:5]

# Updating an existing object:
object = MyModel.objects.get(id=1)
object.field1 = 'new value'
object.save()

#Deleting an object:
object = MyModel.objects.get(id=1)
object.delete()

#Redirecting to another URL in a view:
from django.shortcuts import redirect

def my_view(request):
    return redirect('other_view')

# Customizing the Django admin site:
from django.contrib import admin
from .models import MyModel

@admin.register(MyModel)
class MyModelAdmin(admin.ModelAdmin):
    list_display = ('field1', 'field2')
    list_filter = ('field1',)
    search_fields = ('field1',)