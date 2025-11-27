#include<bits/stdc++.h>
const int num = 100;
using namespace std;
class bian{
	public:
		int bian[num];
		bool tong(int x){
			return bian[x];
		};
		int llong(int x){
			return bian[x];
		};
}bian[num];
int a,b,c,n,m,i;
int main(){
	freopen()
	cin>>n>>m;
	for(i = 0;i <= m;i++){
		cin>>a>>b>>c;
		bian[a].bian[b] = c;
		bian[b].bian[a] = c;
	}
	return 0;
}
