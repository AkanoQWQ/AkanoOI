#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 3e5 + 2;
const int INF = 1e8;
int vis[MAXN * 2];
int n,q,a[MAXN],logval2[MAXN * 2];
vector<int> pow2s;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	n = 3e5;
	pow2s.push_back(1);
	while(pow2s.back()*2 <= 2*n){
		pow2s.push_back(pow2s.back() * 2);
	}
	for(int i = 0;i <= 2*n;i++){
		logval2[i] = -INF;
	}
	logval2[1] = 0;
	for(int i = 2;i <= 2*n;i++){
		if(i % 2 == 0)logval2[i] = logval2[i / 2] + 1;
	}
	int cnts = 0;
	for(int i = 1;i <= n;i++){
		for(auto p2 : pow2s){
			int oth = p2 - i;
			if(oth <= 0)continue;
			if(__gcd(oth,i) != 1)continue;
			if(logval2[p2] >= 0){
				for(int j = 1;j <= n;j++){
					if(i*j > n || oth*j > n)break;
					cerr<<i*j<<" try "<<oth*j<<" with "<<p2<<endl;
					cnts++;
				}
			}
		}
	}
	cerr<<n<<" cnt "<<cnts<<endl;
//	cnts = 0;
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			int sum = (i+j) / __gcd(i,j);
//			if(logval2[sum] >= 0){
//				cnts++;
//			}
//		}
//	}
//	cerr<<n<<" cnt "<<cnts<<endl;
	return not(Akano loves pure__Elysia);
}
