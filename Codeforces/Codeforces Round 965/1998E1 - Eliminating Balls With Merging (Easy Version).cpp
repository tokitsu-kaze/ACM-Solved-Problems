#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX],l[MAX],r[MAX],st[MAX],top,id[MAX];
ll bit[MAX];
int f[MAX];
int main()
{
	int t,i,n,x,ans;
	ll now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			f[i]=0;
			id[i]=i;
			bit[i]=bit[i-1]+a[i];
		}
		f[0]=f[n+1]=0;
		top=0;
		for(i=1;i<=n;i++)
		{
			while(top&&a[st[top-1]]<a[i])
			{
				r[st[top-1]]=i;
				top--;
			}
			st[top++]=i;
		}
		while(top)
		{
			r[st[top-1]]=n+1;
			top--;
		}
		for(i=n;i;i--)
		{
			while(top&&a[st[top-1]]<a[i])
			{
				l[st[top-1]]=i;
				top--;
			}
			st[top++]=i;
		}
		while(top)
		{
			l[st[top-1]]=0;
			top--;
		}
	//	for(i=1;i<=n;i++) printf("%d [%d,%d]\n",i,l[i],r[i]);
		sort(id+1,id+1+n,[&](int x,int y){
			return a[x]>a[y];
		});
		for(i=1;i<=n;i++)
		{
			now=bit[r[id[i]]-1]-bit[l[id[i]]];
			if(now>=a[r[id[i]]]) f[id[i]]|=f[r[id[i]]];
			if(now>=a[l[id[i]]]) f[id[i]]|=f[l[id[i]]];
			if(l[id[i]]==0&&r[id[i]]==n+1) f[id[i]]=1;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=f[i];
	//		printf("%d f:%d\n",i,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

