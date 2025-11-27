#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
int n,m1,m2,ans;
struct plane{
	int a,b;
}p1[MAXN],p2[MAXN];
bool cmp4plane(plane a,plane b){
	return a.a < b.a;
}
struct node{
	int v,no;
	friend bool operator<(node a,node b){
		return a.v < b.v;
	}
};
/*struct node{//原本的写法 
	int v,no;
	operator <(const node a)const{
		return this->v > a.v;
	}
};*/
priority_queue<node> wating;
priority_queue<int> poss;
int s1[MAXN],s2[MAXN];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= m1;i++){
		scanf("%d%d",&p1[i].a,&p1[i].b);
	}
	for(int i = 1;i <= m2;i++){
		scanf("%d%d",&p2[i].a,&p2[i].b);
	}
	sort(p1+1,p1+m1+1,cmp4plane);
	sort(p2+1,p2+m2+1,cmp4plane);
	for(int i = 1;i <= n;i++){
		poss.push(-i);
	}
	for(int i = 1;i <= m1;i++){
		while(!wating.empty() && wating.top().v <= p1[i].a){
			poss.push(wating.top().no);
			wating.pop();
		}
		int choice = -1;
		if(!poss.empty()){
			choice = -poss.top();
			node cn;
			cn.no = poss.top(),cn.v = p1[i].b;
			wating.push(cn);
			poss.pop();
		}
		if(choice != -1){
			s1[choice]++;
		}
	}
	while(!poss.empty())poss.pop();
	while(!wating.empty())wating.pop();
	for(int i = 1;i <= n;i++){
		poss.push(-i);
	}
	for(int i = 1;i <= m2;i++){
		while(!wating.empty() && wating.top().v <= p2[i].a){
			poss.push(wating.top().no);
			wating.pop();
		}
		int choice = -1;
		if(!poss.empty()){
			choice = -poss.top();
			node cn;
			cn.no = poss.top(),cn.v = p2[i].b;
			wating.push(cn);
			poss.pop();
		}
		if(choice != -1){
			s2[choice]++;
		}
	}
	for(int i = 1;i <= n;i++){
		s1[i] += s1[i-1];
		s2[i] += s2[i-1];
	}
	for(int i = 0;i <= n;i++){
		ans = max(ans,s1[i]+s2[n-i]);
	}
	printf("%d",ans);
	return 0;
}
