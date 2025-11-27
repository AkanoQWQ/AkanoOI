#include<bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int t,n,a[MAXN],k,alivenum,can;
struct snake{
	int v,no;
	bool alive;
}s[MAXN],cache[MAXN];
struct node{
	snake sv[MAXN];
	int liven;
};
inline void save(node& a){
	a.liven = alivenum;
	for(int i = 1;i <= n;i++){
		a.sv[i] = s[i];
	}
	return ;
}
inline void load(node& a){
	alivenum = a.liven;
	for(int i = 1;i <= n;i++){
		s[i] = a.sv[i];
	}
	return ;
}
bool survive(int killed,int subject){
	alivenum--;
	s[killed].alive = 0;
	s[subject].v -= s[killed].v;
	if(alivenum == 1)return 1;//自己活下来了 
	int strong = 0,weak = n + 1;
	for(int i = 1;i <= n;i++){
		if(s[i].alive == 0)continue;
		if(s[i].v >= s[strong].v){
			strong = i;
		}
		if(s[i].v < s[weak].v){
			weak = i;
		}
	}
	node SNK_SAVE;
	save(SNK_SAVE);
	if(survive(weak,strong)){
		//do nothing because function "survive" has executed
	}else{
		load(SNK_SAVE);//delete kill
	}
	return s[subject].alive;
}
void calc(){
	for(int i = 1;i <= n;i++){
		s[i].v = a[i];
		s[i].no = i;
		s[i].alive = 1;
	}
	alivenum = n;
	s[0].v = -1,s[n+1].v = 0x7fffffff;
	if(survive(1,n)){
		//qwq owo uwu
	}else{
		alivenum = n;//do nothing
	}
	printf("%d\n",alivenum);
	return ;
}
int main(){
//	freopen("snakes.in","r",stdin);
//	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	t--;
	cin>>n;
	if(n >= 20){
		for(int i = 1;i <= t+1;i++){
			cout<<n<<endl;
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	calc();
	if(t == 0)return 0;
	while(t--){
		scanf("%d",&k);
		for(int i = 1;i <= k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x] = y;
		}
		calc();
	}
	return 0;
}
