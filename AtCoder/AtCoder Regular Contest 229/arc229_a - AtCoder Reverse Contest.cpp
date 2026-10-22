#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int cas,x,a,b,i,mx,mn;
	string tmp,res;
	scanf("%d",&x);
//	for(cas=1;cas<=600;cas++)
	{
//		x=cas;
		tmp="";
		for(i=1;i<=25;i++) tmp+="AR";
		while(x>=25)
		{
			x-=25;
			tmp+="CR";
		}
		res="";
		for(i=0;i<2*x;i++) res+=tmp[i];
		res+="CR";
		for(i=2*x;i<tmp.size();i++) res+=tmp[i];
//		printf("%d\n",cas);
		assert(res.size()<=100);
		if(res.size()==0) res+="D";
		cout<<res<<"\n";
	}
	return 0;
}
/*
CÍùÇ°ÒÆ¶¯¡£
ARARARCRC
2*3

*/
