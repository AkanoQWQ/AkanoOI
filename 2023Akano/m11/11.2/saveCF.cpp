//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using pii = pair<int,int>;
//const int MAXW = 14;
//const int MAXSTAT = (1<<12) + 10 + 18 + 11 + 8;
//const int MAXN = 2006 + 1018 + 1108 + 1000;
//string str;
//int n,step,maxs,res;
//vector<int> pos[28];
//pii q[MAXN],nxt[MAXN];
//int vis[MAXN][MAXN],qTail,nxtTail;
//string ans;
//mt19937 rng(time(0));
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
////	cin>>str;
//	for(int i = 1;i <= 5000;i++){
//		if(rng() % 100 < 2){
//			str += "b";
//		}else{
//			str += "a";
//		}
//	}
//	n = str.length();
//	str = "." + str;
//	for(int i = 1;i <= n;i++){
//		pos[str[i] - 'a'].push_back(i);
//	}
//	step = log2(n);
//	maxs = (1<<step) - 1;
//	res = n - maxs;
//	q[++qTail] = {1,maxs};
//	for(int i = 1;i <= res;i++){
//		if(clock() > CLOCKS_PER_SEC * 0.97){
//			cout<<i<<"IN"<<res<<endl;
//			return 0;
//		}
//		sort(q+1,q+qTail+1);
//		for(int ch = 0;ch < 26;ch++){
//			nxtTail = 0;
//			auto st = pos[ch].begin();
//			for(int nowi = 1;nowi <= qTail;nowi++){
//				auto u = q[nowi];
//				while(st != pos[ch].end() && *st < u.first)st++;
//				for(auto it = st;it != pos[ch].end();it++){
//					const int j = *it;
//					if(((u.second & (j - u.first)) == (j - u.first))){
//						if(vis[j+1][u.second - (j - u.first)] != i){
//							vis[j+1][u.second - (j - u.first)] = i;
//							nxt[++nxtTail] = {j+1,u.second - (j - u.first)};
//						}
//					}
//					if(j > u.first + u.second)break;
//				}
//			}
////			cerr<<endl;
//			if(nxtTail != 0){
//				swap(q,nxt),swap(qTail,nxtTail);
//				ans += 'a' + ch;
//				break;
//			}
//		}
//	}
//	cout<<ans<<endl;
//	return not(Akano loves pure__Elysia);
//}
