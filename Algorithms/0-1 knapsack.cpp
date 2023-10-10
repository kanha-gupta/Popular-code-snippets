// program to solve 0-1 knapsack problem

#include<iostream>
#include<iomanip>
using namespace std;
struct Item
{
	int profit, weight;
};
void knapSack(Item * s, int n , int W)
{
	int K[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
			K[i][j]=0;
			else if(s[i-1].weight<=j)
			{
				int u =s[i-1].profit+K[i-1][j-s[i-1].weight];
				int v=K[i-1][j];
				K[i][j]=u>v?u:v;
				
			}
			else
			K[i][j]=K[i-1][j];
		}
	}
	cout<<"Maximum value:"<<K[n][W]<<endl;
	cout<<"Selected items:"<<endl;
	while(n!=0)
	{
		if(K[n][W]!=K[n-1][W])
		{
			cout<<"Package "<<n<<" with W="<<s[n-1].weight<<" and value="<<s[n-1].profit<<endl;
			W=W-s[n-1].weight;
		}
		n--;
	}
}
int main()
{
	int n, W;
	cout<<"Enter no. of items:";
	cin>>n;
	cout<<"Enter the capacity weight:";
	cin>>W;
	struct Item s[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter profit and weights associated with item:";
		cin>>s[i].profit;
		cin>>s[i].weight;
		
	}
	knapSack(s,n,W);
	return 0;
	
}
