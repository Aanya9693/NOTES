#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int>&item1, vector<int>&item2){
   double ratio1=(double)item1[0]/item1[1];
   double ratio2=(double)item2[0]/item2[1];
   //sort in decreasing order
   return ratio1>ratio2;
}

double fractionalKnapsack(int wt, vector<vector<int>>&items){
   int n=items.size();
   //sort like weight of each item is minimum
   sort(items.begin(), items.end(), cmp);
   double finalVal=0.0;
   for(int i=0; i<n; i++){
      if(items[i][1]<=wt){
         wt-=items[i][1];
         finalVal += items[i][0]; // Add the full value of the item
      }else{
         finalVal+= (items[i][0] * (double)wt/items[i][1]);
         break;
      }
   }
   return finalVal;
}

int main(){
    int wt = 50;

    // Define the items with their (value, weight)
    vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}};

    // Call the fractionalKnapsack function and print the result
    double maxValue = fractionalKnapsack(wt, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}