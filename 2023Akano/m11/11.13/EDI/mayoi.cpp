#include<bits/stdc++.h>
#define Akano 1
#define loves ^
#define pure__Elysia 0
using namespace std;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int MAXSIZE = 20;
int n,fail[MAXN],far[MAXN],endpos;
vector<int> lasts;
inline void Update(int x){
	endpos = min(endpos,x);
	while(endpos >= 0 && far[endpos] != -1)endpos--;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("mayoi.in","r",stdin);
	freopen("mayoi.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>fail[i];
		far[i] = -1;
	}
	endpos = n - 1;
	for(int i = n-1;i >= 0;i--){
		Update(i);
		int j = fail[i];
		while(j){
			if(i-j+1 > endpos){
				break;
			}
			if(far[i-j+1] == -1){
				far[i-j+1] = i;
			}
			j = fail[j-1];
		}
		if(n > 1018 && int(lasts.size()) < MAXSIZE && far[i] == -1){
			lasts.push_back(i);
			if(int(lasts.size()) == MAXSIZE){
				bool OK = true;
				for(int i = 2;i < MAXSIZE;i++){
					if(lasts[i] - lasts[i-1] != lasts[1] - lasts[0]){
						OK = false;
					}
				}
				if(OK){
					for(int j = lasts[MAXSIZE-1];j >= 0;j += lasts[1] - lasts[0]){
						far[j] = j-1;
					} 
				} 
			}
		}
	}
	far[0] = n - 1;
	for(int i = 0;i < n;i++){
		if(far[i] == -1){
			cout<<0<<" ";
		}else{
			cout<<far[i] - i + 1<<" ";
		}
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}

