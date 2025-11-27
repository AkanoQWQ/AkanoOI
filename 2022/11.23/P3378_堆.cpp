#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,opt,x; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	while(n--){
		cin>>opt;
		if(opt == 1){
			cin>>x;
			q.push(x);
		}else if(opt == 2){
			cout<<q.top()<<endl;
		}else{
			q.pop();
		}
	}
	return 0;
}

