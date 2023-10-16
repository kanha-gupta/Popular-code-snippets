// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void print_nested_vec(vector<pair<int, int>> v){
    cout<<"The size of the nested vector is "<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;    
}
int main(){
    // hERE we have created a vector of pair (i.e so to understand we can say that we did use the data type -> pair<int, int> <- inside the vector)
    // vector <pair<int, int>> p {{1, 2}, {4, 5}, {7, 8}}; 
    vector<pair<int, int>> p;
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x>>y;
        // p.push_back(make_pair(x, y));
        p.push_back({x, y});
    }
    print_nested_vec(p);
    return 0;
}