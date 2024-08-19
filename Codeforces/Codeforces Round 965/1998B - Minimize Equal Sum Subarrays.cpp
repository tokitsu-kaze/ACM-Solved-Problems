#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i]+1;
			if(b[i]==n+1) b[i]=1;
		}
		for(i=1;i<=n;i++) printf("%d%c",b[i]," \n"[i==n]);
	}
	return 0;
}

