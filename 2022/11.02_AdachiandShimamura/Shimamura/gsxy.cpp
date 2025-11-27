#include<bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
int n,m,a[5][5];
void show(){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return ;
}
int main(){
	freopen("buyy.in","r",stdin);
	//freopen("buyy.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i-1][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		int ccc;
		cin>>ccc;
	}
	vector<vector<double> > a(n, vector<double>(n));
	double det = 1;
	for(int i = 0;i < n;++i){
		show();
		int k = i;
		for(int j = i + 1;j < n;++j){
			if(abs(a[j][i])>abs(a[k][i]))k = j;
		}
		if (abs(a[k][i]) < EPS){
			det = 0;
			continue;
		}
		swap(a[i], a[k]);
		if (i != k){
			det = -det;
		}
		det *= a[i][i];
		for(int j = i + 1;j < n;++j)a[i][j] /= a[i][i];
		for(int j = 0;j < n;++j)
			if(j != i && abs(a[j][i]) > EPS)
				for(int k = i + 1;k < n;++k)a[j][k] -= a[i][k] * a[j][i]; 
	}
	show();
	return 0;
}
