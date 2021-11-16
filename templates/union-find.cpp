#include<iostream>
#include<vector>
using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> size;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        size.resize(maxSize);
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main(){

    int n =10;
    DisjointSet S(n);  // Initializing with maximum Size
    S.union_set(1, 2);
    S.union_set(3, 7);
    int parent = S.find_set(10);  // root of 1
    cout<<parent<<endl;
}