class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto i:nums){
            add(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */