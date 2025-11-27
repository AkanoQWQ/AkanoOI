#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int,int>;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int dx[4] = {1,0,-1,0};
constexpr int dy[4] = {0,1,0,-1};

class FastIO{//1.3
private:
#define TMPCT template<class T>
	constexpr static int buffSize = 1<<25;
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
	
	template<bool boolean,class T = void>
	using enableTp = typename enable_if<boolean,T>::type*;
	
	TMPCT using isIntegerp = enableTp<(is_integral<T>::value || is_same<T,__int128>::value || is_same<T,unsigned __int128>::value) && not(is_same<T,char>::value),T>;
	TMPCT using isFloatp = enableTp<is_floating_point<T>::value,T>;
	TMPCT using isStringp = enableTp<is_same<T,string>::value,T>;
	TMPCT using isCharp = enableTp<is_same<T,char>::value,T>;
	TMPCT using isCCPp = enableTp<is_convertible<T,ccp>::value,T>;
	
	FILEp inFile,outFile;
	char inputBuff[buffSize +2],outputBuff[buffSize + 2];
	charp inputPtr = inputBuff,inputEnd = inputPtr;
	charp outputPtr = outputBuff,outputEnd = outputBuff + buffSize;
	bool IsSplited(char ch){
		return (ch == ' ' || ch == '\n');
	}
	TMPCT void Read(T& x,isIntegerp<T> = nullptr){
		x = 0;
		char ch = FastGetChar();
		int f = 1;
		while(!isdigit(ch) && !fail){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		while(isdigit(ch)  && !fail){
			x = (x * 10) + (ch ^ 48);
			ch = FastGetChar();
		}
		x *= f;
		return ;
	}
	TMPCT void Write(T x,isIntegerp<T> = nullptr){
		static int writeBuff[128];
		if(x < 0){
			FastPutChar('-');
			x = -x;
		}else if(x==0){
			FastPutChar('0');
		}
		int tail = 0;
		while(x){
			writeBuff[++tail] = x % 10;
			x /= 10;
		}
		while(tail){
			FastPutChar(writeBuff[tail--] + '0');
		}
		return ;
	}
	TMPCT void Read(T& ret,isFloatp<T> = nullptr){
		ret = 0;
		int f = 1;
		char ch = FastGetChar();
		while(!isdigit(ch)){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		bool afterPoint = false;
		T now = 1;
		while(isdigit(ch) || ch == '.'){
			if(ch == '.'){
				afterPoint = true;
			}else if(afterPoint == false){
				ret = ret * 10 + ch - '0';
			}else{
				now /= 10;
				ret += now * (ch - '0');
			}
			ch = FastGetChar();
		}
		ret *= f;
		return ;
	}
	TMPCT void Write(T x,isFloatp<T> = nullptr){
		const static double EPS = 1e-8;
		if(fabs(x) <= EPS){
			FastPutChar('0');
			return ;
		}else if(x < 0){
			FastPutChar('-');
			x = -x;
		}
		T noww = 1;
		while(noww * 10 <= x)noww *= 10;
		while(noww >= 1){
			int cnt = x / noww;
			x -= cnt * noww;
			FastPutChar('0' + cnt);
			noww /= 10;
		}
		if(fabs(x) <= EPS)return ;
		FastPutChar('.');
		T nowEPS = EPS;
		while(fabs(x) > nowEPS){
			x *= 10;
			int res = int(x);
			x -= res % 10;
			nowEPS *= 10;
			FastPutChar('0' + res);
		}
		return ;
	}
	TMPCT void Read(T& str,isStringp<T> = nullptr){
		str = "";
		char ch = FastGetChar();
		while(IsSplited(ch) && !fail){
			ch = FastGetChar();
		}
		while(!IsSplited(ch) && !fail){
			str += ch;
			ch = FastGetChar();
		}
		return ;
	}
	TMPCT void Write(const T& str,isStringp<T> = nullptr){
		for(auto i : str){
			FastPutChar(i);
		}
		return ;
	}
	TMPCT void Write(const T& cstr,isCCPp<T> = nullptr){
		ccp it = cstr;
		for(;*it;it++){
			FastPutChar(*it);
		}
		return ;
	}
	TMPCT void Read(T& ch,isCharp<T> = nullptr){
		ch = FastGetChar();
		while(IsSplited(ch) && !fail){
			ch = FastGetChar();
		}
		return ;
	}
	TMPCT void Write(const T& charvar,isCharp<T> = nullptr){
		FastPutChar(charvar);
		return ;
	}
	TMPCT void Write(const T& streamfuncvar,enableTp<is_same<T,ostreamFunc>::value,T> = nullptr){
		ostringstream oss;
		oss<<streamfuncvar;
		if(!oss.str().empty())FastPutChar('\n');//默认为endl
		return Flush();
	}
	void FmtOutput(ccp format){
		for(;*format;format++){
			FastPutChar(*format);
		}
		return ;
	}
	template<typename FirstType,typename... ResType>
	void FmtOutput(ccp format,const FirstType& firstElement,const ResType&... res){
		for(;*format;format++){
			if(*format == '{' && *(format+1) == '}'){
				operator<<(firstElement);
				FmtOutput(format + 2,res...);
				return ;
			}
			FastPutChar(*format);
		}
		return ;
	}
	char FastGetChar(){
		if(inputPtr == inputEnd){
			size_t res = fread(inputBuff,1,buffSize,inFile);
			inputEnd = inputBuff + res;//为什么其他地方不改inputEnd呢
			if(res == 0){
				fail = true;
				inputPtr = inputBuff;
				return EOF;
			}
			inputPtr = inputBuff;
		}
		return *(inputPtr++);
	}
	void FastPutChar(char ch){
		if(outputPtr == outputEnd){
			Flush();
		}
		*(outputPtr++) = ch;
		return ;
	}
public:
	bool fail;
	char Getchar(){
		return FastGetChar();
	}
	void Putchar(char ch){
		return FastPutChar(ch);
	}
	void Flush(){
		fwrite(outputBuff,1,outputPtr - outputBuff,outFile);
		outputPtr = outputBuff;
		return ;
	}
	void Endl(){
		return FastPutChar('\n');
	}
	TMPCT FastIO& operator>>(T& var){
		Read(var);
		return *this;
	}
	TMPCT FastIO& operator<<(const T& var){
		Write(var);
		return *this;
	}
	FastIO& operator<<(const ostreamFunc& var){//函数指针比较特殊,需要单独处理
		Write(var);
		return *this;
	}
	template<typename... ArgTypes>
	FastIO& operator()(ccp format,const ArgTypes&... args){
		FmtOutput(format,args...);
		return *this;
	}
	operator bool(){
		return not(fail);
	}
	FastIO(){
		inFile = stdin,outFile = stdout;
		return ;
	}
	FastIO(FILEp _inFile,FILEp _outFile){
		inFile = _inFile,outFile = _outFile;
		return ;
	}
	~FastIO(){
		Flush();
		return ;
	}
#undef TMPCT
};
FastIO fio(stdin,stdout),ferr(nullptr,stderr);

struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,Q,nnt,belong2[MAXN],SCC_CNT;
long long w[MAXN],answ[MAXN],sumw[MAXN];
vector<vi> belong;
vector<pii> seg[MAXN];
vector<string> mp;
int dfn[MAXN],low[MAXN],dnt;
bool ins[MAXN];
stack<int> stk;
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	ins[u] = true;
	stk.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]){
		SCC_CNT++;
		while(!stk.empty()){
			const int tp = stk.top();
			ins[tp] = false;
			stk.pop();
			belong2[tp] = SCC_CNT;
			if(tp == u)break;
		}
	}
	return ;
}
inline void Remake(){
	set<pii> saveEdge;
	for(int u = 1;u <= nnt;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(belong2[u] != belong2[v]){
				saveEdge.insert({belong2[u],belong2[v]});
			}
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : saveEdge){
		AddEdge(i.first,i.second);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			belong[i][j] = belong2[belong[i][j]];
		}
	}
	return ;
} 
inline void BFS(int stX,int stY){
	queue<pii> q;
	int nowid = ++nnt;
	q.push({stX,stY});
	belong[stX][stY] = nowid;
	while(!q.empty()){
		const pii u = q.front();
		q.pop();
		for(int k = 0;k < 4;k++){
			const int OX = u.first + dx[k],OY = u.second + dy[k];
			if(not(1 <= OX && OX <= n && 1 <= OY && OY <= m && belong[OX][OY] == 0 && mp[OX][OY] == mp[u.first][u.second]))continue;
			belong[OX][OY] = nowid;
			q.push({OX,OY});
		}
	}
	return ;
}
inline vector<pii> Merge(const vector<pii>& v1,const vector<pii>& v2){
	vector<pii> ret;
	auto it1 = v1.begin(),it2 = v2.begin();
	while(it1 != v1.end() || it2 != v2.end()){
		bool do1 = false;
		if(it1 == v1.end()){
			do1 = false; 
		}else if(it2 == v2.end()){
			do1 = true;
		}else if(it1->first < it2->first){
			do1 = true;
		}else{
			do1 = false; 
		}
		if(do1){
			if(ret.empty()){
				ret.push_back(*(it1++));
			}else if(it1->first <= ret.back().second+1){
				ret.back().second = max(ret.back().second,it1->second);
				it1++;
			}else{
				ret.push_back(*(it1++));
			}
		}else{
			if(ret.empty()){
				ret.push_back(*(it2++));
			}else if(it2->first <= ret.back().second+1){
				ret.back().second = max(ret.back().second,it2->second);
				it2++;
			}else{
				ret.push_back(*(it2++));
			}
		}
	}
	return ret;
}
bool dfsvis[MAXN];
void dfs(int u){
	if(dfsvis[u])return ;
	dfsvis[u] = true;
	seg[u].clear();
	seg[u].emplace_back(u,u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		dfs(v);
		seg[u] = Merge(seg[u],seg[v]);
	}
	for(auto i : seg[u]){
		answ[u] += sumw[i.second] - sumw[i.first-1];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	fio>>n>>m>>Q;
	belong.resize(n+3),mp.resize(n+3);
	for(int i = 1;i <= n;i++){
		fio>>mp[i];
		mp[i] = "." + mp[i];
		belong[i].resize(m+1);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(belong[i][j] == 0)BFS(i,j);
		}
	}
	set<pii> saveEdge;
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= m;j++){
			if(belong[i][j] != belong[i+1][j])saveEdge.insert({belong[i][j],belong[i+1][j]});
		}
	}
	for(auto i : saveEdge){
		AddEdge(i.first,i.second);
	}
	for(int i = 1;i <= nnt;i++){
		if(!dfn[i])Tarjan(i);
	}
	Remake();
	long long totw = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1,noww;j <= m;j++){
			fio>>noww;
			totw += noww;
			w[belong[i][j]] += noww;
		}
	}
	for(int i = 1;i <= SCC_CNT;i++){
		sumw[i] = sumw[i-1] + w[i];
	}
	for(int u = 1;u <= SCC_CNT;u++){
		dfs(u);
	}
	while(Q--){
		int x,y;//x,y就按照x行y列来写,转换一下 
		fio>>x>>y;
		fio<<answ[belong[x][y]]<<'\n';
	}
	return 0;
}

