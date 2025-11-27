## 思路

虽然咱很喜欢随机化，但是没想到这题也能随机化啊（）。其实稍微想想容易清楚就是随机化。  

首先观察题目一个裸的二分，但是位置会随机移动。假设我们确定它所在区间的长度为   [katex]  len  [/katex]  ，那么我们每次二分可以使得区间长度减少   [katex]  \frac {len} 2  [/katex]  ，但是又会增加   [katex]  2 \times k  [/katex]  （他可能从左边走出区间或者右边走出区间，每次最多走出   [katex]  k  [/katex]   距离）  

那么当长度为   [katex]  4 \times k  [/katex]   的时候我们就卡死了，因为每次减少的长度为   [katex]  2 \times k  [/katex]  ，而增加的长度也是   [katex]  2 \times k  [/katex]  ，确定区间没有变。  

我们观察到这个   [katex]  k  [/katex]   实际上是非常小的，所以......自信随机化！每次当确定长度小于一个你定的值（这个地方有讲究，下面可以说一下）的时候，就随机选择区间中的一个值   [katex]  x  [/katex]   询问   [katex]  [x,x]  [/katex]  ，如果成功就结束程序，失败的话就继续二分（记得扩大区间   [katex]  2 \times k  [/katex]  ，因为执行了一次操作）直到区间长度小于我们定的值，继续随机化。  

依旧考虑正确性，假设   [katex]  n = 10 ^ {18},k = 10  [/katex]   并且使得区间长度为   [katex]  40  [/katex]  （最小可确定长度），最开始我们会花费   [katex]  60  [/katex]   次找到目标区间，然后每次有   [katex]  \frac 1 {40}  [/katex]   的概率猜对，如果失败我们会花费   [katex]  5  [/katex]   次重新把区间长度定位回   [katex]  40  [/katex]  ，所以我们保守（偏小）可以执行   [katex]  800  [/katex]   多次操作，错误率仅有   [katex]  2 \times 10^{-10}  [/katex]  ，可以忽略  

另外理论上最低长度是   [katex]  40  [/katex]  ，不过有更优秀的长度！根据以下程序，我们发现   [katex]  59  [/katex]   才是最优区间长度，错误率仅有   [katex]  2 \times 10 ^ {-33}  [/katex]  。  

```cpp
const int times = 4400;
inline double Solve(int minLen){
	int cnt = 0;
	double ans = 1;
	long long len = minLen + 20;
	while(len > minLen){
		len /= 2;
		len += 20;
		cnt++;
	}
	double poss = (double(minLen-1) / double(minLen));
	for(int i = 1;i &lt;= times / cnt;i++){
		ans *= poss;
	}
	return ans;
}
```  

这是因为从   [katex]  60  [/katex]   次变回   [katex]  40  [/katex]   次的代价太高，我们如果调整长度，虽然单次错误率（底数）会变大，但是尝试的次数（指数）也会变大，而指数的影响比起底数要大一点，所以如果这道题稍微卡一下的话可以列一个刚才的测试程序打表看看哪个长度更优（不过为了降低随机性，这种题目一般无论什么参数正确率都很高，理论上来讲正确做法的参数不太离谱都能过）  

## 代码

```cpp
#include&lt;bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll n,k;
mt19937_64 rng(time(0));
inline ll rd(ll l,ll r){
	return (rng() % (r - l + 1)) + l;
}
inline bool Get(ll l,ll r){
	cout&lt;&lt;l&lt;&lt;" "&lt;&lt;r&lt;&lt;endl;
	string res;
	cin>>res;
	if(res == "Yes"){
		if(l == r)exit(0);
		return true;
	}
	return false;
}
int main(){
	cin>>n>>k;
	ll l = 1,r = n+1;
	while(true){
		l -= k,r += k;
		l = max(l,1ll),r = min(r,n);
		while(l + 4 * k &lt; r){
			const ll mid = (l + r) >> 1;
			if(Get(l,mid)){
				r = mid;
			}else{
				l = mid + 1;
			}
			l -= k,r += k;
			l = max(l,1ll),r = min(r,n);
		}
		const ll now = rd(l,r);
		Get(now,now);
	}
	return not(Akano loves pure__Elysia);
}
```

~~励志打完所有交互题~~
