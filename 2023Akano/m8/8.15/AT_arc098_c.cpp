//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN = 1018 + 1108;
//int n,k,q,arr[MAXN],ans = 1e9 + 1018 + 1108;
//pair<int,int> rk[MAXN];
//bool tag[MAXN];
//inline int Solve(int l,int r,int lower,int upper){
//	int ret = 0,len = (r - l + 1);
//	for(int i = l;i <= r;i++){
//		ret += (lower <= arr[i] && arr[i] <= upper);
//	}
//	ret = min(ret,len - k + 1);
//	ret = max(ret,0);
//	return ret;
//}
//inline bool Judge(int l,int r,int pos){
//	int ret = 0;
//	bool OK = false;
//	for(int i = 1;i <= n;i++){
//		if(arr[i] < l){
//			tag[i] = true;
//		}else{
//			tag[i] = false;
//		}
//	}
//	tag[n+1] = true;
//	int st = -1;
//	for(int i = 1;i <= n+1;i++){
//		if(st == -1 && tag[i] == false){
//			st = i;
//		}
//		if(st != -1 && tag[i] == true){
//			ret += Solve(st,i-1,l,r);
//			st = -1;
//			if(st <= pos && pos <= i-1 && i-1-st+1 >= k)OK = true;
//		}
//	}
//	if(OK == false)return false;
//	if(ret >= q)return true;
//	return false;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("C.in","r",stdin);
//	cin>>n>>k>>q;
//	for(int i = 1;i <= n;i++){
//		cin>>arr[i];
//		rk[i].first = arr[i],rk[i].second = i;
//	}
//	sort(rk+1,rk+n+1);
//	for(int i = 1;i+k-1 <= n;i++){
//		if(Judge(rk[i].first,rk[i+k-1].first,rk[i].second)){
//			ans = min(ans,rk[i+k-1].first - rk[i].first);
//		}
//	}
//	cout<<ans;
//	return 0;
//}
