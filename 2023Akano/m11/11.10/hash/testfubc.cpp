#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
inline double Tanh(double x){
	constexpr static double eval = 2.7182818284590452353602874713526624977572;
	cerr<<(pow(eval,x)-pow(eval,-x))<<" / "<<(pow(eval,x)+pow(eval,-x))<<endl;
	return (pow(eval,x)-pow(eval,-x))/(pow(eval,x)+pow(eval,-x));
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(double x = -100;x <= 100;x += 0.1){
		cerr<<x<<" Tanh "<<Tanh(x)<<endl;
	}
	return not(Akano loves pure__Elysia);
}
