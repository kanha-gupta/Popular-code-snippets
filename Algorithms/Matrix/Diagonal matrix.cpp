// Diagonal Matrix using one-dimensional array

#include<iostream>
using namespace std;

template<class T>
class diagonal
{
		T*t;
		int size;
		public:
			diagonal(int n)
			{
				size=n;
				t=new T[size];
			}
			void store(int i,int j,T x);
			int retrieve(int i,int j);
			
			};
			template<class T>
			void diagonal<T> :: store(int i,int j,T x)
			{
				if(i==j)
				 t[i-1]=x;
				else
				 cout<<"Element must be empty"<<endl;
			}
			template<class T>
			int diagonal<T> :: retrieve(int i,int j)
			{
				if(i==j)
				 return t[i-1];
				else
				return 0;
			}
			int main()
			{
				int x;
				diagonal<int>d1(3);
				for(int i=1;i<=3;i++)
				{
					for(int j=1;j<=3;j++)
					{
						cin>>x;
						d1.store(i,j,x);
					
					}
				}
				for(int i=1;i<=3;i++)
				{
					for(int j=1;j<=3;j++)
					{
						cout<<d1.retrieve(i,j)<<"\t";
					}
				cout<<"\n";
			}
			return 0;
			}
