#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 106;

class FastIO{
private:
	const static int buffSize = 1<<23;
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
	FILEp inFile,outFile;
	char inputBuff[buffSize +2],outputBuff[buffSize + 2];
	charp inputPtr = inputBuff,inputEnd = inputPtr;
	charp outputPtr = outputBuff,outputEnd = outputBuff + buffSize;
	inline bool IsSplited(char ch){
		return (ch == ' ' || ch == '\n');
	}
	template <typename T>
	void ReadInt(T &x){
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
	template <typename T>
	void WriteInt(T x){
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
	inline void ReadString(string& str){
		str = "";
		char ch = FastGetChar();
		while(!IsSplited(ch) && !fail){
			str += ch;
			ch = FastGetChar();
		}
		return ;
	}
	inline void WriteString(const string& str){
		for(auto i : str){
			FastPutChar(i);
		}
		return ;
	}
	inline void FmtOutput(ccp format){
		for(;*format;format++){
			FastPutChar(*format);
		}
		return ;
	}
	template<typename FirstType,typename... ResType>
	inline void FmtOutput(ccp format,const FirstType& firstElement,const ResType&... res){
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
	template<typename T>
	inline void ReadFloat(T& ret){
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
	template<typename T>
	inline void WriteFloat(T x){
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
public:
	bool fail;
	inline char FastGetChar(){
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
	inline void FastPutChar(char ch){
		if(outputPtr == outputEnd){
			Flush();
		}
		*(outputPtr++) = ch;
		return ;
	}
	inline void Flush(){
		fwrite(outputBuff,1,outputPtr - outputBuff,outFile);
		outputPtr = outputBuff;
		return ;
	}
	inline void Endl(){
		FastPutChar('\n');
		return ;
	}
	FastIO& operator>>(short& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(int& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(__int128& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(float& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(double& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(string& stringVar){
		ReadString(stringVar);
		return *this;
	}
	FastIO& operator>>(char& charVar){
		charVar = FastGetChar();
		while(IsSplited(charVar))charVar = FastGetChar();
		return *this;
	}
	FastIO& operator<<(short integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(int integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(__int128 integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(string stringVar){
		WriteString(stringVar);
		return *this;
	}
	FastIO& operator<<(char charVar){
		FastPutChar(charVar);
		return *this;
	}
	FastIO& operator<<(float floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(double floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(ostreamFunc func){
		ostringstream oss;
		oss<<func;
		string str = oss.str();
		for(auto i : str){
			FastPutChar(i);
		}
		Flush();
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
};
FastIO fio(stdin,stdout),ferr(nullptr,stderr);

template<typename T>
class InverseFactory{
private:
	vector<pair<T&,T> > arr;
	vector<T> sum,inv;
	inline void Build(){
		T cacheval;
		arr.clear(),sum.clear(),inv.clear();
		arr.emplace_back(cacheval,T(1)),sum.push_back(T(1)),inv.push_back(T(1));
		return ;
	}
	inline T KSM(T a,T b){
		T ret = 1;
		while(b){
			if(b & 1)ret = (ret * a) % MOD;
			a = (a * a) % MOD;
			b >>= 1;
		}
		return ret;
	}
public:
	T MOD;
	InverseFactory(){
		MOD = 1;
		Build();
		return ;
	}
	InverseFactory(T _mod){
		MOD = _mod;
		Build();
		return ;
	}
	inline void Insert(T& pos,T val){
		arr.emplace_back(pos,val),sum.push_back((sum.back() * val) % MOD);
		return ;
	}
	inline void Solve(){
		const int nowSize = int(sum.size()) - 1;
		inv.resize(sum.size());
		for(int i = 1;i <= nowSize;i++){
			sum[i] = (sum[i-1] * arr[i].second) % MOD;
		}
		inv[nowSize] = KSM(sum[nowSize],MOD-2);
		for(int i = nowSize;i >= 1;i--){
			inv[i-1] = (inv[i] * arr[i].second) % MOD;
		}
		for(int i = nowSize;i >= 1;i--){
			inv[i] = (inv[i] * sum[i-1]) % MOD;
			arr[i].first = inv[i];
		}
		Build();
		return ;
	}
};
InverseFactory<ll> invFactory;

ll fac[MAXN*MAXN],facInv[MAXN*MAXN];
ll f[MAXN][MAXN],pow2[MAXN*MAXN],sumposs[MAXN][MAXN],chooseBit[MAXN][MAXN],n,k,mod;
inline ll A(ll x,ll y){
	if(x < y)return 0;
	ll ret = 1;
	for(ll i = x - y + 1;i <= x;i++){
		ret = (ret * i) % mod;
	}
	return ret;
}
inline ll C(ll x,ll y){
	if(x < y)return 0;
	return (((fac[x] * facInv[y]) % mod) * facInv[x-y]) % mod;
}
inline void Prepare(){
	fac[0] = facInv[0] = 1;
	int mx = max(n,k);
	invFactory.MOD = mod;
	for(int i = 1;i <= mx * mx;i++){
		fac[i] = (fac[i-1] * i) % mod;
		invFactory.Insert(facInv[i],fac[i]);
	}
	invFactory.Solve();
	pow2[0] = 1;
	for(int i = 1;i <= mx * mx;i++){
		pow2[i] = (pow2[i-1] * 2) % mod;
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= k;j++){
			chooseBit[i][j] = A((pow2[j] - 1 + mod) % mod,i);
			sumposs[i][j] = pow2[i * j];
			for(int lst = 0;lst < j;lst++){
				chooseBit[i][j] -= C(j,lst) * chooseBit[i][lst];
				chooseBit[i][j] = ((chooseBit[i][j] % mod) + mod) % mod;
				sumposs[i][j] -= C(j,lst) * sumposs[i][lst];
				sumposs[i][j] = ((sumposs[i][j] % mod) + mod) % mod;
			}
//			ferr("chooseBit[{},{}] = {},sumposs[{},{}] = {}",i,j,chooseBit[i][j],i,j,sumposs[i][j])<<endl;
		}
	}
	return ;
}
inline ll Poss(int i,int j,int x,int y){
	if((i == n) && (x == i - 1) && (n % 2 == 1)){
		return 0;
	}
	ll ret = (C(i,x)* C(j,y)) % mod;
	ret = (ret * chooseBit[i-x][j-y]) % mod;
	ret = (ret * pow2[(i - x) * y]) % mod;
	return ret;
}
int main(){
	fio>>n>>k>>mod;
	Prepare();
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k;j++){
			for(int x = 0;x < i;x++){
				for(int y = 0;y < j;y++){
					ll res = (sumposs[x][y] - f[x][y] + mod) % mod;
					f[i][j] = (f[i][j] + Poss(i,j,x,y) * res) % mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0;i <= k;i++){
		ll res = (sumposs[n][i] - f[n][i] + mod) % mod;
		ans += C(k,i) * res;
		ans %= mod;
	}
	fio<<ans<<endl;
	ferr("time used : {} ms",1e3 * clock() / CLOCKS_PER_SEC)<<endl;
	return not(Akano loves pure__Elysia);
}
