// Stack class.
class Stack {
    
public:
    int i;
    int cap;
    int arr[100000000];
    Stack(int capacity) {
        // Write your code here.
        cap=capacity;
        //int arr[capacity];
        i=-1;
    }
    //int arr[cap];
    void push(int num) {
        // Write your code here.
        if(i>=cap-1)    return;
        arr[++i]=num;
    }

    int pop() {
        // Write your code here.
        if(i<0)    return -1;
        int x=arr[i--];
        return x;
    }
    
    int top() {
        // Write your code here.
        if(i<0)    return -1;
        int x=arr[i];
        return x;
    }
    
    int isEmpty() {
        // Write your code here.
        return (i==-1);
    }
    
    int isFull() {
        // Write your code here.
        return (i==cap-1);
    }
    
};