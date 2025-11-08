#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void build(int idx, int low, int high, vector<int>& arr) {
    if (low == high) {                   // leaf node → single element
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*idx+1, low, mid, arr);       // build left child
    build(2*idx+2, mid+1, high, arr);    // build right child
    seg[idx] = seg[2*idx+1] + seg[2*idx+2]; // merge result (sum)
}

int query(int idx, int low, int high, int l, int r) {
    if (r < low || high < l) return 0;         // no overlap
    if (l <= low && high <= r) return seg[idx]; // full overlap
    int mid = (low + high) / 2;
    int left = query(2*idx+1, low, mid, l, r);
    int right = query(2*idx+2, mid+1, high, l, r);
    return left + right;                        // merge results
}

void update(int idx, int low, int high, int i, int val) {
    if (low == high) {                 // leaf node → update value
        seg[idx] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (i <= mid) update(2*idx+1, low, mid, i, val);
    else update(2*idx+2, mid+1, high, i, val);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];  // re-calc after update
}

int main() {
    vector<int> arr = {1, 3, 2, 7, 9, 11};
    int n = arr.size();
    seg.resize(4*n);                  // allocate enough memory
    build(0, 0, n-1, arr);

    cout << "Sum [1, 3]: " << query(0, 0, n-1, 1, 3) << endl;
    update(0, 0, n-1, 2, 10);
    cout << "After update, Sum [1, 3]: " << query(0, 0, n-1, 1, 3) << endl;
}
