#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 3e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108;
int n,h[MAXN],minL[MAXN][22],minR[MAXN][22],gotoL[MAXN],gotoR[MAXN];
ll len1[MAXN],len2[MAXN];
ll L,R,maxSize,sizeL;
inline void ReadIn(){
	cin>>n;
	h[0] = h[n+1] = -2;
	for(int i = 1;i <= n;i++){
		cin>>h[i];
	}
	cin>>L>>R;
	return ;
}
inline void GetLR(){
	for(int i = 1;i <= n;i++){
		minL[i][0] = h[i-1];
		for(int j = 1;j <= 20;j++){
			const int nxt = max(i - (1<<(j-1)),1);
			minL[i][j] = min(minL[i][j-1],minL[nxt][j-1]);
		}
	}
	for(int i = n;i >= 1;i--){
		minR[i][0] = h[i+1];
		for(int j = 1;j <= 20;j++){
			const int nxt = min(i + (1<<(j-1)),n);
			minR[i][j] = min(minR[i][j-1],minR[nxt][j-1]);
		}
	}
	for(int i = 1;i <= n;i++){
		gotoL[i] = gotoR[i] = i;
		for(int j = 20;j >= 0;j--){
			if(minL[gotoL[i]][j] > h[i]){//向左走要求严格升,不然会重复
				gotoL[i] = max(gotoL[i] - (1<<j),1);
			}
			if(minR[gotoR[i]][j] >= h[i]){//向右走不要求严格升
				gotoR[i] = min(gotoR[i] + (1<<j),n);
			}
		}
		maxSize = max(maxSize,1ll * (gotoR[i] - gotoL[i] + 1) * h[i]);
		len1[i] = (i - gotoL[i] + 1),len2[i] = (gotoR[i] - i + 1);
		if(len1[i] > len2[i])swap(len1[i],len2[i]);
	}
	return ;
}
inline ll GetSum(ll l,ll r){
	if(l > r)return 0;
	return (r - l + 1) * (l + r) / 2;
}
ll GetCnt(ll x){//获得面积不大于x的区间数量
	ll ret = 0;
	for(int i = 1;i <= n;i++){
		ll maxLen = x / h[i];
		ll up = maxLen;
		//第一阶段,两端都没顶拢
		up = min(maxLen,len1[i]);
		ret += GetSum(1,up);
		//第二阶段,有一端顶拢了
		up = min(maxLen,len2[i]);
		if(up > len1[i]){
			ret += (up - len1[i]) * len1[i];
		}
		//第三阶段,两边都顶拢了
		if(maxLen > len2[i]){
			const ll totLen = len1[i] + len2[i] - 1;
			up = min(maxLen,totLen);
			ret += (totLen+1) * (up - len2[i]);
			ret -= GetSum(len2[i] + 1,up);
		}
	}
	return ret;
}
inline bool Judge(ll x){
	return GetCnt(x) >= L;
}
inline ll GetSizeofL(){
	ll l = 1,r = maxSize + 1;
	while(l < r){
		const ll mid = (l + r) >> 1;
		if(Judge(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	return r;
}
int nowLength[MAXN],nowCnt[MAXN];//每个最高点对应的当前区间长度,现在是当前区间长度的第i个
inline ll GetTot(int pos){//pos最高点有多少个长度为x的区间
	if(nowLength[pos] <= len1[pos])return nowLength[pos];
	if(nowLength[pos] <= len2[pos])return len1[pos];
	return len1[pos] + len2[pos] - nowLength[pos];
}
priority_queue<pair<ll,int> > q;
inline void Prepare(){//把每个最高点的信息预处理出来
	ll delta = L - GetCnt(sizeL-1) - 1;
	for(int i = 1;i <= n;i++){
		ll len = ceil(double(sizeL) / h[i]);
		nowCnt[i] = 1,nowLength[i] = len;
		if(delta != 0 && len * h[i] == sizeL){
			ll up = min(GetTot(i),delta);
			if(up <= 0)continue;
			nowCnt[i] += up;
			if(nowCnt[i] > GetTot(i)){
				nowLength[i]++;
				nowCnt[i] = 1;
			}
			delta -= up;
		}
		if(GetTot(i) > 0){//有可能已经不存在了,泉部被弹出完了
			//插入
			q.push(make_pair(-1ll * h[i] * nowLength[i],i));
		}
	}
	return ;
}
inline void Update(int x){
	nowCnt[x]++;
	if(nowCnt[x] > GetTot(x)){
		nowLength[x]++;
		nowCnt[x] = 1;
	}
	if(nowCnt[x] <= GetTot(x) && GetTot(x) > 0){
		q.push(make_pair(-1ll * h[x] * nowLength[x],x));
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	ReadIn();
	GetLR();
	sizeL = GetSizeofL();
	Prepare();
	for(int i = 1;i <= R-L+1;i++){
		cout<<-q.top().first<<' ';
		const int u = q.top().second;
		q.pop();
		Update(u);
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
