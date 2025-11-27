#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MODD = 147744151;
const int MAXN = 1018;
const int MAXPR = 34;

class FastIO{
private:
	const static int buffSize = 1<<23;
	using charp = char*;
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
public:
	bool fail;
	inline char FastGetChar(){
		if(inputPtr == inputEnd){
			size_t res = fread(inputBuff,1,buffSize,stdin);
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
		fwrite(outputBuff,1,outputPtr - outputBuff,stdout);
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
	operator bool(){
		return not(fail);
	}
	~FastIO(){
		Flush();
		return ;
	}
}fio;

int q,n,m,mod;
int EXGCD(int a,int b,int& x,int& y){
	if(b == 0){
		x = 1,y = 0;
		return a;
	}
	int gcd = EXGCD(b,a % b,x,y);
	int oldX = x;
	x = y;
	y = oldX - (a / b) * y;
	return gcd;
}
inline int Div(int b,int a){//a * x + mod * y = b   get b/a
	int x,y,gcd = EXGCD(a,mod,x,y),newmod = mod / gcd;
	x = (((1ll * x * b / gcd) % newmod) + newmod) % newmod;
	return x;
}
int pr[MAXPR],prCnt;
int prpow[MAXPR][MAXN];

struct MODint{
	int val;//val 与 mod 互质
	int modres[MAXPR],modcnt;
	MODint(){
		val = modcnt = 0;
		for(int i = 1;i <= prCnt;i++)modres[i] = 0;
		return ;
	}
	MODint(int _val){
		val = _val,modcnt = 0;
		for(int i = 1;i <= prCnt;i++)modres[i] = 0;
		while(val % mod == 0){
			val /= mod;
			modcnt++;
		}
		for(int i = 1;i <= prCnt;i++){
			while(val % pr[i] == 0){
				val /= pr[i];
				modres[i]++;
			}
		}
		return ;
	}
	int GetVal(){
		if(modcnt > 0)return 0;
		int ret = val;
		for(int i = 1;i <= prCnt;i++){
			ret = (1ll * ret * prpow[i][modres[i]]) % mod;
		}
		return ret;
	}
}f[MAXN][MAXN];
MODint operator*(const MODint& val1,const MODint& val2){
	MODint ret;
	ret.val = (1ll * val1.val * val2.val) % mod;
	ret.modcnt = val1.modcnt + val2.modcnt;
	int minres = 1e9;
	for(int i = 1;i <= prCnt;i++){
		ret.modres[i] = val1.modres[i] + val2.modres[i];
		minres = min(minres,ret.modres[i]);
	}
	ret.modcnt += minres;
	for(int i = 1;i <= prCnt;i++){
		ret.modres[i] -= minres;
	}
	return ret;
}
MODint operator/(const MODint& val1,const MODint& val2){
	MODint ret;
	ret.val = Div(val1.val,val2.val);
	ret.modcnt = val1.modcnt - val2.modcnt;
	int minres = 1e9;
	for(int i = 1;i <= prCnt;i++){
		ret.modres[i] = val1.modres[i] - val2.modres[i];
		minres = min(minres,ret.modres[i]);
	}
	if(minres < 0){
		minres = abs(minres);
		for(int i = 1;i <= prCnt;i++){
			ret.modres[i] += minres;
		}
		ret.modcnt -= minres;
	}
	return ret;
}
int a[MAXN][MAXN],ans;
int main(){
	fio>>n>>m>>mod;
	{
		int x = mod;
		for(int i = 2;i*i <= x;i++){
			while(x % i == 0){
				pr[++prCnt] = i;
				x /= i;
			}
		}
		if(x != 1)pr[++prCnt] = x;
	}
	for(int i = 1;i <= prCnt;i++){
		prpow[i][0] = 1;
		for(int j = 1;j <= 1000;j++){
			prpow[i][j] = (1ll * prpow[i][j-1] * pr[i]) % mod;
		}
	}
	for(int i = 0;i <= max(n,m);i++){
		f[0][i] = f[i][0] = MODint(1);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			fio>>a[i][j];
			f[i][j] = MODint(a[i][j]) * f[i-1][j] * f[i][j-1] / f[i-1][j-1];
		}
	}
	fio>>q;
	for(int i = 1,_x1,_x2,_y1,_y2;i <= q;i++){
		fio>>_x1>>_y1>>_x2>>_y2;
		MODint res = (f[_x2][_y2] * f[_x1-1][_y1-1]) / (f[_x1-1][_y2] * f[_x2][_y1-1]);
		ans = (1ll * ans + (i ^ res.GetVal())) % MODD;
	}
	fio<<ans<<'\n';
	fio.Flush();
	return not(Akano loves pure__Elysia);
}
