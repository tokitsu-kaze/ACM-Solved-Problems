#include<bits/stdc++.h>
using namespace std;
const int maxn=(int)1e5+10;
int arr[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int m;
		scanf("%d",&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if((arr[i]+m)%7==0)
			{
				flag=1;
			}
		}
		flag?puts("Yes"):puts("No");
	}
	return 0;
}