#include <bits/stdc++.h>

#include <math.h> //  use the above header file (only in comp. programming only)
// in an interview don't use the bits/stdc++.h as it takes a llot of time
// use only those header files that are required in the code (to reduce the time taken to perform the code)

using namespace std; // ----> used 2 declare a scope (CPP HAS DECLARED ALL IT'S FUNCTIONS INSIDE std
                     // so that we can use them any time we want )


namespace baburao
{
    int val = 11; // includes it's own variables
    int getaval()
    { // includes it's own functions
        return val * 10;
    }
}

// Creating a data type which can hold all the data types as meintioned inside the struct
struct node
{
    string str;
    int num;
    double doub;
    char x;

    // Using the concept of constructor overloADINg
    node(){};

    // Creating a constructor inside the structure{constructor inside sttuct is valid only in cpp not in C}
    node(string str_, int num_, double doub_, char x_)
    {
        str = str_;
        num = num_;
        doub = doub_;
        x = x_;
    }
};
    //                  // extra INFo
    // int arr[]  {for data types int, double, char and others OUTSIDDE THE INT main function the max size is 10^7}
    // int arr[]  {for data type bool OUTSIDE THE INT main the max size is 10^8}

array<int, 3> arr; //{0, 0, 0}  In case if the array is declared outside the int main function
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{

    // extra INFo
    // int arr[]  {for data types int, double, char and others the max size is 10^6}
    // int arr[]  {for data type bool the max size is 10^7}

    // *1*

    // int val = 10;
    // // same var and diff data types so it will throw an error
    // double val = 10.25;

    int val = 10;
    // std::cout<<val<<endl;   //{in case if we don't write namespace under the header file }
    cout << val << endl; // prints out 10

    // *2*
    // This is how the namespace works
    cout << baburao::val << endl;       // prints out 11
    cout << baburao::getaval() << endl; // prints out 11

    // *3*
    // {string, int, double, char}

    // It's a valid method but not correct to use {noob lagoge}
    // Constructor having no values in the arguments
    node babu;
    babu.x = 'a';
    babu.num = 23;
    babu.str = "hehe";
    babu.doub = 23.23;

    // *4*
    // This is the correct way to use arguments inside a single package
    // node babu1 = new node("patanhi", 23, 23.23, 'a');  {no suitable constructor exists to convert from "node *" to "node"}

    // The below code gives no error and this acts as a correct way to declare a class with different data types
    node *babu1 = new node("patanhi", 23, 23.23, 'a');

    // several other data types ccan be created like ({var arr[], int, doub, char})etc.

    // *5*
    // Arrays --> int arr[100];
    array<int, 3> arr;         //{?, ?, ?}  In case if the array is declared inside the int main function
    array<int, 5> arris = {1}; // {1, 0, 0, 0, 0}

    int arrays[10000] = {0};


    // .fill function
    array<int, 5>arr;
    // arr.fill(10);    This helps us to fill all the values at all the indexes with the valuue 10
    // {10, 10, 10, 10, 10}

    // .at function
    // arr.at(index);
    arr.at(3);

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr.at(i)<<endl;
    }
    

    // *6*
    // ITERATORS

    // begin(), end(); rbegin(); rend();
    // points at the first element 
    // points at the position after the last
    // points at the last position 
    // points at the position just before the first

    // TO PRINT IN NORMAL ORDER
    array<int, 5> arri = {1, 3, 5, 4, 6};
    for(auto it = arri.begin(); it != arri.end(); it++){
        cout<<*it<<" ";
    }

    // TO PRINT IN REVERSE ORDER
    // We need to use the it++ operator for the reverse operator
    for(auto it = arri.rbegin(); it != arri.rend(); it++){
        cout<<*it<<" ";
    }
    for(auto it = arri.rbegin(); it > arri.rend(); it++){
        cout<<*it<<endl;
    }

    // TO PRINT IN REVERSE ORDER
    for(auto it = arri.begin()-1; it != arri.end(); it++){
        cout<<*it<<" ";
    }

    // *7*
    // For each loop
    // In the case of for each loop, theree is no pointer applied 
    // we directly point to the element itself which always moves in the forward direction
    for(auto it : arr){
        cout<<it<<" ";
    }

    string STR = "MYSTring";
    for(auto iter : STR){
        cout<<iter<<" ";
    }

    //SIZE of ARRAY 
    cout<<arr.size();

    // FIRST ELEMENT ACCESS
    cout<<arr.front();

    // LAST ELEMENT ACCESS
    cout<<arr.back();
    cout<<arr.at(arr.size()-1);


    // *8*
    // VECTORS
    vector<int> v;
    cout<<v.size()<<endl;     // function to print the size of the vector

    v.push_back(1);   // To add the element inside the vector
    v.push_back(2);   // To add another element inside the vector

    cout<<v.size()<<endl;

    v.pop_back();
    v.clear();      // Clears all the elements at once
                    // makes the size of the vector = 0

    vector<int> vec1(4, 0);
    vector<int> vec2(4, 10);

    // Copies the entire vector into vec3
    // This also workss 
    vector<int> vec3(vec2.begin(), vec2.end());           // [)

    // This works
    // vector<int> vec3(vec2.begin(), vec2.begin()+1);           // [)
    vector<int> vec3(vec2);

    vector<int> vec4;
    vec4.push_back(1);
    vec4.push_back(2);
    vec4.push_back(3);
    vec4.push_back(4);

    vector<int> vec4_cpy(vec4.begin(), vec4.begin()+2);   //vec4_cpy includes {1, 2}
    
    // .pushback() and emplaceback() work exactly the same 
    // THE ONLY THING IS THAT emplace_back() works  A LITTLE MORE FASTER THAN PUSHBACK();

    // *8*
    // Defining 2D vectors

    vector<vector<int>> vevec;

    vector<int> vecis1;
    vecis1.push_back(1);
    vecis1.push_back(12);
    
    vector<int> vecis2;
    vecis2.push_back(2);
    vecis2.push_back(23);
    
    vector<int> vecis3;
    vecis3.push_back(2);
    vecis3.push_back(23);

    vevec.push_back(vecis1);
    vevec.push_back(vecis2);
    vevec.push_back(vecis3);

    // Now we have created a 2D vector 
    for(auto vctr:vevec){      // --> vctr represents the vector itself contained inside the 2D vector
        for(auto itt:vctr){    // --> itt represents the elements of the vectors contained inside the MAtrIx
            cout<<itt<<" ";
        }
        cout<<endl;
    }

    // Traditional/NORMAL mETHOD
    for (int i = 0; i < vevec.size(); i++)
    {
        for (int j = 0; j < vevec[i].size(); j++)
        {
            cout<<vevec[i][j]<<" ";
        }
        cout<<endl; 
    }
    

    // How 2 access the elements 
    // vevec[i][j];  {This is how we will get an element from somwhere in this world }


    // dEfininG a vector of 20x10 
    // DefinINg a 2D vecToR
    vector<vector<int>> a(20, (vector<int> (10, 0)));

    // dEfininG an array of size {x}
    vector<int> arre[4];
    
    // how to push MoRe elements inside the array????
    arre[0].push_back(0);


    // Defining 4 a 10x20x30 vector
    vector<vector<vector<int>>> vecis(10, (vector<vector<int>>(20, (vector<int> (30, 0))))); 

}