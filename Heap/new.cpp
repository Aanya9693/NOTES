#include<bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    vector<int>heap;
    
    void heapifyUp(int index){
        int parentIdx=(index-1)/2;
        if(index>0 && heap[index]<heap[parentIdx]){
            swap(heap[index], heap[parentIdx]);
            heapifyUp(parentIdx);
        }
    }
    void heapifyDown(int index){
        int lefChild=2*index+1;
        int rightChild=2*index+2;
        int smallest=index;
        if(lefChild<heap.size() && heap[lefChild]<heap[smallest]){
            smallest=lefChild;
        }
        if(rightChild<heap.size() && heap[rightChild]<heap[smallest]){
            smallest=rightChild;
        }
        if(smallest!=index){
            swap(heap[smallest], heap[index]);
            heapifyDown(smallest);
        }
    }
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size()-1);
    }
    int getMin(){
        if(heap.size()==0){
            cout<<"Heap is empty";
        }
        return heap[0];
    }
    bool isEmpty(){
        return heap.size()==0;
    }
    int extractMin(){
        if(heap.size()==0){
            cout<<"Heap is Empty"<<endl;
        }
        int minElement=heap[0];
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minElement;
    }
};

int main(){
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(3);
    // for(int i=0; i<4; i++){
    //     cout<<minHeap.heap[i]<<" ";
    // }
    // cout<<minHeap.heap;
    cout<<"Min value: "<<minHeap.getMin()<<endl;
    while(!minHeap.isEmpty()){
        cout<<"Extracted: "<<minHeap.extractMin()<<endl;
    }
    return 0;
}