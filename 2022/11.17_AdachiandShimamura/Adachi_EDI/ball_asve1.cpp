#include<bits/stdc++.h>
using namespace std;
const int MAXN = 56;
const int MAXM = 506;
const int MAXK = 820006;
pair<int,int> rem[MAXK];
int ktail;
int n,m;
struct koloro_stack{
	int l[MAXM],tail,no;
	inline int& operator[](int n){
		return l[n];
	}
	inline int top(){
		return l[tail];
	}
	inline int get_top(){
		return l[tail--];
	}
	inline void ins(int inx){
		l[++tail] = inx;
		return ;
	}
	inline int count(int md){
		int ret = 0;
		for(int i = 1;i <= tail;i++){
			ret += l[i] > md;
		}
		return ret;
	}
	inline bool empty(){
		return tail <= 0;
	}
}k[MAXN];
void movek(koloro_stack from,koloro_stack to){
	const int tp = from.get_top();
	to.ins(tp);
	++ktail;
	rem[ktail].first = from.no,rem[ktail].second = to.no;
	return ;
}
int sort_array[MAXM*4],sat;
void (&koloro_stack from,&koloro_stack to,&koloro_stack h,&koloro_stack n){
	sat = 0;
	for(int i = 1;i <= from.tail;i++){
		sort_array[++sat] = from[i];
	}
	for(int i = 1;i <= to.tail;i++){
		sort_array[++sat] = to[i];
	}
	sort(sort_array+1,sort_array+sat+1);
	const int mid = sort_array[(from.tail + to.tail) / 2];//left <=
	const int a = from.count(mid);
	for(int i = 1;i <= a;i++){
		move(h,n);
	}
	while(!from.empty()){
		if(from.top() > mid){
			move(from,h);
		}else{
			move(from,n);
		}
	}
	for(int i = 1;i <= m-a;i++){
		move(n,from);
	}
	while(!to.empty()){
		if(to.top() > mid){
			move(to,n);
		}else{
			move(to,x);
		}
	}
	for(int i = 1;i <= m-a;i++){
		move(n,to);
	}
	return ;
}
int main(){
	//freopen("ball.in","r",stdin);
	//freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		k[i].no = i;
		for(int j = 1;j <= n;j++){
			int inx;
			scanf("%d",&inx);
			k[i].ins(inx);
		}
	}
	return 0;
}

