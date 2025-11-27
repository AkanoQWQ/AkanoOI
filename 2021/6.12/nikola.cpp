#include<bits/stdc++.h>
using namespace std;
struct state{
	int pos,steps,spends;
}states[1006];
int s[1006],head = 0,tail = 1,ans = 1000000,n,i,went[1006];
int main(){
	freopen("nikola.in","r",stdin);
	freopen("nikola.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>s[i];
	}
	states[0].pos = 1;
	states[0].steps = 1;
	states[0].spends = 0;
	while(head < tail){//3 2
		if(states[head].pos > states[head].steps){
			states[tail].pos = states[head].pos - states[head].steps;
			if(went[states[tail].pos] == 0){
				states[tail].spends += s[states[tail].pos];
				states[tail].steps++;
				tail++;
			}
			went[states[tail].pos] = 1;
		}
		if((n - states[head].pos) >= states[head].steps){//5 8 3
			states[tail].pos = states[head].pos + states[head].steps;
			if(went[states[tail].pos] == 0){
			states[tail].spends += s[states[tail].pos];
			states[tail].steps++;
			tail++;
			}
			went[states[tail].pos] = 1;
		}
		if(states[head].pos == n){
			ans = min(states[head].spends,ans);
		}
		head++;
	}
	cout<<ans;
	return 0;
}

