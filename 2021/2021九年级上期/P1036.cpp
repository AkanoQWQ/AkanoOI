#include<bits/stdc++.h>
using namespace std;
char ch;
int i,j,lens,wina,winb,losea,loseb,a[20061][2],b[20061][2],wn,taila,tailb;
bool BRE;
int main(){
	//freopen("P1036.in","r",stdin);
	//freopen("P1036.out","w",stdout);
	while(cin>>ch){
		if(ch == 'E'){
			if(wina != 0 || losea != 0){
				a[taila][0] = wina;
				a[taila][1] = losea;
				wina = 0,losea = 0;
			}
			taila++;
			if(winb != 0 || loseb != 0){
				b[tailb][0] = winb;
				b[tailb][1] = loseb;
				winb = 0,loseb = 0;
			}
			tailb++;
			break;
		}
		if(ch == 'W'){
			wina++,winb++,wn++;
		}
		if(ch == 'L'){
			losea++,loseb++;
		}
		if((wina >= 11 || losea >= 11) && abs(wina - losea) >= 2){
			a[taila][0] = wina;
			a[taila][1] = losea;
			wina = 0,losea = 0;
			taila++;
		}
		if((winb >= 21 || loseb >= 21) && abs(winb - loseb) >= 2){
			b[tailb][0] = winb;
			b[tailb][1] = loseb;
			winb = 0,loseb = 0;
			tailb++;
		}
	}
	for(i = 0;i < taila;i++){
		cout<<a[i][0]<<":"<<a[i][1]<<endl;
	}
	if(taila == 0)cout<<"0:0"<<endl;
	cout<<endl;
	for(i = 0;i < tailb;i++){
		cout<<b[i][0]<<":"<<b[i][1]<<endl;
	}
	if(tailb == 0)cout<<"0:0"<<endl;
	return 0;
}

