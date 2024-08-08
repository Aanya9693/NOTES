#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt, vector<int>weights, vector<int>values, int n){
    vector<vector<int>>dp(n+1, vector<int>(wt+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=wt; j++){
            if(weights[i-1]<=j){
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-weights[i-1]]+values[i-1]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][wt];
}

int main(){
    int n = 4; // Number of items
    int wt = 7; // Capacity of the knapsack

    // Define the weights and values of the items
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};

    // Call the knapsack function and print the result
    int maxValue = knapsack(wt, weights, values, n);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}