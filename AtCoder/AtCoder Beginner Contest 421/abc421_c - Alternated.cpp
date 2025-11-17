#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX];
vector<int> pos[2];
ll cal(int n,int f)
{
	int i,p[2],tmp;
	ll res=0;
	p[0]=p[1]=0;
	for(i=1;i<=n;i++)
	{
		tmp=pos[f][p[f]++];
		if(tmp>i) res+=tmp-i;
		f^=1;
	}
	return res;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	n*=2;
	scanf("%s",s+1);
	pos[0].clear();
	pos[1].clear();
	for(i=1;i<=n;i++) pos[s[i]-'A'].push_back(i);
	printf("%lld\n",min(cal(n,0),cal(n,1)));
	return 0;
}
