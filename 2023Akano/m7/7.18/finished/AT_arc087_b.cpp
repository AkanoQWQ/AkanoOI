#include<bits/stdc++.h>
using namespace std;
const int PY = 8006;
const int n = PY + 8006 + 2;
const int MAXN = n + 1018 + 1108;
string ord;
int x,y,step;
bool ST = true,NOWX = true;
bool OKX[MAXN],OKY[MAXN],k[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("ARC087.in","r",stdin); 
	cin>>ord>>x>>y;
	x += PY,y += PY;
	OKX[PY] = OKY[PY] = true;
	ord += "T";
	for(auto i : ord){
		if(i == 'F'){
			step++;
		}else{
			if(ST){
				x -= step;
				ST = false;
			}else{
				memset(k,0,sizeof(k));
				if(NOWX){
					for(int i = 0;i <= n;i++){
						if(i - step >= 0){
							k[i-step] |= OKX[i];
						}
						if(i + step <= n){
							k[i+step] |= OKX[i];
						}
					}
					for(int i = 0;i <= n;i++)OKX[i] = k[i];
				}else{
					for(int i = 0;i <= n;i++){
						if(i - step >= 0){
							k[i-step] |= OKY[i];
						}
						if(i + step <= n){
							k[i+step] |= OKY[i];
						}
					}
					for(int i = 0;i <= n;i++)OKY[i] = k[i];
				}
			}
			NOWX = !NOWX;
			step = 0;
		}
	}
	if(OKX[x] && OKY[y]){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

