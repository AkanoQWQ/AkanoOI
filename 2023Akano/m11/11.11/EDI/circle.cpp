#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pii = pair<int,int>;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int MOD = 1e9 + 7;

bool _ST_;

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
int n,belong[MAXN * 3],arr[MAXN * 3];
vector<int> stpos,arrpos[MAXN];
ll totans,f[MAXN * 3];
inline bool Stat3(int i){
	const int x = arr[i];
	return int(arrpos[x].size()) == 3 && i == arrpos[x][0];
}
inline bool Stat2(int i){
	const int x = arr[i];
	if(int(arrpos[x].size()) == 2){
		return i == arrpos[x][0];
	}else if(int(arrpos[x].size()) == 3){
		return i == arrpos[x][1];
	}
	return false;
}
inline bool Stat1(int i){
	const int x = arr[i];
	if(int(arrpos[x].size()) == 2){
		return i == arrpos[x][1];
	}else if(int(arrpos[x].size()) == 3){
		return i == arrpos[x][2];
	}
	return true;
}
int bancnt[MAXN];
inline bool Able(int l,int r,int w,int x){
	l++,r--;
	if(l > r)return true;
	return bancnt[r] - bancnt[l-1] == (r-l+1) * w + x;
}
inline ll Solve(int delL,int delR,bool throughCenter){
	for(int i = 1;i <= n;i++){
		arrpos[i].clear();
	}
	int tail = 0;
	if(throughCenter){
		for(int i = delL + 1;i <= delR - 1;i++){
			arr[++tail] = belong[i];
			arrpos[arr[tail]].push_back(tail);
		}
	}else{
		for(int i = delR + 1;i <= 3*n;i++){
			arr[++tail] = belong[i];
			arrpos[arr[tail]].push_back(tail);
		}
		for(int i = 1;i <= delL - 1;i++){
			arr[++tail] = belong[i];
			arrpos[arr[tail]].push_back(tail);
		}
	}
	for(int i = 1;i <= tail+2;i++){
		f[i] = bancnt[i] = 0;
	}
	for(int i = 1;i < n;i++){
		if(int(arrpos[i].size()) <= 1){
			return 0;
		}
		if(int(arrpos[i].size()) == 2){
			bancnt[arrpos[i][0]]++,bancnt[arrpos[i][1]+1]--;
		}else{
			bancnt[arrpos[i][1]]++,bancnt[arrpos[i][1]+1]--;
		}
	}
	for(int i = 1;i <= tail;i++){
		bancnt[i] += bancnt[i-1];
		bancnt[i] += bancnt[i-1];
	}
	f[1] = 1;
//	for(int i = 1;i <= tail;i++){
//		cerr<<arr[i]<<",";
//	}
//	cerr<<endl;
	for(int i = 1;i <= tail;i++){
		const int x = arr[i];
		if(Stat3(i)){
			if(Able(arrpos[x][0],arrpos[x][1],0,1)){
				f[arrpos[x][1]+1] += f[i];
//				cerr<<i<<"update"<<arrpos[x][1]+1<<" case1-1"<<endl;
			}else{
//				cerr<<i<<" try upd "<<arrpos[x][1]+1<<" fail"<<endl;
			}
			f[i+1] = (f[i+1] + f[i]) % MOD;
//			cerr<<i<<"update"<<i+1<<" case1-2"<<endl;
		}else if(Stat2(i)){
			if(int(arrpos[x].size()) == 2){
				if(Able(arrpos[x][0],arrpos[x][1],1,0)){
//					cerr<<i<<"update"<<arrpos[x][1]+1<<" case2-1"<<endl;
					f[arrpos[x][1]+1] = (f[arrpos[x][1]+1] + f[i]) % MOD;
				}
			}else{
				if(Able(arrpos[x][1],arrpos[x][2],0,1)){
//					cerr<<i<<"update"<<arrpos[x][2]+1<<" case2-2"<<endl;
					f[arrpos[x][2]+1] = (f[arrpos[x][2]+1] + f[i]) % MOD;
				}
			}
		}else if(Stat1(i)){
			f[i+1] = (f[i+1] + f[i]) % MOD;
//			cerr<<i<<"update"<<i+1<<" case3"<<endl;
		}
	}
//	for(int i = 1;i <= tail;i++){
//		cerr<<f[i]<<" ";
//	}
//	cerr<<endl;
	return f[tail+1];
}

bool _ED_;

int main(){
//	ferr("memory usage : {} MiB\n",(&_ST_ - &_ED_) / 1024. / 1024.);
//	freopen("circle/circle81.in","r",stdin);
//	freopen("circle.out","w",stdout);
	fio>>n;
	for(int i = 1;i <= 3*n;i++){
		fio>>belong[i];
		if(belong[i] == n)stpos.push_back(i);
	}
	totans = (Solve(stpos[0],stpos[1],false) + Solve(stpos[0],stpos[2],true) + Solve(stpos[1],stpos[2],false)) % MOD;
	fio<<totans<<endl;
	return not(Akano loves pure__Elysia);
}
