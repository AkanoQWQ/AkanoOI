#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108 + 1000;
namespace BigintSpace{
	using Bigint = __int128;
	ostream& operator<<(ostream& os,Bigint bint){
		string otp;
		if(bint < 0){
			os<<'-';
			bint = -bint;
		}else if(bint == 0){
			os<<'0';
		}
		while(bint){
			otp += (bint % 10) + '0';
			bint /= 10;
		}
		reverse(otp.begin(),otp.end());
		os<<otp;
		return os;
	}
	istream& operator>>(istream& is,Bigint& bint){
		bool f = false;
		bint = 0;
		char ch = is.get();
		while(!isdigit(ch) && !is.fail()){
			if(ch == '-')f = true;
			ch = is.get();
		}
		while(isdigit(ch) && !is.fail()){
			bint = bint * 10 + ch - '0';
			ch = is.get();
		}
		if(f)bint = -bint;
		return is;
	}
}
using namespace BigintSpace;
int n,k,a[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>bi;
	const Bigint bii = bi;
	Bigint biii = 0;
	biii = bi + bii;
	cout<<bii<<endl;
	return 0;
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	return not(Akano loves pure__Elysia);
}
