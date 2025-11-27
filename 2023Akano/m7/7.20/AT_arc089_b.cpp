#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXK = 2006;
int n,k,x,y,c,blk[MAXK][MAXK],wht[MAXK][MAXK];
char kol;
inline void ReadIn(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>x>>y>>kol;
		x %= 2*k,y %= 2*k;
		if(kol == 'B')blk[x][y]++;
		if(kol == 'W')wht[x][y]++;
	}
	return ;
}
inline void Pre(){
	for(int i = 0;i < 2*k;i++){
		for(int j = 0;j < 2*k;j++){
			if(i >= 1)blk[i][j] += blk[i-1][j];
			if(j >= 1)blk[i][j] += blk[i][j-1];
			if(i >= 1 && j >= 1)blk[i][j] -= blk[i-1][j-1];
			if(i >= 1)wht[i][j] += wht[i-1][j];
			if(j >= 1)wht[i][j] += wht[i][j-1];
			if(i >= 1 && j >= 1)wht[i][j] -= wht[i-1][j-1];
		}
	}
	return ;
}
inline int GetVal(int f[][MAXK],int _x1,int _y1,int _x2,int _y2){
	int ret = 0;
	ret += f[_x2][_y2];
	if(_x1 >= 1)ret -= f[_x1-1][_y2];
	if(_y1 >= 1)ret -= f[_x2][_y1-1];
	if(_x1 >= 1 && _y1 >= 1)ret += f[_x1-1][_y1-1];
	return ret;
}
inline int GetVal(int f[][MAXK],pii p1,pii p2){
	if(p1.first > p2.first || p1.second > p2.second)return 0;
	return GetVal(f,p1.first,p1.second,p2.first,p2.second);
}
inline int Calc(){
	int ret = 0;
	for(int i = 0;i < k;i++){
		for(int j = 0;j < k;j++){
			int now = 0;
			now += GetVal(blk,{k-i,k-j},{k-i+k-1,k-j+k-1});
			now += GetVal(blk,{0,0},{k-i-1,k-j-1});
			now += GetVal(blk,{k-i+k,0},{2*k-1,k-j-1});
			now += GetVal(blk,{0,k-j+k},{k-i-1,2*k-1});
			now += GetVal(blk,{k-i+k,k-j+k},{2*k-1,2*k-1});
			now += GetVal(wht,{0,0},{2*k-1,2*k-1});
			now -= GetVal(wht,{k-i,k-j},{k-i+k-1,k-j+k-1});
			now -= GetVal(wht,{0,0},{k-i-1,k-j-1});
			now -= GetVal(wht,{k-i+k,0},{2*k-1,k-j-1});
			now -= GetVal(wht,{0,k-j+k},{k-i-1,2*k-1});
			now -= GetVal(wht,{k-i+k,k-j+k},{2*k-1,2*k-1});
			ret = max(ret,now);
			now = 0;
			now += GetVal(wht,{k-i,k-j},{k-i+k-1,k-j+k-1});
			now += GetVal(wht,{0,0},{k-i-1,k-j-1});
			now += GetVal(wht,{k-i+k,0},{2*k-1,k-j-1});
			now += GetVal(wht,{0,k-j+k},{k-i-1,2*k-1});
			now += GetVal(wht,{k-i+k,k-j+k},{2*k-1,2*k-1});
			now += GetVal(blk,{0,0},{2*k-1,2*k-1});
			now -= GetVal(blk,{k-i,k-j},{k-i+k-1,k-j+k-1});
			now -= GetVal(blk,{0,0},{k-i-1,k-j-1});
			now -= GetVal(blk,{k-i+k,0},{2*k-1,k-j-1});
			now -= GetVal(blk,{0,k-j+k},{k-i-1,2*k-1});
			now -= GetVal(blk,{k-i+k,k-j+k},{2*k-1,2*k-1});
			ret = max(ret,now);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("ARC_B.in","r",stdin);
	ReadIn();
	Pre();
	cout<<Calc()<<endl;
	return 0;
}
