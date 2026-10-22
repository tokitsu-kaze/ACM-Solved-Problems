#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int ask1(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int ask2(int m0,int m1)
{
	printf("%d %d\n",m0,m1);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
void out(int x)
{
	printf("%d\n",x);
	fflush(stdout);
}
mt19937 rd(time(0));
int main()
{
	int T,i,res,x,m0,m1;
	scanf("%d",&T);
	while(T--)
	{
		res=ask1(1);
		if(res==0)
		{
			x=ask2(0,1);
			out(x%2);
		}
		else if(res>1)
		{
			m0=0;
			for(i=30;~i;i--)
			{
				if((res>>i)&1)
				{
					m1=(1<<i);
					break;
				}
			}
			x=ask2(m0,m1);
			if(x&m1) out(0);
			else out(1);
		}
		else
		{
			m0=0;
			m1=rd()&((1<<29)-1);
			m1=(m1<<1)|1;
			x=ask2(m0,m1);
			if(x==m0 || x==m1)
			{
				if(x==m0) out(0);
				else out(1);
			}
			else
			{
				if(x&1) out(0);
				else out(1);
			}
		}
	}
	return 0;
}
/*
逻辑推理题（分讨题）。
先问 1，可以判一些情况。
然后 m0 m1 分别为 0 和 随机奇数，逻辑推理一下。
由于固定末位是 1，前 29 位随机，所以错误概率是 1/(2^29)。
*/
