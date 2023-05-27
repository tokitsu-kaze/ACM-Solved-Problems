#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k,cnt[11],b[111],c[111],bb,cc,ok,ans;
	char a[111][5],tmp[5];
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		for(i=0;i<n;i++) scanf("%s%d%d",a[i],&b[i],&c[i]);
		vector<int> res;
		for(i=9999;~i;i--)
		{
			memset(cnt,0,sizeof cnt);
			sprintf(tmp,"%04d",i);
			for(k=0;k<4;k++) cnt[tmp[k]-'0']++;
			ok=1;
			for(j=0;j<n;j++)
			{
				bb=0;
				for(k=0;k<4;k++)
				{
					if(cnt[a[j][k]-'0']>0) bb++;
					cnt[a[j][k]-'0']--;
				}
				cc=0;
				for(k=0;k<4;k++)
				{
					cnt[a[j][k]-'0']++;
					if(tmp[k]==a[j][k]) cc++;
				}
				if(bb!=b[j] || cc!=c[j])
				{
					ok=0;
					break;
				}
			}
			if(ok) res.push_back(i);
		}
		if(res.size()>1) puts("Not sure");
		else printf("%d\n",res[0]);
	}
	return 0;
}
