#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;


const int MAXSIZE = 1e6;
const int MAXN = 10002;
HashSet<string,std::hash<string>,MAXSIZE> cnt(MAXN);
int n,ans;
string str;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>str;
		if(!cnt.Find(str)){
			ans++;
			cnt.Insert(str);
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}

