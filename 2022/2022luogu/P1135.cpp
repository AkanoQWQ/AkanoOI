#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[2006],head,tail;
bool vis[2006];
struct que{
	int steps,pos;
}q[2006];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++){
		cin>>k[i];
	}
	//cout<<tail<<endl; 
	if(a == b){
		cout<<0;
		return 0;
	}
	q[tail].pos = a,q[tail].steps = 0,vis[a] = 1;
	tail++;
	//cout<<q[0].pos<<"1"<<endl;
	while(head < tail){
		int K1 = q[head].pos - k[q[head].pos];
		//cout<<"get"<<K1<<","<<q[head].pos<<","<<k[q[head].pos]<<endl;
		if(K1 >= 1 && K1 <= n && vis[K1] == 0){
			vis[K1] = 1;
			q[tail].pos = K1,q[tail].steps = q[head].steps + 1;
			if(q[tail].pos == b){
				cout<<q[tail].steps;
				return 0;
			}
			tail++;
		}
		K1 = q[head].pos + k[q[head].pos];
		//cout<<"get"<<K1<<endl;
		if(K1 >= 1 && K1 <= n && vis[K1] == 0){
			vis[K1] = 1;
			q[tail].pos = K1,q[tail].steps = q[head].steps + 1;
			if(q[tail].pos == b){
				cout<<q[tail].steps;
				return 0;
			}
			tail++;
		}
		head++;
	}
	cout<<-1;
	return 0;
}

