# 题面
## 题目描述

给定一个矩阵，每个格子由下列字母表示： 

- 有障碍的区域表示为‘#’ 

- 初始位置表示为‘C’ 

- 目标位置表示为 ‘F’ 

- 空白区域表示为‘.’ 

可以进行三种操作： 

- 走到上下左右相邻的格子，不能走到有墙的区域上，消耗 一个单位时间。 

- 在墙壁上创建传送门，用枪向上、向下、向左，向右直射向着墙壁。传送门会 在被击中的墙的一侧产生。在每一时刻，最多两个传送门可以是活动的。如果在 已有两个传送门的基础上再射击创建了一个新的，那么较早创建的门将消失。这 个射击消耗的时间可忽略。

- 如果她在一个靠近墙的地方，墙上有一个传送门，她可以进入，到达另一个门 外的无障碍区域出来，需要消耗一个单位时间。 求到达目的地“F”所需的最少时间

## 输入格式

输入的第一行包含正整数 N 和 M（4≤ N、 M≤ 500）。以下 N 行中的每一行都包含 M 个字符，用于描述房间的布局。

## 输出格式

您必须输出解决谜题所需的最小时间，如果无法解决，则输出“nemoguce”（不 带引号，表示“不可能”）。 

## 样例

```
6 8
########
#.##..F#
#C.##..#
#..#...#
#.....##
######## 
```

```
4
```

## 思路

~~首发思路:并不存在，因为早上睡过头了，于是考试时间只有一个小时，根本没有看这道题~~

现在看来后悔死了，这道题相比前面的题要简单的多

对于矩阵图，我们一般不会想到离散化建图连边跑最短路——但是这道题中n,m的范围很小，所以我们可以这么做，那么这就是一道很裸的最短路

好吧，其实不是很裸。因为我们还要考虑传送门的情况。然而，还是得益于本题的范围较小，在空间和时间上我们都可以暴力地找传送门建边！

具体操作如下：我们枚举“当前位置“，向上、下、左、右四个方向分别发出一条射线，遇到墙壁就停下来。对于找到了墙壁的方向，我们可以两两配对。假设`a`为进入的传送门，`b`为走出的传送门，那么我们就建立一条从当前位置到`b`的边，其权值为当前位置到`dis[a]+1`，加一的原因在于进入传送门也要花费时间。

最后跑一个最短路（由于是矩阵图，我们可以直接选择SPFA），然后咱就A了这道题，可喜可贺可喜可贺。

总结：这道题的最大问题在于能否想到**可以**暴力建点建边。按照个人经验来说看到矩阵图咱第一时间想到的是BFS，而绝对不会想到可以建点图SPFA，所以说具体问题还是要具体分析复杂度。本题中建图的复杂度为 $ O(n \times m \times (n+m)) $ （主要在于每一个点都要发出四条射线，最多会走 $ n + m  $ 次）。

另外，我们在做题的时候遇到了玄学BUG，会TLE，结果调试发现n,m的值改变了！第一时间认为是内存覆盖，果然，把数组开大一点就正确了。

# 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 666;
const int MAXM = MAXN*MAXN*10;
const int MAXP = MAXN*MAXN;
const int INF = 0x7fffffff;
const int movex[4] = {0,1,0,-1};
const int movey[4] = {1,0,-1,0};//ri,dow,le,upp
int head[MAXP],etot;
struct Edge{
	int nxt,to,v;
}e[MAXM];
void AddEdge(int frm,int to,int v){
	e[++etot].to = to;
	e[etot].nxt = head[frm];
	e[etot].v = v;
	head[frm] = etot;
	return ;
}
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,tot,no[MAXN][MAXN],st,ed;
char mp[MAXN][MAXN];
int dis[MAXP];
bool inq[MAXP];
queue<int> q;
void SPFA(){
	for(int i = 0;i <= n*m+1;i++)dis[i] = INF;
	memset(inq,0,sizeof(inq));
	while(!q.empty())q.pop();
	dis[st] = 0;
	q.push(st);
	inq[st] = 1;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[u] + e[i].v < dis[v]){
				dis[v] = dis[u] + e[i].v;
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			while(1){
				mp[i][j] = getchar();
				if(mp[i][j] == '#'||mp[i][j] == '.'||mp[i][j] == 'C'||mp[i][j] == 'F')break;
			}
			no[i][j] = ++tot;
			if(mp[i][j] == 'C'){
				st = no[i][j];
			}else if(mp[i][j] == 'F'){
				ed = no[i][j];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int ps[4][3];
			memset(ps,0,sizeof(ps));
			for(int k = 0;k < 4;k++){
				const int OX = i + movex[k];
				const int OY = j + movey[k];
				if(mp[OX][OY] != '#' && mp[i][j] != '#'){
					AddEdge(no[i][j],no[OX][OY],1);
				}
				if(mp[i][j] == '#')continue;
				int x = i,y = j;
				while(x > 0 && y > 0 && x <= n && y <= m){
					if(mp[x+movex[k]][y+movey[k]] == '#'){
						ps[k][0] = x;
						ps[k][1] = y;
						break;
					}
					ps[k][2]++;
					x += movex[k],y += movey[k];
				}
			}
			for(int s = 0;s < 4;s++){
				if(ps[s][1] == 0)continue;
				for(int k = 0;k < 4;k++){
					if(ps[k][1] == 0)continue;
					AddEdge(no[i][j],no[ps[s][0]][ps[s][1]],ps[k][2]+1);
				}
			}
			
		}
	}
	SPFA();
	if(dis[ed] == INF){
		printf("nemoguce");
	}else{
		printf("%d",dis[ed]);
	}
	return 0;
}
```
