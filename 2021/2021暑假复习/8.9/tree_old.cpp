#include<bits/stdc++.h>
using namespace std;
const int maxn = 198964;
struct tree{
	int h,pos;
}t[maxn];
bool comp(tree a,tree b){
	return a.pos < b.pos;
}
int n,i,ans,j;
int main(){
	freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>t[i].pos>>t[i].h;
	}
	//sort(t,t+n,comp);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			if(abs(t[i].pos-t[j].pos) < t[j].h && i != j){
				ans += t[j].h - abs(t[i].pos-t[j].pos);
				t[j].h = abs(t[i].pos-t[j].pos);
			}
		}
	}
	cout<<ans;
	return 0;
}
//priority_queue<int,vector<int>,greater<int> >a;

