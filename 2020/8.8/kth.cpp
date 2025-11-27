#include<bits/stdc++.h>
using namespace std;
priority_queue <int> stu; 
int i,j,n,cache,k,ans[100001];
char cache_char;
int main(){
	scanf("%d",&n);
	scanf("%d",&k);
	for(i = 0;i < n;i++){
		cin>>cache_char;
		if(cache_char == 'I'){
			scanf("%d",&cache);
			if(stu.size() < k){
				stu.push(-cache);
			}else{
				if(-cache < stu.top()){
					stu.push(-cache);
					stu.pop();
				}
			}
		}else{
			ans[j] = -stu.top();
			j++;
		}
	}
	for(i = 0;i < j;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
