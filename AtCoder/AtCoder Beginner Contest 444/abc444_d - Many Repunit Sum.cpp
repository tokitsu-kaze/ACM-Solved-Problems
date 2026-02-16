#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],sum[MAX];
int main()
{
	int n,i,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(sum,0,sizeof sum);
	for(i=1;i<=n;i++) sum[a[i]]++;
	for(i=MAX-10;i;i--) sum[i]+=sum[i+1];
	now=0;
	string res="";
	for(i=1;i<=MAX-10;i++)
	{
		now+=sum[i];
		res+='0'+(now%10);
		now/=10;
	}
	while(now)
	{
		res+='0'+(now%10);
		now/=10;
	}
	while(res.size()>0 && res.back()=='0') res.pop_back();
	reverse(res.begin(),res.end());
	cout<<res<<"\n";
	return 0;
}
