#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef long long LL;
const int N = 3e5 + 5, M = 1e6 + 35;
int n, a[N], pre[N], nex[N]; LL cur;
vi p[M];
list <pi> seg[N];//某一个段的所有极大区间的集合,下标为段的左端点 
LL sum(int l, int r) {
    return 1LL * (l + r) * (r - l + 1) / 2;
}
LL calc(list <pi> L) {										//?没看懂? 
    LL ret = 0;
    for (auto it = L.begin(); it != L.end(); it++) {
        auto [x, y] = *it;
        if (next(it) == L.end()) {
            ret += sum(1, y - x);
            break;
        } else {
            int nx = next(it) -> fi;
            ret += 1LL * (nx - x) * y - sum(x, nx - 1);
        }
    }
    return ret;
}
void upd(list <pi> &L) {									//没看懂? 
    if (L.size() <= 1) 
        return;
    cur += calc(L);//差值计算贡献 
    int mx = -1;
    list <pi> nL;
    auto it = L.begin();
    for (auto [x, y] : L) {
        while (next(it) != L.end() && next(it) -> fi <= y)
            it++;
        if (it -> se > mx) {
            nL.push_back({x, mx = it -> se});
        }
    }
    swap(L, nL);
    cur -= calc(L);//注意这个地方的贡献是负的,所以才是加上原来的贡献再减掉新的贡献 
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]].push_back(i);//为后面更新 a_i = v 做准备 
    }
    cur = 1LL * n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) 
        pre[i] = nex[i] = i;//用于存储段的链表,为什么初值是自己?还是说它表示的是一个范围? 
    LL ans = 0;
    vi q;
    for (int v = 1; cur > 0; v++) {
        ans += cur;
        vi nq;
        for (auto l : q) {
            upd(seg[l]);
            if (seg[l].size() > 1) nq.push_back(l);
        }
        for (auto i : p[v]) {
            int l = pre[i], r = nex[i + 1];
            bool add = seg[l].size() <= 1;
            nex[l] = r, pre[r] = l;//删除节点?合并节点? 
            seg[l].push_back({i, i + 1});
            cur--;
            seg[l].splice(seg[l].end(), seg[i + 1]);
            add &= seg[l].size() > 1;
            if (add) nq.push_back(l); 
        }
        swap(q, nq);
    }
    cout << ans << "\n";
    return 0;   
}
