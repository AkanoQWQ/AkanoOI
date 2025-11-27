//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using ll = long long;
//bool ST;
//const int MAXN = 2e6 + 1018 + 1108;
//const int SIZE = 3;
//const int MOD[SIZE] = {10000007,998244353,1000000007};
//const int stp[SIZE] = {27,29,31};
//const int SIZE2 = 5e3;
//const int MX_OMG = 7e6;
//ll stps[MAXN][SIZE];
//ll hs[MAXN][SIZE],cnt;
//struct HsPair{
//	ll c[SIZE];
//};
//ostream& operator<<(ostream& cout,HsPair hsp){
//	cout<<"(";
//	for(int i = 0;i < SIZE;i++){
//		cout<<hsp.c[i];
//		if(i != SIZE-1)cout<<",";
//	}
//	cout<<")";
//	return cout;
//}
//bool operator==(HsPair hs1,HsPair hs2){
//	for(int i = 0;i < SIZE;i++){
//		if(hs1.c[i] != hs2.c[i])return false;
//	}
//	return true; 
//}
//struct MyHash{
//	int st,ed,tail;
//	inline void PushBack(char ch){
//		for(int i = 0;i < SIZE;i++){
//			hs[tail][i] = (hs[tail-1][i] * stp[i] + ch - 'a') % MOD[i];
//		}
//		tail++;
//		return ;
//	}
//	inline void SetString(const string& str){
//		st = cnt + 2,ed = st + str.length() - 1;
//		tail = st;
//		for(auto i : str)PushBack(i);
//		cnt = ed;
//		return ;
//	}
//	inline int len(){
//		return ed - st + 1;
//	}
//	inline HsPair Cut(int l,int r){
//		l += st-1,r += st-1;
//		HsPair ret;//Uninital
//		for(int i = 0;i < SIZE;i++){
////			cerr<<"find "<<hs[r][i]<<" and "<<hs[l-1][i]<<"*"<<stps[r-l+1][i]<<" len "<<l<<","<<r<<endl;
//			ret.c[i] = hs[r][i] - ((hs[l-1][i] * stps[r-l+1][i]) % MOD[i]);
//			ret.c[i] = (ret.c[i] + MOD[i]) % MOD[i];
//		}
//		return ret;
//	}
//	inline void Show(){
//		for(int j = 0;j < SIZE;j++){
//			for(int i = st;i <= ed;i++){
//				cout<<hs[i][j]<<",";
//			}
//			cout<<"   |    ";
//		}
//		cout<<endl;
//		return ;
//	}
//}mh[MAXN];
//int n,q,mxlen;
//inline void Init(){
//	for(int i = 0;i < SIZE;i++){
//		stps[0][i] = 1;
//		for(int j = 1;j <= mxlen+3;j++){
//			stps[j][i] = (stps[j-1][i] * stp[i]) % MOD[i];
//		}
//	}
//	return ;
//}
//int blk,ans[SIZE2][SIZE2],dir[MAXN],arr[MAXN];
//inline int Calc(int u,int v){
//	const int len = mh[u].len(),up = min(len,mh[v].len());
//	int res = 0;
//	for(int i = up;i >= 1;i--){
//		if(mh[u].Cut(len-i+1,len) == mh[v].Cut(1,i)){
//			res = i;
//			break;
//		}
//	}
//	return res;
//}
//inline void Solve(){
//	blk = mxlen;
//	for(int i = mxlen;i >= 0;i--){
//		arr[i] += arr[i+1];
//		long long omg = 1ll * arr[i] * arr[i] * i;
//		if(arr[i] <= SIZE2 && omg <= MX_OMG){
//			blk = i;
//		}
//	}
//	vector<int> vec;
//	for(int i = 1;i <= n;i++)dir[i] = -1;
//	for(int i = 1;i <= n;i++){
//		if(int(vec.size() >= SIZE2-2)){
//			break;
//		}
//		if(mh[i].len() >= blk){
//			dir[i] = vec.size();
//			vec.push_back(i);
//		}
//	}
//	cerr<<"res "<<clock()<<" and size "<<vec.size()<<" choose "<<blk<<endl;
//	for(int i = 0;i < int(vec.size());i++){
//		for(int j = 0;j < int(vec.size());j++){
//			ans[i][j] = Calc(vec[i],vec[j]);
//		}
//	}
//	cerr<<"end use "<<clock()<<endl;
//	return ;
//}
//bool ED;
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("string/string4.in","r",stdin);
//	freopen("string/string4.out","w",stdout);
//	cerr<<(&ST-&ED) / 1024 / 1024<<" MB used"<<endl;
//	cin>>n>>q;
//	for(int i = 1;i <= n;i++){
//		string str;
//		cin>>str;
//		mh[i].SetString(str);
//		mxlen = max(mxlen,mh[i].len());
//		arr[mh[i].len()]++;
//	}
//	Init();
//	Solve();
//	cerr<<"END SOLVE"<<endl;
//	while(q--){
//		int u,v,res;
//		cin>>u>>v;
//		if(dir[u] != -1 && dir[v] != -1){
//			res = ans[dir[u]][dir[v]];
//		}else{
//			res = Calc(u,v);
//		}
//		cout<<res<<'\n';
//	}
//	return not(Akano loves pure__Elysia);
//}
