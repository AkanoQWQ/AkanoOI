#include<bits/stdc++.h>
using namespace std;
int tail,nnum[100006],cnum[100006]/*charNum*/,i,j,len,head = 0,a,b,ans = 99999999,cnt;
string s;
char ch;
bool Caps = 0,CCaps/*CacheCaps*/;//´óĞ´
bool BeCap(char cchar){
	if(cchar >= 'A' && cchar <= 'Z')return 1;
	return 0;
}
int main(){
	freopen("change.in","r",stdin);
	freopen("change.out","w",stdout);
	cin>>s;
	len = s.length();
	Caps = BeCap(s[0]),tail = 0;
	if(Caps == 0){
		cnum[0] = -1;
	}else{
		cnum[0] = 1;
	}
	for(i = 1;i < len;i++){
		ch = s[i];
		CCaps = BeCap(ch);
		if(CCaps == Caps){
			if(Caps == 1){
				cnum[tail]++;
			}else{
				cnum[tail]--;
			}
		}else{
			tail++;
			if(CCaps == 0){
				cnum[tail] = -1;
			}else{
				cnum[tail] = 1;
			}
			Caps = CCaps;
		}
	}
	if(cnum[0] > 0)head++;
	if(cnum[tail] < 0)tail--;
	for(i = 0;i <= tail;i++){
		//cout<<cnum[i]<<" ";
		nnum[i] = cnum[i];
	}
	//cout<<endl; 
	for(i = 2;i <= tail;i++){
		cnum[i] += cnum[i-2]; 
	}
	/*for(i = 0;i <= tail;i++){
		cout<<cnum[i]<<" ";
	}*/
	for(i = head;i <= tail;i++){
		cnt = 0;
		if(cnum[i] < 0){
			if(i == 0){
				if(cnum[tail] > 0){
					cnt += cnum[tail];
				}else{
					cnt += cnum[tail-1];
				}
				ans = min(ans,cnt);
				continue;
			}
			if(cnum[tail] > 0){
				cnt += abs(cnum[i] - nnum[i]);
				cnt += abs(cnum[tail] - cnum[i-1]);
			}else{
				cnt += abs(cnum[i] - nnum[i]);
				cnt += abs(cnum[tail-1] - cnum[i-1]);
			}
			ans = min(ans,cnt);
		}else{
			if(i == 1){
				if(cnum[tail] > 0){
					cnt += abs(cnum[tail]);
					cnt += abs(cnum[0]);
				}else{
					cnt += abs(cnum[tail-1]);
					cnt += abs(cnum[0]);
				}
				ans = min(ans,cnt);
				//if(cnt == 16298)cout<<"test"; 
				continue;
			}
			if(cnum[tail] > 0){
				cnt += abs(cnum[i-1]);
				cnt += abs(cnum[tail] - cnum[i-2]);
			}else{
				cnt += abs(cnum[tail-1] - cnum[i-2]);
				cnt += abs(cnum[i-1]);
			}
			ans = min(ans,cnt);
		}
	}
	cnt = 0;
	if(cnum[tail] < 0){
		cnt += abs(cnum[tail]);
	}else{
		cnt += abs(cnum[tail-1]);
	}
	ans = min(ans,cnt);
	/*for(i = 0;i <= tail;i++){
		cout<<cnum[i]<<" ";
	}
	cout<<endl;*/
	if(ans == 99999999)ans = 0;
	cout<<ans; 
	return 0;
}
//2 | -4 3 -1 2
//2 | -4 5 -5 7
//-2 3 -3 5
//-2 3 -5 8 
//-2 3 -3 3 -1 1 -1
//-2 3 -5 6 -6 7 -7
