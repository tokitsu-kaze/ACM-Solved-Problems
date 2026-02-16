#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int tmp[]={14,92,200,326,476,644,830,1028,1244,1466,1706,1958,11999};
string dir[]={"NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"};
int main(){
	int a,b,w;
	scanf("%d%d",&a,&b);
	a*=10;
	if(a<1126) a+=36000;
	a-=1126;
	w=0;
	while(b>tmp[w]) w++;
	if(w==0) cout<<"C";
	else cout<<dir[a/2250];
	cout<<" "<<w<<"\n";
	return 0;
}
