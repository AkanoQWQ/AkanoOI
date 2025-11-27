#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100006;
const int INF = 0x7fffffff;
const int LG = 19;
struct city{
	int id,h,lst,nxt;
}c[MAXN];
ll n,dir[MAXN],dp[MAXN][LG][2][3],close[MAXN][2],closec[MAXN][2],x0,ra,rb;
bool cmp4city(city a,city b){
	return a.h < b.h;
}
void AddClose(int no,int cityNo,int upd){
	if(upd < 1 || upd > n)return ;
	//cout<<no<<" with "<<upd<<endl;
	if(abs(c[cityNo].h - c[upd].h) <= close[no][0]){
		if(abs(c[cityNo].h-c[upd].h)==close[no][0]&&c[cityNo].h>c[closec[no][0]].h){
			goto N2;
		}else{
			close[no][1] = close[no][0],closec[no][1] = closec[no][0];
			close[no][0] = abs(c[cityNo].h - c[upd].h);
			closec[no][0] = upd;
			return ;
		}
		close[no][0] = abs(c[cityNo].h - c[upd].h);
		closec[no][0] = upd;
		//cout<<"END"<<no<<" with "<<upd<<endl; 
		return ;
	}
	N2:
	if(abs(c[cityNo].h - c[upd].h) <= close[no][1]){
		if(abs(c[cityNo].h-c[upd].h)==close[no][1]&&c[cityNo].h>c[closec[no][1]].h){
			return ;
		}
		close[no][1] = abs(c[cityNo].h - c[upd].h);
		closec[no][1] = upd;
		return ;
	}
	return ;
}
void Calc(int p,int maxdis){
	ra = 0,rb = 0;
	for(int i = 19;i >= 0;i--){
		if(dp[p][i][0][0] > 0 && dp[p][i][0][0] <= n){
			if(dp[p][i][0][1]+dp[p][i][0][2]+ra+rb <= maxdis){
				ra += dp[p][i][0][1];
				rb += dp[p][i][0][2]; 
				p = dp[p][i][0][0];
			}
		}
	}
	return ; 
}
double ans0 = INF;
int c0;
int main(){
	freopen("city.in","r",stdin);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&c[i].h);
		c[i].id = i;
		close[i][0] = INF,close[i][1] = INF;
	}
	sort(c+1,c+n+1,cmp4city);
	c[0].h = INF;
	for(int i = 1;i <= n;i++){
		dir[c[i].id] = i;
		c[i].lst = i-1,c[i].nxt = i+1;
	}
	for(int i = 1;i <= n;i++){
		AddClose(i,dir[i],c[c[dir[i]].lst].lst);
		AddClose(i,dir[i],c[dir[i]].lst);
		AddClose(i,dir[i],c[dir[i]].nxt);
		AddClose(i,dir[i],c[c[dir[i]].nxt].nxt);
		c[c[dir[i]].lst].nxt = c[dir[i]].nxt;
		c[c[dir[i]].nxt].lst = c[dir[i]].lst;
	}
	
	for(int i = 1;i <= n;i++){
		closec[i][0] = c[closec[i][0]].id;
		closec[i][1] = c[closec[i][1]].id;
		//cout<<i<<":"<<closec[i][0]<<" "<<closec[i][1]<<endl;
	}
	for(int i = 1;i <= n;i++){
		dp[i][0][0][0] = closec[i][0];
		dp[i][0][1][0] = closec[i][1];
		dp[i][0][0][1] = close[i][0];
		dp[i][0][1][2] = close[i][1];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= LG;j++){
			for(int k = 0;k < 2;k++){
				if(j == 1){
					dp[i][j][k][0] = dp[dp[i][j-1][k][0]][j-1][1-k][0];
					dp[i][j][k][1] = dp[i][j-1][k][1] + dp[dp[i][j-1][k][0]][j-1][1-k][1];
					dp[i][j][k][2] = dp[i][j-1][k][2] + dp[dp[i][j-1][k][0]][j-1][1-k][2];
				}else{
					dp[i][j][k][0] = dp[dp[i][j-1][k][0]][j-1][k][0];
					dp[i][j][k][1] = dp[i][j-1][k][1] + dp[dp[i][j-1][k][0]][j-1][k][1];
					dp[i][j][k][2] = dp[i][j-1][k][2] + dp[dp[i][j-1][k][0]][j-1][k][2];
				}
			}
		}	
	}
	
	for(int i = 1;i <= n;i++){
		cout<<i<<":";
		for(int j = 1;j <= 5;j++){
			for(int k = 0;k < 2;k++){
				cout<<dp[i][j][k][0]<<" "<<dp[i][j][k][1]<<" "<<dp[i][j][k][2]<<endl;
			}
		}
	}
	
	return 0;
	c[0].h = -INF;
	scanf("%lld",&x0);
	for(int i = 1;i <= n;i++){
		Calc(i,x0);
		if(rb == 0)rb = 1;
		cout<<i<<":"<<double(ra) / double(rb)<<" bec "<<ra<<" "<<rb<<endl;
		if(double(ra) / double(rb) < ans0){
			ans0 = double(ra) / double(rb);
			c0 = i;
		}else if(double(ra) / double(rb) == ans0){
			if(c[dir[i]].h > c[dir[c0]].h){
				ans0 = double(ra) / double(rb);
				c0 = i;
			}
		}
	}
	printf("%lld\n",c0);
	return 0;
}
