#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const int MAXN = 1e6 + 1018 + 1108;
int n,m;
struct Rule{
	int l,r;
	ull x;
}rule[MAXN];
bool OK[MAXN];
int segCnt[MAXN],doubleSegCnt[MAXN],illegalCnt[MAXN];
ull mx;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>rule[i].l>>rule[i].r>>rule[i].x;
		OK[i] = true;
		mx = max(mx,rule[i].x);
	}
	for(int w = 0;w < 64 && (1ull<<w) <= mx;w++){
		memset(segCnt,0,sizeof(segCnt));//覆盖了多少次
		for(int i = 1;i <= m;i++){
			if(1ull<<w & rule[i].x){
				segCnt[rule[i].l]++,segCnt[rule[i].r+1]--;
			}
		}
		for(int i = 1;i <= n;i++){
			segCnt[i] += segCnt[i-1];
			doubleSegCnt[i] = doubleSegCnt[i-1] + (segCnt[i] >= 2);
			illegalCnt[i] = illegalCnt[i-1] + (segCnt[i] > 0);
		}
		int onlyNo = 0,illegalSeg = 0;
		int leftest = n,rightest = 1;
		bool illegal2 = false;
		for(int i = 1;i <= m;i++){
			if(not(1ull<<w & rule[i].x)){
//				cerr<<i<<" illtot "<<(illegalCnt[rule[i].r] - illegalCnt[rule[i].l-1])<<" compare "<<rule[i].r - rule[i].l + 1<<endl;
				if(illegalCnt[rule[i].r] - illegalCnt[rule[i].l-1] == rule[i].r - rule[i].l + 1){
//					cerr<<i<<" ill in "<<w<<endl;
					leftest = min(leftest,rule[i].r);
					rightest = max(rightest,rule[i].l);
					onlyNo = i,illegalSeg++;
				}
				if(doubleSegCnt[rule[i].r] - doubleSegCnt[rule[i].l-1] == rule[i].r - rule[i].l + 1){
//					cerr<<"in "<<rule[i].l<<" to "<<rule[i].r<<" appear ill2!!!"<<endl;
					illegal2 = true;
				}
			}
		}
		if(illegalSeg > 0){
			for(int i = 1;i <= m;i++){
				if(not(1ull<<w & rule[i].x)){
					if(not(illegalSeg == 1 && i == onlyNo)){
//						if(OK[i] == true)cerr<<i<<" ill 1 in "<<w<<endl;
						OK[i] = false;
					}
				}
			}
		}
		if(illegal2){
			for(int i = 1;i <= m;i++){
				if(not(illegalSeg == 1 && i == onlyNo)){
//					if(OK[i] == true)cerr<<i<<" ill 2 in "<<w<<endl;
					OK[i] = false;
				}
			}
		}
		for(int i = 1;i <= m;i++){
			if(1ull<<w & rule[i].x){
//				cerr<<i<<" is "<<rule[i].l<<" to "<<rule[i].r<<" compare "<<leftest<<" to "<<rightest<<endl;
				if(rule[i].l > leftest || rule[i].r < rightest){
//					if(OK[i] == true)cerr<<i<<" ill 3 in "<<w<<endl;
					OK[i] = false;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++)cout<<OK[i];
	return not(Akano loves pure__Elysia);
}
