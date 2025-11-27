#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int t,n;
string str;
bool aWIN,bWIN;
inline void Check(int x,int y){
	int anum = 0,bnum = 0,wina = 0,winb = 0;
	for(int i = 1;i <= n;i++){
		if(str[i] == 'A'){
			anum++;
		}else{
			bnum++;
		}
		if(anum == x){
			wina++;
			anum = bnum = 0;
		}
		if(bnum == x){
			winb++;
			anum = bnum = 0;
		}
		if(wina == y){
			aWIN = true;
			return ;
		}
		if(winb == y){
			bWIN = true;
			return ;
		}
	}
	return ;
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>str;
		str = "." + str;
		aWIN = bWIN = false;
		for(int x = 1;x <= n;x++){
			for(int y = 1;y <= n;y++){
				Check(x,y);
			}
		}
		cerr<<aWIN<<" and "<<bWIN<<endl;
		if((aWIN && bWIN) || (!aWIN && !bWIN)){
			cout<<"?\n";
		}else if(aWIN){
			cout<<"A\n";
		}else{
			cout<<"B\n";
		}
	}
	return not(Akano loves pure__Elysia);
}
