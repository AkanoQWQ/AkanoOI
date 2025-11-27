## 简要题意

给定一个单向链表，节点维护的值单调递增，可以花费一次询问查找一个节点的值和它的后继节点，求链表中某一个值的后继。需要在   [katex]  2000  [/katex]   次询问中获得   [katex]  5 \times 10 ^ 4  [/katex]   大小的链表的答案。

## 思路

一个非常有意思的交互题，还用到了随机化的思想。  

首先我们考虑暴力询问每一个节点的值，显然是可以的，但是询问次数爆炸。  

我们又考虑能不能勤俭节约一点，跳着询问链表上两个节点中某一的值（当然，不知节点的后继节点的情况下你无法“跳着”询问，这只是一个思路），然后找到两个值最接近的节点，再询问它中间的节点，可以发现询问次数减半  

然后再次扩展，我们可以隔着   [katex]  x  [/katex]   个节点询问一次，然后把最匹配答案的两个节点中间的   [katex]  x  [/katex]   个节点依次访问了（顺带一提，其实我们只需要记录已知节点中的   [katex]  val  [/katex]   （题目给定的要求的值）的前驱节点就行）  

在   [katex]  k  [/katex]   次询问时，我们可以由此访问到   [katex]  (k-x) \times x  [/katex]   个节点，显然   [katex]  x = \frac k 2  [/katex]   的时候最优，带入   [katex]  k = 2000  [/katex]   就是   [katex]  x = 1000  [/katex]   及   [katex]  (k-x) \times x = 10^6  [/katex]  ，远大于   [katex]  5 \times 10 ^ 4  [/katex]   并且有一定容错空间。  

最后我们其实没法在不消耗询问的情况下遍历链表“跳着访问”（不然直接二分了），其实直接在内存（数组）上随机查询是一样的！因为数组和维护的链表其实是一个映射关系，在数组上随机访问到某个节点的概率和在链表上随机访问到某个节点的概率是相同的，而在链表上随机访问   [katex]  1000  [/katex]   个节点和等间距访问   [katex]  1000  [/katex]   个节点也是“差不多”的。  

虽然说它们是“差不多”的，但是随机化的正确率有多高？考虑对于答案节点来说，只要访问到它的前   [katex]  1000  [/katex]   个节点中的任意一个就可以求得答案，而随机访问   [katex]  1000  [/katex]   次都访问不到这些节点的概率是   [katex]  (1 - \frac {1000} {50000}) ^ {1000} \approx 1.6 \times 10^{-9}  [/katex]  ，这是可以忽视的。  

另外题目给出的开头节点是非常重要的，如果答案是第   [katex]  k  [/katex]   个节点，只要访问到它的前   [katex]  min(k,x)  [/katex]   个节点就得出了答案，然而如果   [katex]  k \le x  [/katex]  ，那么访问到它前面的概率就和   [katex]  k  [/katex]   相关，如果这个   [katex]  k  [/katex]   很小（  [katex]  k = 1  [/katex]  ），那么得出正确答案的概率很低！不过给出了开头节点，相当于我们已经知道了这些节点的前继节点了，所以无须担心这个问题。  

于是我们就愉快的做出了这道交互题啦~  

## 代码
```cpp
#include&lt;bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e4 + 1018 + 1108;
const int maxTimes = 1006;
int nxt[MAXN],val[MAXN],n,x,start,lst,res = 1996;
inline void Query(int x){
	if(nxt[x])return ;
	res--;
	cout&lt;&lt;"? "&lt;&lt;x&lt;&lt;endl;
	cin>>val[x]>>nxt[x];
	return ;
}
mt19937 rd(time(0));
int main(){
	val[0] = -1;
	cin>>n>>start>>x;
	lst = start;
	Query(lst);
	vector&lt;int> vec(n);
	for(int i = 0;i &lt; n;i++)vec[i] = i+1;
	shuffle(vec.begin(),vec.end(),rd);
	for(int i = 0;i &lt; min(maxTimes,n);i++){
		const int u = vec[i];
		Query(u);
		if(val[lst] &lt; val[u] &amp;&amp; val[u] &lt;= x){
			lst = u;
		}
	}
	int u = lst;
	while(res >= 0 &amp;&amp; u > 0){
		if(val[u] >= x)break;
		const int v = nxt[u];
		if(v == -1)break;
		Query(v);
		if(val[v] &lt; x){
			u = v;
		}else{
			u = v;
			break;
		}
	}
	if(val[u] &lt; x)val[u] = -1;
	cout&lt;&lt;"! "&lt;&lt;val[u]&lt;&lt;endl;
	return not(Akano loves pure__Elysia);
}
```

~~励志打完所有交互题~~
