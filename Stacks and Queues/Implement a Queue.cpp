class Queue {
public:
    int first;
    int rear;
    int arr[100000000];
    Queue() {
        // Implement the Constructor
        first=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (first==rear);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[rear++]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(first==rear){
            return -1;
        } else{ 
           int ans = arr[first];
           arr[first] = -1;
           first++;
            if(first==rear){
                first=0;
                rear=0;
            }
          return ans;    
        }
    }

    int front() {
        // Implement the front() function
        if(rear==first)    return -1;
        int x = arr[first];
        return x;
    }
};