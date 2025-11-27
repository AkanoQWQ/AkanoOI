#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
struct Object{
	int dep,step;
}obj[MAXN];
struct Cmper{
	bool operator()(int obj1,int obj2){//大根堆反着来 
		if(obj[obj1].dep != obj[obj2].dep)return obj[obj1].dep > obj[obj2].dep;
		return obj[obj1].step < obj[obj2].step;
	}
};
bool Cmp(Object o1,Object o2){
	return o1.step > o2.step;
}
priority_queue<int,vector<int>,Cmper> q;
int n;
long long ans;
vector<int> b;
unordered_map<int,int> cnt;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>obj[i].dep;
		cnt[obj[i].dep]++;
		q.push(i);
	}
	for(int i = 1;i <= n;i++){
		int inb;
		cin>>inb;
		b.push_back(inb);
	}
	while(!q.empty()){
		const int u = q.top();
		q.pop();
		if(cnt[obj[u].dep] == 1)continue;
		cnt[obj[u].dep]--;
		obj[u].dep++;
		cnt[obj[u].dep]++;
		obj[u].step++;
		q.push(u);
	}
	sort(b.begin(),b.end());
	sort(obj+1,obj+n+1,Cmp);
	for(int i = 1;i <= n;i++){
//		cerr<<obj[i].step<<" and "<<b[i-1]<<endl;
		ans += 1ll * obj[i].step * b[i-1];
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
