#include<bits/stdc++.h>
using namespace std;
struct stu{
	int zong,math,hao;
}a[100001];
int comp(stu a,stu b){
	if(a.zong != b.zong){
		return a.zong > b.zong;
		if(a.math!= b.math){
			return a.math > b.math;
		}else{
			return a.hao > b.hao;
		}
	}
}
int i,n;
int main(){
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>a[i].zong>>a[i].math>>a[i].hao;
	}
	cout<<endl;
	sort(a+1,a+n+1,comp);
	for(i = 1;i <= n;i++){
		cout<<a[i].zong<<" "<<a[i].math<<" "<<a[i].hao<<endl;
	}
	return 0; 
}

