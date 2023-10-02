/*          Doubly Linked List
Operations ::
Insert an element x at the beginning of the doubly linked list
Insert an element x at position in the doubly linked list
Insert an element x at the end of the doubly linked list
Remove an element from the beginning of the doubly linked list
Remove an element from position in the doubly linked list.
Remove an element from the end of the doubly linked list
Search for an element x in the doubly linked list and return its pointer
Concatenate two doubly linked lists
*/

#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

template <class X>
class DNode
{
    public:
    X info;
    DNode * next;
    DNode * prev;
    DNode()
    {
        next=0;
        prev=0;
    }
    DNode(X info,DNode * n1=0, DNode *n2=0)
    {
        this->info=info;
        next=n1;
        prev=n2;
    }
    
};
template <class X>
class DList
{
    
    private:
    DNode <X> * head;
    DNode <X> * tail;
    public:
    DList()
    {
        head=0;
        tail=0;
    }
    void addtohead(X);
    void addtotail(X);
    void deletefromhead();
    void deletefromtail();
    void search(X);
    bool isempty();
    void display();
    int length();
    void deleteat(int );
    void insertat(int, X);
    void concat(DList * ob1, DList * ob2);
    ~DList()
    {
        DNode <X> * temp=head;
        while(temp=0)
        {
            temp=temp->next;
            delete head;
            head=temp;
        }
    }
};
template<class X>
void DList<X>::addtohead(X x)
{
    DNode <X>* p= new DNode<X>(x);
    if(head==0)
    {
        head=p;
        tail=p;
        
    }
    else 
    {
        p->next=head; //linking added object
        head->prev=p; //linking previous of second element with added object
        head=p; //creating new head
    }
}
template<class  X>
void DList<X>::addtotail(X x)
{
    DNode <X> * p=new DNode<X>(x);
    if(head==0)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
}
template<class X>
void DList<X>::deletefromhead()
{
    X x= head->info;
    if(head==tail)
    {
        delete head;
        head=0;
        tail=0;
    }
    else
    {
        DNode <X> * temp= head;
        head=head->next;
        delete temp;
        head->prev=0;
    }
    cout<<"Deleted element:"<<x<<endl;
}
template <class X>
void DList<X>::deletefromtail()
{
    X x=tail->info;
    if(head==tail)
    {
        delete tail;
        head=0;
        tail=0;
        
    }
    else
    {
      DNode <X>* temp=tail;
      tail=tail->prev;
      delete temp;
      tail->next=0;
    }
    cout<<"Deleted element:"<<x<<endl;
}
template <class X>
void DList<X>::display()
{
	if(isempty())
	{
		cout<<"Empty list"<<endl;
		
	}
	else
	{
    DNode <X> * p=head;
    while(p!=0)
    {
        cout<<(p->info)<<"  ";
        p=p->next;
    }
    cout<<endl;
   }
}
template <class X>
void DList<X>::search(X x)
{
    DNode <X> * p=head;
    bool flag=false;
    while(p!=0)
    {
        if(p->info==x)
        {
            flag=true;
            break;
            
        }
        p=p->next;
    }
    if(flag)
    cout<<"Element found "<<endl;
    else
    cout<<"Element not found"<<endl;
}
template <class X>
bool DList<X>::isempty()
{
    
    if(head==0 && tail==0)
    {
        return true;
    }
    else
    return false;
}
template <class X>
int DList<X>::length()
{
    DNode <X> * temp= head;
    int count=0;
    while(temp!=0)
    {
        count++;
        temp=temp->next;
        
    }
    return count;
}
template <class X>
void DList<X>::insertat(int x, X y)
{
    
    int n=length();
    if(x>0 && x<=n)
    {
        DNode <X> * temp=head;
        if(x!=1)
        {
        for(int i=1;i<(x-1);i++)
        {
            temp=temp->next;
        }
        DNode <X> *  p= new DNode<X>(y);
        p->next=temp->next;
        p->prev=temp;
        temp->next=p;
        temp=p->next;
        temp->prev=p;}
        else
        {
            addtohead(y);
        }
        
        
    }
    
    else if(x==(n+1)) 
    {
        if(x==1) //when list is empty
        {
            addtohead(y);
        }
        
        else //when x exceeds linked list
        {
            addtotail(y);
        }
        
    }
    else
    {
        cout<<"Invalid insertion index!"<<endl;
    }
}
template <class X>
void DList<X>::deleteat(int x)
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
			DNode <X> * temp=head;
			for(int i=1;i<x-1;i++)
		{
			temp=temp->next;
		}
		   DNode <X> * p= temp->next;
		    temp->next=p->next;
		    cout<<"Deleted element:"<<(p->info)<<endl;
		    delete p;
		    p=temp->next;
		    p->prev=temp;
	
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
template<class X>
void DList<X>::concat(DList * ob1, DList * ob2)
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
		DNode <X>* temp=ob1->tail;
		DNode<X> * temp2=ob2->head;
		temp2->prev=temp;
		temp->next=ob2->head;
		this->tail=ob2->tail;
		
	}
   }
   return ;
}
template<class X>
 void Choose(DList <X> * ob, X d)
{
	int x;
	X y=d;
	int option=0;
	bool key=true;
	
	while(key)
	{
		cout<<"************************************************"<<endl;
		cout<<"To add a node from head in linked list,Press 1"<<endl;
		cout<<"To add a node from tail in linked list, Press 2"<<endl;
		cout<<"To delete node from head in linked list, Press 3"<<endl;
		cout<<"To delete node from tail in linked list, Press 4"<<endl;
		cout<<"To display the linked list, Press 5"<<endl;
		cout<<"To enter a node at ith position , Press 6"<<endl;
		cout<<"To delete a node at ith position , Press 7"<<endl;
		cout<<"To search for an element in linked list, Press 8"<<endl;
		cout<<"To end demonstration, Press 9"<<endl;
		cout<<"Option:";
		cin>>option;
		
		cout<<"*************************************************"<<endl;
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
			     cout<<"Enter info to be inserted in the node:";
			     cin>>y;
			    cout<<"Enter index at which the node has to be inserted:";
			     cin>>x;
			      ob->insertat(x,y);
			      break;
			case 7:
			     
			    cout<<"Enter index at which the node has to be inserted:";
			     cin>>x;
			      ob->deleteat(x);
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
	bool proceed;
	switch(choice)
	{
		case 1:
			{DList <int> * ob=new DList<int>();
			int y;
			Choose(ob,y);
				cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			DList <int> * ob1=new DList<int>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			DList <int> * ob2=new DList<int>();
			ob2->concat(ob,ob1);
			ob2->display();
			}}
		    break;
	    case 2:
	    	{DList <char> * ob=new DList<char>();
			char y;
			Choose(ob,y);
				cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			DList <char> * ob1=new DList<char>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			DList <char> * ob2=new DList<char>();
			ob2->concat(ob,ob1);
			ob2->display();}}
		    break;
		case 3:
			{
			DList <double> * ob=new DList<double>();
			double y;
			Choose(ob,y);
				cout<<"Do you want to concatenate this linked list with a new linked list? If so , Press 1  else press 0"<<endl;
		    cin>>proceed;
			if(proceed)
			{
			cout<<"*************Consider linked list 2 now***********************"<<endl;
			DList <double> * ob1=new DList<double>();
			Choose(ob1,y);
			cout<<"***********Concatenating both lists***************************"<<endl;
			DList <double> * ob2=new DList<double>();
			ob2->concat(ob,ob1);
			ob2->display();}}
		    break;
		     	
		default:
		cout<<"Invalid choice."<<endl;	
		
	}
	return 0;
	
	
}
