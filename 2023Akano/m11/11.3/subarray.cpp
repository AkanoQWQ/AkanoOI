#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 1018 + 1108;
constexpr ll INF = 1e16 + 200610181108;

class FastIO{//1.2
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

pair<ll,int> sumdelta[MAXN];
int time2pos[MAXN];
int n,m,q,timeCnt = 1;
ll a[MAXN],sum[MAXN];

struct Segment{
	ll k,b;
	inline ll Calc(ll x){//在这里嵌入了sumdelta
		return k * sumdelta[x].first + b;
	}
	Segment(){
		k = 0,b = -INF;
		return ;
	}
	Segment(ll _k,ll _b){
		k = _k,b = _b;
		return ;
	}
};
class LichaoSegmentTree{
private:
	Segment lazy[MAXN * 4];
	void PushDown(int p,int l,int r,Segment v){
		const int mid = (l + r) >> 1;
		Segment& u = lazy[p];
		if(v.Calc(mid) > u.Calc(mid))swap(u,v);
		bool psdL = (v.Calc(l) > u.Calc(l)),psdR = (v.Calc(r) > u.Calc(r));
		if(psdL)PushDown(p*2,l,mid,v);
		if(psdR)PushDown(p*2+1,mid+1,r,v);
		return ;
	}
	void Insert(int p,int l,int r,int OBJL,int OBJR,Segment seg){
		if(OBJL <= l && r <= OBJR){
			PushDown(p,l,r,seg);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)Insert(p*2,l,mid,OBJL,OBJR,seg);
		if(mid < OBJR)Insert(p*2+1,mid+1,r,OBJL,OBJR,seg);
		return ;
	}
	ll Query(int p,int l,int r,int pos){
		ll ret = lazy[p].Calc(pos);
		if(l == r)return ret;
		const int mid = (l + r) >> 1;
		if(mid >= pos)ret = max(ret,Query(p*2,l,mid,pos));
		if(mid < pos)ret = max(ret,Query(p*2+1,mid+1,r,pos));
		return ret;
	}
public:
	inline void Clear(){
		for(int i = 0;i < MAXN * 4;i++){
			lazy[i] = Segment();
		}
		return ;
	}
	inline void Insert(int l,int r,Segment seg){
		Insert(1,1,timeCnt,l,r,seg);
		return ;
	}
	inline ll Query(int x){
		return Query(1,1,timeCnt,x);
	}
}tr;
ll ans[MAXN];
vector<pair<int,int> > queryL[MAXN],queryR[MAXN];//时间和位置
int main(){
	freopen("subarray/subarray5.in","r",stdin);
//	freopen("subarray.out","w",stdout);
	fio>>n>>m;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
		sum[i] = sum[i-1] + a[i];
	}
	sumdelta[1] = {0,1};
	for(int i = 1,opt,x;i <= m;i++){
		fio>>opt>>x;
		if(opt == 1){
			q++;
			queryL[x-1].emplace_back(timeCnt,q),queryR[x+1].emplace_back(timeCnt,q);
			ans[q] = a[x] + sumdelta[timeCnt].first;
			if(q == 4)ferr<<"org "<<ans[q]<<" and timecnt "<<timeCnt<<" val "<<sumdelta[timeCnt].first<<endl;
		}else{
			timeCnt++;
			sumdelta[timeCnt] = sumdelta[timeCnt - 1];
			sumdelta[timeCnt].first += x,sumdelta[timeCnt].second = timeCnt;
		}
	}
	sort(sumdelta + 1,sumdelta + timeCnt + 1);
	for(int i = 1;i <= timeCnt;i++){
		time2pos[sumdelta[i].second] = i;
	}
	for(int i = n;i >= 1;i--){
		tr.Insert(1,n,Segment(i+1,sum[i]));
		for(auto query : queryR[i]){
			ans[query.second] += max(0ll,tr.Query(time2pos[query.first]) - sum[i-1] - i * sumdelta[time2pos[query.first]].first);
			if(query.second == 4){
				ferr<<"got "<<tr.Query(time2pos[query.first]) - sum[i-1] - i * sumdelta[time2pos[query.first]].first<<endl;
			}
		}
	}
	tr.Clear();
	for(int i = 1;i <= n;i++){
		tr.Insert(1,n,Segment(-i,-sum[i-1]));
		for(auto query : queryL[i]){
			ans[query.second] += max(0ll,tr.Query(time2pos[query.first]) + sum[i] + (i+1) * sumdelta[time2pos[query.first]].first);
			if(query.second == 4){
				ferr<<"got "<<tr.Query(time2pos[query.first]) + sum[i] + (i+1) * sumdelta[time2pos[query.first]].first<<endl;
			}
		}
	}
	for(int i = 1;i <= q;i++){
		fio<<ans[i]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
