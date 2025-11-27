#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 999;

template<int SIZE>
class BitArray{
private:
	using ull = unsigned long long;
	const int LEN = SIZE / 64;
	ull bit[(SIZE / 64)+1];
	friend class Reference;
	class Reference{
	private:
		friend class BitArray;
		BitArray* source;
		size_t pos;
		Reference() = default;
		Reference(BitArray* _source,size_t _pos){
			source = _source;
			pos = _pos;
			return ;
		}
	public:
		operator bool(){
			return source->Get(pos);
		}
		Reference& operator=(bool _val){
			source->Set(pos,_val);
			return *this;
		}
	};
public:
	BitArray operator|(const BitArray& oth)const{
		BitArray ret;
		for(int i = 0;i <= LEN;i++){
			ret.bit[i] = bit[i] | oth.bit[i];
		}
		return ret;
	}
	BitArray operator&(const BitArray& oth)const{
		BitArray ret;
		for(int i = 0;i <= LEN;i++){
			ret.bit[i] = bit[i] & oth.bit[i];
		}
		return ret;
	}
	BitArray& operator&=(const BitArray& oth){
		for(int i = 0;i <= LEN;i++){
			bit[i] &= oth.bit[i];
		}
		return *this;
	}
	BitArray& operator|=(const BitArray& oth){
		for(int i = 0;i <= LEN;i++){
			bit[i] |= oth.bit[i];
		}
		return *this;
	}
	BitArray operator<<(int x)const{
		BitArray ret;
		int high = x >> 6,low = x & 63;
		ull last = 0;
		for(int i = 0;i + high <= LEN;i++){
			ret.bit[i + high] = (bit[i] << low) | last;
			if(low)last = bit[i] >> (64 - low);
		}
		return ret;
	}
	BitArray operator>>(int x)const{
		BitArray ret;
		int high = x >> 6,low = x & 63;
		ull last = 0;
		for(int i = LEN;i >= high;i--){
			ret.bit[i - high] = (bit[i] >> low) | last;
			if(low)last = bit[i] << (64 - low);
		}
		return ret;
	}
	BitArray& operator<<=(int x){
		int high = x >> 6,low = x & 63;
		for(int i = LEN - high;i >= 0;i--){
			bit[i + high] = (bit[i] << low);
			if(low && i)bit[i + high] |= bit[i - 1] >> (64 - low);
		}
		for(int i = 0;i < high;i++)bit[i] = 0;
		return *this;
	}
	BitArray& operator>>=(int x){
		int high = x >> 6,low = x & 63;
		for(int i = high;i <= LEN;i++){
			bit[i - high] = (bit[i] >> low);
			if(low && i)bit[i - high] |= bit[i - 1] << (64 - low);
		}
		for(int i = LEN-high+1;i <= LEN;i++)bit[i] = 0;
		return *this;
	}
	inline void Set(int pos,bool x){
		int pos1 = pos >> 6;
		int pos2 = pos & 63;
		if(x == true){
			bit[pos1] |= (1ull<<pos2);
		}else{
			bit[pos1] |= (1ull<<pos2);
			bit[pos1] ^= (1ull<<pos2);
		}
		return ;
	}
	inline bool Get(int pos){
		int pos1 = pos >> 6;
		int pos2 = pos & 63;
		return (bit[pos1] >> pos2) & 1;
	}
	BitArray(){
		memset(bit,0,sizeof(bit));
		return ;
	}
	inline Reference operator[](int pos){
		return Reference(this,pos);
	}
};
BitArray<1000> arr;

int n = 6;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= n;i++){
		if(i & 1)arr[i] = true;
	}
	for(int i = 1;i <= n;i++){
		cout<<arr[i];
	}
	cout<<endl;
	arr >>= 3;
	for(int i = 1;i <= n;i++){
		cout<<arr[i];
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
