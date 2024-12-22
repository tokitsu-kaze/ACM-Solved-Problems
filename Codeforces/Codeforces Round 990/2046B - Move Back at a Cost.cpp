#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int a[MAX],sufmn[MAX];
int main()
{
	int T,n,i,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sufmn[n+1]=INF;
		for(i=n;i;i--) sufmn[i]=min(sufmn[i+1],a[i]);
		vector<int> res,tmp;
		mn=INF;
		for(i=1;i<=n;i++)
		{
			if(a[i]==sufmn[i])
			{
				if(a[i]>mn) tmp.push_back(a[i]+1);
				else res.push_back(a[i]);
			}
			else
			{
				tmp.push_back(a[i]+1);
				mn=min(mn,a[i]+1);
			}
		}
		sort(tmp.begin(),tmp.end());
		for(auto &it:tmp) res.push_back(it);
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
	}
	return 0;
}
/*
1
5
5 4 3 2 1
*/

