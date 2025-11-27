#include<bits/stdc++.h>
using namespace std;
int n,i;
struct stu{
	int math,chi,eng,tot,num;
}s[2006];
bool cmp(stu a,stu b){
	if(a.tot != b.tot)return a.tot > b.tot;
	if(a.chi != b.chi)return a.chi > b.chi;
	return a.num < b.num;
}
int main(){
	//freopen("P1063.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s[i].chi>>s[i].math>>s[i].eng;
		s[i].tot = s[i].chi + s[i].eng + s[i].math,s[i].num = i+1;
	}
	sort(s,s+n,cmp);
	for(i = 0;i < 5;i++){
		cout<<s[i].num<<" "<<s[i].tot<<endl;
	}
	return 0;
}

