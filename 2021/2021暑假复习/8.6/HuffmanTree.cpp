#include<bits/stdc++.h>
using namespace std; 

const int maxbit = 100;
const int maxvalue = 10000;
const int maxleaf = 10;
const int maxnode = 2*maxleaf - 1;

struct node{
	double weight;
	int parent,lchild,rchild;
	char value;
}node[maxnode];

struct codet{
	int bit[maxbit];
	int start;
}code[maxnode];

void HMT(int n){//huffmantree
	int x1,x2,m1,m2;
	for(int i = 0;i < 2*n - 1;i++){
		node[i].weight = 0,node[i].lchild = -1;
		node[i].parent = -1,node[i].rchild = -1;
	}
	for(int i = 0;i < n;i++){
		cin>>node[i].weight>>node[i].value;
	}
	for(int i = 0;i < n-1;i++){
		m1 = m2 = maxvalue,x1 = x2 = 0;
		for(int j = 0;j < n + i;j++){
			if(node[j].weight < m1&&node[j].parent == -1){
				m2 = m1,x2 = x1,m1 = node[j].weight,x1 = j;
			}else if(node[j].weight < m2&&node[j].parent == -1){
				m2 = node[j].weight,x2 = j;
			}
		}
		node[x1].parent = n + i;
		node[x2].parent = n + i;
		node[n+i].weight = m1 + m2;
		node[n+i].lchild = x1;
		node[n+i].rchild = x2;
	}
}

void HMC(int n){//huffmancode
	codet cd;
	int c,p;
	for(int i = 0;i < n;i++){
		cd.start = n-1;
		c = i;
		p = node[c].parent;
		while(p != -1){
			if(node[p].lchild == c){
				cd.bit[cd.start] = 0;
			}else{
				cd.bit[cd.start] = 1;
			}
			cd.start--;
			c = p;
			p = node[c].parent;
		}
		for(int j = cd.start+1;j < n;j++){
			code[i].bit[j] = cd.bit[j];
		}
		code[i].start = cd.start;
	}
}
int n;
int main(){
	freopen("HFMT.in","r",stdin);
	//freopen("HFMT.out","w",stdout);
	cin>>n;
	HMT(n);
	HMC(n);
	for(int i = 0;i < n;i++){
		cout<<node[i].value<<":Huffman code is:";
		for(int j = code[i].start+1;j < n;j++){
			cout<<code[i].bit[j];
		}
		cout<<endl;
	}
	return 0;
}

