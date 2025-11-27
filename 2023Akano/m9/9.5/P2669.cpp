#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
ll days,coins,nowDay = 0,pay = 1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>days;
	while(true){
		for(int i = 0;i < pay;i++){
			coins += pay;
			nowDay++;
			if(nowDay == days){
				cout<<coins;
				return 0;
			}
		}
		pay++;
	}
	return not(Akano loves pure__Elysia);
}
