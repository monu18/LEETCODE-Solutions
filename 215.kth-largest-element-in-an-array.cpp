/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
template <typename T>
class Minheap {
    vector<T> v;
    public:

    int size() {
        return v.size();
    }

    T top() {
        return v[0];
    }
    void insert(T val) {
        v.push_back(val);
        int i = v.size()-1;

        while(i>0 && v[i] < v[(i-1)/2]) {
            swap(v[i], v[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    void deleteMin() {
        if (v.empty()) return;

        v[0] = v.back();
        v.pop_back();
        heapifyDown(0);

    }
    void heapifyDown(int i) {
        int n = v.size();

        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && v[left] < v[smallest])
                smallest = left;

            if (right < n && v[right] < v[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(v[i], v[smallest]);
            i = smallest;
        }
    }
    void buildHeap(vector<T>& arr) {
    v = arr;             
    int n = v.size();

    // start from last non-leaf node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Minheap<int> h;

        for (int num : nums) {
            h.insert(num);

            if (h.size() > k) {
                h.deleteMin();
            }
        }

        return h.top();

    }
};
// @lc code=end

