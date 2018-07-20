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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,k,i,a[111],mid,s,temp;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
		}
		mid=n;
		s=2*n;
		for(i=1;i<=k;i++)
		{
			if(a[i]>=4)
			{
				mid-=a[i]/4;
				a[i]-=4*(a[i]/4);
				if(mid<0)
				{
					a[i]-=mid*4;
					mid=0;
				}
			}
			if(mid==0) break;
			if(a[i]==3)
			{
				mid--;
				a[i]=0;
			}
			if(mid==0) break;
		}
		temp=0;
		for(i=1;i<=k;i++)
		{
			if(a[i]==0) continue;
			if(a[i]==1)
			{
				if(temp)
				{
					temp--;
					a[i]=0;
				}
				continue;
			}
			if(mid)
			{
				mid--;
				if(a[i]==2) temp++;
				a[i]=0;
			}
			else
			{
				if(a[i]==1&&temp)
				{
					temp--;
					a[i]=0;
				}
				else
				{
					if(s>=a[i]/2)
					{
						s-=a[i]/2;
						a[i]-=a[i]/2*2;
						if(s>=a[i])
						{
							s-=a[i];
							a[i]=0;
						}
					}
					else
					{
						a[i]-=s*2;
						s=0;
					}
				}
			}
			if(s==0) break;
		}
		for(i=1;i<=k;i++)
		{
			if(a[i]==0) continue;
			if(mid)
			{
				mid--;
				if(a[i]<=2) temp++;
				a[i]=0;
			}
			else
			{
				if(temp)
				{
					if(temp>=a[i]) temp-=a[i];
					else
					{
						a[i]-=temp;
						if(a[i]%2) s--;
						s-=a[i]/2;
					}
					
				}
				else
				{
					if(a[i]%2) s--;
					s-=a[i]/2;
				}
			}
		}
//		cout<<s<<" "<<temp<<endl;
		if(s<0) puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
2 2
5 8
1 2
7 1
1 2
4 4
1 4
2 2 1 2
*/