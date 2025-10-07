/* 
Implementing a Disjoint Set Union (Union-Find) data structure with:
Path compression in find (ultimateParent)
Union by size in unionBySize

Why use this:
Efficiently groups elements into disjoint sets and checks whether two elements
belong to the same set.
- With path compression + union by size, operations are nearly constant time:
amortized O(alpha(N)) where alpha is inverse Ackermann function.

Abrevation Used :
* up - Ultimate Parent 
* u - node 1
* v - node 2
* up_u - Ultimate Parent of node 1
* up_v - Ultimate Parent of node 2
*/

#include <bits/stdc++.h>
using namespace std;

class DisjoinSet{
private:   
    //Declaring 2 vectors to store parent of each node, and size of the ultimate parents.
    vector<int>parent;
    vector<int>size;

public:
    DisjoinSet(int n) {
        //Resizing vectors and marking as their own parent initialy, with self size of comp intitialy as 1.
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        size.resize(n,1);
    }

    //Path compression, make point each node to ultimate parent in node's comp. Which helps us to boil down TC.
    int ultimateParent(int value) {
        if(value == parent[value]) return value;
        return parent[value] = ultimateParent(parent[value]);
    }

    /* Union by size checks and connects lower size comp with higher size to keep height min as much as we can.
    If size is same we can connect any comp bw two. 2nd and 3rd condition can we done together too, for better understanding
    i have kept condition separate. */
    void unionBySize(int u, int v) {
        int up_u = ultimateParent(u);
        int up_v = ultimateParent(v);

        if(up_u == up_v) return;

        if(size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

        else if(size[up_v] < size[up_u]) {
            parent[up_v]=up_u;
            size[up_u] += size[up_v];
        }

        else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }

    }
};

int main() {

    //You can run your own test cases too.
    //Creating Object of DisjointSet class, constructor resize based on the size of Object.
    DisjoinSet ds(7);
    ds.unionBySize(0,1);
    ds.unionBySize(1,3);
    ds.unionBySize(2,4);

    //Before union checking 4,3 whether they belong to same comp or not.
    if(ds.ultimateParent(4) == ds.ultimateParent(3) ) {
        cout<<"4 and 3 belongs to Same Component \n";
    }   

    else {
        cout<<"4 and 3 doesn't belongs to Same Component \n";
    }

    ds.unionBySize(4,3);

    //After union again checking whether 4,3 belong to same comp or not.
    if(ds.ultimateParent(4) == ds.ultimateParent(3) ) {
        cout<<"4 and 3 belongs to Same Component \n";
    }   

    else {
        cout<<"4 and 3 doesn't belongs to Same Component \n";
    }

    return 0;
}