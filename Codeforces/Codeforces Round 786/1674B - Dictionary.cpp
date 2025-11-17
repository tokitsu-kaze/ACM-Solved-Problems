#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i,j,tot,T;
	char s[5];
	tot=0;
	map<string,int> mp;
	for(i='a';i<='z';i++)
	{
		for(j='a';j<='z';j++)
		{
			if(i==j) continue;
			string tmp="";
			tmp+=i;
			tmp+=j;
			mp[tmp]=++tot;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		printf("%d\n",mp[s]);
	}
	return 0;
}
