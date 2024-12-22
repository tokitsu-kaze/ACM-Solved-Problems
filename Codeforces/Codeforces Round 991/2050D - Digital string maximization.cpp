#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=2;i<=n;i++)
		{
			j=i;
			while(j>1 && s[j]>'0' && s[j]-1>s[j-1])
			{
				s[j]--;
				swap(s[j],s[j-1]);
				j--;
			}
		}
		puts(s+1);
	}
	return 0;
}
