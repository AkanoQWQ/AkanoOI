//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1018;
//int n,m,cnt = 0,q;
//struct LinearBasis{
//	bitset<MAXN> val[MAXN];
//	inline bool Insert(bitset<MAXN> ins){
//		for(int i = n - 1;i >= 0;i--){
//			if(ins == 0)return false;
//			if(!ins[i])continue;
//			if(val[i] == 0){
//				val[i] = ins;
//				return true;
//			}else{
//				ins ^= val[i];
//			}
//		}
//		return false;
//	}
//}lb;
//vector<pair<bitset<MAXN>,int> > line;
//int ans[MAXN];
//inline void Solve(){
//	for(int i = 0;i < n;i++){
//		int mx = i;
//		for(int j = i;j < n;j++){
//			if(line[j].first[i] == 1){
//				mx = j;break;
//			}
//		}
//		swap(line[i],line[mx]);
//		for(int j = 0;j < n;j++){
//			if(line[j].first[i] == 1 && i != j){
//				line[j].first ^= line[i].first;
//				line[j].second ^= line[i].second;
//			}
//		}
//	}
//	for(int i = 0;i < n;i++){
//		if(line[i].second){
//			cout<<"?y7M#"<<endl;
//		}else{
//			cout<<"Earth"<<endl;
//		}
//	}
//	return ;
//}
//string str;
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>n>>m;
//	for(int i = 1;i <= m;i++){
//		cin>>str>>q;
//		if(lb.Insert(bitset<MAXN>(str))){
//			++cnt;
//			line.push_back(make_pair(bitset<MAXN>(str),q));
//		}
//		if(cnt == n){
//			cout<<i<<endl;
//			Solve();
//			return 0;
//		}
//	}
//	cout<<"Cannot Determine"<<endl;
//	return 0;
//}

