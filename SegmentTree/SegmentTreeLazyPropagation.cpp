#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void build(vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply pending update to this node
            tree[node] += (end - start + 1) * lazy[node];

            // Propagate laziness to children if not a leaf
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0; // Clear lazy tag after pushing
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        pushDown(node, start, end); // Handle any pending updates first

        if (start > r || end < l)
            return; // no overlap

        if (l <= start && end <= r) {
            // Current segment fully inside range
            tree[node] += (end - start + 1) * val;
            if (start != end) { // mark children lazy
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        pushDown(node, start, end); // Handle pending updates

        if (start > r || end < l)
            return 0; // no overlap

        if (l <= start && end <= r)
            return tree[node]; // total overlap

        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) +
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }

    void printTree() {
        cout << "\nTree: ";
        for (int i = 1; i < 2 * n; i++) cout << tree[i] << " ";
        cout << "\nLazy: ";
        for (int i = 1; i < 2 * n; i++) cout << lazy[i] << " ";
        cout << "\n";
    }
};

int main() {
    vector<int> arr = {0, 0, 0, 0, 0, 0}; // initial array
    SegmentTree st(arr);

    cout << "Initial build complete.\n";
    st.printTree();

    cout << "\nUpdate(1,3,+2)\n";
    st.update(1, 3, 2);
    st.printTree();

    cout << "Query(0,3): " << st.query(0, 3) << "\n";

    cout << "\nUpdate(2,5,+1)\n";
    st.update(2, 5, 1);
    st.printTree();

    cout << "Query(3,5): " << st.query(3, 5) << "\n";

    return 0;
}
