#include<bits/stdc++.h>
using namespace std;
int n,i,a[10006],b[10006],ta,tb,chances,tail = 0,head,aans;
struct act{
	int needs_a,needs_b;
}acts[200611];
bool SameAtFirst = 1,Found1,Found2;
int main(){
	freopen("sepadd.in","r",stdin);
	freopen("sepadd.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
		ta += a[i];
	}
	for(i = 0;i < n;i++){
		cin>>b[i];
		tb += b[i];
	}
	for(i = 0;i < n;i++){
		if(a[i] != b[i]){
			SameAtFirst = 0;
			break ;
		}
	}
	if(SameAtFirst){
		cout<<"Yes";
		return 0;
	}
	if(ta >= tb){
		cout<<"No";
		return 0;
	}
	chances  = tb - ta;
	for(i = 0;i < n;i++){
		if(a[i] != b[i]){
			aans += max(a[i] - b[i],b[i] - a[i]);
		}
	}
	aans /= 3;
	aans++;
	if(chances > aans){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	/*while(tail > head){
		if(acts[head].needs_a == 0 && acts[head].needs_b == 0){
			head++;
		}
		if(acts[head].needs_b >= 1){
			Found1 = 0,Found2 = 0;
				if(acts[head].needs_a == 0 && acts[head].needs_b == 0){
					head++;
				}
			if(acts[head].needs_a >= 2 && acts[head].needs_b >= 1){
				acts[head].needs_a -= 2;
				acts[head].needs_b--;
				
				if(head == tail){
					cout<<"Yes";
					return 0;
				}
				chances--;
				if(chances <= 0){
					cout<<"No";
					return 0; 
				}
				goto eend;
			}
			for(i = head+1;i < tail;i++){
				if(acts[i].needs_a >= 2){
					Found2 = 1;
					acts[head].needs_b--;
					acts[i].needs_a -= 2;
					break;
				}
				if(acts[i].needs_a == 1 && Found1 == 0){
					Found1 = i;
				}
			}
			if(Found2 == 0){
				if(Found1 != 0){
					acts[head].needs_b--;
					acts[i].needs_a = 0;
					acts[i].needs_b++;
				}else{
					acts[head].needs_b--;
					acts[tail].needs_b = 2;
					tail++;
				}
			}
			if(acts[head].needs_a == 0 && acts[head].needs_b == 0){
				head++;
			}
			if(head == tail){
				cout<<"Yes";
				return 0;
			}
			chances--;
			if(chances <= 0){
				cout<<"No";
				return 0; 
			}
		}
		/*11111111111111111这里以后要加else
		if(acts[head].needs_a >= 1){
			Found1 = 0;
			for(i = head+1;i < tail;i++){
				if(acts[i].needs_b >= 1){
					Found1 = 1;
					acts[head].needs_a -= 2;
					acts[i].needs_b--;
					break;
				}
			}
			if(Found1 == 0){
				acts[head].needs_a -= 2;
				acts[tail].needs_a = 1;
				tail++;
			}
			
			if(acts[head].needs_a < 0){
				acts[head].needs_b = 0 - acts[head].needs_a;
				acts[head].needs_a = 0;
			}
			
			if(acts[head].needs_a == 0 && acts[head].needs_b == 0){
				head++;
			}
			if(head == tail){
				cout<<"Yes";
				return 0;
			}
			chances--;
			if(chances <= 0){
				cout<<"No";
				return 0; 
			}
		}
		/*11111111111111111
		eend:;
	}
	*/
	return 0;
}	
