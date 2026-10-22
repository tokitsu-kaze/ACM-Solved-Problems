#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int prer[MAX],sufl[MAX],l[MAX],r[MAX];
int main()
{
	int n,q,i,s,t;
	scanf("%d%d",&n,&q);
	l[1]=INF;
	for(i=2;i<=n;i++) scanf("%d",&l[i]);
	r[n]=INF;
	for(i=1;i<n;i++) scanf("%d",&r[i]);
	prer[0]=INF;
	for(i=1;i<=n;i++) prer[i]=min(prer[i-1],r[i]);
	sufl[n+1]=INF;
	for(i=n;i;i--) sufl[i]=min(sufl[i+1],l[i]);
	while(q--)
	{
		scanf("%d%d",&s,&t);
		if(s<t) printf("%d\n",min(r[s],l[s]+prer[s]));
		else if(s>t) printf("%d\n",min(l[s],r[s]+sufl[s]));
	}
	return 0;
}
