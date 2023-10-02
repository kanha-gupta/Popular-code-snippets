/*           Circular Linked List
Operations ::
Insert an element x at the front of the circularly linked list
 Insert an element x after an element y in the circularly linked list
Insert an element x at the back of the circularly linked list
Remove an element from the back of the circularly linked list
Remove an element from the front of the circularly linked list
remove the element x from the circularly linked list
Search for an element x in the circularly linked list and return its pointer
Concatenate two circularly linked lists
*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;
template<class Ttype>
class SNode
{
	public:
	Ttype info;
	SNode * next;
	SNode()
	{
		next=NULL;
	}
	SNode(Ttype info, SNode *n=0)
	{
		this->info=info;
		next=n;
	}

	
};
template<class Ttype>
class Slist
{
	private:

	SNode <Ttype> * tail;
	public:
			Slist()
			{
				
				tail=0;
			}
			~Slist()
			{
				SNode <Ttype> *temp=tail->next;
				while(temp==tail)
				{
					temp=temp->next;
					delete temp;
					temp;
				}
				delete tail;
			}
			void addtohead(Ttype);
			void addtotail(Ttype);
			void deletefromhead();
			void deletefromtail();
			
			bool isempty();
			void display();
			void deletenode(int);
			void insertnode(int,Ttype);
			void search(Ttype );
			int length();
			void concat(Slist * ob1, Slist * ob2);
			
		
};
template<class Ttype>
bool Slist<Ttype>::isempty()
{
	if(tail==0)
	{
		return true;
	}
	else
	return false;
}
template<class Ttype>
void Slist<Ttype>::display()
{
	if(isempty())
	{
		cout<<"Empty list"<<endl;
	}
	else
	{
	
	SNode <Ttype> * p=tail->next;
	while(p!=tail)
	{
		cout<<(p->info)<<" ";
		p=p->next;
	}
	cout<<(tail->info)<<endl;
}
	
} 
template<class Ttype>
void Slist<Ttype>::addtohead(Ttype x) 
{
	SNode <Ttype> * p=new SNode<Ttype>(x);
	if(tail==0)
	{
		tail=p;
		tail->next=tail;
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
	}
		
}
template<class Ttype>
void Slist<Ttype>::addtotail(Ttype x)
{
	SNode <Ttype> * p=new SNode<Ttype>(x);
	if(tail==0)
	{
		tail=p;
		tail->next=tail;
		
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
		tail=p;
	}
}
template<class Ttype>
void Slist<Ttype>::deletefromhead() //only called if isempty is false
{
	if(!isempty())
	{
	Ttype x=tail->next->info;
	if(tail->next==tail)
	{
		delete tail;
		tail=0;
	}
	else
	{
		SNode <Ttype> * p=tail->next;
		tail->next=p->next;
		delete p;
					
	}
	cout<<"Deleted element:"<<x<<endl;
}
   else
   cout<<"List is empty . No deletion can occur."<<endl;
}
template<class Ttype>
void Slist<Ttype>::deletefromtail()
{
	if(!isempty())
	{
	
	Ttype x=tail->info;
	if(tail->next==tail)
	{
		delete tail;
	
		tail=0;
		
	}
	else
	{
		SNode <Ttype> * p= tail->next;
		SNode <Ttype> * head=p;
		while(p->next!=tail)
		{
			p=p->next;
		}
		delete tail;
		tail=p;
		tail->next=head; //super important
	}
	cout<<"Deleted element:"<<x<<endl;
}
  else
  {
  	cout<<"Linked list is empty. No deletion can occur."<<endl;
  }
	
}
template<class Ttype>
int Slist<Ttype>::length()
{
	int count=0;
	SNode <Ttype> * p=tail->next;
	while(p!=tail)
	{
		count++;
		p=p->next;
	}
	if(!isempty())
	{count++;}
	return count;
}
template<class Ttype>
void Slist<Ttype>::insertnode(int x,Ttype y)
{
	int n=length();
	if(x>0 && x<=n)
	{
		if(x==1)
		{
			addtohead(y);
		}
		
		else
		{
		
		SNode <Ttype>* temp=tail->next;
		for(int i=1;i<x-1;i++)
		{
			temp=temp->next;
		}
		SNode <Ttype> * p=new SNode<Ttype>(y);
		p->next=temp->next;
		temp->next=p;
	}
		
	}
	else if(x==(n+1))
	{
		if(x==1)
		{
			addtohead(y);
		}
		else
		addtotail(y);
	}
	else
	{
		cout<<"Invalid index entered."<<endl;
	}
	
}
template<class Ttype>
void Slist<Ttype>::deletenode(int x)
{
	int n=length();
	if(x>0 && x<=n)
	{
		if(x==1)
		{
			
			
			deletefromhead();
		}
		else if(x==n)
		{
			
			deletefromtail();
		}
		else
		{
			SNode <Ttype> * temp=tail->next;
			for(int i=1;i<x-1;i++)
		{
			temp=temp->next;
		}
		   SNode <Ttype> * p= temp->next;
		   temp->next=p->next;
		   cout<<"Deleted element:"<<(p->info)<<endl;
		   delete p;
			
		}
	}
	else if(n==0)
	{
		cout<<"Error::Empty list. "<<endl;
	}
	else
	{
		cout<<"Invalid index entered."<<endl;
	}
	
}
template<class Ttype>
void Slist<Ttype>::search(Ttype x)
{
	bool flag=false;
	if(isempty())
	cout<<"List is empty"<<endl;
	else
	{
	
	SNode <Ttype> * temp=tail->next;
	while(temp!=tail)
	{
		if(temp->info==x)
		{
			flag=true;
			break;
		}
		temp=temp->next;
	}
	if((tail->info)==x)
		flag=true;
	if(flag)
	{
		cout<<"Element found in list."<<endl;
		
	}
	else
	{
		cout<<"Element not found in list"<<endl;
	}}
}
template<class Ttype>
void Slist<Ttype>::concat(Slist * ob1, Slist * ob2)
{
	if((ob1->isempty()) && (ob2->isempty()))
	{
		
		tail=0;
	}
	else
	{
	if(ob1->isempty())
	{
		this->tail=ob2->tail;
		this->tail->next=ob2->tail->next;
		
	}
	else if(ob2->isempty())
	{
		this->tail=ob1->tail;
		this->tail->next=ob1->tail->next;
		
	}
	else
	{
		this->tail=ob2->tail;
		SNode <Ttype>* temp=ob1->tail->next;
		ob1->tail->next=ob2->tail->next;
		this->tail->next=temp;
		
	}
   }
   return ;
}
template<class Ttype>
void Choose(Slist <Ttype> * ob, Ttype d)
{
	
	int option=0;
	Ttype y=d;
	int x;
	bool key=true;
	while(key)
	{
		cout<<"**************************************************"<<endl;
		cout<<"To add a node from head in linked list,Press 1"<<endl;
		cout<<"To add a node from tail in linked list, Press 2"<<endl;
		cout<<"To delete node from head in linked list, Press 3"<<endl;
		cout<<"To delete node from tail in linked list, Press 4"<<endl;
		cout<<"To display the linked list, Press 5"<<endl;
		cout<<"To enter a node at ith position , Press 6"<<endl;
		cout<<"To delete a node at ith position , Press 7"<<endl;
		cout<<"To search for an element in linked list, Press 8"<<endl;
		cout<<"To end demonstration, Press 9"<<endl;
		cout<<"Your option:";
		cin>>option;
		cout<<"**************************************************"<<endl;
		switch(option)
		{
			case 1: 
			     cout<<"Enter info to be inserted in the node:";
			     cin>>y;
			      ob->addtohead(y);
			     
			      break;
			case 2: 
			     cout<<"Enter info to be inserted in the node:";
			     cin>>y;
			      ob->addtotail(y);
			     
			      break;
			case 3: 
			      ob->deletefromhead();
			      break;
			case 4: 
			    
			      ob->deletefromtail();
			      break;
			case 5: 
			    
			      cout<<"Linked list :"<<endl;
			      ob->display();
			      break;
			case 6:
				cout<<"Enter index at which the node has to be inserted:";
			     cin>>x;
			     cout<<"Enter info to be inserted in the node:";
			     
			     cin>>y;
			      ob->insertnode(x,y);
			     
			      break;
			      
			case 7:
			     
			    cout<<"Enter index at which the node has to be deleted:";
			     cin>>x;
			      ob->deletenode(x);
			      break;
			case 8:
			     cout<<"Enter element to be searched in linked list:";
				 cin>>y;
				 ob->search(y);
				
				 break;
			case 9:
			    cout<<"Demonstration complete."<<endl;
				key=false;	
				break;
				default: cout<<"Invalid option selected."<<endl; 	  	  	  	  	  	        
		}
		
		
	}
	
}

int main()
{
	cout<<"To insert integers in linked list, Press 1"<<endl;
	cout<<"To insert characters in linked list, Press 2"<<endl;
	cout<<"To insert floating point numbers in linked list, Press 3"<<endl;
	int choice;
	cin>>choice;
	bool proceed=false;
	switch(choice)
	{
		case 1:
			{Slist <int> * ob=new Slist<int>();
			int y;
			Choose(ob,y);
			ob->display();
			cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
					
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			Slist <int> * ob1=new Slist<int>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			Slist <int> * ob2=new Slist<int>();
			ob2->concat(ob,ob1);
			ob2->display();}
			}
		    break;
	    case 2:
	    	{Slist <char> * ob=new Slist<char>();
			char y;
			Choose(ob,y);
				cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			Slist <char> * ob1=new Slist<char>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			Slist <char> * ob2=new Slist<char>();
			ob2->concat(ob,ob1);
			ob2->display();}}
		    break;
		case 3:
			{
			Slist <double> * ob=new Slist<double>();
			double y;
			Choose(ob,y);
				cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			Slist <double> * ob1=new Slist<double>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			Slist <double> * ob2=new Slist<double>();
			ob2->concat(ob,ob1);
			ob2->display();}}
		    break;
		     	
		default:
		cout<<"Invalid choice."<<endl;	
		
	}
	return 0;
	
}
