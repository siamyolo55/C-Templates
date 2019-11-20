#include<bits/stdc++.h>
using namespace std;

int i,j;
int n,q,x,nv;
const int N = 1e5+8;
int data[N];
int tree[4*N];

void init(int node,int b,int e){
    if(b==e){
        tree[node] = data[b];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

void update(int node,int b,int e,int i){
    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[node] = nv; /// new value
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)>>1;
    if(i<=mid) update(left,b,mid,i);
    else update(right,mid+1,e,i);
    tree[node] = tree[left] + tree[right];
}

int query(int node,int b,int e){
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)>>1;
    int p1 = query(left,b,mid);
    int p2 = query(right,mid+1,e);
    return p1+p2;
}
