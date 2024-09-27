class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    map<int, int>mp;
    bool book(int start, int end) {
        mp[start] += 1;
        mp[end] -= 1;
        int ActiveEvent = 0;
        for(auto [value, count] : mp){
            ActiveEvent += count;
            if(ActiveEvent > 2){
                mp[start] -= 1;
                mp[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */