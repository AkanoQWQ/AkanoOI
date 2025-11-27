#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 33;

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
		while(IsSplited(ch) && !fail)ch = FastGetChar();
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
FastIO fio(stdin,stdout);

int n,m,k,tid,perfect[MAXN],w[MAXM],c[MAXM];
string s,t[MAXM];
namespace CommonHash{
	const int base = 33;
	mt19937 rng(time(0));
	int char2val[28];
	ull strHash[MAXN],hashBase[MAXN],tHash[MAXM];
	inline ull Cut(int l,int r){
		return strHash[r] - strHash[l-1] * hashBase[r - l + 1];
	}
	inline void Prepare(){
		for(int i = 0;i < 26;i++){
			char2val[i] = i;
		}
		shuffle(char2val,char2val + 26,rng);
		hashBase[0] = 1;
		for(int i = 1;i <= n;i++){
			hashBase[i] = hashBase[i-1] * base;
			strHash[i] = strHash[i-1] * base + char2val[s[i] - 'a'];
		}
		for(int i = 1;i <= m;i++){
			for(auto ch : t[i]){
				tHash[i] = tHash[i] * base + char2val[ch - 'a'];
			}
		}
		return ;
	}
	inline bool Judge(int i,int j){
		bool ret = (i + int(t[j].length()) - 1 <= n) && (Cut(i,i + int(t[j].length()) - 1) == tHash[j]);
		return ret;
	}
}
using namespace CommonHash;
struct Segment{
	int l,r,kol,value;
	Segment() = default;
	Segment(int _l,int _r,int _kol,int _value){
		l = _l,r = _r,kol = _kol,value = _value;
		return ;
	}
};
bool Cmp(Segment seg1,Segment seg2){
	if(seg1.r != seg2.r)return seg1.r > seg2.r;
	return seg1.l > seg2.l;
}
vector<Segment> segs;

class SegmentTree{
private:
	struct Node{
		int maxval,addlazy,setlazy;
	}node[MAXN * 4];
	inline void PushUp(int p){
		node[p].maxval = max(node[p*2].maxval,node[p*2+1].maxval);
		return ;
	}
	inline void SetVal(int p,int _val){
		node[p].maxval = max(node[p].maxval,_val);
		node[p].setlazy = max(node[p].setlazy,_val);
		return ;
	}
	inline void AddVal(int p,int _val){
		node[p].maxval += _val;
		node[p].addlazy += _val;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].addlazy != 0){
			AddVal(p*2,node[p].addlazy),AddVal(p*2+1,node[p].addlazy);
			node[p].addlazy = 0;
		}
		if(node[p].setlazy != 0){
			SetVal(p*2,node[p].setlazy),SetVal(p*2+1,node[p].setlazy);
			node[p].setlazy = 0;
		}
		return ;
	}
	void Set(int p,int l,int r,int OBJL,int OBJR,int _val){
		if(OBJL <= l && r <= OBJR){
			SetVal(p,_val);
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Set(p*2,l,mid,OBJL,OBJR,_val);
		if(mid < OBJR)Set(p*2+1,mid+1,r,OBJL,OBJR,_val);
		PushUp(p);
		return ;
	}
	void Add(int p,int l,int r,int OBJL,int OBJR,int _val){
		if(OBJL <= l && r <= OBJR){
			AddVal(p,_val);
			return ;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Add(p*2,l,mid,OBJL,OBJR,_val);
		if(mid < OBJR)Add(p*2+1,mid+1,r,OBJL,OBJR,_val);
		PushUp(p);
		return ;
	}
	int Query(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return node[p].maxval;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		int ret = 0;
		if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
		if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
		PushUp(p);
		return ret;
	}
public:
	inline void Set(int l,int r,int _val){
		if(l > r)return ;
		Set(1,1,n,l,r,_val);
		return ;
	}
	inline void Add(int l,int r,int _val){
		if(l > r)return ;
		Add(1,1,n,l,r,_val);
		return ;
	}
	inline int Query(int l,int r){
		if(l > r)return 0;
		return Query(1,1,n,l,r);
	}
}ftr[MAXM],gtr;

inline int Solve(){
	int ret = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(Judge(i,j)){
				segs.emplace_back(i,i + int(t[j].length()) - 1,c[j],perfect[i] + w[j]);
			}
		}
	}
	sort(segs.begin(),segs.end(),Cmp);
	for(auto seg : segs){
		const int l = seg.l,r = seg.r,kol = seg.kol,value = seg.value;
		int cache = 0;
		cache = max(cache,gtr.Query(r+k+1,n) + value);
		cache = max(cache,ftr[kol].Query(l,n) + value);
		gtr.Set(l,l,cache);
		ret = max(ret,cache);
		ftr[kol].Set(l,l,cache);
		ftr[kol].Add(1,l-1,value);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("piano/piano0.in","r",stdin);
//	freopen("piano.out","w",stdout);
	fio>>n>>m>>k>>tid;
	fio>>s;
	s = "." + s;
	for(int i = 1;i <= n;i++){
		fio>>perfect[i];
	}
	for(int i = 1;i <= m;i++){
		fio>>t[i]>>w[i]>>c[i];
	}
	Prepare();//common hash
	fio<<Solve();
	return not(Akano loves pure__Elysia);
}
