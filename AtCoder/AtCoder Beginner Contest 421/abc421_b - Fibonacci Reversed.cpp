#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int x,y,i;
	ll f[12];
	scanf("%d%d",&x,&y);
	f[1]=x;
	f[2]=y;
	for(i=3;i<=10;i++)
	{
		string tmp=to_string(f[i-1]+f[i-2]);
		reverse(tmp.begin(),tmp.end());
		f[i]=stoll(tmp);
	}
	printf("%lld\n",f[10]);
	return 0;
}
