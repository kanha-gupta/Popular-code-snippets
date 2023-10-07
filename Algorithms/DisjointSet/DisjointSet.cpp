class disjoint_set{
    public:
int *parent;
int sz;

 disjoint_set(int n){
    parent=new int[n];
    for(int i=0;i<n;i++) parent[i]=-1;
     sz=n;
 }
 ~disjoint_set(){
     delete [] parent;
 }
 bool sameParent(int a,int b){
     return find(a)==find(b);
 }
 int find(int i){
     if(parent[i]<0)
     return i;
   return parent[i]=find(parent[i]);
 }
 void join(int a,int b){
  int x=find(a),y=find(b);
  if(x!=y){
      sz--;
      if(parent[x]<parent[y]) swap(x,y);
      parent[x]+=parent[y];
     parent[y]=x;
  }
 }
 int size(){
     return sz;
 }
 int getSize(int i){
    if(parent[i]<0) return (-parent[i]);
    return getSize(parent[i]);
 }
};