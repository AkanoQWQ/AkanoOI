*ps:其实现在还不泉呢，差几个莫队ww*
## 简介

莫队问题的一般形式：给定一个序列，对 $l,r$ 区间进行询问。  

如果这个信息足够好维护且可合并，直接线段树就可以解决（甚至还可以带修），但是面对某些不是那么好维护或者无法在河里的时空复杂度内维护的信息就要使用莫队了（比如说颜色个数，每个线段树用桶来维护花费太大）  

## 暴力莫队
首先我们还是抛开时间复杂度的问题。对于 $q$ 个询问，我们**依次**解决（不排序）。  

这也就是说，我们已经求出了 $[l,r]$ 的答案和信息，需要接下来求 $[l',r']$ 的答案。显然我们一步步走，只要能求出 $[l \pm 1,r \pm 1]$ 就可以算出所有答案了。  

那么具体怎么做呢？这是按照题目而定的。例如上文提到的统计颜色个数（给定一个序列 $a$ ，询问 $l,r$ 之间有多少个不同的数），显然用一个桶来维护，那么扩展（`--l`,`++r`）就是往桶里加元素，收缩（`l++`,`r--`）就是往桶里减元素，当一个元素“无中生有”或者“化有为无”后当前答案就会相应加减一。然后就 OK 啦 (*￣︶￣)   

复杂度和指针 $l,r$ 的移动次数有关，因为单次移动是 $O(1)$ 的（桶的复杂度，如果是线段树之类的还要带上数据结构的复杂度），每个询问最多移动 $O(n)$ 次，所以复杂度 $O(nq)$ ，显然不可接受，需要优化。  

## 普通莫队
我们注意到容器的复杂度已经没法优化了（如果需要的话，可以把指针移动的询问离线下来，降低容器带来的复杂度，这是二次离线的内容），需要优化指针的移动次数。  

考虑把每次询问 $l,r$ 看做一个点，那么我们需要做的就是在二维平面上生成一颗曼哈顿距离最小生成树，这是一个可行的方案，但是没有必要。莫队采用了更加简洁的方式，对左端点分块，以左端点所在块为第一关键字，右端点为第二关键字。  

那么每次询问的移动，如果左端点和上一个左端点在同一块内，那么左端点移动距离最多为 $O(\sqrt n)$ （实际上是块长，现在取块长为 $\sqrt n$），右端点因为是单增的（作为第二关键字排序），单块的均摊复杂度是 $O(n)$ ；如果左端点和和上一个左端点不在同一个块内，就算泉部重新算也不过 $O(n)$ 。  

总结一下，（在 $n,q$ 同阶的情况下）对于右端点，从每块的角度来看，单块最多 $O(n)$，总共 $O(n \sqrt n)$；对于左端点，块内部每次 $O(\sqrt n)$ ，块间 $O(n)$，总共 $O(n \sqrt n)$。

## 莫队优化
首先块长并不是卡死 $\sqrt n$ 的。分析一下复杂度，实际应该是 $O(q \times b + \frac n b \times n)$ （$b$ 为块长），前者由块内移动贡献，后者由块间移动贡献（$\frac n b$ 就是块的数量）。在 $b = \frac n {\sqrt q}$ 的时候，复杂度最小，为 $O(n \sqrt q)$。所以说在 $n,q$ 不同阶的时候要调整块长。例如 $q = \sqrt n$ 的时候，应该取 $b = n ^ {\frac 3 4}$ 使得复杂度为 $O(n ^ {\frac 5 4})$  

理论最优块长也不一定是最好的！很多时候因为一些玄学问题（或者代码效率问题），在需要的情况下块长需要进行微调（根号内外乘上一个系数之类的）。或者算出来的最优块长不如一个随便的块长（带修莫队）。有时候，固定块长也是一个不错的选择。  

观察指针在块间的移动，在第一个块后右指针右移了很多，然而第二个块又要从最左边开始，会跨过整个序列移动右指针，这是非常不好的，我们可以通过一个叫做奇偶化排序的东西优化掉它，使得右指针实际上是来回刷而不是刷完了拉到左边再开始刷（实际上，这个模式有点像接下来的回滚莫队）  

