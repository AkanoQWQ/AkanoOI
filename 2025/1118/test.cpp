#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 1018 + 1108;

int arr[MAXN],n;
class SegmentTree{
private:
    struct Node{
        int lazyTag,val;
    };
    Node node[MAXN * 4];
    void Pushup(int p){
        node[p].val = node[p*2].val + node[p*2+1].val;
        return ;
    }
    void Pushdown(int p){
        node[p*2].val += node[p].lazyTag;
        node[p*2+1].val += node[p].lazyTag;
        node[p].lazyTag = 0;
        return ;
    }
    void Build(int p,int l,int r){
        if(l == r){
            node[p].val = arr[l];
            return ;
        }
        const int mid = (l + r) >> 1;
        Build(p*2,l,mid);
        Build(p*2+1,mid+1,r);
        Pushup(p);
        return ;
    }

public:
    void Build(){

        return ;
    }
};

int main(){

    return 0;
}