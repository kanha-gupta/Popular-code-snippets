// minimum spanning tree using kruskal's algorithm

#include<iomanip>
#include<iostream>
using namespace std;
class Graph
{
	private:
		int n;
		int * V;
		int ** G;
		int * parent;
		public:
		Graph(int num)
		{
			n=num;
			V=new int[num];
			G=new int *[num];
			parent=new int[num];
			for(int i=0;i<n;i++)
			{
				G[i]=new int[num];
				parent[i]=i;
			}
			
		}
		void getInput()
		{
			cout<<""<<n<<" vertices in graph are as follows:";
			for(int i=0;i<n;i++)
			{
				cout<<i<<" , ";
				V[i]=i;
			}
			cout<<endl;
			char choice;
			cout<<"Press 'y' if edge is present between two vertices , else 'n'"<<endl;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i==j)
					{
						G[i][j]=999;
						continue;
					}
					
					cout<<"Is there an edge between "<<V[i]<<" and "<<V[j]<<" in the graph:";
					cin>>choice;
					if(choice=='y'|| choice=='Y')
					{
						cout<<"Enter weight of edge between "<<V[i]<<" and "<<V[j]<<" in the graph:";
						cin>>G[i][j];
					}
					else
					{
						G[i][j]=999;
					}
					
				}
			}
		}
		int find(int i)
		{
			while(parent[i]!=i)
			i=parent[i];
			return i;
		}
		void unionset(int i,int j)
		{
			int a=find(i);
			int b=find(j);
			parent[a]=b;
		}
		void kruskal()
		{
			int mincost=0;
			int u,v;
			int mstedges=1;
			int min;
			cout<<"MST edges are as follows:"<<endl;
			while(mstedges<n)
			{
				min=999;
				u=-1;
				v=-1;
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<n;j++)
					{
						if(G[i][j]<min && find(i)!=find(j))
						{
							min=G[i][j];
							u=i;
							v=j;
							
						}
					}
				}
				if(u!=-1)
				{
					unionset(u,v);
					cout<<""<<(mstedges++)<<" Edge between "<<V[u]<<" and "<<V[v]<<" cost:"<<min<<endl;
					mincost+=min;
				}
			}
			cout<<"Total cost of minimum spanning trees:"<<mincost<<endl;
		}
		
};
int main()
{
	cout<<"Enter number of vertices present in graph:";
	int n;
	cin>>n;
	Graph g(n);
	g.getInput();
	g.kruskal();
	return 0;
}
