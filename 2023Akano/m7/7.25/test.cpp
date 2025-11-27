#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
double rd1(){
	double ret = (rng() % 1001) + 500;
	return ret / 1000;
}
int rd(){
	return (rng() % 10000) + 10;
}
bool Judge(double A,double B,double _x1,double _y1,double _x2,double _y2){
	bool XBY = (A - _x1) / (B - _y1) > (A - _x2) / (B - _y2);
	return XBY;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	for(int t = 1;t <= 100;t++){
		double _x1 = rd() * rd1(),_x2 = rd() * rd1(),_y1 = rd() * rd1(),_y2 = rd() * rd1();
//		cout<<"JUDGE "<<_x1<<","<<_y1<<" and "<<_x2<<","<<_y2<<endl;
		bool FIR = Judge(1,1,_x1,_y1,_x2,_y2);
		bool brk = false;
		for(int A = 1;A <= 100;A++){
			for(int B = 1;B <= 100;B++){
				if(Judge(A,B,_x1,_y1,_x2,_y2) != FIR){
					cout<<"WA in "<<A<<","<<B<<endl;
					cout<<"WITH "<<_x1<<","<<_y1<<" and "<<_x2<<","<<_y2<<endl;
					brk = true;
					break;
				}
			}
			if(brk)break;
		}
	}
	cout<<Judge(1,1,4770,4559.67,9496.84,92.56)<<endl;
	cout<<Judge(1,93,4770,4559.67,9496.84,92.56)<<endl;
	return 0;
}
