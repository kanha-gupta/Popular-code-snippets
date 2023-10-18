#This snippet focuses on Django Forms and authentications.

# Creating a form in Django:
from django import forms

class MyForm(forms.Form):
    field1 = forms.CharField(max_length=100)
    field2 = forms.IntegerField()

# Rendering a form in a view:
from .forms import MyForm

def my_view(request):
    form = MyForm()
    return render(request, 'my_template.html', {'form': form})

# Handling form submissions:
def my_view(request):
    if request.method == 'POST':
        form = MyForm(request.POST)
        if form.is_valid():
            pass # Process the form data
    else:
        form = MyForm()
    return render(request, 'my_template.html', {'form': form})

# Using Django’s authentication system:
from django.contrib.auth import authenticate, login, logout

def login_view(request):
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            # Redirect to a success page
        else:
            pass # Return an error message
    else:
        pass # Render the login form

# Logging out a user:
def logout_view(request):
    logout(request)
    # Redirect to a logged out page

# Creating a model form:
from django import forms
from .models import MyModel

class MyModelForm(forms.ModelForm):
    class Meta:
        model = MyModel
        fields = ['field1', 'field2']

# Rendering a model form in a view:
from .forms import MyModelForm

def my_view(request):
    form = MyModelForm()
    return render(request, 'my_template.html', {'form': form})

# Saving a model form:
def my_view(request):
    if request.method == 'POST':
        form = MyModelForm(request.POST)
        if form.is_valid():
            form.save()
            # Redirect to a success page
    else:
        form = MyModelForm()
    return render(request, 'my_template.html', {'form': form})

# Using Django’s built-in authentication views:-
from django.contrib.auth.views import LoginView, LogoutView

urlpatterns = [
    path('login/', LoginView.as_view(), name='login'),
    path('logout/', LogoutView.as_view(), name='logout'),
]


