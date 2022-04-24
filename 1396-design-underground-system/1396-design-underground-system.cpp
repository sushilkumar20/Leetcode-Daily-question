class UndergroundSystem {
public:
    
   map<int,pair<string,int>> checkin;
    map<string,map<string,pair<int,int>>>mp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto k=checkin[id];
        
        checkin.erase(id);
        
        mp[k.first][stationName].first += (t-k.second);
        mp[k.first][stationName].second ++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)mp[startStation][endStation].first/(double)mp[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */