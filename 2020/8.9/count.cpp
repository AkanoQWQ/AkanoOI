#include<bits/stdc++.h>
using namespace std;
priority_queue <int> stu;
int n,i,j,cache,class_cache[5];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>class_cache[0]>>class_cache[1]>>class_cache[2]>>class_cache[3]>>class_cache[4];
		cache = class_cache[0]+class_cache[1]+class_cache[2]+class_cache[3]+class_cache[4];
		stu.push(cache);
	}
	for(i = 0;i < n;i++){
		cout<<stu.top()<<" ";
		stu.pop();
	}
	return 0;
}
