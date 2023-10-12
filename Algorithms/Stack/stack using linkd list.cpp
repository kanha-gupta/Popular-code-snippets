// implement stack using linked list

#include<iostream>
using namespace std ;

class Snode
{
	public:
		int info;
		Snode *next;
		Snode()
		{
			next=0;
		}
		Snode(int x, Snode *n=0)
		{
			info = x;
			next = n;
		}
};

class StackLL
{
	private:
		Snode *top;
		Snode *tail;
	public:
		StackLL()
		{
			top=0;
			tail=0;
		}
	int isempty();
	void push(int x);
	int pop();
	void display();
};

int StackLL::isempty()
{
	if(top==0)
	{
		return 1;
	}
	else
	{
		return 0 ;
	}
}

void StackLL :: push(int x)
{
	Snode *p=new Snode(x);
	if(top==0)
	{
		top=tail=p;
	}
	else
	{
		p->next=top;
		top=p;
	}
}

int StackLL::pop()
{
	int x= top->info;
	if(top==tail)
	{
		delete top;
		top=tail=0;
	}
	else
	{
		Snode *p=top;
		top=top->next;
		delete p ;
	}
	return x;
}

void StackLL::display()
{
	Snode *temp=top;
	while(temp!=0)
	{
		cout<<temp->info;
		temp=temp->next;
	}
}


int main()
{   char ans;
	StackLL *s1= new StackLL;
	cout<<"Implementation of Stack using Single Linked List"<<endl;
	cout<<"Select any option from below:"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"3.display"<<endl;
	int choice;
	do{
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				int elem;
				cout<<"Enter an elment you want to push:";
				cin>>elem;
				s1->push(elem);
				cout<<"Your elment has successfully pushed into the stack";
				break;
			}
		case 2:
			{
				s1->pop();
				cout<<"Your element has successfully poped from the stack"<<endl;
				s1->display();
				break;
			}
		case 3:
			{
				cout<<"Displaying the Entire stack:"<<endl;
				s1->display();
				break;
			}
	}
	cout<<endl;
	
	cout<<"Do you want to continue yes/no :";
    cin>>ans;
		}while (ans!='n');
}
