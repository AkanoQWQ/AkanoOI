//#include<bits/stdc++.h>
//using namespace std;
//using ll = long long;
//const int MAXE = 714;
//const int MAXN = MAXE * 2;//remember to EDIT
//const int MAXM = MAXN * 128  + 1018 + 1108;//EDIT and *2
//const ll INF = LLONG_MAX;
//struct Element{
//	int a,b,c,id,step;
//}arr[MAXE];
//struct Edge{
//	int nxt,to;
//	ll cap;
//}e[MAXM];
//int head[MAXN],cnt = 1;
//inline void AddEdge(int from,int to,ll val){
//	e[++cnt].to = to;
//	e[cnt].cap = val;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//inline void CreateEdge(int from,int to,ll val){
//	AddEdge(from,to,val);
//	AddEdge(to,from,0);
//	return ;
//} 
//int DFS_ED;//share 
//int dep[MAXN],cur[MAXN];
//bool BFS(int n,int ST,int ED){
//	for(int i = 0;i <= n;i++){
//		dep[i] = 0;
//	}
//	queue<int> q;
//	dep[ST] = 1;
//	q.push(ST);
//	while(!q.empty()){
//		const int u = q.front();
//		q.pop();
//		cur[u] = head[u];
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(dep[v] != 0 || e[i].cap <= 0)continue;
//			dep[v] = dep[u] + 1;
//			q.push(v);
//		}
//	}
//	return (dep[ED] > 0);
//}
//int DFS(int u,ll val){
//	if(u == DFS_ED || val == 0)return val;
//	int ret = 0;
//	for(int i = cur[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		cur[u] = i;
//		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
//		const ll realPush = DFS(v,min(e[i].cap,val));
//		ret += realPush;
//		val -= realPush;
//		e[i].cap -= realPush;
//		e[i^1].cap += realPush;
//		if(realPush == 0)dep[v] = -1;
//		if(val == 0)break;
//	}
//	return ret;
//}
//inline ll Dinic(int n,int ST,int ED){
//	ll ret = 0;
//	DFS_ED = ED;
//	while(BFS(n,ST,ED)){
//		ret += DFS(ST,INF);
//	}
//	return ret;
//}
//int n,dir[MAXE];
//bool Cmp4Dir(int i1,int i2){
//	return arr[i1].c < arr[i2].c;
//}
//int T,nnt,VST,VED,no[MAXE][2],lis;
//bool del[MAXE];
//inline void BuildEdge(){
//	nnt = 0;
//	VST = ++nnt,VED = ++nnt;
//	for(int i = 1;i <= n;i++){
//		if(!del[i])no[i][0] = ++nnt,no[i][1] = ++nnt;
//	}
//	for(int i = 0;i <= nnt;i++){
//		head[i] = 0;
//	}
//	cnt = 1;
//	for(int i = 1;i <= n;i++){
//		if(del[i])continue;
//		if(arr[i].step == 1){
//			CreateEdge(VST,no[i][0],INF);
//		}
//		if(arr[i].step == lis){
//			CreateEdge(no[i][1],VED,INF);
//		}
//		CreateEdge(no[i][0],no[i][1],arr[i].b);
//		for(int j = i+1;j <= n;j++){
//			if(arr[i].step+1 == arr[j].step && !del[j])CreateEdge(no[i][1],no[j][0],INF);
//		}
//	}
//	return ;
//}
//inline ll Read(){
//	ll ret = 0;//no f;
//	char ch = getchar();
//	while(!isdigit(ch))ch = getchar();
//	while(isdigit(ch)){
//		ret = ret * 10 + ch - '0';
//		ch = getchar();
//	}
//	return ret;
//}
//int otp[1018];
//inline void Write(ll inx){
//	if(inx == 0)putchar('0');
//	int len = 0;
//	while(inx){
//		otp[++len] = inx % 10;
//		inx /= 10;
//	}
//	for(int i = len;i >= 1;i--){
//		putchar(otp[i] + '0');
//	}
//	return ;
//}
//int main(){
//	T = Read();
//	while(T--){
//		lis = 0;
//		int anscnt = 0;
//		n = Read();
//		for(int i = 1;i <= n;i++){
//			dir[i] = i,del[i] = false;
//			arr[i].id = i,arr[i].step = 1;
//			arr[i].a = Read();
//		}
//		for(int i = 1;i <= n;i++){
//			arr[i].b = Read();
//		}
//		for(int i = 1;i <= n;i++){
//			arr[i].c = Read();
//		}
//		sort(dir+1,dir+n+1,Cmp4Dir);
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j < i;j++){
//				if(arr[j].a >= arr[i].a)continue;
//				arr[i].step = max(arr[i].step,arr[j].step + 1);
//			}
//			lis = max(lis,arr[i].step);
//		}
//		BuildEdge();
//		ll nowans = Dinic(nnt,VST,VED),wans = 0;
//		for(int i = 1;i <= n;i++){
//			const int u = dir[i];
//			if(wans + arr[u].b > nowans)continue;
//			del[u] = true;
//			wans += arr[u].b;
//			BuildEdge();
//			ll res = Dinic(nnt,VST,VED);
//			if(res + wans == nowans){
//				++anscnt;
//			}else{
//				del[u] = false;
//				wans -= arr[u].b;
//			}
//		}
//		Write(nowans),putchar(' '),Write(anscnt),putchar('\n');
//		for(int i = 1;i <= n;i++){
//			if(del[i]){
//				Write(i),putchar(' ');
//			}
//		}
//		putchar('\n');
//	}
//	return 0;
//}
