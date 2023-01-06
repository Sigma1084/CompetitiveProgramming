#include <bits/stdc++.h>
using namespace std;

class Node1 {
    int data;
};

class Node2:Node1 {
    using Node1::Node1;
};

class Container {
    typename Node = Node1;
};