#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
ll gao(vector<int> &pos)
{
	if(pos.size()==0) return INF;
	int i,mid,now;
	ll res=0;
	mid=pos[pos.size()/2];
	now=mid;
	for(i=pos.size()/2;~i;i--)
	{
		res+=abs(now-pos[i]);
		now--;
	}
	now=mid;
	for(i=pos.size()/2;i<pos.size();i++)
	{
		res+=abs(now-pos[i]);
		now++;
	}
	return res;
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		vector<int> pos[2];
		for(i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
		printf("%lld\n",min(gao(pos[0]),gao(pos[1])));
	}
	return 0;
}
