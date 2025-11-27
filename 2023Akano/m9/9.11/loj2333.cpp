#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXM = 2006 + 1018;
ll n,m,k,a,b,c,t,s[MAXM],base,f[MAXM];
vector<pair<ll,ll> > item[MAXM];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>a>>b>>c>>t;
	for(int i = 1;i <= m;i++)cin>>s[i];
	s[m+1] = n+1;//OK?
	for(int i = 1;i <= m;i++){
		ll nowtime = (s[i]-1) * b;
		if(nowtime > t)break;
		ll farpos = s[i] + (t - nowtime) / a;
		farpos = min(farpos,s[i+1] - 1);
//		cerr<<"default farpos "<<farpos<<endl;
		ll station = 0;//用于这一段的准快车车站 
		item[i].push_back(make_pair(station,farpos - s[i] + 1));
		while(farpos < s[i+1] - 1 && station <= k-m){
			station++;
			ll newStart = farpos + 1;//新车站的起点
			ll resTime = t - nowtime - (newStart - s[i]) * c;
			if(resTime < 0)break;
			farpos = newStart + resTime / a;
			farpos = min(farpos,s[i+1]-1);
//			cerr<<station<<" got "<<farpos - s[i] + 1<<" in "<<farpos<<" from "<<newStart<<endl;
			item[i].push_back(make_pair(station,farpos - s[i] + 1));
		}
		for(int j = int(k-m);j >= 0;j--){
			for(auto itm : item[i]){
				if(j - itm.first >= 0)f[j] = max(f[j],f[j - itm.first] + itm.second);
			}
		}
	}
	for(int i = 1;i <= k-m;i++){
		f[i] = max(f[i],f[i-1]);
	}
	cout<<f[k-m] - 1<<endl;//不包含 1 车站 
	return not(Akano loves pure__Elysia);
}
/*
思考
Thinking 1
首先肯定乘坐顺序是 快车-准快车-慢车
如果是从快车坐完再坐慢车再转快车的话,不如直接做快车到最后(快慢是相对来说) 
*/
