#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+6;
int t,n,a[MAXN*2],opp[MAXN];
int pr[MAXN][2],r,l;
bool opt[MAXN*2],poss;
int movei[4] = {1,-1,1,-1},st[4] = {1,1,0,0};
string moves[4] = {"l2r","l2l","r2r","r2l"};
string stans[4] = {"L","L","R","R"};
string backans;
struct ANS{
	string ans;
	int no;
}ans[6];
bool cmp4ANS(ANS a,ANS b){
	return a.ans < b.ans;
}
int anstail = 0;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(pr,0,sizeof(pr));
		memset(opp,0,sizeof(opp));
		for(int i = 1;i <= 2*n;i++){
			scanf("%d",&a[i]);
			pr[a[i]][1] = pr[a[i]][0];
			pr[a[i]][0] = i;
		}
		for(int i = 1;i <= 2*n;i++){
			if(pr[a[i]][0] != i){
				opp[i] = pr[a[i]][0];
			}else{
				opp[i] = pr[a[i]][1];
			}
		}
		st[2] = 2 * n,st[3] = 2 * n;
		anstail = 0;
		for(int k = 0;k < 4;k++){
			l = 1,r = 2 * n,poss = 1;
			if(opp[st[k]] + n * movei[k] < 1 || opp[st[k]] + n * movei[k] > 2 * n)continue;
			anstail++;
			ans[anstail].ans = "";
			backans = "";
			int insl = opp[st[k]],insr = opp[st[k]];
			for(int j = 1;j <= n;j++){
				if(insr > r+1 || insl < l-1){
					poss = 0;
					break;
				}
				if(opp[insl] == l){
					ans[anstail].ans += 'L';
					l++;
					if(insl == insr){
						insr++;
						backans = 'L' + backans;
					}else{
						backans = 'L' + backans;
					}
					insl--;
				}else if(opp[insr] == l){
					ans[anstail].ans += 'L';
					l++;
					if(insl == insr){
						insl--;
						backans = 'L' + backans;
					}else{
						backans = 'R' + backans;
					}
					insr++;
				}else if(opp[insl] == r){
					ans[anstail].ans += 'R';
					r--;
					if(insl == insr){
						insr++;
						backans = 'L' + backans;
					}else{
						backans = 'L' + backans;
					}
					insl--;
				}else if(opp[insr] == r){
					ans[anstail].ans += 'R';
					r--;
					if(insl == insr){
						insl--;
						backans = 'L' + backans;
					}else{
						backans = 'R' + backans;
					}
					insr++;
				}else{
					poss = 0;
					break;
				}
			}
			ans[anstail].no = k;
			ans[anstail].ans += backans;
			if(!poss)anstail--;
		}
		if(anstail > 0){
			sort(ans+1,ans+anstail+1,cmp4ANS);
			cout<<ans[1].ans<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
