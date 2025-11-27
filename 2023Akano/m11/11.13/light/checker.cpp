#include "testlib.h"
using namespace std;
using LL = long long;

const int N = 1e6 + 10;

int T;
int n, m;
vector<int> room[N];
int a[N << 1], b[N], r[N << 1];
bool Ans[N];

int main(int argc, char **argv) {
	registerTestlibCmd(argc, argv);
	T = inf.readInt();
	bool flag1 = true, flag2 = true;
	while (T--) {
		int n = inf.readInt(), m = inf.readInt();
		for (int i = 1; i <= m; ++i) room[i].clear();
		for (int i = 1; i <= 2 * n; ++i) a[i] = inf.readInt();
		for (int i = 1; i <= n; ++i) b[i] = inf.readInt();
		for (int i = 1; i <= 2 * n; ++i) r[i] = inf.readInt();
		string s = ouf.readToken();
		string t = ans.readToken();
		if (s != t) flag1 = false;
		else {
			if (s == "Yes") {
				for (int i = 1; i <= n; ++i) {
					Ans[i] = ouf.readInt();
					if (Ans[i] < 0 || Ans[i] > 1) quitf(_wa, "");
				}
				for (int i = 1; i <= n; ++i) if (b[i] && Ans[i]) a[i] ^= 1, a[i + n] ^= 1;
				for (int i = 1; i <= 2 * n; ++i) room[r[i]].push_back(i);
				for (int i = 1; i <= m; ++i) {
					int mn = 1, mx = 0;
					for (auto &v: room[i]) mn = min(mn, a[v]), mx = max(mx, a[v]);
					if (mn == mx) flag2 = false;
				}
			}
		}
	}
	if (!flag1) quitf(_wa, "");
	else if (!flag2) quitp(40, "");
	else quitf(_ok, "");
	return 0;
}
