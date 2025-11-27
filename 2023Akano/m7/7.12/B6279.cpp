#include<bits/stdc++.h>
using namespace std;
const int MAXS = 36;
const int MAXN = 36;
const int MAXLEN = 156;
string passage,str[MAXN];
int n,len[MAXN],f[MAXLEN];
bool able[MAXLEN][MAXLEN][MAXN][MAXS];
bool del[MAXLEN][MAXLEN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>passage>>n;
	passage = "." + passage;
	len[0] = passage.length() - 1;
	for(int i = 1;i <= n;i++){
		cin>>str[i];
		str[i] = "." + str[i];
		len[i] = str[i].length() - 1;
	}
	for(int l = len[0];l >= 1;l--){
		for(int r = l;r <= len[0];r++){
			for(int no = 1;no <= n;no++){
				able[l][l-1][no][0] = true;
				for(int lengs = 1;lengs <= len[no] && l + lengs - 1 <= r;lengs++){
					if(able[l][r-1][no][lengs-1] && passage[r] == str[no][lengs]){
						able[l][r][no][lengs] = true;
					}
					for(int mid = l;mid < r;mid++){
						if(able[l][mid][no][lengs] && del[mid+1][r]){
							able[l][r][no][lengs] = true;
						}//terrible... 
					}
				}
				if(able[l][r][no][len[no]])del[l][r] = true;
			}
		}
	}
	for(int i = 1;i <= len[0];i++){
		f[i] = f[i-1] + 1;
		for(int j = 1;j <= i;j++){
			if(del[j][i]){
				f[i] = min(f[i],f[j-1]);
			}
		}
	}
	cout<<f[len[0]]<<flush;
	return 0;
}
