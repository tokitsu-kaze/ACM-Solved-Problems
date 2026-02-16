#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],n;
int ck(int x)
{
	int i;
	map<int,int> mp;
	for(i=1;i<=n;i++)
	{
		if(a[i]==x) continue;
		if(mp.count(x-a[i]))
		{
			mp[x-a[i]]--;
			if(mp[x-a[i]]==0) mp.erase(x-a[i]);
		}
		else mp[a[i]]++;
	}
	return mp.size()==0;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	vector<int> res;
	if(ck(a[n])) res.push_back(a[n]);
	if(ck(a[1]+a[n])) res.push_back(a[1]+a[n]);
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	return 0;
}
