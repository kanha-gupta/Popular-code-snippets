/*
       Binary Search Tree implementation
Operations ::

Insert an element x
Delete an element x
Search for an element x in the BST and change its value to y and then place the node with value y at its appropriate position in the BST
Display the elements of the BST in preorder, inorder, and postorder traversal
Display the elements of the BST in level-by-level traversal
Display the height of the BST
*/

#include<iostream>
#include<iomanip>
using namespace std;
template<class T>
class SNode
{
	public:
		T info;
		SNode * left;
		SNode * right;
		
		SNode()
		{
			left=0;
			right=0;
			
		}
		SNode(T i,SNode * l=0,SNode * r=0)
		{
			info=i;
			left=l;
			right=r;
			
			
		}
};
template<class T>
class bst
{
	 public:
		SNode <T> * root;
		
			bst()
			{
				root=0;
			}
			bool isempty()
			{
				if(root==NULL)
				return true;
				else
				return false;
			}
			void interinsertNode(SNode <T> * newNode,SNode <T> * rnode);
			void finalinsertNode(T info);
			SNode <T> * deleteNode(SNode <T> *,T info);
			SNode <T> * minValueNode(SNode<T>* );
			
			SNode <T> * search(T info);
			void depthfirst();
			void preorder(SNode <T> * p);
			void postorder(SNode <T> * p);
			void inorder(SNode <T> * p);
			int height(SNode <T> * p);
			void printheight();
			void printGivenLevel(SNode <T> * p,int level);
			void breadthfirst();
			void swapNodes(T x,T y);
			
			
};
template<class T>
void bst<T>::interinsertNode(SNode <T> * newNode,SNode <T> * tree)
{
	if(root==0)
	{
		root=newNode;
		cout<<"Root Node Added "<<endl;
	}
	else
	{
	if((newNode->info)==(tree->info))
	{
			cout<<"Element already exists"<<endl;
	}
	else if((tree->info)>(newNode->info))
	{
		if(tree->left!=NULL)
		{
			
			interinsertNode(newNode,tree->left);
		}
		else
		{
			tree->left=newNode;
		
			cout<<"Node added to the left"<<endl;
		}
	}
	else
	{
		if(tree->right!=NULL)
		{
			interinsertNode(newNode,tree->right);
		}
		else
		{
			tree->right=newNode;
			
			cout<<"Node added to the right"<<endl;
		}
	}}
	
}
template<class T>
void bst<T>::finalinsertNode(T info)
{
	SNode <T>* newNode=new SNode<T>(info);
	interinsertNode(newNode,root);
}
template<class T>
SNode <T> * bst<T>::search(T x)
{
	SNode <T> * temp=root;
	while(temp!=0)
	{
		if(temp->info==x)
		{
			return temp;
		}
		else if((temp->info)>x)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	return NULL;
	
}
template<class T>
SNode <T> * bst<T>::minValueNode(SNode <T> * node)
{
	SNode <T>* current = node;
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
}
template<class T>
SNode <T> * bst<T>::deleteNode(SNode <T> * r, T val)
{
	if(r==NULL)
	{
		return NULL;
	}
	else if(val < r->info)
	{
		r->left=deleteNode(r->left,val);
	}
	else if (val > r -> info) 
	{
      r -> right = deleteNode(r -> right, val);
    }
    else
    {
    	 if (r -> left == NULL) 
		 {
        SNode <T> * temp = r -> right;
        delete r;
        return temp;}
		else if (r -> right == NULL) 
		{
        SNode <T>* temp = r -> left;
        delete r;
        return temp;
      } else {
        
        SNode <T> * temp = minValueNode(r -> right);
        r ->info = temp -> info;
       
        r -> right = deleteNode(r -> right, temp ->info);
      }
    }
    return r;
	
}

template<class T>
void bst<T>::preorder(SNode <T> * p)
{
	if(p!=0)
	{
		cout<<p->info<<"  ";
		preorder(p->left);
		preorder(p->right);
	}
}
template<class T>
void bst<T>::inorder(SNode <T> * p)
{
	if(p!=0)
	{
		inorder(p->left);
		cout<<(p->info)<<"  ";
		inorder(p->right);
	}
}
template<class T>
void bst<T>::postorder(SNode <T> * p)
{
	if(p!=0)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<(p->info)<<"  ";
	}
}
template<class T>
void bst<T>::depthfirst()
{
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	else
	{
		cout<<"Pre-order Traversal : ";
		preorder(root);cout<<endl;
		cout<<"In-order Traversal : ";
		inorder(root);cout<<endl;
		cout<<"Post-order Traversal : ";
		postorder(root);cout<<endl; 
		
	}
}
template<class T>
int bst<T>::height(SNode <T> * p)
{
	if(p==0)
	return 0;
	else
	{
	  int leftheight=height(p->left);
	  int rightheight=height(p->right);
	  if(leftheight>rightheight)
	  {
	  	return (leftheight+1);
	  }
	  else
	  return (rightheight+1);
		
	}	
}
template<class T>
void bst<T>::printheight()
{
	if(root==0)
	{
		cout<<"BST is empty"<<endl;
	}
	else
	{
	cout<<"Height :"<<(height(root))<<endl;
}
}
template<class T>
void bst<T>::printGivenLevel(SNode <T> * p,int level)
{
	if(p==0)
	{
		return ;
	}
	else if(level==1)
	{
		cout<<(p->info)<<"  ";
	}
	else
	{
		printGivenLevel(p->left,level-1);
		printGivenLevel(p->right,level-1);
	}
	
}
template<class T>
void bst<T>::breadthfirst()
{
	int h=height(root);
	if(h==0)
	{cout<<"Empty BST"<<endl;}
    else
	{
	SNode <T>* p=root;
	cout<<"Level-order traversal : ";
	for(int i=1;i<=h;i++)
	{
		printGivenLevel(p,i);
	}
	cout<<endl;}

	
}
template<class T>
void bst<T>::swapNodes(T x,T y)
{
	if(!isempty())
	{
		if(search(x)==0)
		{
			cout<<"Node "<<(x)<<" not found "<<endl;
		}
		else
		{
		root=deleteNode(root,x);
		finalinsertNode(y);
	    }
	}
	else
	{
		cout<<"Error:BST is empty. Operation can't be executed"<<endl;
	}
}
void func1()
{
	bool flag=true;
	int x=0,y=0;
	int option=0;
	bst <int> * tree=new bst<int>();
	while(flag)
	{
		cout<<"1.Insert an element x"<<endl;
		cout<<"2.Delete an element x"<<endl;
		cout<<"3.Search for an element x in BST and replace it with y and place y appropriately in BST"<<endl;
		cout<<"4.Display elements of BST in preorder,inorder and postorder traversal"<<endl;
		cout<<"5.Display elements of BST in level-by-level traversal"<<endl;
		cout<<"6.Display height of BST"<<endl;
		cout<<"7.End operation"<<endl;
		cout<<"User's choice:";
		cin>>option;
		cout<<"************************************************************************************"<<endl;
		switch(option)
		{
			case 1:
				{
					cout<<"Enter key value to be inserted :";
					cin>>x;
					tree->finalinsertNode(x);
					break;
				}
			case 2:
				{
					if(!(tree->isempty()))
					{
					cout<<"Enter key value to be deleted : ";
					cin>>x;
					if(tree->search(x))
					{
					tree->root=tree->deleteNode(tree->root,x);
					
					}
					else
					{
						cout<<"element not found"<<endl;
					}
				}
					else
					{
						cout<<"BST is empty. "<<endl;
					}
					break;
				}
			case 3:
				{
					if(!(tree->isempty()))
					{
					cout<<"Enter key value to be searched :";
					cin>>x;
					cout<<"Enter key value to replace with :";
					cin>>y;
					tree->swapNodes(x,y);
				}
				else
				{
					cout<<"BST is empty. Operation can't be performed"<<endl;
				}
					break;
					
				}
			case 4:
				{
					tree->depthfirst();
					break;
				}
			case 5:
				{
					tree->breadthfirst();
					break;
				}
			case 6:
				{
				tree->printheight();
					break;
				}
			case 7:
				{
					cout<<"End of operation"<<endl;
					flag=false;
					break;
				}
			default:
				{
					cout<<"Invalid option"<<endl;
				}
				
		}
		cout<<"******************************************************************************"<<endl;
		
		
	}
}
void func2()
{
		bool flag=true;
	char x,y;
	int option=0;
	bst <char>* tree=new bst<char>();
	while(flag)
	{
		cout<<"1.Insert an element x"<<endl;
		cout<<"2.Delete an element x"<<endl;
		cout<<"3.Search for an element x in BST and replace it with y and place y appropriately in BST"<<endl;
		cout<<"4.Display elements of BST in preorder,inorder and postorder traversal"<<endl;
		cout<<"5.Display elements of BST in level-by-level traversal"<<endl;
		cout<<"6.Display height of BST"<<endl;
		cout<<"7.End operation"<<endl;
		cout<<"User's choice:";
		cin>>option;
		cout<<"************************************************************************************"<<endl;
		switch(option)
		{
			case 1:
				{
					cout<<"Enter key value to be inserted :";
					cin>>x;
					tree->finalinsertNode(x);
					break;
				}
			case 2:
				{
				if(!(tree->isempty()))
					{
					cout<<"Enter key value to be deleted : ";
					cin>>x;
					if(tree->search(x))
					{
					tree->root=tree->deleteNode(tree->root,x);
					
					}
					else
					{
						cout<<"element not found"<<endl;
					}
				}
					else
					{
						cout<<"BST is empty. "<<endl;
					}
					break;
				}
			case 3:
				{
					if(!(tree->isempty()))
					{
					cout<<"Enter key value to be searched :";
					cin>>x;
					cout<<"Enter key value to replace with :";
					cin>>y;
					tree->swapNodes(x,y);
				}
				else
				{
					cout<<"BST is empty. Operation can't be performed"<<endl;
				}
					break;
					
				}
			case 4:
				{
					tree->depthfirst();
					break;
				}
			case 5:
				{
					tree->breadthfirst();
					break;
				}
			case 6:
				{
				tree->printheight();
					break;
				}
			case 7:
				{
					cout<<"End of operation"<<endl;
					flag=false;
					break;
				}
			default:
				{
					cout<<"Invalid option"<<endl;
				}
				
		}
		cout<<"******************************************************************************"<<endl;
		
		
	}
}
int main()
{
	cout<<"To work on characters, Press 1"<<endl;
	cout<<"To work on numbers , Press 2"<<endl;
	int option;
	cin>>option;
	if(option==1)
	{
		func1();
	}
	else if(option==2)
	{
		func2();
	}
	else
	{
		cout<<"Invalid option"<<endl;
	}
	return 0;
	
}
