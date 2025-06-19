#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int f[12];
int ck(int n,int x,int y,int h)
{
	if(f[n]>min(x,y) || f[n]+f[n-1]>h) return 0;
	return 1;
}
int main()
{
	int T,n,m,i,x,y,z;
	f[1]=1;
	f[2]=2;
	for(i=3;i<=10;i++)
	{
		f[i]=f[i-1]+f[i-2];
//		cout<<i<<" "<<f[i]<<endl;
	}
	scanf("%d",&T);
	while(T--)
	{
		string res;
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(ck(n,x,y,z)) res+="1";
			else if(ck(n,x,z,y)) res+="1";
			else if(ck(n,y,x,z)) res+="1";
			else if(ck(n,y,z,x)) res+="1";
			else if(ck(n,z,x,y)) res+="1";
			else if(ck(n,z,y,x)) res+="1";
			else res+="0";
		}
		cout<<res<<"\n";
	}
	return 0;
}
