#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int ask(vector<int> a)
{
	printf("? %d\n",(int)a.size());
	for(int i=0;i<a.size();i++) printf("%d%c",a[i]," \n"[i+1==(int)a.size()]);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int ask(int l,int r)
{
	vector<int> res;
	for(int i=l;i<=r;i++) res.push_back(i);
	return ask(res);
}
int pos[MAX];
int main()
{
	int T,n,k,c,i,j,x,l,r,mid,mx,ans;
	char s[22];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		memset(pos,0,sizeof pos);
		for(i=1;i<=k;i++)
		{
			scanf("%d",&c);
			for(j=1;j<=c;j++)
			{
				scanf("%d",&x);
				pos[x]=i;
			}
		}
		l=1;
		r=n;
		mx=ask(l,r);
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ask(l,mid)==mx) r=mid;
			else l=mid+1;
		}
		
		vector<int> tmp;
		for(i=1;i<=n;i++)
		{
			if(pos[i]!=pos[l] || pos[l]==0) tmp.push_back(i);
		}
		ans=ask(tmp);
		
		printf("!");
		for(i=1;i<=k;i++)
		{
			if(pos[l]==i) printf(" %d",ans);
			else printf(" %d",mx);
		}
		puts("");
		fflush(stdout);
		scanf("%s",s);
	}
	return 0;
}
