#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<17)+10;
int a[MAX];
int main()
{
	int T,n,i,j,k,l,r,cnt,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		n=r-l+1;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(j=17;~j;j--)
		{
			for(k=0;k<=1;k++)
			{
				vector<int> ra,rb;
				for(i=l;i<=r;i++) ra.push_back(i>>j);
				for(i=1;i<=n;i++) rb.push_back((a[i]^(ans|(k<<j)))>>j);
				sort(ra.begin(),ra.end());
				sort(rb.begin(),rb.end());
				
/*				cout<<j<<" "<<(ans|(k<<j))<<endl;
				for(auto &it:ra) cout<<it<<" ";
				puts("");
				for(auto &it:rb) cout<<it<<" ";
				puts("");*/
				
				if(ra==rb)
				{
					ans|=k<<j;
					break;
				}
			}
		}
		printf("%d\n",ans);
		for(i=1;i<=n;i++) a[i]^=ans;
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++) assert(a[i]==i+l-1);
	}
	return 0;
}

