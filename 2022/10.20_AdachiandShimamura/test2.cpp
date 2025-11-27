## 思路

一道意想不到的特判题。

咱想起来围棋中有一句话叫做“有眼杀无眼”，在这道题中就是“纯a杀非纯a”。如果 t 字符串有一个非a字母，由于初始 s 一定带一个a，那么把 t 的非a字母放到第一个位置， s 的字典序一定小于 t 的字典序

但是如果反过来呢？t 全都是a（注意，只要不满足上述的条件，t 就一定为全a），如果这时候 s 有非a字母，那么同理，s 的字典序一定大于 t 的字典序。

上述两个条件都不符合呢？这个时候说明 s 和 t 都是全a字符串，这个时候只有 s 的总长度小于 t 的总长度，才能满足 s 的字典序小于 t 的字典序。

所以，我们记录 s、t 是否全a，记录他们的长度，就可以进行特判了。

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
long long t,q,opt,k;
string s;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		long long alen = 1,blen = 1;
		bool HAVE_B = 0,ALL_A = 1;
		cin>>q;
		while(q--){
			cin>>opt>>k>>s;
			if(opt == 1){
				alen += s.length()*k;
				for(int i = 0;i < s.length();i++){
					if(s[i] > 'a')ALL_A = 0;
				}
			}else{
				blen += s.length()*k;
				for(int i = 0;i < s.length();i++){
					if(s[i] > 'a')HAVE_B = 1;
				}
			}
			if(HAVE_B){
				cout<<"YES"<<endl;
				continue;
			}
			if(ALL_A == 0){
				cout<<"NO"<<endl;
				continue;
			}
			if(alen < blen){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
```
