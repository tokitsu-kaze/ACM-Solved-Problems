#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
const int limt=100;
int n,a[MAX],b[MAX],ans;
void ck(int x)
{
	if(x<3) return;
	if(x>1e9) return;
	if(ans!=-1) return;
	int i,cnt;
	for(i=1;i<=n;i++) b[i]=a[i]%x;
	cnt=0;
	for(i=1;i<=n;i++) cnt+=(b[i]==b[1]);
	if(cnt*2>n) ans=x;
}
int main()
{
	srand(time(0));
	int T,i,j,d,now,sq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=-1;
	T=limt;
	while(T--)
	{
		if(ans!=-1) break;
		random_shuffle(a+1,a+1+n);
		d=abs(a[2]-a[1]);
		now=1;
		while(d%2==0)
		{
			d/=2;
			now*=2;
			ck(now);
		}
		sq=sqrt(d);
		for(i=3;i<=sq&&ans==-1;i++)
		{
			if(d%i==0) ck(i);
			while(d%i==0) d/=i;
		}
		ck(d);
	}
	printf("%d\n",ans);
	return 0;
}
 
