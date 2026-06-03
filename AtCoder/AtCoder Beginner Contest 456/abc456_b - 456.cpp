#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int a[4][7],i,j,k,ans;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=6;j++) scanf("%d",&a[i][j]);
	}
	ans=0;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			for(k=1;k<=6;k++)
			{
				set<int> s;
				s.insert(a[1][i]);
				s.insert(a[2][j]);
				s.insert(a[3][k]);
				if(s.count(4) && s.count(5) && s.count(6)) ans++;
			}
		}
	}
	printf("%.10f\n",ans/6.0/6.0/6.0);
	return 0;
}
