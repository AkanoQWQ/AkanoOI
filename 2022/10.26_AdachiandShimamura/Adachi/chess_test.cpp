#include<bits/stdc++.h>
using namespace std;
bool test = 0;
const int MAXCAP = 2e5 + 2006 + 1108;
string l[100006],_[100006];
const int movex[4] = {0,1,0,-1};
const int movey[4] = {1,0,-1,0};
const char name_move[4] = {'r','d','l','u'};
const int readx[4] = {0,0,0,-1};
const int ready[4] = {0,0,-1,0};
int n,m,q,ans;
inline int no(int inx,int iny){
	return (inx-1)*m + iny;
}
inline pair<int,int> deno(int innum){
	pair<int,int> outpos;
	outpos.second = innum;
	while(outpos.second > m)outpos.second -= m;
	outpos.first = (innum-outpos.second)/m + 1;
	return outpos;
}
int t;
struct Chess{
	int col,v;
}c[MAXCAP],emptyc;
bool ansvis[MAXCAP];
int head,tail,kwei[MAXCAP];
bool ink(int inx){
	if(ansvis[inx])return 0;
	kwei[++tail] = inx;
	ansvis[inx] = 1;
	return 1;
}
void GoStraight(int pos,int col,int v,int stat){//?∆¥–¥¥Ì¡À¬Ô? 
	pair<int,int> newno = deno(pos);
	const int x = newno.first;
	const int y = newno.second;
	char road;
	if(stat == 0 || stat == 2){
		road = _[x+readx[stat]][y+ready[stat]];
	}else{
		road = l[x+readx[stat]][y+ready[stat]];
	}
	if(test)cout<<x<<","<<y<<" to "<<x + movex[stat]<<','<<y + movey[stat]<<" in "<<road<<endl;
	if(c[pos].col == col || c[pos].v > v){
		//do nothing
	}else{
		ans += ink(no(x,y));//ansimp
//		cout<<"2add"<<ans<<endl;
		if(c[pos].col != -1)return ;
		if(road == '2'){
			const int OX = x + movex[stat];
			const int OY = y + movey[stat];
			if(OX < 1 || OX > n || OY < 1 || OY > m)return ;
			GoStraight(no(OX,OY),col,v,stat);
		}
	}
	return ;
}
bool vis[MAXCAP];
void dfs(int pos,int col,int v){
	if(c[pos].col == col || c[pos].v > v){
		return ;
	}
	if(c[pos].col != -1){
		ans += ink(pos);
		return ;
	}
	vis[pos] = 1;
	pair<int,int> newno = deno(pos);
	const int x = newno.first;
	const int y = newno.second;
	ans += ink(pos);//ansimp
//	cout<<"3add"<<ans<<" in "<<x<<","<<y<<endl;
	char road;
	for(int i = 0;i < 4;i++){
		if(i == 0 || i == 2){
			road = _[x+readx[i]][y+ready[i]];
		}else{
			road = l[x+readx[i]][y+ready[i]];
		}
		if(road == '3'){
			const int OX = x + movex[i];
			const int OY = y + movey[i];
			const int ONO = no(OX,OY);
			if(vis[ONO] || OX < 1 || OX > n || OY < 1 || OY > m)continue;
			if(vis[ONO])continue;
			dfs(ONO,col,v);
		}
	}
	return ;
}
void Check(int pos,int col,int v){
	head = 1,tail = 0;
	pair<int,int> xy = deno(pos);
	const int x = xy.first;
	const int y = xy.second;
//	cout<<x<<","<<y<<" here!"<<endl;
	for(int i = 0;i < 4;i++){
		const int OX = x + movex[i];
		const int OY = y + movey[i];
		char road;
		if(i == 0 || i == 2){
			road = _[x+readx[i]][y+ready[i]];
		}else{
			road = l[x+readx[i]][y+ready[i]];
		}
		if(test)cout<<x+readx[i]<<","<<y+ready[i]<<" in "<<name_move[i]<<i<<" "<<road<<endl;
		if(road == '0'){
			//do nothing 
		}else if(road == '1'){
			const int ONO = no(OX,OY);
			if(test)cout<<c[ONO].col<<" and "<<c[ONO].v<<endl;
			if(c[ONO].col == col || c[ONO].v > v){
				//do nothing
			}else{
				ans += ink(ONO);//ansimp
//				cout<<"1add"<<ans<<endl;
			}
			if(test)cout<<"1ans "<<ans<<endl;
		}else if(road == '2'){
//			cout<<"check2"<<endl;
			GoStraight(no(OX,OY),col,v,i);
			if(test)cout<<"2ans "<<ans<<endl;
		}else if(road == '3'){
			memset(vis,0,sizeof(vis));
//			cout<<"GO3 to "<<OX<<","<<OY<<endl;
			dfs(no(OX,OY),col,v);
			if(test)cout<<"3ans "<<ans<<endl;
		}
		//cout<<"Turn "<<name_move[i]<<" in "<<road<<endl;
		//cout<<x<<','<<y<<" to "<<OX<<','<<OY<<endl;
	}
	while(tail >= head){
		ansvis[kwei[tail--]] = 0;
	}
	return ;
}
int tot = 0;
int main(){
	freopen("chess.in","r",stdin);
	//freopen("chess.test","w",stdout);
	emptyc.col = -1;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		for(int i = 0;i <= no(n+5,m+5);i++)c[i] = emptyc;
		for(int i = 0;i < MAXCAP;i++)c[i] = emptyc;
		for(int i = 1;i <= n;i++){
			cin>>_[i];
			_[i] = '.' + _[i] + '.';
		}
		for(int i = 1;i <= n-1;i++){
			cin>>l[i];
			l[i] = '.' + l[i] + '.';
		}
		while(q--){
			tot++;
			ans = 0;
			if(tot == 4008)test = 1;
			if(test)cout<<n<<" "<<m<<" is nm"<<endl;
			int inputx,inputy,inputcol,inputv,calcno;
			cin>>inputcol>>inputv>>inputx>>inputy;
			calcno = no(inputx,inputy);
			c[calcno].col = inputcol,c[calcno].v = inputv;
			Check(calcno,inputcol,inputv);
			if(test)cout<<endl<<endl<<ans<<endl;
			test = 0;
		}
	}
    return 0;
}


