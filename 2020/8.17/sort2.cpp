#include<bits/stdc++.h>
using namespace std;
struct stu{
	int zong,math;
}a[100001];
int comp(stu a,stu b){
	return a.zong>b.zong;
}
int i,n;
int main(){
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>a[i].zong>>a[i].math;
	}
	cout<<endl;
	sort(a+1,a+n+1,comp);
	for(i = 1;i <= n;i++){
		cout<<a[i].zong<<" "<<a[i].math<<endl;
	}
	return 0; 
}
//
//
//
//
//
