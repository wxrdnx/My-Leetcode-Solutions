class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m_db;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m_db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(m_db[key].begin(), m_db[key].end(), timestamp, [](int t, const auto& p) {
            return t < p.first;
        });
        return it != m_db[key].begin() ? prev(it)->second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
