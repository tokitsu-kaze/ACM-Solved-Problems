#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> x(n),y(n);
		for(auto &it:x) scanf("%d",&it);
		for(auto &it:y) scanf("%d",&it);
		for(i=0;i<n;i++)
		{
			vector<pair<int,int>> tmp;
			for(j=0;j<n;j++)
			{
				tmp.push_back({abs(x[j]-x[i]),x[j]});
			}
			sort(tmp.begin(),tmp.end());
			vector<int> now(n);
			for(j=0;j<n;j++) now[j]=tmp[j].second;
			if(now==y)
			{
				printf("%d\n",i+1);
				goto end;
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}
