// Upper Triangular Matrix using one-dimensional array

#include<iostream>
using namespace std;

template<class T>
class upperT
{
	T *t;
	int size;
	public:
		upperT(int n)
		{
			size=n;
			t=new T[n*(n+1)/2];
		}
		void store(int i, int j, T x);
		T retrieve(int i, int j);
};

template<class T>
void upperT<T>::store(int i, int j, T x)
{
	if(i>=j)
		t[j*(j-1)/2+(i-1)]=x;
	else if(x!=0)
		cout<<"x must be zero"<<endl;
}

template<class T >
T upperT<T>::retrieve(int i, int j)
{
	if(i>=j)
		return t[i*(i-1)/2+(j-1)];
	else
		return t[j*(j-1)/2+(i-1)];
}

int main()
{
	int x;
	upperT<int>u1(3);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cout<<"Enter[" <<i <<"," <<j<< "] ";
			cin>>x;
			u1.store(i,j,x);
		}
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cout<<u1.retrieve(i,j)<<"\t";
  		}
  		cout<<"\n";
  	
	}
	return 0;
}
