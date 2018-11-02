#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
typedef long long ll;
int main()
{
	int p[]={2,3,5,7,11,13,17,19},mp[22];
	mem(mp,0);
	for(int i=1;i<=20;i++)
	{
		int tmp=i;
		for(int j=0;j<8;j++)
		{
			if(tmp==1) break;
			int cnt=0;
			while(tmp%p[j]==0)
			{
				cnt++;
				tmp/=p[j];
			}
			mp[p[j]]=max(mp[p[j]],cnt);
		}
	}
	int ans=1;
	for(int i=0;i<8;i++)
	{
		while(mp[p[i]])
		{
			mp[p[i]]--;
			ans*=p[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*

232792560

*/