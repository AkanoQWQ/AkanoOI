#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 3e5 + 6;
int n,m,a[MAXN],ans,len,lr,b[MAXN],c[MAXN],ln,lastln;
string s;
bool f = 1;
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
void merge_sort(int l,int r){
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	merge_sort(l,mid),merge_sort(mid+1,r);
	int i = l,j = mid + 1,tail = l;
	while(i <= mid && j <= r){
		if(b[i] < b[j]){
			c[tail++] = b[i++];
			ans += (j-mid-1);
		}else{
			c[tail++] = b[j++];
		}
	}
	while(i <= mid){
		c[tail++] = b[i++];
		ans += (j-mid-1);
	}
	while(j <= r){
		c[tail++] = b[j++];
	}
	for(int k = l;k <= r;k++){
		b[k] = c[k];
	}
	return ;
}
deque<int> q;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>len;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	lr = n * (n-1) / 2;
	cin>>s;
	for(int i = 1;i <= n;i++){
		q.push_back(i);
	}
	merge_sort(1,n);
	cout<<ans<<endl;
	for(int i = 0;i < len;i++){
		if(s[i] == 'R'){
			ans = lr - ans;
			f = !f;
		}else{

			if(f){
				ln = q.front();
				q.pop_front();
				q.push_back(ln);
			}
			if(!f){
				ln = q.back();
				q.pop_back();
				q.push_front(ln);
			}
			ans = ans + (n-a[ln]) - (a[ln] - 1);
		}
		cout<<ans%10;
	} 
	return 0;
}
/*

*/
