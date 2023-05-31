class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> start;
    unordered_map<string, unordered_map<string, int>> total, times;
    UndergroundSystem() {
        start.clear(), total.clear(), times.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id] = { stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        total[start[id].first][stationName] += t - start[id].second;
        times[start[id].first][stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (total[startStation][endStation])/(double)(times[startStation][endStation]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */