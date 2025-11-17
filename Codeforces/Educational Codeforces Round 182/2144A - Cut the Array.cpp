#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int main()
{
	int T,n,i,a[44],s1,s2,s3,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(l=1;l<n;l++)
		{
			for(r=l+1;r<n;r++)
			{
				s1=s2=s3=0;
				for(i=1;i<=l;i++) s1+=a[i];
				for(i=l+1;i<=r;i++) s2+=a[i];
				for(i=r+1;i<=n;i++) s3+=a[i];
				s1%=3;
				s2%=3;
				s3%=3;
				if(s1==s2 && s2==s3)
				{
					printf("%d %d\n",l,r);
					goto end;
				}
				if(s1!=s2 && s1!=s3 && s2!=s3)
				{
					printf("%d %d\n",l,r);
					goto end;
				}
			}
		}
		puts("0 0");
		end:;
	}
	return 0;
}
