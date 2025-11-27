#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 8e5 + 1018 + 1108;

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

struct Position{
	int x,y;
	Position() = default;
	Position(int _x,int _y){
		x = _x,y = _y;
		return ;
	}
}pointpos[MAXN];
struct Rectangle{
	Position l,r;
	Rectangle() = default;
	Rectangle(Position _l,Position _r){
		l = _l,r = _r;
		return ;
	}
};
inline bool Connected(const Rectangle& r1,const Rectangle& r2){
	int l,r,u,d;
	l = max(r1.l.x,r2.l.x),r = min(r1.r.x,r2.r.x);
	u = max(r1.l.y,r2.l.y),d = min(r1.r.y,r2.r.y);
	return (l <= r && u <= d);
}
inline bool Include(const Rectangle& r1,const Rectangle& r2){//r1 includes r2
	return r1.l.x <= r2.l.x && r2.r.x <= r1.r.x && r1.l.y <= r2.l.y && r2.r.y <= r1.r.y;
}
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
int n,orgn,q,a[MAXN],dep[MAXN],dfn[MAXN],psize[MAXN],dnt;
struct QueryType{
	int opt,x,d,v;
}query[MAXN];
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1,dfn[u] = ++dnt,psize[u] = 1;
	pointpos[u] = Position(dfn[u],dep[u]);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		psize[u] += psize[v];
	}
	return ;
}
struct Node{
	Rectangle rect;
	int l,r,siz;
	ll val,lazy;
	Node() = default;
	Node(Rectangle _rect,int _val){
		rect = _rect;
		l = r = 0,siz = 1;
		val = _val,lazy = 0;
		return ;
	}
}node[MAXN * 4];
bool CmpX(Node n1,Node n2){
	if(n1.rect.l.x != n2.rect.l.x)return n1.rect.l.x < n2.rect.l.x;
	return n1.rect.l.y < n2.rect.l.y;
}
bool CmpY(Node n1,Node n2){
	if(n1.rect.l.y != n2.rect.l.y)return n1.rect.l.y < n2.rect.l.y;
	return n1.rect.l.x < n2.rect.l.x;
}
class KDTree{
private:
	int root,tot;
	vector<Node> resNode,insNode;//散点 和 插入暂用的序列
	inline void PushUp(int p){
		node[p].val = node[node[p].l].val + node[node[p].r].val;
		node[p].siz = node[node[p].l].siz + node[node[p].r].siz;
		return ;
	}
	inline void Add(int p,ll val){
		if(!p)return ;
		node[p].val += node[p].siz * val;
		node[p].lazy += val;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy == 0)return ;
		Add(node[p].l,node[p].lazy),Add(node[p].r,node[p].lazy);
		node[p].lazy = 0;
		return ;
	}
	void Build(int& p,int l,int r,bool W){
		if(p == 0)p = ++tot;
		node[p].l = node[p].r = node[p].lazy = 0;
		if(l == r){
			node[p] = insNode[l];
			return ;
		}
		const int mid = (l + r) >> 1;
		if(W){
			nth_element(insNode.begin()+l,insNode.begin()+mid,insNode.begin()+r,CmpX);
		}else{
			nth_element(insNode.begin()+l,insNode.begin()+mid,insNode.begin()+r,CmpY);
		}
		Build(node[p].l,l,mid,!W),Build(node[p].r,mid+1,r,!W);
		PushUp(p);
		node[p].rect.l.x = min(node[node[p].l].rect.l.x,node[node[p].r].rect.l.x);
		node[p].rect.l.y = min(node[node[p].l].rect.l.y,node[node[p].r].rect.l.y);
		node[p].rect.r.x = max(node[node[p].l].rect.r.x,node[node[p].r].rect.r.x);
		node[p].rect.r.y = max(node[node[p].l].rect.r.y,node[node[p].r].rect.r.y);
		return ;
	}
	inline void ReBuild(){
		swap(insNode,resNode);
		resNode.clear();
		insNode.insert(insNode.begin(),Node());
		for(int i = 1;i <= tot;i++){
			if(node[i].siz == 1){
				insNode.push_back(node[i]);
			}else{
				PushDown(i);//按照顺序PushDown
			}
		}
		root = tot = 0,size = dsize;
		Build(root,1,size,true);
		return ;
	}
	void Change(int p,const Rectangle& OBJ,ll val){
		if(!p)return ;
		if(Connected(OBJ,node[p].rect) == false)return ;
		if(Include(OBJ,node[p].rect)){
			return Add(p,val);
		}
		PushDown(p);
		Change(node[p].l,OBJ,val),Change(node[p].r,OBJ,val);
		PushUp(p);
		return ;
	}
	ll Query(int p,const Rectangle& OBJ){
		if(!p)return 0;
		if(Connected(OBJ,node[p].rect) == false)return 0;
		if(Include(OBJ,node[p].rect)){
			return node[p].val;
		}
		PushDown(p);
		ll ret = 0;
		ret += Query(node[p].l,OBJ) + Query(node[p].r,OBJ);
		return ret;
	}
