#include <bits/stdc++.h> 
// Stack class.
class Stack {
    stack<int>st;
public:
    int cap;
    Stack(int capacity) {
        // Write your code here.
        cap=capacity;
    }

    void push(int num) {
        // Write your code here.
        st.push(num);
    }

    int pop() {
        // Write your code here.
        if(st.empty())return -1;
        int temp=st.top();
        st.pop();

        return temp;
    }
    
    int top() {
        // Write your code here.
        if(st.empty())return -1;
        return st.top();
    }
    
    int isEmpty() {
        // Write your code here.
        return st.empty();

    }
    
    int isFull() {
        // Write your code here.
        return st.size()==cap;
    }
    
};
