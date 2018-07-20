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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=10000;
int a[31][1511];
int main()
{
	int i,j,cnt[31],n,q,k,ans,temp;
	char s[1511],c;
	while(~scanf("%d %s",&n,s))
	{
		mem(cnt,0);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			a[s[i]-'a'][cnt[s[i]-'a']++]=i;
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %c",&k,&c);
			if(cnt[c-'a']==0)
			{
				printf("%d\n",k);
			}
			else if(cnt[c-'a']==1)
			{
				printf("%d\n",min(k+1,n));
			}
			else
			{
				temp=0;
				ans=k;
				for(j=0,i=1;i<cnt[c-'a'];i++)
				{
					if(a[c-'a'][i]-a[c-'a'][i-1]-1<=k)
					{
						temp+=(a[c-'a'][i]-a[c-'a'][i-1]);
						k-=(a[c-'a'][i]-a[c-'a'][i-1]-1);
					}
					else
					{
						while(a[c-'a'][i]-a[c-'a'][i-1]-1>k&&j<i)
						{
							j++;
							temp-=(a[c-'a'][j]-a[c-'a'][j-1]);
							k+=(a[c-'a'][j]-a[c-'a'][j-1]-1);
						}
						if(a[c-'a'][i]-a[c-'a'][i-1]-1<=k)
						{
							temp+=(a[c-'a'][i]-a[c-'a'][i-1]);
							k-=(a[c-'a'][i]-a[c-'a'][i-1]-1);
						}
					}
					ans=max(ans,temp+1+k);
	//				cout<<ans<<" "<<k<<endl;
				}
				printf("%d\n",min(ans,n));
			}
		}
	}
	return 0;
}
/*
5
abbba

6
koyomi
3
1 o
4 o
4 m

15
yamatonadeshiko
10
1 a
2 a
3 a
4 a
5 a
1 b
2 b
3 b
4 b
5 b

10
aaaaaaaaaa
2
10 b
10 z
*/