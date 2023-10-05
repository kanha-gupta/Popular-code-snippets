//   Randomized Select

#include<iostream>
#include<iomanip>
#include<time.h>
#include<cstdlib>
using namespace std;
int partition(int * arr, int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	int j;
	for(j=l;j<r;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return (i+1);
}
int randompartition(int *arr,int l, int r)
{
	int index=rand()%(r-l);
	swap(arr[r],arr[index]);
	return partition(arr,l,r);
}
int randomisedSelect(int * arr, int l, int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int index=randompartition(arr,l,r);
		if(index-l==k-1) //if position is same as k
		return arr[index];
		else if(index-l>k-1)
		return randomisedSelect(arr,l,index-1,k);
		else
		return randomisedSelect(arr,index+1,r,k-index+l-1);
		
	}
	return INT_MAX;
}
int main()
{
	srand(time(NULL));
	cout<<"Enter number of elements of array:";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter elements to be stored in array:"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter k:";
	int k;
	cin>>k;
	cout<<"Kth smallest element:"<<randomisedSelect(arr,0,n-1,k)<<endl;
	return 0;
}
