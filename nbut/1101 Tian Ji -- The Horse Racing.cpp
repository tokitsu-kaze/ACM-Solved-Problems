#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int n,i,j,k,l,cnt,a[1010],b[1010];
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		cnt=j=k=0;
		for(i=n-1,l=n-1;i>=k;)
		{
			if(a[i]>b[l])
			{
				cnt++;
				i--;
				l--;
			}
			else if(a[i]<b[l])
			{
				cnt--;
				k++;
				l--;
			}
			else if(a[i]==b[l])
			{
				if(a[k]>b[j])
				{
					cnt++;
					k++;
					j++;
				}
				else
				{
					if(a[k]<b[l]) cnt--;
					k++;
					l--;
				}
			}
		}
		printf("%d\n",cnt*200);
	}
	return 0;
}