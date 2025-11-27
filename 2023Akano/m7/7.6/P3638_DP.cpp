#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
const int N = 502, inf = 0x3f3f3f3f;
const int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
int T, n, m, f[10][10][N][N], L_, R_;
char mp[N][N];
pr a[N], mem[N][N][4], gto[N][N][4];
bool vis[N][N][4], used[N][N];
pr dfs(int x, int y, int k) {
    if (mem[x][y][k].first >= 0)
        return mem[x][y][k];
    if (vis[x][y][k])
        return mem[x][y][k] = pr(0, 0);
    vis[x][y][k] = 1;

    int k_ = (mp[x][y] == 'A') ? (k + 1) % 4 : ((mp[x][y] == 'C') ? (k + 3) % 4 : k);
    int x_ = x + dx[k_], y_ = y + dy[k_];
    if (x_ < 1 || x_ > m || y_ < 1 || y_ > n || mp[x_][y_] == 'x')
        mem[x][y][k] = pr(x, y);
    else
        mem[x][y][k] = dfs(x_, y_, k_);
    vis[x][y][k] = 0;
    return mem[x][y][k];
}
class Pair_Queue {
protected:
    int head, tail, tms[N * N], st, ed;
    pr q[N * N], cts[N * N];

public:
    void init() { memset(tms, 0, sizeof tms); }
    inline void reset() { head = 1, tail = 0; }
    inline bool empty() { return tail < head; }
    inline void push(int k, int h) { q[++tail] = pr(k, h); }
    inline pr front() { return q[head]; }
    inline void pop() { head++; }
#define dis(k) (f[L_][R_][(k).first][(k).second])
    inline void countsort() {
        st = inf, ed = 0;
        for (int i = head, val; val = dis(q[i]), i <= tail; i++)
            cts[i] = q[i], st = min(st, val), ed = max(ed, val), tms[val]++;
        for (int i = st + 1; i <= ed; i++) tms[i] += tms[i - 1];
        for (int i = head; i <= tail; i++) q[tms[dis(cts[i])]--] = cts[i];
        for (int i = st; i <= ed; i++) tms[i] = 0;
    }
#undef dis
} q1, q2;
void bfs(int l, int r) {
    q1.reset(), q2.reset(), L_ = l, R_ = r;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (f[l][r][i][j] < inf)
                q1.push(i, j);
    if (q1.empty())
        return;
    memset(used, 0, sizeof used), q1.countsort();
    pr u;
#define dis(k) (f[l][r][(k).first][(k).second])
#define use(k) (used[(k).first][(k).second])
    for (int x, y, x_, y_; !q1.empty() || !q2.empty();) {
        if (q1.empty())
            u = q2.front(), q2.pop();
        else if (q2.empty())
            u = q1.front(), q1.pop();
        else if (dis(q1.front()) < dis(q2.front()))
            u = q1.front(), q1.pop();
        else
            u = q2.front(), q2.pop();
        x = u.first, y = u.second, used[x][y] = 1;
        for (int o = 0; o < 4; o++) {
            x_ = gto[x][y][o].first, y_ = gto[x][y][o].second;
            if (!(x_ < 1 || x_ > m || y_ < 1 || y_ > n || mp[x_][y_] == 'x') &&
                f[l][r][x][y] + 1 < f[l][r][x_][y_])
                f[l][r][x_][y_] = f[l][r][x][y] + 1, used[x_][y_] = 1, q2.push(x_, y_);
        }
        while (!q1.empty() && use(q1.front())) q1.pop();
    }
}
int main() {
	freopen("P3638.in","r",stdin);
	freopen("P3638.ans","w",stdout);
    memset(mem, -1, sizeof(mem));
    scanf("%d%d%d", &T, &n, &m), memset(f, 0x3f, sizeof f), q1.init(), q2.init();
    char ch = getchar();
    for (int i = 1, k; i <= m; i++) {
        while (!(('0' <= ch && ch <= '9') || ch == '.' || ch == 'x' || ch == 'A' || ch == 'C'))
            ch = getchar();
        for (int j = 1; j <= n; j++) {
            mp[i][j] = ch, ch = getchar();
            if ('0' <= mp[i][j] && mp[i][j] <= '9')
                a[k = mp[i][j] - '0'] = pr(i, j), f[k][k][i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j] != 'x')
                for (int k = 0; k < 4; k++) gto[i][j][k] = dfs(i, j, k);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j] != 'x'){
            	cout<<"("<<i<<","<<j<<") goto "<<"("<<gto[i][j][0].first<<","<<gto[i][j][0].second<<")"<<endl;
            	cout<<"("<<i<<","<<j<<") goto "<<"("<<gto[i][j][3].first<<","<<gto[i][j][3].second<<")"<<endl;
            	cout<<"("<<i<<","<<j<<") goto "<<"("<<gto[i][j][2].first<<","<<gto[i][j][2].second<<")"<<endl;
            	cout<<"("<<i<<","<<j<<") goto "<<"("<<gto[i][j][1].first<<","<<gto[i][j][1].second<<")"<<endl;
			}
                
    for (int len = 1; len <= T; len++)
        for (int l, r = T; l = r - len + 1, l; r--) {
            for (int mid = l; mid < r; mid++)
                for (int x = 1; x <= m; x++)
                    for (int y = 1; y <= n; y++)
                        f[l][r][x][y] = min(f[l][r][x][y], f[l][mid][x][y] + f[mid + 1][r][x][y]);
            bfs(l, r);
        }
    int ans = inf;
    for (int x = 1; x <= m; x++)
        for (int y = 1; y <= n; y++) ans = min(ans, f[1][T][x][y]);
    printf("%d\n", ans < inf ? ans : -1);
    return 0;
}
