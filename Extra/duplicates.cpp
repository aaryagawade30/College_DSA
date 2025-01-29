#include <bits/stdc++.h>
using namespace std;

int distinct(vector<int> arr) {
    int count = 0;
    unordered_set<int> duplicates;
    for(int i = 0; i < arr.size(); i++) {
        duplicates.insert(arr[i]);
    }

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
    }
    return (duplicates.size() - count);
}

void remDup(vector<int> arr) {
    unordered_set<int> dup;
    for(int i = 0; i < arr.size();i++) {
        dup.insert(arr[i]);
    }
    
    for(auto it: dup) {
        cout << it <<" ";
    }
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 2, 4, 5, 7, 3};
    cout<<distinct(arr);
    remDup(arr);

    return 0;
}