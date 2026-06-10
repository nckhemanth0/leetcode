class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    
    void rebalance(){
        // maintain n1>=n2
        while(maxpq.size()<minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        if(maxpq.size()-minpq.size()>1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() || num<=maxpq.top()){
            maxpq.push(num);
        }else{
            minpq.push(num);
        }
        rebalance();
    }
    
    double findMedian() {
        if(maxpq.size()==minpq.size()){
            return (maxpq.top()+minpq.top())/(2.0);
        }else{
            return maxpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */