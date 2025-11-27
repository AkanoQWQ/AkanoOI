#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ks koloro_stack
FILE_ST
const int MAXN = 56;
const int MAXM = 506;
const int MAXK = 820006;
pair<int,int> rem[MAXK];
int ktail;
int n,m;
struct koloro_stack{
	int l[MAXM],tail,no,obj;
	bool bg[MAXM];
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
	inline int count(){
		int ret = 0;
		for(int i = 1;i <= tail;i++){
			ret += bg[i];
		}
		return ret;
	}
	inline bool empty(){
		return tail <= 0;
	}
	inline int get_max(){
		int ret = 0;
		for(int i = 1;i <= tail;i++){
			if(l[i] > ret)ret = l[i];
		}
		return ret;
	}
	inline bool topb(){
		return bg[tail];
	}
	inline void show(){
		cout<<no<<":";
		for(int i = 1;i <= tail;i++){
			cout<<l[i]<<" ";
		}
		cout<<endl;
		return ;
	}
}k[MAXN];
inline void move(ks& from,ks& to){
	const int tp = from.get_top();
	swap(from.obj,to.obj);
	to.ins(tp);
	++ktail;
	rem[ktail].first = from.no,rem[ktail].second = to.no;
	return ;
}
pair<int,pair<int,int> > sort_array[MAXM*4];
inline void div(ks& from,ks& to,ks& h,ks& nk){
	int sat = 0;
	for(int i = 1;i <= from.tail;i++){
		sort_array[++sat] = make_pair(from[i],make_pair(1,i));
	}
	for(int i = 1;i <= to.tail;i++){
		sort_array[++sat] = make_pair(to[i],make_pair(2,i));
	}
	sort(sort_array+1,sort_array+sat+1);
	for(int i = 1;i <= (from.tail + to.tail) / 2;i++){
		if(sort_array[i].second.first == 1){
			from.bg[sort_array[i].second.second] = 0;
		}else{
			to.bg[sort_array[i].second.second] = 0;
		}
	}
	for(int i = (from.tail + to.tail)/2+1;i <= sat;i++){
		if(sort_array[i].second.first == 1){
			from.bg[sort_array[i].second.second] = 1;
		}else{
			to.bg[sort_array[i].second.second] = 1;
		}
	}
	const int a = from.count();
	for(int i = 1;i <= a;i++){
		move(h,nk);
	}
	while(!from.empty()){
		if(from.topb()){
			move(from,h);
		}else{
			move(from,nk);
		}
	}
	for(int i = 1;i <= m-a;i++){
		move(nk,from);
	}
	while(!to.empty()){
		if(to.topb()){
			move(to,nk);
		}else{
			move(to,from);
		}
	}
	for(int i = 1;i <= m-a;i++){
		move(nk,to);
	}
	for(int i = 1;i <= a;i++){
		move(h,to);
	}
	for(int i = 1;i <= a;i++){
		move(nk,h);
	}
	return ;
}
inline void fully_move(ks& x,ks& y,ks& cache){
	swap(x.obj,y.obj);
	while(!x.empty()){
		move(x,cache);
	}
	while(!y.empty()){
		move(y,x);
	}
	while(!cache.empty()){
		move(cache,y);
	}
	return ;
}
inline int fd(int a,int b){
	if(a != 1 && b != 1)return 1;
	if(a != 2 && b != 2)return 2;
	return 3;
}
int o2[MAXN];
bool cmp(ks a,ks b){
	return a.get_max() < b.get_max();
}
void merge_sort(int l,int r){
	if(l == r){
		return ;
	}
	const int mid = (l + r) >> 1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int x = l,y = mid + 1,t = l;
	cout<<endl<<l<<"|||"<<mid<<"|||"<<r<<endl;
	while(x <= mid && y <= r){
		if(k[x].get_max() < k[y].get_max()){
			div(k[x],k[y],k[fd(x,y)],k[n+1]);
			o2[t] = x;
			cout<<"o2["<<t<<"] is "<<x<<endl;
			k[x].obj = t++;
			cout<<"k["<<x<<"] obj "<<k[x].obj<<endl;
			x++;
		}else{
			div(k[y],k[x],k[fd(x,y)],k[n+1]);
			cout<<"o2["<<t<<"] is "<<y<<endl;
			o2[t] = y;
			k[y].obj = t++;
			cout<<"k["<<y<<"] obj "<<k[y].obj<<endl;
			y++;
		}
	}
	while(x <= mid){
		o2[t] = x;
		cout<<"o2["<<t<<"] is "<<x<<endl;
		k[x].obj = t++;
		cout<<"k["<<x<<"] obj "<<k[x].obj<<endl;
		x++;
	}
	while(y <= r){
		o2[t] = y;
		cout<<"o2["<<t<<"] is "<<y<<endl;
		k[y].obj = t++;
		cout<<"k["<<y<<"] obj "<<k[y].obj<<endl;
		y++;
	}
	for(int i = l+1;i <= r;i++){
		if(k[o2[i]].get_max() < k[o2[i-1]].get_max()){
			puts("ERR");
			break;
		}
	}
	cout<<endl;
	for(int i = l;i <= r;i++){
		cout<<i<<":"<<k[i].obj<<"/";
	}
	cout<<endl;
	for(int i = l;i <= r;i++){
		cout<<k[i].get_max()<<"/";
	}
	cout<<endl;
	for(int i = l;i <= r;i++){
		const int j = o2[i];
//		if(k[j].obj != i)puts("ERR");
		if(k[j].obj == i && i != j){
			swap(o2[i],o2[j]);
			fully_move(k[j],k[i],k[n+1]);
		}
	}
//	for(int i = l;i <= r;i++){
//		cout<<i<<" "<<k[i].get_max()<<" "<<k[i].obj<<endl;
//		k[i].show();
//	}
//	puts("---________------");
	//for(int i = l;i <= r;i++){
	//	if(obj[i] != i){
	//		fully_move(k[i],k[obj[i]],k[n+1]);
	//	}
	//}
	for(int j = l;j <= r;j++){
		cout<<k[j].get_max()<<"_";
	}
	return ;
}
EXCUTE_ST
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		k[i].no = i;
		for(int j = 1;j <= m;j++){
			int inx;
			scanf("%d",&inx);
			k[i].ins(inx);
		}
	}
	k[n+1].no = n+1;
	merge_sort(1,n);
	for(int i = 1;i <= n;i++)k[i].show();
	cout<<ktail<<endl;
	for(int i = 1;i <= ktail;i++){
		cout<<rem[i].first<<" "<<rem[i].second<<endl;
	}
FILE_ED_And_excute
