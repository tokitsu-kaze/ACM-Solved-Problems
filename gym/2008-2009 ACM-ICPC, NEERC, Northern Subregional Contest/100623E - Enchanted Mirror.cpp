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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	char a,b;
	friend bool operator <(node a,node b)
	{
		if(a.a==b.a) return a.b>b.b;
		return a.a>b.a;
	}
}p[111],q[111];
int main()
{
	freopen("enchanted.in","r",stdin);
	freopen("enchanted.out","w",stdout);
	char a[111],b[111],c[111],d[111];
	int i;
	while(~scanf("%s%s%s%s",a,b,c,d))
	{
		reverse(b,b+strlen(b));
		reverse(d,d+strlen(d));
		for(i=0;i<strlen(a);i++)
		{
			p[i].a=a[i];
			p[i].b=b[i];
			q[i].a=c[i];
			q[i].b=d[i];
		}
		sort(p,p+strlen(a));
		sort(q,q+strlen(a));
		int flag=0;
		for(i=0;i<strlen(a);i++)
		{
			if(!(p[i].a==q[i].a&&p[i].b==q[i].b))
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}