#include <bits/stdc++.h> 
class Queue {
    queue<int>q;
public:
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return q.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q.push(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(q.empty())return -1;
        int temp=q.front();
        q.pop();
        return temp;
    }

    int front() {
        // Implement the front() function
        if(q.empty())return -1;
        return q.front();
    }
};
