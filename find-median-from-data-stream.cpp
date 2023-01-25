class MedianFinder {
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_heap.size() == max_heap.size()) {
            if (!max_heap.empty() && num < max_heap.top()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
        } else {
            if (!min_heap.empty() && num > min_heap.top()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            } else {
                max_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (min_heap.size() != max_heap.size()) {
            return min_heap.top();
        } else {
            return (static_cast<double>(min_heap.top() + max_heap.top())) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
