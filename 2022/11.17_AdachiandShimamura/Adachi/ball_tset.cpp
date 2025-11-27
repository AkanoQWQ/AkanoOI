#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 56;
const int MAXM = 406;
int n,m;
int ctr[MAXN][MAXM],tail[MAXN];//container
bool finished[MAXN];
vector<pair<int,int> > exc;//execution
inline void ins(int x,int no){
	ctr[no][++tail[no]] = x;
	return ;
}
inline int get(int no){
	if(tail[no] == 0)return -1;
	return ctr[no][tail[no]--];
}
void show(){
	for(int i = 1;i <= n;i++){
		cout<<i<<":";
		for(int j = 1;j <= tail[i];j++){
			cout<<ctr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return ;
}
void showctr(int no){
	cout<<no<<"("<<tail[no]<<"):";
	for(int i = 1;i <= tail[no];i++){
		 cout<<ctr[no][i]<<" ";
	}
	cout<<endl;
	return ;
}
void check(int no,int type){
	if(tail[no] < 0 || tail[no] > m){
		cout<<"TYPE"<<type<<" "<<exc.size()<<":"<<no<<","<<tail[no];
		puts("OVERFLOW!!!!!!");
	}
	return ;
}
void movek(int from,int to,int type){
	if(exc.size() == 126284){
		cout<<exc.size()<<"movek "<<from<<" , "<<to<<endl;
		showctr(from);
		showctr(to);
	}
	const int getkol = get(from);
	ins(getkol,to);
	exc.push_back(make_pair(from,to));
	if(exc.size() == 126285){
		showctr(from);
		showctr(to);
	}
	check(from,type),check(to,type);
	return ;
}
int findCache(){
	int mint = 2006,ret = -1;
	for(int i = 1;i <= n;i++){
		if(finished[i])continue;
		if(tail[i] == 0)return i;
		if(tail[i] < mint){
			mint = tail[i];
			ret = i;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i == ret)continue;
		if(tail[ret] == 0)break;
		while(tail[i] < m && tail[ret] >= 1){
			movek(ret,i,114);
		}
	}
	return ret;
}
int findNotFull(int f1,int f2){
	for(int i = 1;i <= n;i++){
		if(i == f1 || i == f2)continue;
		if(tail[i] < m)return i;
	}
	return -1;
}
bool NotOK(int no,int kol){
	for(int i = 1;i <= tail[no];i++){
		if(ctr[no][i] != kol){
			return 1;
		}
	}
	return 0;
}
void movekoloro(int from,int to,int kol){
	//cout<<"move "<<kol<<" in "<<from<<" to "<<to<<endl;
	if(to == 12){
		cout<<"now "<<to<<endl;
		showctr(from),showctr(to);
	}
	if(ctr[from][tail[from]] == kol){
		movek(from,to,1);
		//if(to == 12)puts("direct finish");
		return ;
	}
	while(tail[from] > 0){
		if(ctr[from][tail[from]] == kol)break;
		int t = findNotFull(from,to);
		if(t == -1){
			if(to == 12){
				puts("OTHERS ARE FULL");
			}
			t = findNotFull(from,-1);
		}
		movek(from,t,2);
	}
	int rg = 1;
	for(int i = 1;i <= n;i++){
		if(!finished[i] && tail[i] >= 1 && i != from && i != to){
			rg = i;
			break;
		}
	}
	if(to == 12)cout<<"top now "<<ctr[rg][tail[rg]]<<"!"<<endl;
	if(tail[rg] == m){
		int rgto = findNotFull(from,rg);
		movek(rg,rgto,3);
	}
	if(to == 12){
		puts("FIR TO");showctr(to);
	}
	movek(from,rg,4);
	if(to == 12){
		puts("NOW TO");showctr(to);
	}
	
	while(tail[to] >= 1 && NotOK(to,kol)){//ctr[to][tail[to]] != kol
		int t = findNotFull(to,-1);
		if(to == 12){
			cout<<"! to "<<t<<endl;
		}
		movek(to,t,5);
	}
	movek(rg,to,6);
	//cout<<"end movekoloro"<<endl;
	//show();
	if(NotOK(to,kol)){
		
	}else{
		//cout<<"NO PROBLEM"<<endl;
	}
	if(to == 12){
		cout<<"ENDEND"<<to<<endl;
		showctr(from),showctr(to);
	}
	return ;
}
void execute(int koloro){
	//cout<<koloro<<" before"<<endl;
	//show(); 
	const int cache = findCache();
	for(int i = 1;i <= n;i++){
		if(finished[i] || i == cache)continue;
		for(int j = tail[i];j >= 1;j--){
			if(ctr[i][j] == koloro){
				movekoloro(i,cache,koloro);
			}
		}
	}
	finished[cache] = 1;
	//cout<<"afert execute"<<endl;
	//show();
	return ;
}
EXCUTE_ST
	freopen("ball.in","r",stdin);
	freopen("ball.test","w",stdout);
	scanf("%d%d",&n,&m);
	n++;
	for(int i = 1;i <= n-1;i++){
		for(int j = 1;j <= m;j++){
			int x;
			scanf("%d",&x);
			ins(x,i);
		}
	}
	for(int i = 1;i <= n-1;i++){
		execute(i); 
	}
FILE_ED_And_excute