```cpp
bool operator<(Query q1,Query q2){
	if(q1.blk != q2.blk)return q1.blk < q2.blk;
	if(q1.blk & 1){//按照奇偶安排右指针的排序方案
		return q1.r < q2.r;
	}else{
		return q1.r > q2.r;
	}
}
```

在莫队解决一些问题的时候，它可能会以某种规律反复访问数据结构的某些位置（虽然很玄学），通过一些同样玄学的办法（建立随机映射等）可能可以达到玄学的效果（不过一般来说不用了）

## 注意事项
1. 块长不能为 $0$，一般来说取不到 $0$ 但是还是要注意下。  
2. 扩展收缩($l,r$ 加加减减前加后减之类的)是有要求的！直接背并不好背，需要理解。这里只介绍咱的习惯。首先扩展都是左自减左自加（`--l`,`++r`），因为 $l,r$ 表示的是 $[l,r]$ 已经被解决，那么新增的肯定是 $l-1,r+1$ 啊。而删除则是要撤掉现在的 $l$ 或者 $r$，所以是右自减右自加（`l++`,`r--`）。然后先扩展再收缩是因为有时候如果当前指针 $l \gt r$ 会出错，所以说先扩展再收缩才不会错

## 回滚莫队  
莫队要求我们能同时执行扩展收缩两种操作，然而当我们有一种操作**不方便统计对答案的贡献**的时候，就要用到回滚莫队。以下咱以不删除莫队为例子讲解一下。  

注意这里说的是不方便统计对答案的贡献，而不是不方便撤销信息。回滚莫队还是要求要用某种撤销操作更新信息的，它一般就是扩展操作的逆操作。例如，统计出现次数最多的数字，那么我们可以用一个桶维护出现的次数。我们很容易撤销操作对信息带来的影响——只需要桶减一就行，但是撤销后万一它不是答案了呢？所以说我们是不方便统计撤回后的答案，于是使用回滚莫队规避掉撤回后统计答案的麻烦，然而仍然需要一个撤回操作。  

我们可以首先理解一下和普通莫队的区别，普通莫队是左指针在块内来回跳动，回滚莫队的左指针是每次从区间右端点出发向左走，统计完答案再回滚回来。具体操作和莫队一样：按照左指针所在块排序，右指针升序排序（不能奇偶化排序了，大概）  

那么为什么它就能避免撤销答案了呢？首先我们每次以左端点所在块为一个单位，如果左端点不在一个块了就清空答案。而在同一单位内，每次我们向右扩展答案，是不用撤销的（询问右端点单调不降），所以右指针只需要正常统计。右指针扩展完了我们**先把当前答案备份一下（关键之一）**，以便回滚回来以后恢复答案。然后向左扩展左指针，再然后将答案放入最终输出的离线答案库，最后**让左指针向右回滚直到区间右端点（关键之二）**，并将答案恢复成之前保存的答案。这个过程**仍然需要撤销**，只不过我们不需要更新答案，只需要维护信息了。  

另外，如果遇见左指针和右指针在同一个区间的情况，显然没法用上述方法解决，我们直接暴力计算，复杂度为块长。  

回滚莫队的核心概念就是，各个块间独立计算，块内右指针计算的结果不会被撤回，左指针就每次用保留的答案拉回到区间右端点  

## 带修莫队
你也可以叫它三维时空莫队（自己发明的鬼叫法），它并不是支持了真正意义上的修改操作，而是把时间轴也看做一个坐标（想象二维平面立体化为三维时空），所以说我们不仅要支持区间意义上的扩展和收缩，还要支持时间意义上的扩展和收缩  

还是之前颜色数量统计的问题（不同数字统计），我们将初始序列看做时间 $t1$，进行了一次操作将第三个数字从 $n1$ 改成 $n2$ 之后的序列看做时间 $t2$。那么我们先进行区间意义上的扩展收缩使得左右指针匹配询问（也许可以把顺序反过来，这里是个人习惯），然后在时间轴上进行穿梭（很酷！）。首先从 $t1$ 穿梭到 $t2$ 我们当然需要把序列的第三个数字改为 $2$，这是废话，然后我们要考虑这次穿梭对已有信息和答案的变化。  

