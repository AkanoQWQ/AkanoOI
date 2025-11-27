#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 1e6 + 1018 + 1108;

bool _ST_;

class FastIO{//1.3
private:
#define TMPCT template<class T>
	constexpr static int buffSize = 1<<23;
	
	template<bool boolean,class T = void>
	using enableTp = typename enable_if<boolean,T>::type*;
	
	TMPCT using isIntegerp = enableTp<(is_integral<T>::value || is_same<T,__int128>::value || is_same<T,unsigned __int128>::value) && not(is_same<T,char>::value),T>;
	TMPCT using isFloatp = enableTp<is_floating_point<T>::value,T>;
	TMPCT using isStringp = enableTp<is_same<T,string>::value,T>;
	TMPCT using isCharp = enableTp<is_same<T,char>::value,T>;
	
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
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

int n,m,a[MAXN];
namespace Subtask1{
	inline int Calc(){
		int ret = 0;
		for(int l = 1;l <= n;l++){
			int mx = a[l],mn = a[l];
			for(int r = l;r <= n;r++){
				mx = max(mx,a[r]),mn = min(mn,a[r]);
				if(mx + mn > r - l + 1)ret = max(ret,r - l + 1);
			}
		}
		return ret;
	}
	inline void Solve(){
		fio<<Calc()<<'\n';
		for(int i = 1,k;i <= m;i++){
			fio>>k;
			for(int j = 1,x,y;j <= k;j++){
				fio>>x>>y;
				swap(a[x],a[y]);
			}
			fio<<Calc()<<'\n';
		}
		return ;
	}
}
namespace Subtask2{
	struct STtable{
	private:
		int mn[MAXN][21],mx[MAXN][21],logval[MAXN];
	public:
		inline void Build(){
			for(int i = 1;i <= n;i++){
				if(i >= 2){
					logval[i] = logval[i/2] + 1;
				}
				mn[i][0] = mx[i][0] = a[i];
			}
			for(int p = 1;p <= 20;p++){
				for(int i = 1;i <= n;i++){
					const int nxt = min(n,i + (1<<(p-1)));
					mn[i][p] = min(mn[i][p-1],mn[nxt][p-1]);
					mx[i][p] = max(mx[i][p-1],mx[nxt][p-1]);
				}
			}
			return ;
		}
		inline pair<int,int> Query(int l,int r){
			int lgval = logval[r - l + 1];
			return {min(mn[l][lgval],mn[r-(1<<lgval)+1][lgval]),max(mx[l][lgval],mx[r-(1<<lgval)+1][lgval])};
		}
	}st;
	inline bool Calc(int l,int r){
		auto res = st.Query(l,r);
		return res.second + res.first - (r - l + 1) > 0;
	}
	inline bool Judge(int x){
		for(int i = 1;i + x - 1 <= n;i++){
			if(Calc(i,i+x-1))return true;
		}
		return false;
	}
	inline int SolveProb(){
		st.Build();
		int l = 1,r = n + 1;
		while(l < r){
			const int mid = (l + r) >> 1;
			if(Judge(mid)){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		return l-1;
	}
	inline void Solve(){
		fio<<SolveProb()<<'\n';
		for(int i = 1,k;i <= m;i++){
			fio>>k;
			for(int j = 1,x,y;j <= k;j++){
				fio>>x>>y;
				swap(a[x],a[y]);
			}
			fio<<SolveProb()<<'\n';
		}
		return ;
	}
}

bool _ED_;

int main(){
//	cerr<<"memory usage : "<<(&_ST_ - &_ED_) / 1024./1024.<<" MiB used"<<endl;
	freopen("loose.in","r",stdin);
	freopen("loose.out","w",stdout);
	fio>>n>>m;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
	}
	if(false && n <= 2006){
		Subtask1::Solve();
	}else{
		Subtask2::Solve();
	}
	return not(Akano loves pure__Elysia);
}
