#include<bits/stdc++.h>
using namespace std;
priority_queue <int> fruit;
int n,i,ans,tmp,cache;
int main(){
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&cache);
		fruit.push(-cache);
	}
	for(i = 1;i < n;++i){
		tmp = fruit.top();
		fruit.pop();
		tmp += fruit.top();
		fruit.pop();
		ans -= tmp;
		fruit.push(tmp);
	}
	printf("%d",ans);
	return 0;
}
