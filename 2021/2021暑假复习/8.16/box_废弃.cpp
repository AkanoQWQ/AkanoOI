#include<bits/stdc++.h>
using namespace std;
int i,j,tail,lenm,lenn,cache,c2,ci,clenn,CAN_JIAN,a,b,c,JIE,JI,jietail,BRE;
string n,m,cm;
int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	cin>>n>>m;
	lenm = m.length();//100000000000000
	lenn = n.length();//2
					  //10 2
	while(tail-lenn <= lenm){
		JI++;
		CAN_JIAN = 1,JIE = 0;
		cm = m;
		for(i = lenn - 1;i >= 0;i--){
			if(int(cm[tail+i]) < int(n[i])){
				if(tail + i > 0){
					BRE = 0;
					cout<<tail<<":"<<i<<endl; 
					jietail = tail + i - 1;
					while(jietail >= 0){
						if(int(cm[jietail]) > 48){
							cout<<tail<<":"<<cm[jietail]<<"->";
							cm[jietail]--;
							cout<<cm[jietail]<<endl;
							BRE = 1;
							cout<<tail<<":"<<i<<"BRE变为"<<BRE<<endl;
							break;
						}else{
							cm[jietail] = '9';
						}
						jietail--;
					}
					if(BRE == 0){
						cout<<i<<"t"<<endl; 
						CAN_JIAN = 0;
					}
				}else{
					cout<<tail<<":"<<i<<"test"<<endl; 
					CAN_JIAN = 0;
				}
			}
		}
		if(CAN_JIAN == 0){
			cout<<tail<<"无法减"<<endl;
			tail++;
		}else{
			m = cm;
			/*for(i = 0;i < lenn;i++){
				a = int(m[tail+i]);
				b = int(n[i]);
				c = a-b+48;
				m[tail + i] = char(c);
			}*/
		}
		//cout<<tail<<":"<<m<<endl; 
		if(JI >= 100)break;
	}
	cout<<m;
	return 0;
}
//234324  123
