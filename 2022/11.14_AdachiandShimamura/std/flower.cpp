#include <bits/stdc++.h>

using std::pair;
using std::vector;
using std::string;

typedef long long ll;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define pb(a) push_back(a)
#define mp(a, b) std::make_pair(a, b)

template <typename T> bool chkmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> bool chkmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;

string procStatus() {
    std::ifstream t("/proc/self/status");
    return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}

template <typename T> T read(T& x) {
    int f = 1; x = 0;
    char ch = getchar();
    for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x *= f;
}

const int B = 1000;
const int N = 100000;

int n, q;
int a[N + 5];
int lst[N + 5];
int ans[105][N + 5];

int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);

    read(n); read(q);
    for(int i = 0; i < n; ++i) read(a[i]);

    int blks = (n-1) / B + 1;
    for(int i = 0; i < blks; ++i) {
        memset(lst, 0, sizeof lst);
        for(int j = i * B; j < (i+1) * B && j < n; ++j) lst[a[j]] = a[j];
        for(int j = 1; j <= N; ++j) chkmax(lst[j], lst[j-1]);//lst存的是小于等于当前下表的最大的数 
        for(int j = 1; j <= N; ++j) for(int k = 0; k <= N; k += j) chkmax(ans[i][j], lst[std::min(k + j - 1, N)] - k);
    }

    while(q--) {
        static int l, r, k;
        read(l), read(r), read(k);

        -- l, -- r;
        int x = (l / B) + 1, y = (r / B), res = 0;

        if(x == y + 1) {
            for(int i = l; i <= r; ++i) chkmax(res, a[i] % k);
        } else {
            for(int i = x; i < y; ++i) chkmax(res, ans[i][k]);
            for(int i = l; i < x*B; ++i) chkmax(res, a[i] % k);
            for(int i = r; i >=y*B; --i) chkmax(res, a[i] % k);
        }

        printf("%d\n", res);
    }

    return 0;
}
