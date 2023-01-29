class LFUCache {
public:
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    unordered_map<int,int>m;
    unordered_map<int,int>freq;
    int cap;
    int tar;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        put(key,m[key]);
        return m[key];
    }
    
    void put(int key, int value) {
        if(cap==0){
            return;
        }
        if(m.find(key)==m.end()&&m.size()==cap){
            while(m.size()==cap){
                auto x=pq.top();
                if(freq[x.second.second]==x.first){
                    m.erase(x.second.second);
                    freq.erase(x.second.second);
                }
                pq.pop();
            }
        }
        m[key]=value;
        freq[key]++;
        pq.push({freq[key],{tar++,key}});
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */