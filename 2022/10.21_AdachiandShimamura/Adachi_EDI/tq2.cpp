#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1e5 + 5;
const int maxp = 1e2 + 5;

struct Cat
{
	int h, t;
	long long st;
	bool operator <(const Cat a) const
	{
		return st < a.st;
	}
} cats[maxn];

int n, m, p, q[maxn],tail, head;

long long f[maxn][maxp], sum[maxn], d[maxn];

signed main()
{
	freopen("gxytql.in","r",stdin);
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++)
	{
		cin >> d[i];
		d[i] += d[i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> cats[i].h >> cats[i].t;
		cats[i].st = cats[i].t - d[cats[i].h];
	}
	sort(cats + 1, cats + m + 1);
	for (int i = 1; i <= m; i++)
	{
		sum[i] = sum[i - 1] + cats[i].st;
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= p; i++)
	{
		tail = head = 1;
		q[head] = 0;
		for (int j = 1; j <= m; j++)
		{
			while (head < tail && f[q[head]][i - 1] + sum[q[head]] - cats[j].st * q[head] > f[q[head + 1]][i - 1] + sum[q[head + 1]] - cats[j].st * q[head + 1]) head++;
			cout<<j<<" choose "<<q[head]<<" "<<cats[j].st<<endl;
			f[j][i] = f[q[head]][i - 1] + cats[j].st * (j - q[head]) - (sum[j] - sum[q[head]]);
			cout<<i<<","<<j<<":"<<f[j][i]<<endl;
			while (tail > head && (f[j][i - 1] + sum[j] - f[q[tail]][i - 1] - sum[q[tail]]) * (q[tail] - q[tail - 1]) < (f[q[tail]][i - 1] + sum[q[tail]] - f[q[tail - 1]][i - 1] - sum[q[tail - 1]]) * (j - q[tail]))
				tail--;
			tail++;
			q[tail] = j;
			cout<<"END WITH "<<head<<" and "<<tail<<endl;
		}
	}
	printf("%lld\n", f[m][p]);
	return 0;
}
