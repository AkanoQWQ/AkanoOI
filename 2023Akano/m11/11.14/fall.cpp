#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
constexpr int MAXN = 5e5 + 1018 + 1108;

template<int MaxSetSize>
class DisjointSet{
private:
	int size;
	int setFather[MaxSetSize],setSize[MaxSetSize],extraSize[MaxSetSize];
	inline int Find(int x){
		if(setFather[x] == x){
			return x;
		}
		return setFather[x] = Find(setFather[x]);
	}
public:
	inline void Init(int _size){
		size = _size;
		for(int i = 1;i <= size;i++){
			setFather[i] = i,setSize[i] = 1;
		}
		return ;
	}
	inline int GetFa(int x){
		return Find(x);
	}
	inline bool Merge(int u,int v){
		u = Find(u),v = Find(v);
		if(u == v)return false;
		if(setSize[u] < setSize[v])swap(u,v);//siz_u >= siz_u;
		setFather[v] = u,setSize[u] += setSize[v],extraSize[u] += extraSize[v];
		return true;
	}
	inline bool ToGether(int u,int v){
		return Find(u) == Find(v);
	}
	inline int ExSize(int u){
		u = Find(u);
		return extraSize[u];
	}
	inline void AddExSize(int u){
		u = Find(u);
		extraSize[u]++;
		return ;
	}
	DisjointSet(){
		size = 0;
		return ;
	}
	DisjointSet(int _size){
		size = _size;
		return ;
	}
};

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
	int nxt,to,id;
}e[MAXN * 8];
int head[MAXN * 2],cnt = 1;
inline void AddEdge(int from,int to,int id){
	e[++cnt].to = to;
	e[cnt].id = id;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
DisjointSet<MAXN * 2> dsu;
int n,a[MAXN],b[MAXN],totans;
inline int Discretize(){
	vector<int> vec;
	for(int i = 1;i <= n;i++){
		vec.push_back(a[i]),vec.push_back(b[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
		b[i] = lower_bound(vec.begin(),vec.end(),b[i]) - vec.begin() + 1;
	}
	return vec.size();
}
int dfn[MAXN * 2],dnt;
vector<pair<int,int> > edgeans;
bool dfs(int u,int fae){//返回是否使用了父边
	dfn[u] = ++dnt;
	vector<int> links;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].id == e[fae].id)continue;
		if(!dfn[v]){
			bool adde = dfs(v,i);
			if(adde){
				links.push_back(e[i].id);
			}
		}else if(dfn[v] <= dfn[u]){//可能是反向的返祖边
			links.push_back(e[i].id);
		}
	}
	bool ret = true;
	if(fae != 0 && int(links.size()) % 2 == 1){
		ret = false;
		links.push_back(e[fae].id);
	}
	while(int(links.size()) >= 2){
		const int eu = links.back();
		links.pop_back();
		const int ev = links.back();
		links.pop_back();
		edgeans.emplace_back(eu,ev);
	}
	return ret;
}
int main(){
	freopen("fall.in","r",stdin);
	freopen("fall.out","w",stdout);
	fio>>n;
	for(int i = 1;i <= n;i++){
		fio>>a[i]>>b[i];
	}
	int siz = Discretize();
	dsu.Init(2*n);
	for(int i = 1;i <= n;i++){
		if(a[i] != b[i]){
			AddEdge(a[i],b[i],i),AddEdge(b[i],a[i],i);
		}else{
			AddEdge(a[i],a[i],i);//建一条自环
		}
		int oldans = (dsu.ExSize(a[i]) / 2) + (dsu.ExSize(b[i]) / 2);
		if(dsu.ToGether(a[i],b[i])){
			oldans /= 2;
		}
		dsu.Merge(a[i],b[i]);
		dsu.AddExSize(a[i]);
		int newans = (dsu.ExSize(a[i]) / 2);
		totans += newans - oldans;
		fio<<totans<<" ";
	}
	fio<<'\n';
	for(int i = 1;i <= siz;i++){
		if(!dfn[i])dfs(i,0);
	}
	for(auto i : edgeans){
		fio<<i.first<<" "<<i.second<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
