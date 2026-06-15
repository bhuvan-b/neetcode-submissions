class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cnt=0;
    MedianFinder() {
        max_heap=priority_queue<int>();
        min_heap=priority_queue<int, vector<int>, greater<int>>();
        cnt=0;
    }
    
    void addNum(int num) {
        if(min_heap.empty())
        {
            min_heap.push(num);
            cnt++;
            return;
        }
        if(num>min_heap.top())
        {
            min_heap.push(num);
            cout << 1 << " " << num << " " << min_heap.size() << endl;
            cout << "min_heap: " << min_heap.size() << endl;
            cout << "max_heap: " << max_heap.size() << endl;
        }
        else
        {
            max_heap.push(num);
            cout << 2 << " " << num << " " << min_heap.size() << endl;
            cout << "min_heap: " << min_heap.size() << endl;
            cout << "max_heap: " << max_heap.size() << endl;
        }
        int mxs = max_heap.size(), mns = min_heap.size();
        if((mxs-mns)>1)
        {
            cout << "here" << endl;
            int el = max_heap.top();
            max_heap.pop();
            min_heap.push(el);
        }
        else if((mns-mxs)>1)
        {
            cout << "here2" << endl;
            int el = min_heap.top();
            min_heap.pop();
            max_heap.push(el);
        }
        cnt++;
    }
    
    double findMedian() {
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

// 1 3 5 6 7 9 10

// 3 5 1 6 9 10 7

// max_heap    min_heap
// 3           5
// 1 3         5
// 1 3         5 6
// 1 3 9       5 6

// element > max_hp && element < min_hp -> add to the one with less elements
// el < max_hp && el < min_hp -> add to max_heap tree
// el > max_hp && el > min_hp -> add to min_heap tree

// -1 -2 -3 -4 -5


// max_heap                min_heap
//                         -1
// -2                      -1
// -3 -2                   -1
// -4 -3                   -2 -1                        