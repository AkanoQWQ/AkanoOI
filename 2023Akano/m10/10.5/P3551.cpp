#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int n,r,b,tp;
struct Node{
	int sumR,sumB,id;
	Node() = default;
	Node(int _sumR,int _sumB,int _id){
		sumR = _sumR,sumB = _sumB,id = _id;
		return ;
	}
};
Node stk[MAXN];
string str;
inline bool Check(){
	if(tp < r+b)return false;
	return (stk[tp].sumR - stk[tp-r-b].sumR) == r;
}
vector<int> otp;
inline void PushAns(){
	for(int i = 1;i <= r+b;i++){
		otp.push_back(stk[tp--].id);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>b;
	r = 1;
	cin>>str;
	str = "." + str;
	for(int i = 1;i <= n;i++){
		tp++;
		stk[tp] = stk[tp-1];
		stk[tp].id = i,stk[tp].sumB += (str[i] == 'b'),stk[tp].sumR += (str[i] == 'c');
		if(Check()){
			PushAns();
		}
	}
	reverse(otp.begin(),otp.end());
	for(int i = 1,cnt = 0;i <= n / (r+b);i++){
		for(int j = 1;j <= r+b;j++){
			cout<<otp[cnt]<<" ";
			cnt++;
		}
		cout<<endl;
	}
	return not(Akano loves pure__Elysia);
}
