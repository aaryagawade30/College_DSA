#include<bits/stdc++.h>
using namespace std;

void dectobin(int n) {
    stack<int> st;
    if(n == 0) return;
    while(n > 0) {
        st.push(n % 2);
        n /= 2;
    }
    
    while(!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}

void revstr(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }
    while(!st.empty()) {
        cout<< st.top();
        st.pop();
    }
}

void sorting(vector<int> arr) {
    stack<int> st, temp;
    for (int elem : arr) {
        st.push(elem);
    }

    // Process elements in st and place them in sorted order in temp
    while (!st.empty()) {
        int cur = st.top();
        st.pop();

        // Move elements from temp to st until the right position is found
        while (!temp.empty() && temp.top() > cur) {
            st.push(temp.top());
            temp.pop();
        }

        // Push the current element into the temp
        temp.push(cur);
    }

    // Transfer sorted elements from temp back to the array
    int i = 0;
    while (!temp.empty()) {
        arr[i++] = temp.top();
        temp.pop();
    }
    for(int i = arr.size() -1; i >= 0; i--) {
        cout<<arr[i];
    }
}

int main() {
    dectobin(10);
    revstr("aarya");
    vector<int> arr = {2, 3, 5, 4, 1};
    sorting(arr);

    return 0;
}