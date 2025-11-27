#include<bits/stdc++.h>
using namespace std;
struct fru{
	int next,last,type;
}f[200006]; 
int n,fr[200006],tat[200006],tansw,spos,tcnt,i,j,cach,op;
int main(){
	freopen("fruit.in","r",stdin);
	//freopen("fruit.out","w",stdout);
	scanf("%d",&n);
	for(i = 1;i <= n;i++){
		scanf("%d",&fr[i]);
		f[i].last = i-1,f[i].next = i+1,f[i].type = fr[i];
	}
	fr[0] = 1293,cach = 1;
	while(tansw < n){
		spos = cach,op = f[cach].type;
		cout<<spos<<" ";
		spos = f[spos].next;
		while(spos != n+1){
			if(f[spos].type != cach){
				cout<<spos<<" ";
				tansw++;
				if(spos == cach){
					cach = f[spos].next;
				}
				cach = f[spos].type;
				f[f[spos].last].next = f[spos].next;
				f[f[spos].next].last = f[spos].last;
			}
			spos = f[spos].next;
		}
		/*tcnt++;
		i = 1;
		while(i <= n){
			cach = fr[i];
			if(tat[i] == 0){
				tat[i] = tcnt,tansw++,fr[i] = -1;
			}
			spos = i+1;
			while(spos <= n && (fr[spos] == cach || fr[spos] == -1)){
				spos++;
			}
			i = spos;
			
		}
	}
	for(i = 1;i <= tcnt;i++){
		for(j = 1;j <= n;j++){
			if(tat[j] == i){
				printf("%d ",j);
			}
		}
		cout<<endl;
	*/
	cout<<endl;
	}
	
	return 0;
}
