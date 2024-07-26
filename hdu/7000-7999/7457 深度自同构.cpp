#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
const int mod=998244353;
int f[MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	n++;
	for(i=1;i<=n;i++) f[i]=0;
	f[1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			f[j+1]+=f[i];
			if(f[j+1]>=mod) f[j+1]-=mod;
		}
		if(i>1) printf("%d%c",f[i]," \n"[i==n+1]);
	}
	return 0;
}
// A003238
