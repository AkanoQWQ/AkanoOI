#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 6;
int n,m,a[MAXN],b[MAXN];
string s;
int ssort(){
	int ret = 0;
	for(int i = 0;i < n;i++){
		b[i] = a[i];
	}
	for(int i = 1;i < n;i++){
		for(int j = 0;j < n-i;j++){
			if (b[j] > b[j + 1]) {
                swap(b[j],b[j + 1]);
                ++ret;
            }
		}
	}
	return ret;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	cin>>s;
	cout<<ssort()<<endl;
	for(int i = 0;i < s.length();i++){
		if(s[i] == 'R'){
			for(int j = 0;j < n;j++){
				b[j] = a[j];
			}
			for(int j = 0;j < n;j++){
				a[j] = b[n-j-1];
			}
		}else{
			for(int j = 0;j < n;j++){
				b[j] = a[j];
			}
			for(int j = 0;j < n-1;j++){
				a[j] = b[j+1];
			}
			a[n-1] = b[0];
		}
		cout<<ssort()<<" ";
	}
	return 0;
}





