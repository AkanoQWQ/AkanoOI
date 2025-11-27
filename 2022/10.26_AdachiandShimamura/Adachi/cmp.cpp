#include<bits/stdc++.h>
using namespace std;
int a[2000006],b[2000006],c,tail;
int main(){
	freopen("chess.out","r",stdin);
	cin.clear();
	tail = 0;
	while(cin>>c){
		a[++tail] = c;
	}
	cin.clear();
	freopen("chess.ans","r",stdin);
	cin.clear();
	tail = 0;
	while(cin>>c){
		b[++tail] = c;
	}
	for(int i = 1;i <= tail;i++){
		if(a[i] != b[i]){
			cout<<"WA! read "<<a[i]<<" ,expected "<<b[i]<<" in "<<i<<endl;
			return 0;
		}
	}
    return 0;
}
//4008

