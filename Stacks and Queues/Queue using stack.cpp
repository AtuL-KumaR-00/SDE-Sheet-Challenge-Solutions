#include<bits/stdc++.h>

class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
        s1=stack<int>();
        s2=stack<int>();
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s2.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(s2.empty() )    return -1;
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        int x=s1.top();
        s1.pop();
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return x;
    }

    int peek() {
        // Implement the peek() function here.
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        if(s1.size()==0)    return -1;
        int x=s1.top();
        //s1.pop();
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return x;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (s2.size()==0 && s1.size()==0);
    }
};