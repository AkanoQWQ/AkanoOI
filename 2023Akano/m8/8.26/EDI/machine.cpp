#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
const int TOT_MAXN = 3000 + 2006 + 1018 + 1108;
int n,m,q,arr[TOT_MAXN];
bool defkol[TOT_MAXN],kol[TOT_MAXN];//0red 1blue
char ch;
namespace Subtask1{
	inline void Execute(int x){
		int tail = arr[x];
		kol[tail] = 0;
		while(1 <= tail && tail <= n){
			if(kol[tail]){
				kol[tail] = !kol[tail];
				tail--;
			}else{
				kol[tail] = !kol[tail];
				tail++;
			}
		}
		return ;
	}
	inline void Solve(){
		cin>>q;
		for(int i = 1;i <= q;i++){
			int l,r;
			cin>>l>>r;
			for(int i = 1;i <= n;i++)kol[i] = defkol[i];
			for(int i = l;i <= r;i++){
				Execute(i);
			}
			int ret = 0;
			for(int i = 1;i <= n;i++)ret += (!kol[i]);
			cout<<ret<<endl;
		}
		return ;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>ch;
		defkol[i] = (ch == 'B');
	}
	for(int i = 1;i <= m;i++)cin>>arr[i];
	if(true){
		Subtask1::Solve();
	} 
	return (Akano loves pure__Elysia);
}
