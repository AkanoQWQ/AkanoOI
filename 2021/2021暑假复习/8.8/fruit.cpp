#include<bits/stdc++.h>
using namespace std;
long long n,i,ans,c,c2;
bool comp(int a,int b){
	return a>b;
}



priority_queue<int,vector<int>,greater<int> >a;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>c;
		a.push(c);
	}
	while(!a.empty()){
		c = a.top();
		a.pop();
		if(a.empty()){
			break;
		}
		c2 = a.top();
		a.pop();
		c += c2;
		ans += c;
		a.push(c);
	}
	cout<<ans;
	return 0;
}

