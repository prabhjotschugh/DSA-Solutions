class RandomizedSet {
    unordered_set<int>s;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }
        s.insert(val);
        return true;
    }
    bool remove(int val) {
        if(s.find(val) == s.end()){
            return false;
        }
        s.erase(val);
        return true;
    }
    int getRandom() {
        // doing mod to get in range [0, s.size()-1]
        int pos = rand() % s.size();
        // std::next returns an iterator pointing to the element after being advanced by certain no. of positions.
        return *next(s.begin(), pos);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */