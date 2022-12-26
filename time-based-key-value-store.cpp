class TimeMap {
    unordered_map<string, vector<pair<int, string>>> db;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(db[key].begin(), db[key].end(), timestamp, [](int t, const auto& p) {
            return t < p.first;
        });
        return it != db[key].begin() ? prev(it)->second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
