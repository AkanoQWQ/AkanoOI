#include<bits/stdc++.h>
using namespace std;
string str;
int cnt,n;
bool A,B,C;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>str;
	for(auto i : str){
		++cnt;
		A |= (i == 'A');
		B |= (i == 'B');
		C |= (i == 'C');
		if(A && B && C){
			cout<<cnt<<endl;
			return 0;
		}
	}
	return 0;
}

