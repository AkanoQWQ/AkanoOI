#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,ma[886][886],maxma[886][886],head,tail,ans = 0,c;
struct step{
	int x,y,num;
}s[2500000],s2[2500000];//32000000
int main(){
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			cin>>ma[i][j];
		}
	}
	tail = 1;
	s[0].x = 1,s[0].y = 1,s[0].num = ma[1][1];
	while(head < tail){
		//cout<<s[head].x<<" "<<s[head].y<<" "<<s[head].num<<endl;
		if(s[head].num <= ans){
			head++;
			continue;
		}
		if(s[head].num <= maxma[s[head].x][s[head].y]){
			head++;
			continue;
		}else{
			maxma[s[head].x][s[head].y] = s[head].num;
		}
		if(s[head].x == n && s[head].y == m && s[head].num > ans){
			ans = s[head].num;
			maxma[n][m] = min(maxma[n][m],ans);
		}
		if(s[head].x > 1){
			s[tail].x = s[head].x - 1,s[tail].y = s[head].y;
			s[tail].num = min(s[head].num,ma[s[tail].x][s[tail].y]);
			tail++;
		}
		if(s[head].y > 1){
			s[tail].y = s[head].y - 1,s[tail].x = s[head].x;
			s[tail].num = min(s[head].num,ma[s[tail].x][s[tail].y]);
			tail++;
		}
		if(s[head].x < n){
			s[tail].x = s[head].x + 1,s[tail].y = s[head].y;
			s[tail].num = min(s[head].num,ma[s[tail].x][s[tail].y]);
			tail++;
		}
		if(s[head].y < n){
			s[tail].x = s[head].x,s[tail].y = s[head].y + 1;
			s[tail].num = min(s[head].num,ma[s[tail].x][s[tail].y]);
			tail++;
		}
		head++;
		if(tail >= 2490000){
			for(i = head;i < tail;i++){
				s2[i-head] = s[i];
			}
			memset(s,0,sizeof(s));
			for(i = 0;i < tail-head;i++){
				s[i] = s2[i];
			}
			c = tail-head;
			head = 0;
			tail = c;
		}
	}
	cout<<ans; 
	return 0;
}

