#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
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
	cin>>n>>r>>b;
	cin>>str;
	if(r == 0 || b == 0){
		bool OK = (n % (b+r) == 0);
		for(auto i : str){
			if(r == 0 && i != 'B')OK = false;
			if(b == 0 && i != 'R')OK = false;
		}
		if(OK){
			cout<<"YES"<<endl;
			cout<<n / (r + b)<<endl;
			for(int i = 1,cnt = 0;i <= n / (r+b);i++){
				for(int j = 1;j <= r+b;j++){
					cnt++;
					cout<<cnt<<" ";
				}
				cout<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
		return not(Akano loves pure__Elysia); 
	}
	str = "." + str;
	for(int i = 1;i <= n;i++){
		tp++;
		stk[tp] = stk[tp-1];
		stk[tp].id = i,stk[tp].sumB += (str[i] == 'B'),stk[tp].sumR += (str[i] == 'R');
		if(Check()){
			PushAns();
		}
	}
	if(tp == 0){
		reverse(otp.begin(),otp.end());
		cout<<"YES"<<endl;
		cout<<n / (r + b)<<endl;
		for(int i = 1,cnt = 0;i <= n / (r+b);i++){
			for(int j = 1;j <= r+b;j++){
				cout<<otp[cnt]<<" ";
				cnt++;
			}
			cout<<endl;
		}
	}else{
		cout<<"NO"<<endl;
	}
	return not(Akano loves pure__Elysia);
}
