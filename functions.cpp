#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

string strSlice(string s, int start, int end) {
    int l = s.length();
    string ans = "";

    if (end == -1)
        end = s.length();

    if (start < 0 || start >= l)
        return ans;

    if (end <= start || end > l)
        return ans;

    for (int i=start; i<end; i++)
        ans += s[i];

    return ans;
}

// Greatest Triangular Number Less than or equal to
int greatestTriLE(int s) {
    int k = ceil(sqrt(2 * s));
    while (k*(k+1) > 2*s)
        k--;
    return k;
}

template <class T>
vi getFreqs(T a[], int n) {
    sort(a, a+n);  // Sort
    vi freqs;

    int currFreq = 1;
    T currEle = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] == currEle)
            currFreq++;
        else {
            freqs.push_back(currFreq);
            currFreq = 1;
            currEle = a[i];
        }
    }
    freqs.push_back(currFreq);
    return freqs;
}

int maxFreq(int a[], int n) {
    vi freqs = getFreqs(a, n);
    sort(freqs.begin(), freqs.end());
    return freqs[freqs.size()-1];
}

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

/** Bitwise Functions <br>
 *
 * n >> d  --> Right shift d times (Divide by 2^d) <br>
 * n & 1  --> Last digit <br>
 * (n>>d) << d  --> Make the last d digits zeros <br>
 * n % ((n>>d) << d)  --> Get the last d digits <br>
 *
 */


// Number Theory
template <class T>
T phi(T n) {
    if (n == 1)
        return 0;
    T ans = 1;
    T mult;
    T curr;
    for (curr = 2; curr*curr <= n; curr++) {
        if (n%curr != 0)
            continue;

        // n divides curr
        mult = 1;
        while (n > 0 && n%curr == 0) {
            mult *= curr;
            n /= curr;
        }
        ans *= (mult - mult/curr);
    }
    // If n > 0 then it is some prime p
    if (n > 1)
        ans *= (n-1);

    return ans;
}


//int maxDistance() {
//    int maxDistance = 0;
//
//    queue<int> q;
//    q.push(1);
//    while (!q.empty()) {
//        int vert = q.front();
//        q.pop();
//
//        for (int v: edgesFrom[vert]) {
//            distance[v] = min(distance[v], distance[parent[v]]+1);
//            if (distance[v] > maxDistance)
//                maxDistance = distance[v];
//            q.push(v);
//        }
//    }
//}

