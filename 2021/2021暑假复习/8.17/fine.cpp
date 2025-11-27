#include<bits/stdc++.h>
using namespace std;
int n,i,j;
struct stu{
	int num,chi,math,eng,sum;
}s[200611];
bool comp(stu a,stu b){
	if(a.sum != b.sum)return a.sum > b.sum;
	if(a.chi != b.chi)return a.chi > b.chi;
	return a.num < b.num; 
}
int main(){
	freopen("fine.in","r",stdin);
	freopen("fine.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s[i].chi>>s[i].math>>s[i].eng;
		s[i].num = i+1,s[i].sum = s[i].chi + s[i].math + s[i].eng;
	}
	sort(s,s+n,comp);
	for(i = 0;i < 5;i++){
		cout<<s[i].num<<" "<<s[i].sum<<endl;
	}
	return 0;
}

