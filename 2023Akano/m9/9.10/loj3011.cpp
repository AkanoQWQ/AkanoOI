#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
int n,m,container[MAXN],ans;
struct Painting{
	int siz,value;
}p[MAXN];
bool Cmp(Painting p1,Painting p2){
	if(p1.value != p2.value)return p1.value > p2.value;
	return p1.siz > p2.siz;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>p[i].siz>>p[i].value;
	}
	for(int i = 1;i <= m;i++){
		cin>>container[i];
	}
	sort(p+1,p+n+1,Cmp);
	sort(container+1,container+m+1,greater<int>());
	int tail = 1;
	for(int i = 1;i <= n;i++){
		if(tail <= m && p[i].siz <= container[tail]){
			ans++;
			tail++;
		}
	}
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
/*
7:20
*/
