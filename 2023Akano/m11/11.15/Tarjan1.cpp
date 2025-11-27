#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 1e4 + 1018 + 1108;
constexpr int MAXM = 2e5 + 1018 + 1108;

class FastIO{//1.3
private:
#define TMPCT template<class T>
	constexpr static int buffSize = 1<<23;
	
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
	
	template<bool boolean,class T = void>
	using enableTp = typename enable_if<boolean,T>::type*;
	
	TMPCT using isIntegerp = enableTp<(is_integral<T>::value || is_same<T,__int128>::value || is_same<T,unsigned __int128>::value) && not(is_same<T,char>::value),T>;
	TMPCT using isFloatp = enableTp<is_floating_point<T>::value,T>;
	TMPCT using isStringp = enableTp<is_same<T,string>::value,T>;
	TMPCT using isCStringp = enableTp<is_convertible<T,ccp>::value,T>;//输出时同一切换成C语言风格字符串,即CCP
	TMPCT using isCharp = enableTp<is_same<T,char>::value,T>;
	
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
	TMPCT void Read(T& str,isStringp<T> = nullptr){//不支持读入char数组
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
	TMPCT void Write(const T& _cstr,isCStringp<T> = nullptr){//单独支持char数组输出
		ccp cstr = (ccp)_cstr;
		for(;*cstr;cstr++){
			FastPutChar(*cstr);
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
		if(reinterpret_cast<long long>(streamfuncvar) == reinterpret_cast<long long>(endl<char,char_traits<char> >)){
			FastPutChar('\n');
			Flush();
		}
		if(reinterpret_cast<long long>(streamfuncvar) == reinterpret_cast<long long>(flush<char,char_traits<char> >)){
			Flush();
		}
		return ;
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
}e[MAXM];
int head[MAXN],cnt,d[MAXN];
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,value[MAXN],SCCvalue[MAXN];
int dfn[MAXN],low[MAXN],dnt;
bool ins[MAXN];
stack<int,vector<int> > stk;
int SCC_CNT,belong[MAXN];
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u),ins[u] = true;
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
			stk.pop(),ins[tp] = false;
			belong[tp] = SCC_CNT;
			SCCvalue[SCC_CNT] += value[tp];
			if(tp == u)break;
		}
	}
	return ;
}
inline void Remake(){
	set<pair<int,int> > st;
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(belong[u] == belong[v])continue;
			st.insert({belong[u],belong[v]});
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : st){
		d[i.second]++;
		AddEdge(i.first,i.second);
	}
	n = SCC_CNT;
	return ;
}
int dp[MAXN];
inline int Topo(){
	int ret = 0;
	queue<int> q;
	for(int u = 1;u <= n;u++){
		if(d[u] == 0)q.push(u);
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		dp[u] += SCCvalue[u];
		ret = max(ret,dp[u]);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			d[v]--;
			if(d[v] == 0){
				q.push(v);
			}
			dp[v] = max(dp[v],dp[u]);
		}
	}
	return ret;
}
int main(){
//	freopen("test.in","r",stdin);
	fio>>n>>m;
	for(int i = 1;i <= n;i++){
		fio>>value[i];
	}
	for(int i = 1,u,v;i <= m;i++){
		fio>>u>>v;
		AddEdge(u,v);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i]){
			Tarjan(i);
		}
	}
	Remake();
	fio<<Topo();
	return not(Akano loves pure__Elysia);
}
