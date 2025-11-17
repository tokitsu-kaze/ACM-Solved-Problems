#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans,pre,mid,suf,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if(ans==0) puts("YES");
		else
		{
			pre=0;
			ok=0;
			for(i=1;i<=n;i++)
			{
				pre^=a[i];
				suf=ans^pre;
				mid=0;
				for(j=i+1;j<n;j++)
				{
					mid^=a[j];
					suf^=a[j];
					if(pre==mid && mid==suf) ok=1;
				}
			}
			if(ok) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
/*
1
4
5 1 4 5
*/
