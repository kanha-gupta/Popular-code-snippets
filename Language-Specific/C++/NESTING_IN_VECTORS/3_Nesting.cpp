#include <bits/stdc++.h>
using namespace std;
// ARRAY OF VECTORS
void print_nested_vec(vector<int> &v)
{
    cout << "The size of the nested vector is " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    // // BELOW IS AN ARRAY OF 10 VECTORS
    // vector <int> v[10];

    int N; // Number of vectors
    cout << "Enter the number of vectors " << endl;
    cin >> N;
    vector<vector <int>> v ;
    for (int i = 0; i < N; i++)
    {
        int n; // Number of elements in vector
        cout << "Enter the number of elements " << endl;
        cin >> n;
        vector <int> temp;
        for (int j = 0; j < n; j++)
        {
            int y;
            cin >> y;
            temp.push_back(y);
            // v[i].push_back(y);   // ith element does not exist
        }
        v.push_back(temp);  // Pushing a vector inside a VEctor
    }

    // v[0].push_back(11);   // Pushing 11 inside the 1st(0 indexed) vector 
    // v.push_back(vector<int> ()); // Pushing an empty vector inside the main one 
    for (int i = 0; i < v.size(); i++)
    {
        print_nested_vec(v[i]);
    }
    cout<<v[0][1]<<endl;
    cout<<v[1][1];
    return 0;
}