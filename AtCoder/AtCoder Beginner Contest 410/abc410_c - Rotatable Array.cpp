#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX];
int main()
{
	int n,i,q,op,p,x,k,now;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++) a[i]=i+1;
	now=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&p,&x);
			p--;
			a[(now+p)%n]=x;
		}
		else if(op==2)
		{
			scanf("%d",&p);
			p--;
			printf("%d\n",a[(now+p)%n]);
		}
		else
		{
			scanf("%d",&k);
			now=(now+k)%n;
		}
	}
	return 0;
}
