// Implement Queue using Circular Array 

#include<iostream>
#include<iomanip>
using namespace std;
const int size=10;
template <class Ttype>
class cqueue
{
	private:
		Ttype a[size];
		int front;
		int rear;
		public:
			cqueue()
			{
				front =-1;
				rear=-1;
			}
			void enqueue(Ttype);
			void dequeue();
			bool isempty();
			bool isfull();
			void clear();
			void display();
	
};
template<class Ttype>
void cqueue<Ttype>::enqueue(Ttype y)
{
	if(!isfull())
	{
		if(rear==-1 || rear==(size-1))
		{
			rear=0;
			if(front==-1)
			{
				front=0;
			}
		}
		else
		{
			rear++;
		}
		a[rear]=y;
	}
	else
	{
		cout<<"Queue is full. More elements cannot be entered."<<endl;
	}
}
template < class Ttype>
void cqueue<Ttype>::dequeue()
{
	if(!isempty())
	{
		Ttype x=a[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==(size-1))
		{
			front=0;
		}
		else
		{
			front++;
		}
	  cout<<"Dequeued element:"<<x<<endl;
	}
	else
	{
		cout<<"Queue is empty. Elements can't be dequeued."<<endl;
		
	}
}
template< class Ttype>
bool cqueue<Ttype>::isempty()
{
	if(front==rear && front==-1)
	{
		return true;
	}
	else
	return false;
	
}
template<class Ttype>
bool cqueue<Ttype>::isfull()
{
	if(rear==(size-1) && front==0)
	{
		return true;
	}
	else if(rear==(front-1))
	{
		return true;
	}
	else
	return false;	
}
template<class Ttype>
void cqueue<Ttype>::display()
{
	if(!isempty())
	{
	
	if(front<=rear)
	{
		
		for(int i=front;i<=rear;i++)
		{
			cout<<"  "<<a[i];
		}
		cout<<endl;
	}
	else
	{
		for(int i=front;i<=(size-1);i++)
		{
			cout<<"  "<<a[i];
			
		}
		for(int i=0;i<=rear;i++)
		{
			cout<<"  "<<a[i];
		}
		cout<<endl;
	}
}
else
{
	cout<<"Queue is empty"<<endl;
}
}
template<class Ttype>
void cqueue<Ttype>::clear()
{
	front=-1;
	rear=-1;
}
template<class Ttype>
void Choose(cqueue <Ttype> * ob, Ttype x)
{
	bool key=true;
int option=0;
Ttype y=x;
while(key)
{
cout<<"To push elements into Queue, Press 1"<<endl;
cout<<"To pop elements from Queue, Press 2"<<endl;
cout<<"To display elements of Queue, Press 3"<<endl;
cout<<"To clear Queue, Press 4"<<endl;
cout<<"To end demonstration, Press 5"<<endl;
cin>>option;
cout<<"******************************************************"<<endl;
switch(option)
{
case 1:
{
cout<<"Enter element to be pushed into stack:";
cin>>y;
ob->enqueue(y);
ob->display();

}
break;
case 2:
{
ob->dequeue();
ob->display();
}
break;
case 3:
{
ob->display();
}
break;
case 4:
{
	ob->clear();
	ob->display();
}
break;
case 5:
{
	
key=false;
}
break;
default:
cout<<"Invalid option.";
}
cout<<"*******************************************************************"<<endl;
}
	
}
int main()
{
	int choice=0;

cout<<"To insert integers into Queue , Press 1"<<endl;
cout<<"To insert characters into Queue, Press 2"<<endl;
cout<<"To insert floating point Queue , Press 3"<<endl;
cin>>choice;
switch(choice)
{
case 1:
{cqueue <int> * ob=new cqueue <int>();
int y;
Choose(ob,y);}
break;
case 2:
{
cqueue <char> * ob= new cqueue<char>();
char y;
Choose(ob,y);
}
break;
case 3 :
{
cqueue <double> * ob= new cqueue <double>();
double y;
Choose(ob,y);
}
break;
default:
cout<<"Invalid option";
}
return 0;

}
