class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()<=right.size())   left.push(num);
        else right.push(num);
    }
    
    double findMedian() {
        if(right.size()!=0){
            while(left.top()>right.top()){
                int temp1=left.top();
                left.pop();
                int temp2=right.top();
                right.pop();
                left.push(temp2);
                right.push(temp1);
            }
        }
        
        if((left.size()+right.size())%2!=0){
            return left.top();
        }else{
            double med;
            med = (left.top()+right.top())/2.0;
            return med;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */