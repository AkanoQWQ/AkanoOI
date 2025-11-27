# 题面

## 题目描述

给n 个人每个人有个团队（0 或1），每个人可以报一个数，第一个人的范围为[1,k]，
上一个人报的数x 下一个人为[x+1,x+1+k]，报数超过m 的人输，1-n 按顺序报
数，n 的下一个为1 直到游戏结束。每个人都会选择最优策略，问以每个人为起
始点玩这个游戏，那个团队会赢。

## 输入格式
T 第一行三个数N, M and K (1 ≤ N, M, K ≤ 5000). 下一行N 个数，0，1 分别表示每
个人的团队.
## 输出格式
输出n 个数，以空格隔开.
对于每个人而言，如果从他开始这个游戏，输出0 表示0 号团队胜利，1 表示1
号团队胜利

## 样例

```
6 499 5
1 0 0 1 1 0
```

```
0 1 1 1 1 0
```

## 数据范围

对于60% 的数据, 1 ≤ N, M, K ≤ 500.
对于100%的数据， (1 ≤ N, M, K ≤ 5000)

## 思路

虽然题目是一眼博弈论，看上去可能会有一些结论，不过实际上除了可以推出必胜点m-1以外咱没有更多的进展了。于是我们只能选择搜索(自然，搭配上记忆化)。对于每一个状态，如果下一个人是队友，只要有一种情况能够胜利，最终就是胜利的；如果下一个人是对手，只要有一种情况能让对方失败，最终就是胜利的。

然而，我们发现如果用一个表格来装下状态的话，决定dp\[i][j]的状态其实是dp\[i+1]\[j-k-1 ~ j-1](不考虑i = n,j-k-1 < 0的情况)，那么我们就可以按第二个状态为一层，层层递推，利用前缀和进行优化，于是复杂度就被优化为 $ O(n \times m) $ 的了。

# 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
int n,m,k;
bool team[MAXN];
bool dp[MAXN][MAXN];
int s[MAXN][MAXN];
int main(){
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		cin>>team[i];
	}
	for(int i = 1;i <= m;i++){
		for(int pos = 1;pos <= n;pos++){
			int nxt = pos + 1;
			if(nxt == n + 1)nxt = 1;
			int l = max(1,i - k);
			if(team[pos] == team[nxt]){
				dp[pos][i] = s[nxt][i-1] - s[nxt][l-1];
			}else{
				if(s[nxt][i-1] - s[nxt][l-1] == i-l){
					dp[pos][i] = 0;
				}else{
					dp[pos][i] = 1;
				}
			}
			s[pos][i] = s[pos][i-1] + dp[pos][i];
		}
	}
	for(int i = 1;i <= n;i++){
		if(dp[i][m]){
			putchar(team[i]+'0');
		}else{
			putchar((!team[i])+'0');
		}
		putchar(' ');
	}
	return 0;
}
```

