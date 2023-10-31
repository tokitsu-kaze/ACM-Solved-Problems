#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,a,p,l,r,rol,ror,trl,trr,ro,tr;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			ro=tr=1;
			rol=trl=0;
			ror=trr=INF;
			while(n--)
			{
				scanf("%d%d%%",&a,&p);
				if(ro)
				{
					if(!p) r=INF;
					else r=int(a*100/(p-0.5));
					if(p==100) l=a;
					else l=int(a*100/(p+0.5))+1;
					rol=max(rol,l);
					ror=min(ror,r);
					if(ror<rol) ro=0;
				}
				if(tr)
				{
					if(!p) r=INF;
					else r=int(a*100/p);
					if(p==100) l=a;
					else l=int(a*100/(p+1))+1;
					trl=max(trl,l);
					trr=min(trr,r);
					if(trr<trl) tr=0;
				}
			}
			if(tr+ro==2) puts("Either");
			else if(tr) puts("Truncation");
			else if(ro) puts("Rounding");
			else puts("Neither");
		}
	}
    return 0;
}