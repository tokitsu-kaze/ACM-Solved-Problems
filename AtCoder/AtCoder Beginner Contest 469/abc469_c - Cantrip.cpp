#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
char s[MAX];
int main()
{
	int n,i,j,cnt;
	scanf("%d",&n);
	scanf("%s",s+1);
	cnt=0;
	for(i=1,j=1;i<=n;i++)
	{
		cnt++;
		while(j<=n && cnt>0)
		{
			if(s[j]=='o');
			else
			{
				if(cnt>0) cnt--;
				else break;
			}
			j++;
		}
		printf("%d\n",j-1);
	}
	return 0;
}
