#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int n,p[2],s;
char a[1010];
void query(int l,int r)
{
	if(l>r) return;
	int i,ans,mid=(l+r)/2;
	mem(a,'0');
	a[n+1]='\0';
	for(i=l;i<=mid;i++)
	{
		a[i]='1';
	}
	a[n+1]='\0';
	printf("? %s\n",a+1);
	fflush(stdout);
	scanf("%d",&ans);
	if(s+(mid-l+1)==ans)
	{
		p[0]=l;
		query(mid+1,r);
	}
	else if(s-(mid-l+1)==ans)
	{
		p[1]=l;
		query(mid+1,r);
	}
	else query(l,mid);
}
int main()
{
	while(~scanf("%d",&n))
	{
		mem(a,'0');
		a[n+1]='\0';
		printf("? %s\n",a+1);
		fflush(stdout);
		scanf("%d",&s);
		query(1,n);
		printf("! %d %d\n",p[0],p[1]);
		fflush(stdout);
	}
	return 0;
}