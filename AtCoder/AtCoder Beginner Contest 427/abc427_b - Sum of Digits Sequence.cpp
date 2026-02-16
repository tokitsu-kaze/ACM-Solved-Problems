#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
int a[105];
int f(int x)
{
	string s=to_string(x);
	int res=0;
	for(auto &it:s) res+=it-'0';
	return res;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		a[i]=0;
		for(j=0;j<i;j++)
		{
			a[i]+=f(a[j]);
		}
	}
	printf("%d\n",a[n]);
	return 0;
}
