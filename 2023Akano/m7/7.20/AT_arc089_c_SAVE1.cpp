//#include<bits/stdc++.h>
//using namespace std;
//const int MAXAB = 14;
//int A,B,d[MAXAB][MAXAB];
//inline bool Judge(int a,int b,int c){
//	for(int x = 1;x <= A;x++){
//		for(int y = 1;y <= B;y++){
//			if(a * x + b * y + c != d[x][y])return false;
//		}
//	}
//	return true;
//}
//inline void Solve(int a,int b,int c){
//	int nnt = 0;
//	int VST = ++nnt,VED = ++nnt;
//	int V2 = VST;
//	if(c != 0){
//		V2 = ++nnt;
//		cout<<VST<<" "<<V2<<" "<<c<<endl;
//	}
//	int lst_a = V2;
//	for(int i = 1;i < a;i++){
//		cout<<lst_a<<" "<<++nnt<<" X"<<endl;
//		lst_a = nnt;
//	}
//	cout<<lst_a<<" "<<VED<<" X"<<endl;
//	int lst_b = V2;
//	for(int i = 1;i < b;i++){
//		cout<<lst_b<<" "<<++nnt<<" Y"<<endl;
//		lst_b = nnt;
//	}
//	cout<<lst_b<<" "<<VED<<" Y"<<endl;
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cin>>A>>B;
//	for(int i = 1;i <= A;i++){
//		for(int j = 1;j <= B;j++){
//			cin>>d[i][j];
//		}
//	}
//	for(int c = 0;c <= 100;c++){
//		bool GIVE_ONE = c;
//		for(int a = 0;a <= 300;a++){
//			for(int b = 0;a + b + GIVE_ONE <= 300;b++){
//				if(Judge(a,b,c)){
//					Solve(a,b,c);
//					return 0;
//				}
//			}
//		}
//	}
//	return 0;
//}
