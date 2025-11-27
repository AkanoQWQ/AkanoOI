#include<bits/stdc++.h>
using namespace std;
int h,w,i,j,cachex,cachey,cache,ans,aans;
char gc[21][21];
int walk(int x,int y,int mubiaox,int mubiaoy,int bu,int cachex,int cachey){
	int ll,rr,ss,xx,cacheans;
	cout<<x<<" "<<y<<endl;
	if(x == mubiaox && y == mubiaoy){
		if(aans > bu){
			aans = bu;
		}
		return bu;
	}
	cacheans = 99999;
	if(x > 0){
		if(gc[x-1][y] == '.'&&x-1 != cachex){
			ll = walk(x-1,y,mubiaox,mubiaoy,bu+1,x,y);
		}
	}
	if(y > 0){
		if(gc[x][y-1] == '.'&&y-1 != cachey){
			rr = walk(x,y-1,mubiaox,mubiaoy,bu+1,x,y);
		}
	}
	if(x < h-1){
		if(gc[x+1][y] == '.'&&x+1 != cachex){
			ss = walk(x+1,y,mubiaox,mubiaoy,bu+1,x,y);
		}
	}
	if(y < w-1){
		if(gc[x][y+1] == '.'&&y+1 != cachey){
			xx = walk(x,y+1,mubiaox,mubiaoy,bu+1,x,y);
		}
	}
	if(ll < cacheans)cacheans = ll;
	if(rr < cacheans)cacheans = rr;
	if(ss < cacheans)cacheans = ss;
	if(xx < cacheans)cacheans = xx;
	if(cacheans != 99999){
		return cacheans;
	}
	return bu;
}
int main(){
	freopen("gc.in","r",stdin);
	freopen("gc.out","w",stdout);
	cin>>h>>w;
	for(i = 0;i < h;i++){
		for(j = 0;j < w;j++){
			cin>>gc[i][j];
		}
	}
	
	cache = walk(0,0,h-1,w-1,0,0,0);
	if(cache > ans){
		ans = cache;
	}
	cache = walk(0,w-1,h-1,0,0,0,0);
	if(cache > ans){
		ans = cache;
	}
	cache = walk(h-1,0,0,w-1,0,0,0);
	if(cache > ans){
		ans = cache;
	}
	cache = walk(h-1,w-1,0,0,0,0,0);
	if(cache > ans){
		ans = cache;
	}
	
	cout<<ans<<" "<<aans;
	cout<<0;
	return 0;
}
