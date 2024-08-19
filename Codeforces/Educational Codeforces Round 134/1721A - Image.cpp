#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j;
	char mp[2][2];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<2;i++) scanf("%s",mp[i]);
		set<char> s;
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				s.insert(mp[i][j]);
			}
		}
		printf("%d\n",s.size()-1);
	}
	return 0;
}
