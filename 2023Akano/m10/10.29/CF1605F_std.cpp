#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 105;

int t, n, k, MOD, modinv[maxn], fact[maxn], invfact[maxn], cnt_distinct_positive[maxn][maxn], cnt_total[maxn][maxn], cnt_bad[maxn][maxn], pow2[maxn * maxn];
// cnt_distinct_positive[i][j] = ways of choosing i distinct positive values with a combined of exactly j bits on.
// cnt_total[i][j] = total number of arrays of length i with exactly j bits on in total
// cnt_bad[i][j] = number of bad arrays of length i with exactly j bits on in total

int mod_expo(int x, int p)
{
	if(!p)
		return 1;
	int res = mod_expo(x, p / 2);
	res *= res;
	res %= MOD;
	if(p & 1)
		res *= x;
	return res % MOD;
}

int mod_inv(int x)
{
	return mod_expo(x, MOD - 2);
}

// O(1) with O(n) precalc needed
int fast_nCr(int x, int r)
{
	assert(x < maxn && r >= 0 && r <= x);
	int num = fact[x];
	int denom = (invfact[r] * invfact[x - r]) % MOD;
	return (num * denom) % MOD;
}

// O(x - r)
int slow_nPr(int x, int r)
{
	assert(r >= 0 && r < maxn);
	int res = 1;
	for(int j = 1; j <= r; j++)
	{
		res *= (x - j + 1 + MOD) % MOD;
		res %= MOD;
	}
	return res;
}

int32_t main(){
	freopen("CF1605F.in","r",stdin);
	cin >> n >> k >> MOD;
	fact[0] = invfact[0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		modinv[i] = mod_inv(i);
		fact[i] = (fact[i - 1] * i) % MOD;
		invfact[i] = mod_inv(fact[i]);
	}
	pow2[0] = 1;
	for(int i = 1; i <= n * k; i++)
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			// The number of ways of selecting i distinct positive values with upto j bits set in total
			cnt_distinct_positive[i][j] = slow_nPr((mod_expo(2, j) - 1 + MOD) % MOD, i);
			// The number of ways of selecting i non-negative values with upto j bits set
			cnt_total[i][j] = pow2[i * j];
			// Inclusion exclusion to get the count for exactly j bits for both values.
			for(int l = 0; l < j; l++)
			{
				cnt_distinct_positive[i][j] += (MOD - ((fast_nCr(j, l) * cnt_distinct_positive[i][l])) % MOD);
				cnt_distinct_positive[i][j] %= MOD;
				cnt_total[i][j] += (MOD - ((fast_nCr(j, l) * cnt_total[i][l])) % MOD);
				cnt_total[i][j] %= MOD;
			}
		}
	}
	// An empty array is good.
	cnt_total[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
		{
			cnt_bad[i][j] = 0;
			// i' <=> a, j' <=> b
			for(int a = 0; a < i; a++)
				for(int b = 0; b < j; b++)
				{
					printf("res[%lld,%lld] = %lld\n",a,b,(cnt_total[a][b] - cnt_bad[a][b] + MOD) % MOD);
					// The only case where this incorrect addition of "bad" arrays of size $$$i$$$ occurs is when we consider good 
					// arrays of size $$$i - 1$$$ for odd $$$i$$$ during this process. So while calculating the answer for $$$n$$$ in the 
					// problem we just have to skip good arrays of size $$$n - 1$$$ if $$$n$$$ is odd. 
					if(i == n && (n & 1) && a == i - 1){
						cerr<<i<<","<<j<<","<<a<<","<<b<<" ret0"<<endl;
						continue;
					}
					// f(i, j, i', j')
					int cur_bad = 1;
					// The number of ways of good arrays of length $$$i'$$$ distinct positive values with exactly $$$j'$$$ bits set in total:
					cur_bad *= (cnt_total[a][b] - cnt_bad[a][b] + MOD) % MOD;
					cur_bad %= MOD;
					// The number of ways of selecting $$$i - i'$$$ distinct positive values with exactly $$$j - j'$$$ bits set in total. 
					cur_bad *= cnt_distinct_positive[i - a][j - b];
					cur_bad %= MOD;
					// The number of ways of distributing the $$$i - i'$$$ values among the existing good array of length $$$i'$$$:
					cur_bad *= fast_nCr(i, a);
					cur_bad %= MOD;
					// The number of ways of choosing which $$$j'$$$ of the $$$j$$$ bits were from the good array.
					cur_bad *= fast_nCr(j, b);
					cur_bad %= MOD;
					// The number of ways of choosing the remaining $$$j'$$$ bits of each of the $$$i - i'$$$ distinct values.
					cur_bad *= pow2[(i - a) * b];
					cur_bad %= MOD;
					cnt_bad[i][j] += cur_bad;
//					cerr<<i<<","<<j<<","<<a<<","<<b<<" poss "<<cur_bad<<endl;
					cnt_bad[i][j] %= MOD;
				}
		}
	int ans = 0;
	for(int j = 0; j <= k; j++)
	{
		int cnt_good = (cnt_total[n][j] - cnt_bad[n][j] + MOD) % MOD;
		// The number of ways of choosing the j bits from the k total bits.
		ans += (fast_nCr(k, j) * cnt_good) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
