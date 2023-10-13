// program to solve the weighted interval scheduling problem

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct Job
{
	int start_time,finish_time, weight;
	char label;
};
bool JobCompare(Job j1,Job j2)
{
	return (j1.finish_time<j2.finish_time);
	
}
int latestCompatible(Job arr[], int i)
{
	for(int j=i-1;j>=0;j--)
	{
		if(arr[j].finish_time<=arr[i].start_time)
		{
			return j;
		}
	}
	return -1;
}
int findOptimal(Job * arr, int n,int * table)
{
	sort(arr,arr+n,JobCompare); //stl function , 3rd argument is basis for comparison, second pointer of end of array
	
	table[0]=arr[0].weight;
	for(int i=1;i<n;i++)
	{
		int inclWeight=arr[i].weight;
		int l=latestCompatible(arr,i);
		if(l!=-1)
		{
			inclWeight+=table[l];}
			table[i]=max(inclWeight,table[i-1]);
			
		
	}
	int result=table[n-1];
	return result;	
	
}

int main()
{
	int n;
	cout<<"Enter number of Jobs:";
	cin>>n;
	struct Job job[n];
	char label;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter job name(a character ,eg-a,b,c):";
		cin>>job[i].label;
		cout<<"Enter Job start time, finish time and weight respectively:";
		cin>>job[i].start_time;
		cin>>job[i].finish_time;
		cin>>job[i].weight;
		
	}
	int table[n]={0};
	int ans=findOptimal(job,n,table);
	cout<<"Optimal solution:"<<ans<<endl;
	
	return 0;
	
}
