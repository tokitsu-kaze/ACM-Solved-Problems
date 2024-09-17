#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int main()
{
	int n,i,t,mx,res;
	char s[12];
	scanf("%d",&n);
	map<string,int> id;
	mx=-1;
	res=1;
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",s,&t);
		if(id.count(s)) continue;
		id[s]=i;
		if(t>mx)
		{
			mx=t;
			res=i;
		}
	}
	printf("%d\n",res);
	return 0;
}
