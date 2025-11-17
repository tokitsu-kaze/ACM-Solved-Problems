#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
mt19937 rd(time(0));
int main()
{
	int T,n,i,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=0;i<200*n;i++)
		{
			x=rd()%n+1;
			y=rd()%n+1;
			if(x==y) continue;
			if(x>y) swap(x,y);
			if((a[y]%a[x])%2==0)
			{
				printf("%d %d\n",a[x],a[y]);
				goto end;
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}
