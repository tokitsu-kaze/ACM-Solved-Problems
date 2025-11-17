#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=300+10;
mt19937 rd(time(0));
int main()
{
	int T,n,i,a[66],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=2*n;i++) scanf("%d",&a[i]);
		while(1)
		{
			shuffle(a+1,a+1+2*n,rd);
			a[2*n+1]=a[1];
			a[0]=a[2*n];
			ok=1;
			for(i=1;i<=2*n;i++)
			{
				if(a[i]*2==(a[i-1]+a[i+1])) ok=0;
			}
			if(ok) break;
		}
		for(i=1;i<=2*n;i++) printf("%d%c",a[i]," \n"[i==2*n]);
		
	}
	return 0;
}
