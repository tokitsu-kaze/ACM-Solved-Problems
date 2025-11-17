#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll a,b,c,x[MAX],y[MAX];
void cal(int i,int j)
{
	a=y[j]-y[i];  
	b=x[i]-x[j];  
	c=-a*x[i]-b*y[i];
}
mt19937 rd(time(0));
int main()
{
	const __int128_t i128=1;
	int n,i,cnt,pa,pb,ok;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lld%lld",&x[i],&y[i]);
	int LIMT=50;
	ok=0;
	while(LIMT--)
	{
		pa=pb=-1;
		while(pa==pb)
		{
			pa=rd()%n;
			pb=rd()%n;
		}
		cal(pa,pb);
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(i128*a*x[i]+i128*b*y[i]+i128*c==i128*0) cnt++;
		}
		if(cnt*2>n)
		{
			ok=1;
			break;
		}
	}
	if(ok)
	{
		puts("Yes");
		printf("%lld %lld %lld\n",a,b,c);
	}
	else puts("No");
	return 0;
}
