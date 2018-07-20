
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
const int MAX=1e5+10;
const ll mod=1e9+7;
char a[MAX];
int x[MAX],y[MAX],z[MAX];
int main()
{
	int q,l,r,i,len,xx,yy,zz,ans;
	while(~scanf("%s",a+1))
	{
		mem(x,0);
		mem(y,0);
		mem(z,0);
		len=strlen(a+1);
		for(i=1;i<=len;i++)
		{
			if(a[i]=='x') x[i]++;
			else if(a[i]=='y') y[i]++;
			else if(a[i]=='z') z[i]++;
			x[i]+=x[i-1];
			y[i]+=y[i-1];
			z[i]+=z[i-1];
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(r-l+1<3)
			{
				puts("YES");
				continue;
			}
			xx=x[r]-x[l-1];
			yy=y[r]-y[l-1];
			zz=z[r]-z[l-1];
			int temp=(r-l+1)/3;
			if(xx<temp||yy<temp||zz<temp)
			{
				puts("NO");
				continue;
			}
			xx-=temp;
			yy-=temp;
			zz-=temp;
			if(xx>1||yy>1||zz>1)
			{
				puts("NO");
				continue;
			}
			if(xx+yy+zz==(r-l+1)-temp*3) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
// zyxzyxz