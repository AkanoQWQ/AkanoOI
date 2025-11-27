#include<bits/stdc++.h>
using namespace std;
int tin[50] = {0,1,2,3,4,5,6,12,13,14,15,16,23,24,25,26,34,35,36,45,46,123,124,125,126,134,135,136,145,146,156,1234,1235,1236,1245,1246,1256,1345,1346,1356,1456,12345,12346,12356,13456,123456};
char m[8][8],cm[8][8];
int i,j,ci,cj,a[8],b[8],ca,cb,h,w,k,atail,btail,bnum,cbnum,ii,ans,cci,ccj;
int mcnt[200611][2],mtail,cnta,cntb,weia,weib,NEED_BREAK,BRE;
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>h>>w>>k;
	for(i = 1;i <= h;i++){
		for(j = 1;j <= w;j++){
			cin>>m[i][j];
			if(m[i][j] == '#')bnum++;
		}
	}
	if(bnum == k){
		cout<<1;
		return 0; 
	}
	for(ci = 0;ci < 46;ci++){
		memset(a,0,sizeof(a));
		ca = tin[ci],atail = 0,cnta = 0,weia = 1; 
		while(ca > 0){
				a[atail] = ca % 10;
				if(a[atail] > h){
					a[atail] = 0;
				}else{
					atail++; 
				}
				ca /= 10;
		}
		for(cci = 0;cci < atail;cci++){
				cnta += a[cci]*weia;
				weia *= 10;
		}
		for(cj = 0;cj < 46;cj++){
			
			memset(b,0,sizeof(b));
			for(i = 1;i <= h;i++){
				for(j = 1;j <= w;j++){
					cm[i][j] = m[i][j];
				}
			}
			cb = tin[cj],btail = 0,cbnum = bnum,cntb = 0,weib = 1,NEED_BREAK = 0;
			
			
			while(cb > 0){
				b[btail] = cb % 10;
				if(b[btail] > w){
					b[btail] = 0;
				}else{
					btail++; 
				}
				cb /= 10;
			}
			
			for(cci = 0;cci < btail;cci++){
				cntb += b[cci]*weib;
				weib *= 10;
			}
			
			for(cci = 0;cci < mtail;cci++){
				if(mcnt[cci][0] == cnta && mcnt[cci][1] == cntb){
					NEED_BREAK = 1;
					break;
				}
			}
			if(NEED_BREAK == 1){
				continue;
			}else{
				mcnt[mtail][0] = cnta,mcnt[mtail][1] = cntb;
				mtail++;
			}
			//cout<<cnta<<" "<<cntb<<endl;
			/*cout<<"atail:"<<atail<<",btail:"<<btail<<endl;
			for(cci = 0;cci < atail;cci++){
				cout<<a[cci]<<" ";
			}
			cout<<endl;
			for(cci = 0;cci < btail;cci++){
				cout<<b[cci]<<" ";
			}
			cout<<endl<<"-------"<<endl;*/
			for(i = 0;i < atail;i++){
				if(a[i] > h)continue;
				for(j = 1;j <= w;j++){
					if(cm[a[i]][j] == '#'){
						//cout<<"["<<a[i]<<"],["<<j<<"]"<<"被横向染色了"<<endl;
						cm[a[i]][j] = 'R';
						cbnum--;
					}
				}//r:两个R 
				BRE = 0;
				for(j = 0;j < btail;j++){
					if(b[j] > w)continue;
					for(ii = 1;ii <= h;ii++){
						if(cm[ii][b[j]] == '#'){
							cm[ii][b[j]] = 'R';
							//cout<<"["<<ii<<"],["<<b[j]<<"]"<<"被纵向向染色了"<<endl;
							cbnum--;
						}else if(cm[ii][b[j]] == 'R'){
							cm[ii][b[j]] = 'r';
						}
					}
					
					/*for(ii = 1;ii <= w;ii++){
						if(cm[ii][b[j]] == 'R'){
							cm[ii][b[j]] = '#';
							//cout<<"["<<ii<<"],["<<b[j]<<"]"<<"被纵向回溯了"<<endl;
							cbnum++;
						}else if(cm[ii][b[j]] == 'r'){
							cm[ii][b[j]] = 'R';
						}
					}*/
				}
				if(cbnum == k){
						ans++;
						//cout<<cnta<<" "<<cntb<<"成立"<<endl;
						BRE = 1;
					}
					if(BRE == 1){
						break;
					}
				/*for(j = 1;j <= w;j++){
					if(cm[a[i]][j] == 'R'){
						cm[a[i]][j] = '#';
					}else if(cm[a[i]][j] == 'r'){
						cout<<"ERROR!"<<endl;
						ans += 100000;
					}
				}*/
			}
			/*for(cci = 1;cci <= h;cci++){
				for(ccj = 1;ccj <= w;ccj++){
					cout<<cm[cci][ccj]<<" ";
				}
				cout<<endl;
			}
			cout<<endl<<endl<<endl;*/
		}
		
	}
	cout<<ans;
	//for(i = 0;i < mtail;i++){
		//cout<<mcnt[i][0]<<","<<mcnt[i][1]<<endl;
	//}
	return 0;//m[h][w]
}

