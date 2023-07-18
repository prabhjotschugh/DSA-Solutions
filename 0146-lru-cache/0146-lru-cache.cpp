class LRUCache {
public:
    struct node{
        int key,val;
        node *prev;
        node *next;
        node(int k,int v){
            key = k;
            val = v;
        }
    };
    int cap=0;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    unordered_map<int,node *>m;
    LRUCache(int capi) {
        cap =capi;     
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(node *n){
            node *n1=n->prev;
            node *n2 = n->next;
            n1->next=n2;
            n2->prev=n1;
    }
    void addnode(node *n){
        node *n1 = head->next;
        head->next = n;
        n->next = n1;
        n->prev= head;
        n1->prev = n;
    }
    int get(int key) {
        if(m.find(key)==m.end())    return -1;
        node * address = m[key];
        int ans = address->val;
        deletenode(address);
        addnode(address);
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node * add = m[key];
            deletenode(add);
            addnode(add);
            head->next->val = value;
        }
        else{
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */