#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int a[MAX];
int main()
{
	int T,n,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n,[](int x,int y){
			if(x%2==y%2) return x>y;
			if(x%2==0) return true;
			else return false;
		});
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(__gcd(a[i],2*a[j])>1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

