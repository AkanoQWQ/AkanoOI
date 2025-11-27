#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100026;
ll n,m,p,d[MAXN],s[MAXN],dp[126][MAXN];
ll q[MAXN],head,tail;
ll INF = 1;
class Cat{
	public:
		ll t,h,a;
		void Meow(){
			cout<<"Meow!"<<endl;
			return ;
		}
}c[MAXN];
bool cmp4Cat(Cat ca,Cat cb){
	return ca.a < cb.a;
	ca.Meow();
}
ll Calcy(ll i,ll k){
	return dp[i-1][k] + s[k];
}
long double Calck(ll ix1,ll iy1,ll ix2,ll iy2){
	return (1.0f*iy2-iy1) / (1.0f*ix2-ix1);
}
int main(){
	for(int i = 1;i <= 60;i++)INF *= 2;
	//freopen("gxytql.in","r",stdin);
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i = 2;i <= n;i++){
		ll c;
		scanf("%lld",&c);
		d[i] = d[i-1] + c;
	}
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld",&c[i].h,&c[i].t);
		c[i].a = c[i].t - d[c[i].h];
	}
	sort(c+1,c+m+1,cmp4Cat);
	for(int i = 0;i <= p;i++){
		for(int j = 0;j <= m;j++){
			dp[i][j] = INF;
		}
	}
	for(int i = 1;i <= m;i++){
		s[i] = s[i-1] + c[i].a;
	}
	dp[0][0] = 0;
	for(int i = 1;i <= p;i++){
		head = 1,tail = 1;
		q[tail] = 0;
		for(int j = 1;j <= m;j++){
			while(head < tail && Calck(q[head],Calcy(i,q[head]),q[head+1],Calcy(i,q[head+1])) < 1.0f*c[j].a){
				head++;
			}
			dp[i][j] = Calcy(i,q[head]) - c[j].a * q[head] - s[j] + c[j].a * j;
			while(head < tail && Calck(q[tail-1],Calcy(i,q[tail-1]),q[tail],Calcy(i,q[tail])) > Calck(q[tail],Calcy(i,q[tail]),j,Calcy(i,j))){
				tail--;
			}
			q[++tail] = j;
		}
	}
	cout<<dp[p][m];
	return 0;
}
