#include<iostream>
#include<iomanip>
using namespace std;
template<class T>
class Node
{
	public:
		T info;
		Node * next;
		Node * prev;
		Node()
		{
			next=0;
			prev=0;
			
		}
		Node(T i,Node * n=0, Node * p=0)
		{
			info=i;
			next=n;
			prev=p;
		}
};
template<class T>
class LinkedDequeue
{
	private:
	Node <T> * front , *rear;
	int n;
	public:
		LinkedDequeue()
		{
			front=0;
			rear=0;
			n=0;
		}
		int size(){
			return n;
		}
		bool isempty()
		{
			if(front==0 && n==0)
			return true;
			else 
			return false;
		}
		T frontE()
		{
			T f=front->info;
			return f;
		}
		T backE()
		{
			T b=rear->info;
			return b;
		}
		void print()
		{
			if(isempty())
			{
				cout<<"Empty queue"<<endl;
			}
			else
			{
				Node <T> * temp=front;
				while(temp!=0)
				{
					cout<<temp->info<<"  ";
					temp=temp->next;
				}
				cout<<endl;
			}
		}
		void insertFront(T e);
		void insertBack(T e);
		void removeFront();
		void removeBack();
	
};
template<class T>
void LinkedDequeue<T>::insertFront(T e)
{
	Node <T> * temp=new Node<T>(e);
	
	if(rear==0)
	{
		front=temp;
		rear=temp;
	
	}
	else
	{
		temp->next=front;
		front->prev=temp;
		front=temp;
		
	}
	n++;
	cout<<"Added "<<e<<" to the front"<<endl;
}
template<class T>
void LinkedDequeue<T>::insertBack(T e)
{
	Node <T> * temp=new Node<T>(e);
	
	if(rear==0)
	{
		front=temp;
		rear=temp;
	
	}
	else
	{
		temp->prev=rear;
		rear->next=temp;
		rear=temp;
		
	}
	n++;
	cout<<"Added "<<e<<" to the back"<<endl;
}
template<class T>
void LinkedDequeue<T>::removeFront()
{
	T element=front->info;
	Node <T> * temp=front;
	if(front==rear)
	{
		delete temp;
		front=0;
		rear=0;
	}
	else
	{
		front=temp->next;
		front->prev=0;
		delete temp;
		
	}
	cout<<"Deleted element:"<<element<<endl;
	n--;
}
template<class T>
void LinkedDequeue<T>::removeBack()
{
	T element=rear->info;
	Node <T> * temp=rear;
	if(front==rear)
	{
		delete temp;
		front=0;
		rear=0;
	}
	else
	{
		rear=temp->prev;
		rear->next=0;
		delete temp;
		
	}
	cout<<"Deleted element:"<<element<<endl;
	n--;
}
template<class T>
void choose(LinkedDequeue<T> * ob, T val)
{
	int option;
	bool flag=true;
	while(flag)
	{
		cout<<"1.Size of dqueue"<<endl;
		cout<<"2.Insert element in front"<<endl;
		cout<<"3.Insert element at back"<<endl;
		cout<<"4.Remove element from front"<<endl;
		cout<<"5.Remove element from back"<<endl;
		cout<<"6.Print front element"<<endl;
		cout<<"7.Print back element"<<endl;
		cout<<"8.Print dqueue"<<endl;
		cout<<"9.Exit"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				{
					cout<<"size:"<<(ob->size())<<endl;
				}
				break;
			case 2:
				{
					cout<<"Enter value to insert:";
					cin>>val;
					ob->insertFront(val);
				}
				break;
			case 3:
				{
					cout<<"Enter value to insert:";
					cin>>val;
					ob->insertBack(val);
				}
				break;
			case 4:
				{
					if(ob->isempty())
					{
						cout<<"Queue is empty"<<endl;
					}
					else
					{
						ob->removeFront();
					}
				}
				break;
			case 5:
				{
					if(ob->isempty())
					{
						cout<<"Queue is empty"<<endl;
					}
					else
					{
						ob->removeBack();
					}
			}
			break;
			case 6:
				{
					if(ob->isempty())
					{
						cout<<"Empty queue"<<endl;
					}
					else
					{
						cout<<"Front element:"<<(ob->frontE())<<endl;
					}
				}break;
			case 7:
				{
					if(ob->isempty())
					{
						cout<<"Empty queue"<<endl;
					}
					else
					{
						cout<<"Back element:"<<(ob->backE())<<endl;
					}
				}
				break;
			case 8:
				{
					ob->print();
				}
				break;
				case 9:
					{
						flag=false;
					}
					break;
					default:
						{
							cout<<"Invalid option"<<endl;
						}
						break;
		}
	}
	
}
int main()
{
	char v;
	int i;
	int opt;
	cout<<"1.To work with numbers"<<endl;
	cout<<"2.To work with characters"<<endl;
	cin>>opt;
	if(opt==1)
	{
		LinkedDequeue <int> * ob=new LinkedDequeue<int>();
		choose(ob,i);
	}
	else if(opt==2)
	{
	   LinkedDequeue <char> * ob=new LinkedDequeue<char>();
		choose(ob,v);
	}
	else
	{
		cout<<"Invalid option"<<endl;
	}
	return 0;
}
