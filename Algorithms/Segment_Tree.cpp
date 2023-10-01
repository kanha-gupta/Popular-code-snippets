#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class SGTree
{
    private:        
        vector<long long>seg;
 
    public:

        SGTree(int n)
        {
            seg.resize(4*n);
        }
 
        void build(int idx,int lo,int hi,vector<int>&a)
        {
            if(lo==hi)
            {
                seg[idx]=a[lo];
                return ;
            }
 
            int mid = lo + (hi-lo)/2;
            build(2*idx + 1,lo,mid,a);
            build(2*idx + 2,mid+1,hi,a);
            seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
        }
 
        void update(int idx,int lo,int hi,int i,int val)
        {
            if(lo==hi)
            {
                seg[idx]=val;
                return ;
            }
 
            int mid = lo + (hi-lo)/2;
            if(i<=mid)
                update(2*idx+1 , lo , mid , i , val);
            else
                update(2*idx+2 , mid+1 , hi , i , val);
            
            seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        }
 
        int query(int idx,int lo,int hi,int l,int r)
        {
            //[lo hi l r]   [l r lo hi]  -> No overlapp
            if(hi<l || r<lo)
                return 0LL;
            
            //[l lo hi r]  Complete overlap
            if(l<=lo && r>=hi)
                return seg[idx];
            
            //Partial overlap
            int mid = lo + (hi-lo)/2;
            long long left = query(2*idx+1,lo,mid,l,r);
            long long right = query(2*idx+2,mid+1,hi,l,r);
 
            return left+right;
        }
};

/*
The above segement tree is used to calculate the sum between ranges of indices whilst also providing dynamic updates.
Incase one encounters a question which asks about querying some other operation rather than adding , only the query function
should be updated and it would be good to go.
*/