public:
	int size,dsize,block;
	inline void Build(){
		size = dsize = orgn;
		root = tot = 0;
		insNode.clear();
		insNode.emplace_back(Rectangle(Position(2006,1018),Position(2006,1108)),1314);
		for(int i = 1;i <= orgn;i++){
			insNode.emplace_back(Rectangle(pointpos[i],pointpos[i]),a[i]);
		}
		assert(int(insNode.size()) == size + 1);
		Build(root,1,orgn,true);
		return ;
	}
	inline void Insert(Position pos,int val){
		resNode.emplace_back(Rectangle(pos,pos),val);
		dsize++;
		if(int(resNode.size()) >= block){
			ReBuild();
		}
		return ;
	}
	inline void Change(const Rectangle& OBJ,int val){
		Change(root,OBJ,val);
		for(auto& i : resNode){
			if(Include(OBJ,i.rect)){
				i.val += val;
			}
		}
		return ;
	}
	inline ll Query(const Rectangle& OBJ){
		ll ret = Query(root,OBJ);
		for(auto i : resNode){
			if(Include(OBJ,i.rect)){
				ret += i.val;
			}
		}
		return ret;
	}
}kdt;
int main(){
	fio>>n>>q;
	kdt.block = 919;
	orgn = n;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
	}
	for(int i = 2,fa;i <= n;i++){
		fio>>fa;
		AddEdge(fa,i),AddEdge(i,fa);
	}
	for(int i = 1;i <= q;i++){
		fio>>query[i].opt;
		if(query[i].opt == 1){
			fio>>query[i].x>>query[i].d>>query[i].v;
		}else if(query[i].opt == 2){
			fio>>query[i].x>>query[i].d;
		}else if(query[i].opt == 3){
			fio>>query[i].x>>query[i].v;
			n++;
			AddEdge(n,query[i].x),AddEdge(query[i].x,n);
		}
	}
	dfs(1,0);
	kdt.Build();
	n = orgn;
	for(int i = 1;i <= q;i++){
		if(query[i].opt == 1){
			const int u = query[i].x,stD = dep[u],edD = dep[u] + query[i].d;
			kdt.Change(Rectangle(Position(dfn[u],stD),Position(dfn[u] + psize[u] - 1,edD)),query[i].v);
		}else if(query[i].opt == 2){
			const int u = query[i].x,stD = dep[u],edD = dep[u] + query[i].d;
			cout<<kdt.Query(Rectangle(Position(dfn[u],stD),Position(dfn[u] + psize[u] - 1,edD)))<<'\n';
		}else if(query[i].opt == 3){
			n++;
			kdt.Insert(pointpos[n],query[i].v);
		}
	}
	return not(Akano loves pure__Elysia);
}
