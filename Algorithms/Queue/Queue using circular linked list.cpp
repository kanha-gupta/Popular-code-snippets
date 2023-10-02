#include<iostream>
#include<iomanip>
using namespace std;
template<class Ttype>
class DNode 
{
	public:
		Ttype info;
		DNode * next;
	
		DNode()
		{
			next=0;
		
		}
		DNode(Ttype info, DNode * n=0)
		{
			this->info=info;
			next=n;
			
		}
};
template<class Ttype>
class QCLL
{
	private:
		
		DNode <Ttype> * rear;
		public:
			QDLL()
			{
				
				rear=0;
			}
			void enqueue(Ttype);
			void dequeue();
			void display();
			bool isempty();
			void clear();
};
template<class Ttype>
void QCLL<Ttype>::clear()
{
	
	DNode <Ttype> * temp=rear->next;
	while(temp!=rear)
	{
		delete temp;
		temp=temp->next;
		
		
	}
	delete rear;
	
	rear=0; //super important
	
}
template<class Ttype>
bool QCLL<Ttype>::isempty()
{
	if(rear==0)
	{return true;}
	else
	{return false;}
}
template<class Ttype>
void QCLL<Ttype>::enqueue(Ttype x)
{
	DNode <Ttype> * p=new DNode<Ttype>(x);
	if(isempty())
	{
		
		rear=p;	
		rear->next=rear;
	}
	else
	{
		p->next=rear->next;
		rear->next=p;
		rear=p;
	}	
}
template<class Ttype>
void QCLL<Ttype>::dequeue()
{
	if(isempty())
	{
		cout<<"No item can be dequeued from an already empty queue."<<endl;
	}
	else
	{
		DNode <Ttype>* temp=rear->next;
		Ttype x=temp->info;
		if(rear->next==rear)
		{
			delete temp;
			rear=0;
		}
		else
		{rear->next=rear->next->next;

		delete temp;
		}
		cout<<"Dequeued element:"<<x<<endl;
	}
}
template<class Ttype>
void QCLL<Ttype>::display()
{
	if(isempty())
	cout<<"Empty Queue"<<endl;
	else
	{
		cout<<"Queue:";
		DNode <Ttype> * temp=rear->next;
		while(temp!=rear)
		{
			cout<<"  "<<(temp->info);
			temp=temp->next;
		}
		cout<<"  "<<(rear->info)<<endl;
	}
}
template<class Ttype>
void Choose(QCLL <Ttype> * ob, Ttype x)
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
{QCLL <int> * ob=new QCLL <int>();
int y;
Choose(ob,y);}
break;
case 2:
{
QCLL <char> * ob= new QCLL<char>();
char y;
Choose(ob,y);
}
break;
case 3 :
{
QCLL <double> * ob= new QCLL <double>();
double y;
Choose(ob,y);
}
break;
default:
cout<<"Invalid option";
}
return 0;

}
