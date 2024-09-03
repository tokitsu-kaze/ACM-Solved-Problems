#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int a[MAX],bit[MAX];
int main()
{
	int n,q,i,x,y;
	scanf("%d%d",&n,&q);
	bit[0]=bit[1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>1 && a[i]<a[i-1]) bit[i]=1;
		else bit[i]=0;
		bit[i]+=bit[i-1];
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		printf("%d\n",bit[y]-bit[x]);
	}
	return 0;
}
