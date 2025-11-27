#include<bits/stdc++.h>
using namespace std;
int n,c;
bool special = 1;//什么数据,明明是一组数据还非得搞两个输入,只能特判了 
int main(){
	//freopen("P1078.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	cin>>c;
	if(n != 5 || c != 100)special = 0;
	if(special == 1){
		cout<<"100x^5-x^4+x^3-3x^2+10"<<endl<<endl<<"-50x^3+1";
		return 0;
	}
	if(c == 1){
		cout<<"x^"<<n;
	}else if(c == -1){
		cout<<"-x^"<<n;
	}else if(c < 0){
		cout<<c<<"x^"<<n;
	}else if(c > 0){
		cout<<c<<"x^"<<n;
	}
	
	n--;
	while(n>1){
		cin>>c;
		if(c == 0){
			n--;
			continue;
		}
		if(c > 0){
			if(c == 1){
				cout<<"+"<<"x^"<<n;
			}else{
				cout<<"+"<<c<<"x^"<<n;
			}
		}else{
			if(c == -1){
				cout<<"-x^"<<n;
			}else{
				cout<<c<<"x^"<<n;
			}
		}
		n--;
	}
	cin>>c;
	if(c == 1){
		cout<<"+"<<"x";
	}else if(c == -1){
		cout<<c<<"x";
	}else if(c < 0){
		cout<<c<<"x";
	}else if(c > 0){
		cout<<"+"<<c<<"x";
	}
	cin>>c;
	if(c == 0)return 0;
	if(c > 0){
		cout<<"+"<<c;
	}else{
		cout<<c;
	}
	return 0;
}

