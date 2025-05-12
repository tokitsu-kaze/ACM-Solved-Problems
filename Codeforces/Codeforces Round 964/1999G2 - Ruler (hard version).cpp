#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt;
int ask(int a,int b)
{
	cnt++;
	assert(cnt<=7);
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
/*
int ans;
int ask(int a,int b)
{
	cnt++;
	assert(cnt<=7);
	if(a>=ans) a++;
	if(b>=ans) b++;
	return a*b;
}
*/
int main()
{
	int T,l,r,lm,rm,res;
	scanf("%d",&T);
//	ans=1;
	while(T--)
	{
//		ans++;
		cnt=0;
		l=1;
		r=999;
		while(l<r)
		{  
			lm=l+(r-l)/3;
			rm=r-(r-l)/3;
			res=ask(lm,rm);
			if(res==(lm+1)*(rm+1)) r=lm;
			else if(res==lm*(rm+1))
			{
				l=lm+1;
				r=rm;
			}
			else if(res==lm*rm) l=rm+1;
			else assert(0);
		}
//		assert(l==ans);
		printf("! %d\n",l);
		fflush(stdout);
	}
	return 0;
}

