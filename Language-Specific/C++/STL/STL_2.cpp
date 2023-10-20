#include <bits/stdc++.h>
using namespace std;

int main()
{

    // *1*
    // ORDERED SET {Stores a unique elements}
    // Given n elements, how to find the number of unique elements
    int arr[] = {2, 5, 2, 1, 5, 6, 9};
    set<int> st;
    int n;
    cin >> n;

    // sTORES the elements in linearly ascending order
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x); // log(n) time complexity
    }
    // cout<<*(st.begin());

    // eRASE function
    st.erase(st.begin()); // st.erase(iterator2_b_erased) -->{2, 5}

    // DELETING ELEMENTS BETWEEEN A RANGE USING BEGIN AND END ITERATORS
    st.erase(st.begin(), st.end()); // --> To delete the entire set
    // st.erase(st.begin(), st.begin()+1);    // This gives an error due to different type

    // FIND  function in sets
    set<int> stis = {2, 4, 6, 8};
    // Time ccomplexity ---> log(n)
    stis.find(2); // returns the iterator containing value 2
    stis.find(3); // returns the end iterator as there is no 3 inside the set {it = stis.end()}

    // emplace function in sets
    stis.emplace(3);
    // SIMILAR TO
    stis.insert(3);

    // SET CAN CONTAIN ANY DATA STRUCTURE (that is if we create a user defined data structure) then it can also be contained inside the set
    // For eg:
    // set<node> setis;

    // TWO WAYS FOR SET ALSO
    // THIS {<} does not work for sets as unique elements are present in sets
    // for (auto it = st.begin(); it < st.end(); it++)
    // {
    //     cout<<*it<<" ";
    // }

    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }

    for (auto it : stis)
    {
        cout << it << " ";
    }

    // *2*
    // UNORDERED SET
    // No fashion of stroing elements {either ascending of descending}

    unordered_set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(1);

    // Average time complexity is O(1)
    // Worst time complexity is O(n)

    // At first use unordered set if there is no requirement of any order sepcific result
    // It gives avg case result, and if worst TLE occurs then use Ordered set

    // *3*
    // MUTLISET
    // Gives the functionality to store the elements in sorted order but
    // unique elements are not stored{each element is stored}

    // Uses log(n) time cmplexity
    multiset<int> ms;
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(5);
    ms.insert(3);
    ms.insert(7);

    // ms --> {2, 2, 3, 3, 5, 7}
    // ms.emplace(3);    //Acts similar to insert function

    ms.erase(2);           // To delete all the instances of the element
    auto itt = ms.find(2); // returns an iterator pointing to the ffirst occurence
    ms.clear();            // deletes the entire set
    ms.erase(ms.begin(), ms.end());

    ms.erase(ms.find(2));
    // THIS IS NOT WORKING FOR THE CURRENT VERSION OF CPP
    // ms.erase(ms.find(2), ms.find(2)+2);

    // Gives the number of occurences of the particular element
    stis.count(2);

    // *4*
    // ORDERED MAPS
    // KEY--> VALUE PAIR
    // Only stores unique keys

    // a --> 27
    // b --> 28
    // c --> 23
    // d --> 21

    // ONLY STORES UNIQUE KEYS
    // STORES IN SEREIES ACCORING TO THE STRING VALUE
    // IF STRING IS THE KEY THEN sort acc. to lexicographical order
    // similarly for the integer values
    map<string, int> mpp;
    mpp["a"] = 27;
    mpp["b"] = 28;
    mpp["c"] = 23;
    mpp["d"] = 21;
    mpp.emplace("d", 21); // Similar to the upper method and also has slight lower time complexity

    // ********
    mpp["a"] = 98; // The value of "a" will be overwrited

    mpp.erase("a");         // To erase using key
    mpp.erase(mpp.begin()); // To erase using iterator

    mpp.clear(); // To clean the entire map

    // Correct
    mpp.erase(mpp.begin(), mpp.end()); // Cleans up the entire range

    // Not working correct for this version or whatsoever reason
    // mpp.erase(mpp.begin(), mpp.begin()+2);       // To delete the elements in a particular range

    auto its = mpp.find("1"); // 2 POInt out where the element lies
    auto it = mpp.find("a");

    mpp.empty(); // to find out if the element is present inside the container

    // TO DISPLAY ALL THE PAIRS OF KEY AND VALUES
    // Simply printing map
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    for (auto it = mpp.begin(); it != mpp.end(); it++)
    {
        cout << it->first << " " << (*it).second << endl;
    }

    // *5*
    // UNORDERED MAP

    unordered_map<int, int> ump;
    // Does Not store in any order
    // O(1) in almost all cases
    // O(n) in worst case complexity, (Here n is the container size)

    // MULTIMAP ALSO WORKS IN A SIMILAR WAY TO MULTI SET
    // nO UNIQUE KEYS, REPEATITION OF VALUES, IN SORTED ORDER !!!!!!!!!!!!!!!

    // *6*
    // PAIR CLASS
    pair<int, int> pr = {1, 2};

    // Nested pairs
    pair<pair<int, int>, int> pr2 = {{pr.first, pr.second}, 3};

    pair<pair<int, int>, pair<int, int>> pairis = {{1, 3}, {4, 5}};
    cout << pairis.first.first << endl;   //  ----> 1
    cout << pairis.second.second << endl; //  ----> 4

    // DIFFERENT TYPES OF INVOLVEMENT OF PAIR CLASS
    vector<pair<int, int>> vec;
    set<pair<int, int>> si;
    map<pair<int, int>, int> mpisi;

    // UNORDERED MAP CAN ONLY STORE SINGLE VALUES
    // For eg: int, bool, double etc

    // unordered_map<pair<int, int>, int> {NOT POSSIBLE}

    //   THERE IS NO CONCEPT OF ITERATORS IN STACK AND QUEUE
    // sO will be using while loop
    // *7*
    // STACK AND QUEUE
    stack<int, int> sta; // LIFO DS
    // pop
    // top
    // size
    // empty
    // push and emplace

    sta.push(1);
    sta.push(12);
    sta.push(123);
    sta.push(1234);
    sta.push(12345);

    cout << sta.top() << endl; // prints 12345
    sta.pop();                 // Removes the topmost or last entered element from the stack
    cout << sta.top() << endl; // prints 1234

    bool flag = sta.empty(); // returns a boolean value

    sta.top(); // gives an errror if there is no element present inside the stack

    //  2 Delete the entire stack
    while (!sta.empty())
    {
        sta.pop();
    }

    cout << sta.size() << endl; // To determine the number of elements inside the stack

    // To print all the elements inside the stack
    // tHE BELOW GIVEN IS A MUST CHECK CONDITION FOR STACK QUESIONS IN CP
    if (!sta.empty())
    {
        cout << sta.top() << endl;
    }

    // *8*
    // QUEUE DS
    // FIFO OPERATIONS
    // push
    // front
    // pop
    // size
    // empty

    // All operations take constant time
    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(3);
    q.push(6);

    cout << q.front() << endl; // Print 1
    q.pop();

    cout << q.front() << endl; // Print 5
    q.pop();

    // making THE QUEUE EMPTY takes linear time
    // O(n) time complexity
    while (!q.empty())
    {
        q.pop();
    }

    // *9*
    // PRIORITY QUEUE
    // Takes elements in the desceneding order
    // push
    // size
    // top
    // pop
    // empty
    //   Stores all in sorted order and does all operatins in log(n) time complexity
    priority_queue<int> pq;
    pq.push(2);
    pq.push(5);
    pq.push(6);
    pq.push(1);

    cout << pq.top() << endl; // prints 6
    pq.pop();
    cout << pq.top() << endl; // prints 5

    priority_queue<pair<int, int>> ppq;
    ppq.push({1, 5});
    ppq.push({1, 3});
    ppq.push({1, 9});
    // In the above case all the elements will be taken in the descending order {
    //     first the .first elememnt will be checked Then .second element willl be checked
    // }

    // HOW TO MAKE THE priority_queue STORE ALL THE ELEMENTS IN THE ASCENDING ORDER
    // mADE A MIN PRIORITY QUEUE USING A MAX PRIORITY QUEUE
    pq.push(-2);
    pq.push(-5);
    pq.push(-6);
    pq.push(-1);

    // While inserting the elements do the negationn
    // This thing will take in all the elemnts in the order opposite to their natural flow

    // And while printig them negate them again as done below
    cout << (-1) * pq.top(); // Prints 1
    pq.pop();

    cout << (-1) * pq.top(); // Prints 2

    //  *10*
    // min priority_queue

    priority_queue<int, vector<int>, greater<int>> mpq;     //  <--- sYNTAX
    mpq.push(7);
    mpq.push(4);
    mpq.push(3);
    mpq.push(9);

    // FOR SOME DIFFERENET DATA TYPE AS SHOWN BELOW 
    priority_queue<pair<int,int> , vector<int>, greater<pair<int,int>>> Impq;     
    cout << mpq.top() << endl; // Prints 3

    // *11*
    // DEQUE DATA STRUCTURE 

    deque<int> dq;
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin
    // end
    // rbegin
    // rend
    // size, clear, empty, at


    // *12* 
    // LIST implements DOUBLY LINKED LIST

    list<int> ls;
    // push_front()
    // push_back()
    // pop_front()
    // pop_back()
    // begin
    // end
    // rbegin
    // rend
    // size, clear, empty, at

    // remove FUNCTION IS AN EXTRA ONE 
    // remove    --> O(1)
    ls.push_front(1);
    ls.push_front(3);
    ls.push_front(7);
    ls.push_back(43);

    ls.remove(2);       // -> O(1) operation 

    // QUESTION
    // given NN elements, print the element that occurs max number of times 

    // input  = 5
    // 1, 3, 3, 3, 2
    // Output = 3

    int n;
    cin>>n;

    unordered_map<int, int> mpi;       // USE THE unordered map to reduce the time complexity 
                                       // O(n x 1) for avg case time ccomplexity 
                                       // For worst case time complexity O(n x n) occurs and if TLE OCCURS 
                                       // tHEN SITCH TO ORDERED MAP having time complexity (n x log(n))

    int maxim = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        mpi[x]++;
        if(mpi[x]>mpi[maxim]) maxim = x;
        cout<<maxim<<endl;      
    }
    


    
    return 0;
}