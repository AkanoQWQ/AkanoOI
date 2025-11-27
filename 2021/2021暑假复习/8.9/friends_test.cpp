#include<bits/stdc++.h>
using namespace std;
struct name{
	string xing,ming;
	int num,xt;//xing_times
}names[198964];
string a,b;
int i,j,t,nums[198964],cnt,n;
bool comp(name a,name b){
	if(a.xt != b.xt)return a.xt > b.xt;
	return a.num < b.num;
}
int main(){
	freopen("friends.in","r",stdin);
	freopen("friends.out","w",stdout);
	while(cin>>a){
		cin>>b;
		names[i].xing = a;
		names[i].ming = b;
		names[i].num = i;
		i++;
	}
	n = i;
	for(i = 0;i < n;i++){
		if(names[i].xt != 0)continue;
		a = names[i].xing;
		memset(nums,0,sizeof(nums));
		nums[0] = i;
		t = 1;
		cnt = 1;
		for(j = 0;j < n;j++){
			if(i != j && names[i].xing == names[j].xing){
				cnt++;
				nums[t] = j;
				t++;
			}
		}
		for(j = 0;j < t;j++){
			names[nums[j]].xt = cnt;
			//cout<<names[nums[j]].xing<<" "<<names[nums[j]].ming<<":"<<names[nums[j]].xt<<",in the turn"<<i<<endl;
		}
	}
	sort(names,names+n,comp);
	for(i = 0;i < n;i++){
		cout<<names[i].xing<<" "<<names[i].ming<<endl;
	}
	return 0;
}

