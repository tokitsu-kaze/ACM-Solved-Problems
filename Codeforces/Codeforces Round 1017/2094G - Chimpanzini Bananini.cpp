#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,q,op,x,n;
	ll sum,res,revres;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&q);
		deque<int> dq,rdq;
		sum=res=revres=0;
		n=0;
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				x=dq.back();
				dq.pop_back();
				dq.push_front(x);
				res+=(sum-x);
				res-=1LL*(n-1)*x;
				
				x=rdq.front();
				rdq.pop_front();
				rdq.push_back(x);
				revres-=(sum-x);
				revres+=1LL*(n-1)*x;
			}
			else if(op==2)
			{
				swap(dq,rdq);
				swap(res,revres);
			}
			else if(op==3)
			{
				scanf("%d",&x);
				sum+=x;
				n++;
				
				dq.push_back(x);
				res+=1LL*n*x;
				
				rdq.push_front(x);
				revres+=sum;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}

