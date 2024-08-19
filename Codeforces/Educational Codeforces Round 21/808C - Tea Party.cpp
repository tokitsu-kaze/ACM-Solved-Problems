#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct node{int a,id;}a[105];
int res[105];
int main()
{
	int n,w,i,tmp;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].a);
		a[i].id=i;
	}
	sort(a+1,a+1+n,[](node x,node y){
		return x.a<y.a;
	});
	for(i=1;i<=n;i++)
	{
		res[a[i].id]=(a[i].a+1)/2;
		w-=res[a[i].id];
	}
	if(w<0) return 0*puts("-1");
	for(i=n;i;i--)
	{
		tmp=min(w,a[i].a-res[a[i].id]);
		res[a[i].id]+=tmp;
		w-=tmp;
	}
	if(w>0) return 0*puts("-1");
	for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
