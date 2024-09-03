#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e3+10;
int a[MAX],id[MAX];
int main()
{
	int n,i;
	ll now,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,[](int x,int y){
		return a[x]<a[y];
	});
	ans=now=0;
	for(i=1;i<=n;i++)
	{
		ans+=now;
		now+=a[id[i]];
	}
	for(i=1;i<=n;i++) printf("%d%c",id[i]," \n"[i==n]);
	printf("%.2f\n",ans*1.0/n);
	return 0;
}

