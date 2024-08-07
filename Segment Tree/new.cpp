#include<bits/stdc++.h>
using namespace std;

vector<int>arr, segTree;

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
void update(int node, int l, int r, int idx, int val){
    //find lead node and update its value
    if(l==r){
        arr[idx]+=val;
        segTree[node]+=val;
    }else{
        int mid=(l+r)/2;
        //if node value idx is at left part then update left part
        if(l<=idx and idx<=mid){
            update(2*node+1, l, mid, idx, val);
        }else{
            update(2*node+2, mid+1, r, idx, val);
        }
        
        segTree[node]=segTree[2*node+1]+segTree[2*node+2];
    }
}
int main(){
    int n=6;
    arr={0, 1, 3, 5, -2, 3};
    
    //create a segment tree of size(4*n)
    segTree.resize(4*n);
    
    //build a segment tree
    build(0, 0, n-1);
    //sum of values in range 0-4
    cout<<"Sum of values in range 0-4 are: "<<query(0, 0, n-1, 0, 4)<<endl;
    
    //update value at idx 
    update(0, 0, n-1, 1, 100);
    cout<<"Sum of values in range 0-4 after update are: "<<query(0, 0, n-1, 0, 4)<<endl;
    
    return 0;
}