#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
const int mod=1e9+7;
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> res;
		set<int> s;
		res.push_back(1);
		s.insert(0);
		for(i=2;i<=n;i++)
		{
			for(j=res.back()+1;j<=100;j++)
			{
				if(!s.count(j%i))
				{
					s.insert(j%i);
					res.push_back(j);
					break;
				}
			}
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i], " \n"[i+1==res.size()]);
	}
	return 0;
}
