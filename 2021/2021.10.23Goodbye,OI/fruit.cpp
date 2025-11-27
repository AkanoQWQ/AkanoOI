#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
struct Fruit{
	int last,next,st,ed,type;
}f[200618];
bool outed[200618],op;
int tail,cache,i,n,a,getnum,sttail,pos,spos;
int main(){
	freopen("fruit.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>i;
	cache = i,f[0].last = 200611,f[0].type = i,f[0].st = 0;
	for(i = 1;i < n;i++){
		cin>>a;
		if(a != cache){
			cache = a;
			f[tail].next = tail+1;
			tail++;
			f[tail].type = a;
			f[tail].last = tail-1;
			f[tail].st = i,f[tail].ed = i;
		}else{
			f[tail].ed++;
		}
	}
	f[tail].next = 200611,f[200611].ed = 1;
	while(getnum < n){
		op = 0;
		pos = sttail;
		while(pos != 200611){
			if(outed[f[pos].st+1] == 1){
				//cout<<"ERROR"<<f[pos].st+1<<endl;
			}else{
				op = 1;
				cout<<f[pos].st+1<<" ";
				outed[f[pos].st+1] = 1;
				getnum++;
			}
			f[pos].st++;
			if(f[pos].ed < f[pos].st){
				if(f[f[pos].last].type != f[f[pos].next].type){
					f[f[pos].last].next = f[pos].next;
					f[f[pos].next].last = f[pos].last;
				}else{//1 2 3 4
					if(f[pos].next != 200611){
						f[f[pos].last].ed = f[f[pos].next].ed;
						f[f[pos].last].next = f[f[pos].next].next;
						f[f[f[pos].next].next].last = f[pos].last;
					}else{
						f[f[pos].last].next = 200611;
					}
				}
				if(pos == sttail){
					sttail = f[pos].next;
				}
			}
			pos = f[pos].next;
		}
		cout<<endl;
	}
	return 0;
}

