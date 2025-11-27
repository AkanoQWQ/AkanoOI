#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

BasicTreap<int> tr;
int n,q,lastans,ans;
inline int Read(){//no f
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar(); 
	}
	return ret;
}
int main(){
	n = Read(),q = Read();
	for(int i = 1;i <= n;i++){
		int x = Read();
		tr.Insert(x);
	}
	while(q--){
		int opt = Read(),x = Read();
		x ^= lastans;
		if(opt == 1){
			tr.Insert(x);
		}else if(opt == 2){
			tr.Delete(x);
		}else if(opt == 3){
			lastans = tr.GetRank(x);
			ans ^= lastans;
		}else if(opt == 4){
			lastans = tr.GetVal(x);
			ans ^= lastans;
		}else if(opt == 5){
			lastans = tr.GetPre(x).first;
			ans ^= lastans;
		}else if(opt == 6){
			lastans = tr.GetNext(x).first;
			ans ^= lastans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
