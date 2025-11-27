#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
int t,n;
bool tong[MAXN];
struct pr{
	int num,no;
}a[MAXN],b[MAXN];
bool cmp1(pr p1,pr p2){
	return p1.num > p2.num; 
}
bool huifu(pr p1,pr p2){
	return p1.no < p2.no;
}
void show(){
	for(int i = 1;i <= n/2;i++){
			cout<<a[i].no<<"|";
		}
		cout<<endl;
		for(int i = 1;i <= n/2;i++){
			cout<<a[i].num<<",";
		}
		cout<<endl;
	return ;
}
queue<pair<int,int> > q;
bool cmp2(pr& p1,pr& p2){
	while(!q.empty()){
		show();
		cout<<"truly swap "<<q.front().first<<" "<<q.front().second<<endl;
		swap(a[q.front().first].no,a[q.front().second].no);
		show();
		q.pop();
	}
	bool swp = p1.num < p2.num;
	if(p2.num > b[p1.no].num){
		swp = 0;
	}
	if(swp){
		cout<<p1.no<<","<<p1.num<<" swap "<<p2.no<<","<<p2.num<<endl;
		q.push(make_pair(p1.no,p2.no));
		return 1;
	}
	return 0;
}
int main(){
	freopen("g.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool able = 1;
		for(int i = 1;i <= n;i++)tong[i] = 1;
		for(int i = 1;i <= n/2;i++){
			cin>>b[i].num;
			if(tong[b[i].num] == 0){
				able = 0;
				break;
			}
			b[i].no = i;
			tong[b[i].num] = 0;
		}
		if(able == 0){
			puts("-1");
			continue;
		}
		sort(b+1,b+(n/2)+1,cmp1);
		int pos = n; 
//		for(int i = 1;i <= n/2;i++){
//			cout<<b[i].num<<",";
//		}
//		cout<<endl;
		for(int i = 1;i <= n/2;i++){
			while(tong[pos] == 0)pos--;
			if(pos >= b[i].num){
//				cout<<b[i].num<<" compare "<<pos<<endl;
				able = 0;
				break;
			}
			a[b[i].no].num = pos;
			a[b[i].no].no = b[i].no;
			tong[pos] = 0;
		}
		sort(b+1,b+(n/2)+1,huifu);
		for(int i = 1;i <= n/2;i++){
			cout<<a[i].no<<"|";
		}
		cout<<endl;
		for(int i = 1;i <= n/2;i++){
			cout<<a[i].num<<",";
		}
		cout<<endl;
		puts("NIE");
		sort(a+1,a+(n/2)+1,cmp2);
		while(!q.empty()){
			while(!q.empty()){
				swap(a[q.front().first].no,a[q.front().second].no);
				q.pop();
			}
			sort(a+1,a+(n/2)+1,cmp2);
		}
		show();
		puts("OVER");
		if(able == 0){
			puts("-1");
			continue;
		}
		for(int i = 1;i <= n/2;i++){
			cout<<a[i].num<<" "<<b[i].num<<" ";
		}
		cout<<endl;
	}
	return 0;
}

