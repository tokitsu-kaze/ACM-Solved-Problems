#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
struct student
{
	int id;
	int time;
}a[20010];
int cmp(student a,student b)
{
	return a.time<b.time;
}
int main()
{ 
	int s,b,c,t,n,l,i,ans[20010],k,flag;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>l;
			mem(ans,0);
			for(i=0;i<n;i++)
			{
				scanf("%d:%d:%d",&s,&b,&c);
				a[i].time=s*3600+b*60+c;
				a[i].id=i+1;
			}
			sort(a,a+n,cmp);
			k=flag=0;
			ans[k++]=a[0].id;
			for(i=1;i<n;i++)
			{
				if(a[i].time>=a[flag].time+l)
				{
					flag=i;
					ans[k++]=a[i].id;
				}
			}
			sort(ans,ans+k);
			cout<<k<<endl;
			for(i=0;i<k;i++)
			{
				cout<<ans[i];
				if(i!=k-1) cout<<" ";
				else puts("");
			}
		}
	}
    return 0;
}