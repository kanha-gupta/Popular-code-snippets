/*            Singly Linked List
Operations ::
Insert an element x at the beginning of the singly linked list
Insert an element x at position in the singly linked list
Remove an element from the beginning of the singly linked list
Remove an element from position in the singly linked list.
Search for an element x in the singly linked list and return its pointer
Concatenate two singly linked lists
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
	SNode <Ttype> * head;
	SNode <Ttype> * tail;
	public:
			Slist()
			{
				head=0;
				tail=0;
			}
			~Slist()
			{
				SNode <Ttype> *temp=head;
				while(temp!=0)
				{
					temp=temp->next;
					delete head;
					head=temp;
				}
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
	if(head==0 && tail==0)
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
	
	SNode <Ttype> * p=head;
	while(p!=0)
	{
		cout<<"  "<<(p->info);
		p=p->next;
	}
}
	
} 
template<class Ttype>
void Slist<Ttype>::addtohead(Ttype x) 
{
	SNode <Ttype> * p=new SNode<Ttype>(x);
	if(head==0)
	{
		head=p;
		tail=p;
	}
	else
	{
		p->next=head;
		head=p;
	}
		
}
template<class Ttype>
void Slist<Ttype>::addtotail(Ttype x)
{
	SNode <Ttype> * p=new SNode<Ttype>(x);
	if(tail==0)
	{
		head=p;
		tail=p;
		
	}
	else
	{
		tail->next=p;
		tail=p;
	}
}
template<class Ttype>
void Slist<Ttype>::deletefromhead() //only called if isempty is false
{
	if(!isempty())
	{
	Ttype x=head->info;
	if(head==tail)
	{
		delete head;
		head=0;
		tail=0;
	}
	else
	{
		SNode <Ttype> * p=head;
		head=p->next;
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
	if(head==tail)
	{
		delete tail;
		head=0;
		tail=0;
		
	}
	else
	{
		SNode <Ttype> * p= head;
		while(p->next!=tail)
		{
			p=p->next;
		}
		delete tail;
		tail=p;
		tail->next=0; //super important
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
	SNode <Ttype> * p=head;
	while(p!=0)
	{
		count++;
		p=p->next;
	}
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
		
		SNode <Ttype>* temp=head;
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
			SNode <Ttype> * temp=head;
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
	SNode <Ttype> * temp=head;
	while(temp!=0)
	{
		if(temp->info)
		{
			flag=true;
			break;
		}
		temp=temp->next;
	}
	if(flag)
	{
		cout<<"Element found in list."<<endl;
		
	}
	else
	{
		cout<<"Element not found in list"<<endl;
	}
}
template<class Ttype>
void Slist<Ttype>::concat(Slist * ob1, Slist * ob2)
{
	if((ob1->isempty()) && (ob2->isempty()))
	{
		head=0;
		tail=0;
	}
	else
	{
	if(ob1->isempty())
	{
		this->head=ob2->head;
		this->tail=ob2->tail;
	}
	else if(ob2->isempty())
	{
		this->head=ob1->head;
		this->tail=ob1->tail;
		
	}
	else
	{
		this->head=ob1->head;
		SNode <Ttype>* temp=ob1->tail;
		temp->next=ob2->head;
		this->tail=ob2->tail;
		
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
			Choose(ob,y);	cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			Slist <int> * ob1=new Slist<int>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			Slist <int> * ob2=new Slist<int>();
			ob2->concat(ob,ob1);
			ob2->display();
			}}
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
