#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int MYnumval[11][9];
//0 : ABCDEF
MYnumval[0][0] = MYnumval[0][1] = MYnumval[0][2] = MYnumval[0][3] = MYnumval[0][4] = MYnumval[0][5] = 1;
//1 : BC
MYnumval[1][1] = MYnumval[1][2] = 1;
//2 : ABDEG
MYnumval[2][0] = MYnumval[2][1] = MYnumval[2][3] = MYnumval[2][4] = MYnumval[2][6] = 1;
//3 : ABCDG
MYnumval[3][0] = MYnumval[3][1] = MYnumval[3][2] = MYnumval[3][3] = MYnumval[3][6] = 1;
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return not(Akano loves pure__Elysia);
}
