#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],b[MAX],tmp[MAX];
int main()
{
	int T,n,m,i,j,pos,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		pos=1;
		for(i=2;i<=m;i++)
		{
			if(b[i]<b[pos]) pos=i;
		}
		tot=0;
		for(i=pos;i<=m;i++) tmp[++tot]=b[i];
		for(i=1;i<pos;i++) tmp[++tot]=b[i];
		for(i=1;i<=m;i++) b[i]=tmp[i];
		for(i=1;i+m-1<=n;i++)
		{
			if(a[i]<=b[1]) continue;
			for(j=1;j<=m;j++)
			{
				a[i+j-1]=b[j];
				if(i+j-1+m-1<=n && a[i+j-1]>b[1]) break;
			}
		}
		for(i=n-m+1,j=1;i<=n;i++,j++)
		{
			if(a[i]<b[j]) break;
			if(a[i]>b[j])
			{
				for(i=n-m+1,j=1;i<=n;i++,j++) a[i]=b[j];
				break;
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",a[i], " \n"[i==n]);
	}
	return 0;
}
