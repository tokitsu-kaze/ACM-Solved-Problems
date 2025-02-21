#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=2e5+10;
int main()
{
	int T,n,x,i,sq,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		sq=sqrt(n-x);
		set<int> s;
		for(i=1;i<=sq;i++)
		{
			if((n-x)%i) continue;
			k=(n-x)/i+2;
			if(k%2==0)
			{
				k/=2;
				if(k>=2 && k>=x) s.insert(k);
			}
			
			k=i+2;
			if(k%2==0)
			{
				k/=2;
				if(k>=2 && k>=x) s.insert(k);
			}
		}
		sq=sqrt(n+x-2);
		for(i=1;i<=sq;i++)
		{
			if((n+x-2)%i) continue;
			k=(n+x-2)/i+2;
			if(k%2==0)
			{
				k/=2;
				if(k>=2 && k>=x) s.insert(k);
			}
			
			k=i+2;
			if(k%2==0)
			{
				k/=2;
				if(k>=2 && k>=x) s.insert(k);
			}
		}
		if((n+x-2+2)%2==0)
		{
			k=(n+x-2+2)/2;
			if(k>=2 && k>=x) s.insert(k);
		}
/*		for(auto &it:s) printf("%d ",it);
		puts("");*/
		printf("%d\n",s.size());
	}
	return 0;
}
/*
(2k-2)*y+x=n
(2k-2)*y=(n-x)

(2k-2)*y+k+k-x=n
(2k-2)*(y+1)-x+2=n
(2k-2)*(y+1)=n+x-2
*/

