// TODO: O(n^2)

// nlog(n)
// 1 2 3 5 10 2 -1 100 500
// 1 2 3 5 10 100 500
int lis(vi& v) {
    if (v.size() == 0) // boundary case
        return 0;
 
    vi tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto start = tail.begin(), end = tail.begin() + length;
        auto it = lower_bound(start, end, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}
 

// Also LIS with Segment Tree