这个例子其实很简单，如果修改的点 $k$ 满足 $l \le k \le r$ 的话，说明我们的区间包含了这次修改，自然会被这次穿梭影响到，所以我们删除一个数字 $n1$ 并加上一个数字 $n2$（这个操作和平常对序列上的一个数进行增删没有任何区别）。否则，这次穿梭对答案和信息没有影响（当然，序列还是要改的）  

那么时间轴上的收缩操作呢？也只是反操作罢了，当你从 $t2$ 返回 $t1$ 时，看做执行修改使得 $k$ 位置上的 $n2$ 变为 $n1$ 就行了。

## 代码
**普通莫队：**[P1494 小 Z 的袜子](https://www.luogu.com.cn/problem/P1494)（要结合下组合数学）  

```cpp
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 5e4 + 1018 + 1108;
int n,q,blk_len,kol[MAXN],arr[MAXN];
ll ans[MAXN][2];
struct Query{
	int l,r,blk,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(q1.blk != q2.blk)return q1.blk < q2.blk;
	if(q1.blk & 1){
		return q1.r < q2.r;
	}else{
		return q1.r > q2.r;
	}
}
inline void ReadIn(){
	cin>>n>>q;
	blk_len = sqrt(n) + 1;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i,ask[i].blk = ((ask[i].l-1) / blk_len) + 1;
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline void Add(int x,ll& nowans){
	nowans += kol[arr[x]];
	kol[arr[x]]++;
	return ;
}
inline void Del(int x,ll& nowans){
	kol[arr[x]]--;
	nowans -= kol[arr[x]];
	return ;
}
inline void Solve(){
	int l = 1,r = 0;
	ll nowans = 0;
	for(int i = 1;i <= q;i++){
		if(ask[i].l == ask[i].r){
			ans[ask[i].id][0] = 0;
			ans[ask[i].id][1] = 1;
			continue;
		}
		while(l > ask[i].l)Add(--l,nowans);
		while(r < ask[i].r)Add(++r,nowans);
		while(l < ask[i].l)Del(l++,nowans);
		while(r > ask[i].r)Del(r--,nowans);
		ans[ask[i].id][0] = nowans;
		ans[ask[i].id][1] = 1ll * (r - l + 1) * (r - l) / 2;
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		ll gcd = __gcd(ans[i][0],ans[i][1]);
		cout<<ans[i][0] / gcd<<"/"<<ans[i][1] / gcd<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
```

**回滚莫队：**[歴史の研究](https://www.luogu.com.cn/problem/AT_joisc2014_c)  

```cpp
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
template<typename T,int SIZE>
class ClearableArray{
	private:
		bool vis[SIZE];
		queue<int> clearQueue;
		T content[SIZE];
	public:
		T& operator[](int x){
			if(!vis[x]){
				vis[x] = true,clearQueue.push(x);
			}
			return content[x];
		}
		inline void Clear(){
			while(!clearQueue.empty()){
				const int u = clearQueue.front();
				clearQueue.pop();
				vis[u] = false,content[u] = T();
			}
			return ;
		}
};
ClearableArray<int,MAXN> cnt,cntBF;
ll ans[MAXN];
int n,q,blk_len,arr[MAXN],bel[MAXN];
vector<int> vec;
struct Query{
	int l,r,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(bel[q1.l] != bel[q2.l])return bel[q1.l] < bel[q2.l];
	return q1.r < q2.r;
}
inline void ReadIn(){
	cin>>n>>q;
	blk_len = sqrt(n) + 1;
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len)+1;
		cin>>arr[i];
		vec.push_back(arr[i]);
	}
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++){
		arr[i] = lower_bound(vec.begin(),vec.end(),arr[i]) - vec.begin();
	}
	for(int i = 1;i <= q;i++){
		cin>>ask[i].l>>ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline ll BF(int l,int r){
	ll ret = 0;
	cntBF.Clear();
	for(int i = l;i <= r;i++){
		cntBF[arr[i]]++;
		ret = max(ret,1ll * cntBF[arr[i]] * vec[arr[i]]);
	}
	return ret;
}
inline void Add(int x,ll &nowans){
	cnt[arr[x]]++;
	nowans = max(nowans,1ll * cnt[arr[x]] * vec[arr[x]]);
	return ;
}
inline void Del(int x){
	cnt[arr[x]]--;
	return ;
}
inline ll Calc(int& l,int& r,int OBJL,int OBJR,int blkR,ll& nowans){
	if(bel[OBJL] == bel[OBJR])return BF(OBJL,OBJR);
	while(r < OBJR){
		Add(++r,nowans);
	}
	ll save = nowans;
	while(l > OBJL){
		Add(--l,nowans);
	}
	ll ret = nowans;
	while(l <= blkR){
		Del(l++);
	}
	nowans = save;
	return ret;
}
inline void Solve(){
	int blk_cnt = bel[ask[q].l],tail = 0;
	for(int i = 1;i <= blk_cnt;i++){
		cnt.Clear();
		int l = i * blk_len + 1,r = i * blk_len;
		ll nowans = 0;
		while(tail+1 <= q && bel[ask[tail+1].l] == i){
			tail++;
			ans[ask[tail].id] = Calc(l,r,ask[tail].l,ask[tail].r,i * blk_len,nowans);
		}
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
```

**带修莫队：**[P1903 数颜色 / 维护队列](https://www.luogu.com.cn/problem/P1903)  

```cpp
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 130000 + 2006 + 1018 + 1108;
const int MAXVAL = 1e6 + 1018 + 1108;
int n,q,blk_len,nowans,bel[MAXN],kol[MAXN],kol2[MAXN],trans[MAXN][3],ans[MAXN];
int cnt[MAXVAL];
struct Query{
	int l,r,t,id;
}ask[MAXN];
bool operator<(Query q1,Query q2){
	if(bel[q1.l] != bel[q2.l])return bel[q1.l] < bel[q2.l];
	if(bel[q1.r] != bel[q2.r])return bel[q1.r] < bel[q2.r];
	return q1.t < q2.t;
}
inline void ReadIn(){
	int cacheQ;
	cin>>n>>cacheQ;
	blk_len = pow(n,0.66);
	blk_len = max(blk_len,1);
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / blk_len) + 1;
		cin>>kol[i];
		kol2[i] = kol[i];
	}
	int nowt = 1;
	for(int i = 1;i <= cacheQ;i++){
		char opt;
		cin>>opt;
		if(opt == 'Q'){
			++q;
			cin>>ask[q].l>>ask[q].r;
			ask[q].t = nowt,ask[q].id = q;
		}else{
			++nowt;
			cin>>trans[nowt][0]>>trans[nowt][2];
			trans[nowt][1] = kol2[trans[nowt][0]];
			kol2[trans[nowt][0]] = trans[nowt][2];
		}
	}
	sort(ask+1,ask+q+1);
	return ;
}
inline void AddKolor(int x){
	if(cnt[x] == 0)nowans++;
	cnt[x]++;
	return ;
}
inline void DelKolor(int x){
	cnt[x]--;
	if(cnt[x] == 0)nowans--;
	return ;
}
inline void Add(int x){
	AddKolor(kol[x]);
	return ;
}
inline void Del(int x){
	DelKolor(kol[x]);
	return ;
}
inline void Travel(int l,int r,int x,bool f){
	int from = trans[x][1],to = trans[x][2];
	if(f)swap(from,to);
	if(l <= trans[x][0] && trans[x][0] <= r){
		DelKolor(from),AddKolor(to);
	}
	kol[trans[x][0]] = to;
	return ;
}
inline void Solve(){
	int l = 1,r = 0,t = 1;
	for(int i = 1;i <= q;i++){
		while(l > ask[i].l){
			Add(--l);
		}
		while(r < ask[i].r){
			Add(++r);
		}
		while(l < ask[i].l){
			Del(l++);
		}
		while(r > ask[i].r){
			Del(r--);
		}
		while(t < ask[i].t){
			Travel(l,r,++t,false);
		}
		while(t > ask[i].t){
			Travel(l,r,t--,true);
		}
		ans[ask[i].id] = nowans;
	}
	return ;
}
inline void Output(){
	for(int i = 1;i <= q;i++){
		cout<<ans[i]<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Solve();
	Output();
	return not(Akano loves pure__Elysia);
}
```
