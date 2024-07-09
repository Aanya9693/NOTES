#include <bits/stdc++.h>
using namespace std;

string duplicate(vector<int>& arr) {
    int n=arr.size();
    unordered_map<int, int>freqMap;
    for (int i = 0; i < n; ++i) {
        freqMap[arr[i]]++;
    }
    string ans = "No duplicate digits";
    for (auto it : freqMap) {
        if (it.second >= 2) {
            ans = to_string(it.first) + " is duplicate " + to_string(it.second) + " times";
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {2, 2, 3, 2, 2};
    cout << duplicate(arr) << endl;
    
    return 0;
}
