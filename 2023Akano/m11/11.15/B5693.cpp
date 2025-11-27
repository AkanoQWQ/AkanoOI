#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
#define BanCIO
using namespace std;
using ll = long long;
using pii = pair<int,int>;
constexpr int MAXN = 5e5 + 1018 + 1108;

#ifdef BanCIO
#define cin BANNED
#define cout BANNED
#define cerr BANNED
#endif

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

template<typename T,int SIZE>
class BIT{
private:
	T val[SIZE];
	inline int Lowbit(int x){
		return x & (-x);
	}
	inline T QueryPre(int x){
		T ret = 0;
		while(x){
			ret += val[x];
			x -= Lowbit(x);
		}
		return ret;
	}
public:
	inline void Change(int x,T _val){
		while(x <= SIZE){
			val[x] += _val;
			x += Lowbit(x);
		}
		return ;
	}
	inline T Query(int l,int r){
		return QueryPre(r) - QueryPre(l-1);
	}
	inline void Clear(){
		memset(val,0,sizeof(val));
		return ;
	}
	BIT(){Clear();}
};

int T,tid,n,a[MAXN];
BIT<int,MAXN> bit;
bool CmpByABigger(int x1,int x2){
	return a[x1] > a[x2];
}
bool CmpByASmaller(int x1,int x2){
	return a[x1] < a[x2];
}
namespace ScanLine{
	class SegmentTree{
	private:
		struct Node{
			int mx,lazy;
		}node[MAXN * 4];
		inline void PushUp(int p){
			node[p].mx = max(node[p*2].mx,node[p*2+1].mx);
			return ;
		}
		inline void Add(int p,int val){
			node[p].mx += val,node[p].lazy += val;
			return ;
		}
		inline void PushDown(int p){
			if(not(node[p].lazy))return ;
			Add(p*2,node[p].lazy),Add(p*2+1,node[p].lazy);
			node[p].lazy = 0;
			return ;
		}
		void Change(int p,int l,int r,int OBJL,int OBJR,int w){
			if(OBJL <= l && r <= OBJR){
				return Add(p,w);
			}
			const int mid = (l + r) >> 1;
			PushDown(p);
			if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR,w);
			if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR,w);
			PushUp(p);
			return ;
		}
	public:
		inline void Clear(){
			memset(node,0,sizeof(node));
			return ;
		}
		inline void Change(int l,int r,int w){
			return Change(1,1,n,l,r,w);
		}
		inline int Query(){
			return node[1].mx;
		}
	}tr;
	struct Line{
		int l,r,w;
		Line() = default;
		Line(int _l,int _r,int _w){
			l = _l,r = _r,w = _w;
			return ;
		}
	};
	vector<Line> line[MAXN];
	inline void AddRectangle(int l,int r,int u,int d){
		line[u].emplace_back(l,r,1);
		line[d+1].emplace_back(l,r,-1);
		return ;
	}
	inline ll Solve(){
		ll ret = 0;
		tr.Clear();
		for(int i = 1;i <= n;i++){
			for(auto seg : line[i]){
				tr.Change(seg.l,seg.r,seg.w);
			}
			ret = max(ret,ll(tr.Query()));
			line[i].clear();
		}
		return 1 + 2 * ret;
	}
}
int main(){
//	freopen("essenceoftwilight.in","r",stdin);
//	freopen("essenceoftwilight.out","w",stdout);
	fio>>n;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
		ans += (i-1) - bit.Query(1,a[i]);
		bit.Change(a[i],1);
		assert(a[i] < MAXN);
	}
	vector<int> preArr,sufArr;
	for(int i = 1;i <= n;i++){
		if(preArr.empty() || a[i] > a[preArr.back()]){
			preArr.push_back(i);
		}
	}
	for(int i = n;i >= 1;i--){
		if(sufArr.empty() || a[i] < a[sufArr.back()]){
			sufArr.push_back(i);
		}
	}
	for(int i = 1;i <= n;i++){
		int firstL,firstR,secondL,secondR;
		
		{//a_{arr_firstL} > a_i
			int l = 0,r = preArr.size();
			while(l < r){
				const int mid = (l + r) >> 1;
				if(a[preArr[mid]] > a[i]){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			firstL = r;
		}
		
		{//arr_fisrtR < i
			int l = 0,r = preArr.size();
			while(l < r){
				const int mid = (l + r) >> 1;
				if(preArr[mid] < i){
					l = mid + 1;
				}else{
					r = mid;
				}
			}
			firstR = l - 1;
		}
		
		{//a_{arr_secondL} < a_i
			int l = 0,r = sufArr.size();
			while(l < r){
				const int mid = (l + r) >> 1;
				if(a[sufArr[mid]] < a[i]){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			secondL = r;
		}
		
		{//arr_secondR > i
			int l = 0,r = sufArr.size();
			while(l < r){
				const int mid = (l + r) >> 1;
				if(sufArr[mid] > i){
					l = mid + 1;
				}else{
					r = mid;
				}
			}
			secondR = l - 1;
		}
		if(firstL > firstR || secondL > secondR)continue;
		if(firstL < 0 || firstR >= int(preArr.size()) || secondL < 0 || secondR > int(sufArr.size()))continue;
		ScanLine::AddRectangle(firstL + 1,firstR + 1,secondL + 1,secondR + 1);
	}
	fio<<min(max(ans - ScanLine::Solve() + 1,0ll),ans)<<endl;
	return not(Akano loves pure__Elysia);
}
