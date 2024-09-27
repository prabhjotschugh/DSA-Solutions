class MyCalendar {
vector<pair<int, int>> bks;
public:
    bool book(int s, int e) {
        for (auto& [bs, be] : bks)
            if (s < be && bs < e) return false;
        bks.push_back({s, e});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */