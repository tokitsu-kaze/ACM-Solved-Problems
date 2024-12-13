#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int main()
{
	int T,a,b,i,j,n;
	char s[11];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		a=0;
		for(i=0;i<n;i++)
		{
			a=a*10+s[i]-'0';
			if(i+1<n && s[i+1]=='0') continue;
			b=0;
			for(j=i+1;j<n;j++) b=b*10+s[j]-'0';
			if(b>a)
			{
				printf("%d %d\n",a,b);
				goto end;
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}
