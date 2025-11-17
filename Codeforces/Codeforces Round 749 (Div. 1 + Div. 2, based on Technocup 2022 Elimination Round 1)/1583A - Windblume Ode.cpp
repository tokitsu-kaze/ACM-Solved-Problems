#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
int ck(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0) return 1;
	}
	return 0;
}
int main()
{
	int T,n,i,a[105],sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(ck(sum))
		{
			printf("%d\n",n);
			for(i=1;i<=n;i++) printf("%d%c",i," \n"[i==n]);
			continue;
		}
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(sum%2==0) res.push_back(i);
			else
			{
				if(a[i]&1) sum-=a[i];
				else res.push_back(i);
			}
		}
		printf("%d\n",res.size());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
