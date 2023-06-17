#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define inf INT_MAX

struct MaxHeap {
    int *heap;
    int heapSize;
    int arraySize;

    static int getLeft(int index) { return 2*index + 1; }
    static int getRight(int index) { return 2*index + 2; }
    static int getParent(int index) { return (index-1) / 2; }

    bool empty() const { return heapSize == 0; }
    bool hasLeft(int index) const { return getLeft(index) < heapSize; }
    bool hasRight(int index) const { return getRight(index) < heapSize; }

    static bool compare(int a, int b) { return a > b; }

    void swap(int i, int j) const {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void heapifyUp(int index) {
        if (index == 0)
            return;
        int parent = getParent(index);
        if (compare(heap[index], heap[parent])) {
            swap(parent, index);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index=0) {
        if (index >= heapSize)
            return;

        int left = getLeft(index);
        int right = getRight(index);
        int maxEle = index;

        if (hasLeft(index) && compare(heap[left], heap[maxEle]))
            maxEle = left;
        if (hasRight(index) && compare(heap[right], heap[maxEle]))
            maxEle = right;
        if (maxEle != index) {
            swap(index, maxEle);
            heapifyDown(maxEle);
        }
    }

    explicit MaxHeap(int size) {
        arraySize = size;
        heap = new int[size];
        heapSize = 0;
    }

    void push(int data) {
        if(heapSize == arraySize)
            return;
        heap[heapSize] = data;
        heapifyUp(heapSize++);
    }

    int peek() const {
        if (heapSize > 0) return heap[0];
        return 0;
    }

    int pop(int index=0) {
        if (heapSize == 0 || index < 0 || index >= heapSize)
            return -1;
        int retInt = heap[index];
        heap[index] = heap[--heapSize];
        heapifyDown(index);
        return retInt;
    }

    ~MaxHeap() { delete [] heap; }
};


void solve()
{
    int n;
    cin >> n;

    // Code starts here
    // We have n vertices 1 is the root
    vi edgesFrom[n+1];
    int parent[n+1];
    int distance[n+1];
    for (int i=2; i<=n; i++)
        distance[i] = inf;
    distance[1] = 0;

    int temp;
    for (int i=2; i<=n; i++) {
        cin >> temp;
        parent[i] = temp;
        edgesFrom[temp].push_back(i);
    }

    vi groups;
    groups.push_back(1);
    for (int i=1; i<=n; i++) {
        if (edgesFrom[i].empty())
            continue;
        groups.push_back(edgesFrom[i].size());
    }
    sort(groups.begin(), groups.end());

    int ans = groups.size();
    vi a;
    for (int i=1; i<groups.size(); i++) {
        if (groups[i] > i+1)
            a.push_back(groups[i] - i - 1);
    }

    // Operate on a where they increase always

    MaxHeap heap(a.size());
    for(int i : a)
        heap.push(i);

    int turn = 0;
    while (!heap.empty() && heap.peek() > turn) {
        turn++;
        int x = heap.pop();
        x--;
        heap.push(x);
    }

    cout << ans+turn;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }

    return 0;
}
