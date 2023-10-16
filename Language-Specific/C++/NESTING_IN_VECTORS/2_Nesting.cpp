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
    vector<int> v[N];
    for (int i = 0; i < N; i++)
    {
        int n; // Number of elements in vector
        cout << "Enter the number of elements " << endl;
        cin >> n;
        for (int j = 0; j < n; j++)
        // for (int i = 0; i < n; i++)  YE GADBAD KAR DEGA
        // DON'T EVER USE SAME VARIABLES(MAINLY FOR NESTED LOOPS OR MEMBERS)
        {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }

    for (int i = 0; i < N; i++)
    {
        print_nested_vec(v[i]);
    }
    cout<<v[0][1]<<endl;
    cout<<v[1][1];
    return 0;
}