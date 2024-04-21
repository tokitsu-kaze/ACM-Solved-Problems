#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int main()
{
	int t,n,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> pos[2];
		for(i=1;i<=2*n;i++)
		{
			scanf("%d",&x);
			pos[x&1].push_back(i);
		}
		if(pos[0].size()&1) pos[0].pop_back();
		if(pos[1].size()&1) pos[1].pop_back();
		if(pos[0].size()+pos[1].size()==2*n)
		{
			if(pos[0].size()>=2)
			{
				pos[0].pop_back();
				pos[0].pop_back();
			}
			else
			{
				pos[1].pop_back();
				pos[1].pop_back();
			}
		}
		for(i=0;i<pos[0].size();i+=2) printf("%d %d\n",pos[0][i],pos[0][i+1]);
		for(i=0;i<pos[1].size();i+=2) printf("%d %d\n",pos[1][i],pos[1][i+1]);
	}
	return 0;
}
