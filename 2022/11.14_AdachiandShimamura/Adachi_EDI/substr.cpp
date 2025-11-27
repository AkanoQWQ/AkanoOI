#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
const int st = 0;
int n,tnt = st;
string instr;
int tr[MAXN][26],fail[MAXN],stat[MAXN];
void insert(string str,int no){
	int u = st,len = str.length() - 1;
	for(int i = 1;i <= len;i++){
		const int c = str[i] - 'A';
		if(!tr[u][c])tr[u][c] = ++tnt;
		u = tr[u][c];
	}
	stat[u] |= (1 << (no-1));
	return ;
}
queue<int> qb;
void build(){
	for(int i = 0;i < 26;i++)if(tr[st][i] != 0)qb.push(tr[st][i]);
	while(!qb.empty()){
		const int u = qb.front();
		qb.pop();
		for(int i = 0;i < 26;i++){
			if(tr[u][i]){
				fail[tr[u][i]] = tr[fail[u]][i];
				stat[tr[u][i]] |= stat[fail[tr[u][i]]];
				qb.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	return ;
}
int output_tail,outputs[MAXN*(1<<12) + 5];
int head = 1,tail = 1;
struct sq{
	int pos,lst,stats;
	char ch;
}q[MAXN*(1<<12) + 5],csq;
void output_ans(int u){
	output_tail = 0;
	for(;u;u = q[u].lst){
		outputs[++output_tail] = q[u].ch;
	}
	for(int i = output_tail - 1;i >= 1;i--){
		putchar('A' + outputs[i]);
	}
	return ;
}
bool vis[MAXN][1<<13 + 2];
void bfs(){
	q[1].stats = 0;
	q[1].pos = st;
	q[1].lst = 0;
	q[1].ch = 0;
	while(head <= tail){
		const int u = q[head].pos,chr = q[head].ch,nows = q[head].stats;
		if(nows == (1 << n) - 1){
			output_ans(head);
			return ;
		}
		head++;
		for(int i = 0;i < 26;i++){
			csq.pos = tr[u][i],csq.ch = i,csq.lst = head - 1;
			csq.stats = nows | stat[csq.pos];
			if(!vis[csq.pos][csq.stats]){
				vis[csq.pos][csq.stats] = 1;
				q[++tail] = csq;
			}
		}
	}
	return ;
}
int main(){ 
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>instr;
		insert("." + instr,i);
	}
	build();
	bfs();
	return 0;
}
