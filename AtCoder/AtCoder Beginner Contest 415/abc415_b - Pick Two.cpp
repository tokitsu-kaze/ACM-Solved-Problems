#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int n,i;
	char s[1010];
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='#') res.push_back(i);
	}
	for(i=1;i<res.size();i+=2) printf("%d,%d\n",res[i-1],res[i]);
	return 0;
}
