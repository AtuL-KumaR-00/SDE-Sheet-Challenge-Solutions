#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return (q1.size()==0);
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q1.size()==0)    return -1;
        int x=q1.front();
        q1.pop();
        return x;
    }

    int top() {
        // Implement the top() function.
        if(q1.size()==0)    return -1;
        int x=q1.front();
        //q1.pop();
        return x;
    }
};