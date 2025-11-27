/* This is sample grader for the contestant */
#include "flea.h"
#include <stdio.h>
#include <assert.h>

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define MaxN 1000

static int n, m;
static long long ca[MaxN];
static long long cb[MaxN];
static long long cc[MaxN];
static long long tot_get;

void get(int k, long long *a, long long *b, long long *c)
{
	long long fx = 9223372036854775807ll;
	int i;
	tot_get++;
	if (1 > k || k > m)
		return;
	for (i = 0; i < n; i++)
	{
		long long val = ca[i] * k * k + cb[i] * k + cc[i];
		if (val < fx)
		{
			fx = val;
			*a = ca[i];
			*b = cb[i];
			*c = cc[i];
		}
	}
}

int main()
{
	int i;
	assert(scanf("%d %d", &n, &m) == 2);
	for (i = 0; i < n; i++)
		assert(scanf(I64 " " I64 " " I64, &ca[i], &cb[i], &cc[i]) == 3);

	tot_get = 0;
	long long res = find_max(n, m);
	printf(I64 " " I64 "\n", res, tot_get);

	return 0;
}
