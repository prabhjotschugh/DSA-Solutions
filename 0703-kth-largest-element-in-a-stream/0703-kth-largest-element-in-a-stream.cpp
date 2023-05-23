class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(auto i:nums){
            if(pq.size()<k){
                pq.push(i);
                continue;
            }
            if(i>pq.top()){
                pq.pop();
                pq.push(i);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<size){
                pq.push(val);
                return pq.top();
            }
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */