class LRUCache {
    using List = list<pair<int, int>>;
    int m_capacity;
    List m_list;
    unordered_map<int, List::iterator> m_map;
public:
    LRUCache(int capacity): m_capacity(capacity) {
        
    }
    
    int get(int key) {
        auto map_it = m_map.find(key);
        if (map_it == m_map.end()) {
            return -1;
        }
        auto list_it = map_it->second;
        m_list.splice(m_list.begin(), m_list, list_it);
        return list_it->second;
    }
    
    void put(int key, int value) {
        auto map_it = m_map.find(key);
        if (map_it != m_map.end()) {
            auto list_it = map_it->second;
            list_it->second = value;
            m_list.splice(m_list.begin(), m_list, list_it);
        } else {
            m_list.push_front({key, value});
            if (m_capacity == 0) {
                m_map.erase(m_list.back().first);
                m_list.pop_back();
            } else {
                m_capacity--;
            }
        }
        m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
