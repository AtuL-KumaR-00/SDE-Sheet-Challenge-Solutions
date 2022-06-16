#include<bits/stdc++.h>
void sortStack(stack<int> &stack)
{
	// Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    while(stack.empty()==false){
        pq.push(stack.top());
        stack.pop();
    }
    while(pq.empty()==false){
        stack.push(pq.top());
        pq.pop();
    }
}