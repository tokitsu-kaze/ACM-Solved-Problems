#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
vector<int> pos[MAX];
int main()
{
	int T,n,i,j,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) pos[i].clear();
		for(i=n-1;i;i--)
		{
			if(b[i]==b[i+1]) pos[b[i]].push_back(i);
		}
		ok=1;
		i=j=1;
		while(i<=n && j<=n)
		{
			if(b[j]==-1)
			{
				j++;
				continue;
			}
			if(a[i]==b[j])
			{
				i++;
				j++;
				continue;
			}
			while(pos[a[i]].size()>0)
			{
				if(pos[a[i]].back()<=j) pos[a[i]].pop_back();
				else break;
			}
			if(pos[a[i]].size()>0)
			{
				b[pos[a[i]].back()]=-1;
				pos[a[i]].pop_back();
				i++;
			}
			else
			{
				ok=0;
				break;
			}
		}
		while(j<=n && b[j]==-1) j++;
		if(i<=n || j<=n) ok=0;
//		printf("%d %d\n",i,j);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
发现一次改变会把两个相同数字贴在一起，
所以每个区间最多操作一次。 
a变b好像不太好变，考虑将b变成a。
发现b的数字只能往右移动，
并且在移动时需要选择后面有两个相同数字。
维护一下相同数字的位置，然后模拟即可。 
*/
