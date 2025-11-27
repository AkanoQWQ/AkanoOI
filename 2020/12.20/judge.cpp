#include<bits/stdc++.h>
using namespace std;
int n,i,j,a,w,t,r;
string s;

int main(){
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s;
		if(s == "AC"){
			a++;
		}
		if(s == "WA"){
			w++;
		}
		if(s == "TLE"){
			t++;
		}
		if(s == "RE"){
			r++;
		}
	}
	cout<<"AC x "<<a<<endl;
	cout<<"WA x "<<w<<endl;
	cout<<"TLE x "<<t<<endl;
	cout<<"RE x "<<r<<endl;
	return 0;
}
