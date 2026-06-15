class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        max_heap=priority_queue<int>();
        min_heap=priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        if(min_heap.empty())
        {
            min_heap.push(num);
            return;
        }
        if(num>min_heap.top())
        {
            min_heap.push(num);
        }
        else
        {
            max_heap.push(num);
        }
        int mxs = max_heap.size(), mns = min_heap.size();
        if((mxs-mns)>1)
        {
            int el = max_heap.top();
            max_heap.pop();
            min_heap.push(el);
        }
        else if((mns-mxs)>1)
        {
            int el = min_heap.top();
            min_heap.pop();
            max_heap.push(el);
        }
    }
    
    double findMedian() {
        int cnt = min_heap.size()+max_heap.size();
        if(cnt%2==0)
        {
            return (min_heap.top()+max_heap.top())/2.0;
        }
        else
        {
            if((int)min_heap.size()>(int)max_heap.size())
                return min_heap.top();
            return max_heap.top();
        }
    }
};
