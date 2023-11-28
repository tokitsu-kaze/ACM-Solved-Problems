#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int n,k;
int ck(int x)
{
	int i,cnt=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='0')
		{
			i+=x-1;
			cnt++;
		}
	}
	return cnt<=k;
}
int main()
{
	int t,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
