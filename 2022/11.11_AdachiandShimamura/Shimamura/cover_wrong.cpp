#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
const int movex[4] = {1,0,-1,0};
const int movey[4] = {0,1,0,-1};
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
string sread(){
    string s = "";
    char c = getchar();
    while(c != '.' && c != '#'){
		s += c;
		c = getchar();
	}
    while(c == '.' || c == '#'){
		s += c;
		c = getchar();
	}
    return s;
}
int r,c,pcnt;
long long acnt;
string mp[MAXN];
int di[MAXN*MAXN];
int dnt;
int findp(int x,int y){
	int ret = 1;//itself
	for(int k = 0;k < 4;k++){
		int OX = x + movex[k],OY = y + movey[k];
		while(OX >= 1 && OX <= r && OY >= 1 && OY <= c && mp[OX][OY] == '.'){
			ret++;
			OX += movex[k];
			OY += movey[k];
		}
	}
	return ret;
}
long double ans,lf1 = 1.0;
unsigned long long ca;
int main(){
	freopen("big_sample/cover.in","r",stdin);
	//freopen("cover.out","w",stdout);
	r = read(),c = read();
	for(int i = 1;i <= r;i++){
		mp[i] = "!" + sread();
	}
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			if(mp[i][j] == '.'){
				pcnt++;
				di[++dnt] = findp(i,j);
				long double addn = (1<<(di[dnt])) * (1.0f - (lf1 / (1<<di[dnt])));
				acnt += addn;
				//printf("add %Lf %d\n",addn,acnt);
				//printf("bec %d * %Lf\n",(1 << (di[dnt])),(lf1 / (1<<di[dnt])));
			}
		}
	}
	ans = pcnt;
	for(int i = 1;i <= dnt;i++){
		if(di[i] >= 64){
			cout<<di[i]<<" too big"<<endl;
		}else{
			ca = 1 << di[i];
			ans -= (lf1 / ca);
		}
	}
	cout<<"pnt"<<pcnt<<endl;
	cout<<int(ans)<<endl<<acnt<<endl<<acnt/(1<<pcnt);
	return 0;
}
