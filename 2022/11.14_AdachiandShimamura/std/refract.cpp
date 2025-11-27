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
#define debug(...) fprintf(stderr, __VA_ARGS__)

template <typename T> bool chkmax(T& a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> bool chkmin(T& a, T b) { return a > b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f;


template <typename T> T read(T& x) {
    int f = 1; x = 0;
    char ch = getchar();
    for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x *= f;
}

const int N = 6000;
const int mo = 1e9 + 7;

pii p[N + 5];
int dp[N + 5][2], n;

int main() {
    freopen("refract.in", "r", stdin);
    freopen("refract.out", "w", stdout);

    read(n);
    for(int i = 1; i <= n; i++) {
        read(p[i].fst), read(p[i].snd);
    }
    sort(p + 1, p + n + 1);

    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1;
        for(int j = i-1; j >= 1; j--) {
            if(p[j].snd > p[i].snd) {
                (dp[j][1] += dp[i][0]) %= mo;
            }else {
                (dp[i][0] += dp[j][1]) %= mo;
            }
        }
    }

    int ans = mo - n;
    for(int i = 1; i <= n; i++) ans = ((ans + dp[i][0]) % mo + dp[i][1]) % mo;
    printf("%d\n", ans);

    return 0;
}
