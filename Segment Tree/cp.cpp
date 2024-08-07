#include<bits/stdc++.h> 
using namespace std;
 
vector<int>arr, segTree, lazy;

void build(int node, int l, int r){
    //if l==r -> it is leaf node
    if(l==r){
        segTree[node]=arr[l];
    }else{
        //find middle element to split the array
        int mid=(l+r)/2;
        //left half
        build(2*node+1, l, mid);
        //right half
        build(2*node+2, mid+1, r);
        
        //storing the sum of both
        // children into parent
        segTree[node]=segTree[2*node+1] + segTree[2*node+2];
    }
}
int query(int node, int tl, int tr, int l, int r){
    //if it lies out of range then return 0
    if(tr<l or r<tl){
        return 0;
    }
    
    //if node contains the range then
    //return node value
    if(l<=tl and tr<=r){
        return segTree[node];
    }
    //partially overlap
    int mid= tl + (tr-tl)/2;
    return query(2*node+1, tl, mid, l, r) + query(2*node+2, mid+1, tr, l, r);
}
void updateRange(int start, int end, int i, int l, int r, int val){
   if(lazy[i]!=0){
      segTree[i]+=(end-start+1)*lazy[i];
      if(start!=end){
         lazy[2*i+1]+=lazy[i];
         lazy[2*i+2]+=lazy[i];
      }
      lazy[i]=0;
   }
  
   
   //out of range
   if(start>end || start>r || end<l){
      return;
   }
   //fully in range
   if(start>=l && end<=r){
      segTree[i]+=(end-start+1)*val;
      if(start!=end){
         lazy[2*i+1]+=val;
         lazy[2*i+2]+=val;
      }
      return;
   }
   //if not completely in range
   //but overlaps, recursion for children
   int mid = (start+end)/2;
   updateRange(start, mid, 2 * i + 1, l, r, val);
    updateRange(mid + 1, end, 2 * i + 2, l, r, val);
   segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    // cout<<"kdh"<<endl;
}
int main(){
   arr = { 1, 3, 5, 7, 9, 11 };
    // int n = sizeof(arr) / sizeof(arr[0]);
   int n=6;
     //create a segment tree of size(4*n)
    segTree.resize(4*n);
    lazy.resize(4*n);
    
    //build a segment tree
    build(0, 0, n-1);
     //sum of values in range 0-4
    cout<<"Sum of values in range 2-4 are: "<<query(0, 0, n-1, 2, 4)<<endl;
     // Add 10 to all nodes at indexes
    // from 1 to 5.
    updateRange(0, n-1, 0, 2, 4, 10);
 
    // Find sum after the value is updated
    cout << "Updated sum of values in given range = " << query(0, 0, n-1, 2, 4) << endl;
}