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

const int N = 50;

int n, m;
char g[N + 5][N + 5];
int dis[N + 5][N + 5];

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int bfs(int x, int y) {
    std::deque<pii> q;
    memset(dis, -1, sizeof dis);

    dis[x][y] = 0;
    q.push_back(mp(x, y));

    int res = 0;
    while(!q.empty()) {
        int cx = q.front().fst, cy = q.front().snd;

        if(g[cx][cy] == '1')
            chkmax(res, dis[cx][cy]);

        q.pop_front();
        for(int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] == -1) {

                if(g[nx][ny] == g[cx][cy]) {
                    dis[nx][ny] = dis[cx][cy];
                    q.push_front(mp(nx, ny));
                } else {
                    dis[nx][ny] = dis[cx][cy] + 1;
                    q.push_back(mp(nx, ny));
                }
            }
        }
    }
    return res;
}

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    read(n), read(m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", g[i]);
    }

    int ans = oo;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            chkmin(ans, bfs(i, j));
        }
    }
    printf("%d\n", ans + 1);

    return 0;
}
