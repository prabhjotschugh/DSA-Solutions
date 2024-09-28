class MyCircularDeque {
public:
    int maxSize;
    deque<int>dq;
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(dq.size() == maxSize) return false;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(dq.size() == maxSize) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(dq.empty()) return false;
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(dq.empty()) return false;
        dq.pop_back();
        return true;
    }
    
    int getFront() {
        if(dq.empty()) return -1;
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */