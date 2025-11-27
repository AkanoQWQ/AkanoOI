#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
const ll INF = 1e16 + 11081108;
ll m,n,k,stu[MAXN * 2];
vector<ll> group[MAXN];
inline ll Calc(ll h,ll deskL,ll deskR){
	if(h < deskL){
		return deskL - h;
	}else if(h > deskR){
		return h - deskR;
	}
	return 0;
}
struct Desk{
	ll l,r;
}desk[MAXN];
bool Cmp(Desk desk1,Desk desk2){
	if(desk1.l != desk2.l)return desk1.l < desk2.l;
	return desk1.r < desk2.r;
}
inline void RemakeDesk(){
	sort(desk+1,desk+k+1,Cmp);
	int tail = 0;
	for(int i = 1,nowr = 0;i <= k;i++){
		if(desk[i].r > nowr){
			desk[++tail] = desk[i];
			nowr = desk[i].r;
		}
	}
	k = tail;
	return ;
}
ll pre[MAXN * 2];
inline ll Sum(ll l,ll r){
	if(l > r)return 0;
	return pre[r] - pre[l-1];
}
inline ll Calc(int pos,int deskID,int& l,int& r){
	ll ret = 0;
	while(l <= 2*m && group[pos][l] < desk[deskID].l)l++;
	while(r <= 2*m && group[pos][r] <= desk[deskID].r)r++;
	ret = (l - 1ll) * desk[deskID].l - (2*m - r + 1ll) * desk[deskID].r - Sum(1,l-1) + Sum(r,2*m);
//	cerr<<pos<<" choose "<<deskID<<" : "<<" + "<<(l - 1) * desk[deskID].l<<" - "<<(2*m - r + 1) * desk[deskID].r<<" - "<<Sum(1,l-1)<<" + "<<Sum(r,2*m)<<endl;
	return ret;
}
ll Solve(int stuL,int stuR,int deskL,int deskR){
	if(stuL > stuR)return 0;
	const int mid = (stuL + stuR) >> 1;
	ll ans = INF,choice = 0;
	for(int i = 1;i <= 2*m;i++){
		pre[i] = pre[i-1] + group[mid][i];
	}
	int totl = 1,totr = 1;
	for(int i = deskL;i <= deskR;i++){
		ll newans = Calc(mid,i,totl,totr);
		if(newans < ans){
			ans = newans,choice = i;
		}
	}
	return Solve(stuL,mid-1,deskL,choice) + ans + Solve(mid+1,stuR,choice,deskR);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("desk/desk5.in","r",stdin);
//	freopen("desk.out","w",stdout);
	cin>>m>>n>>k;
	for(int i = 1;i <= n;i++){
		group[i].push_back(0);
	}
	for(int i = 1;i <= k;i++){
		cin>>desk[i].l>>desk[i].r;
	}
	RemakeDesk();
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= 2*n;j++){
			cin>>stu[j];
		}
		sort(stu+1,stu+2*n+1);
		for(int j = 1;j <= 2*n;j++){
			group[(j+1)/2].push_back(stu[j]);
		}
	}
	for(int i = 1;i <= n;i++){
		sort(group[i].begin()+1,group[i].end());
	}
	cout<<Solve(1,n,1,k)<<endl;
	return not(Akano loves pure__Elysia);
}
