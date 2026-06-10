class MyCircularQueue {
private:
    int front,capacity,size;
    vector<int> v;
public:
    MyCircularQueue(int k): capacity(k) {
        front=0,size=0;
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        v[(front+size)%capacity]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        if(!isEmpty()){
            return v[front];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()){
            return v[(front+size-1)%capacity];
        }
        return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */