////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 00:14:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4423
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1720KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e3+10;
const ll mod=2008;
/*
分子分母都含有自变量x，不好处理。最简单的想法就是把分子上的自变量消去。（二次->一次->零次）。然后就是各种情况讨论。

1.二次->一次
f(x) =  (Ax^2 + Bx + C) / (x^2 + Dx + E)

=  A + (bx + c) / (x^2 + Dx + E) (其中b=B-A*D, c=C-A*E)

=  A + g(x)

这样我们把分子的二次项消除了。注意之后的结果区间都要加上A。

2.一次-> 零次
(1) 若B = 0。那么g(x) = c / (x^2 + Dx + E)

(a)如果c=0。则值域为[0, 0].

(b)如果c!=0。则此时分母的式子是一个开口向上的抛物线，设其极小值为mins，则取值区间为[mins, INF).

此时需要对mins和c的正负情况讨论才能写出正确区间。（mins的正负即表示Δ）

c>0时

mins>0  值域为 (0, c/mins].
mins>0  值域为 (0, INF].
mins<0  值域为 (-INF, c/mins] U (0, INF)
c<0时同上分析，区间颠倒下就可以了。

(2) 若b != 0。那么g(x) = (bx + c) / (x^2 + Dx + E)
要消去一次项，我们可以换元，令t=b*x + c得到

g(t) = b*b*t / (t^2 + bb*t + cc)   其中bb=D*b-2*c，cc=(c*c+E*b*b-D*b*c);

(1)如果t取0，则g(t)=0;

(2)当t!=0时 g(x) =b*b/(t+cc/t + bb) = h(t)

此时要求h(t)= b*b/(t+cc/t + bb)的值域(t!=0)。只有分母有自变量，非常好求解了。注意最后要把0点补回去。

(i) cc<0 时。t+cc/t 能取遍(-INF, INF)。所以值域的为(-INF, INF)。

(ii) cc>0 时。t+cc/t 的值域为(-INF, 2√cc] U [2√cc, INF)

故分母的值域为(-INF, 2√cc+bb] U [2√cc+bb, INF)
*/
int main()
{
	int t;
	double A,B,C,D,E,a,b,c,bb,cc,x1,x2,t1,t2,y1,mins;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf",&A,&B,&C,&D,&E);
		a=A;
		b=B-A*D;
		c=C-A*E;
		mins=E-D*D/4;//分母抛物线的极大值
		if(b==0)//f(x)=A+((B-A*D)*x+C-A*E)/(x*x+D*x+E)，f(x)=a+(b*x+c)/(x*x+D*x+E)
		{
			if(c==0) printf("[%.4f, %.4f]\n",A,A);
			else if(c>0)
			{
				if(mins>0) printf("(%.4f, %.4f]\n",A,c/mins+A);
				else if(mins<0) printf("(-INF, %.4f] U (%.4f, INF)\n",c/mins+A,A);
				else printf("(%.4f, INF)\n",A);
			}
			else 
			{
				if(mins>0) printf("[%.4f, %.4f)\n",c/mins+A,A);
				else if(mins<0) printf("(-INF, %.4f) U [%.4f, INF)\n",A,c/mins+A);
				else printf("(-INF, %.4f)\n",A);
			}
		}
		else//b!=0情况，f(x)=A+b*b/(t+(c*c+E*b*b-D*b*c)/t+D*b-2*c)
		{
			x1=-c/b;
			if(x1*x1+D*x1+E==0)//排除那种分子分母有公因式的情况
			{
				x2=-D-x1;
				if(x1==x2) printf("(-INF, %.4f) U (%.4f, INF)\n",A,A);
				else
				{//(b*(x-x1))/((x-x1)*(x-x2))
					y1=b/(x1-x2);
					if(y1>0) printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n",A,A,A+y1,A+y1);
					else printf("(-INF, %.4f) U (%.4f, %.4f) U (%.4f, INF)\n",A+y1,A+y1,A,A);
				}
			}
			else
			{
				bb=D*b-2*c;
				cc=(c*c+E*b*b-D*b*c);
				if(cc>0)//分母化成了g(t)=t+cc/t+bb，t=b*x+c,分子变成了b*b,所以不用考虑分子的符号了
				{
					t1=2.0*sqrt(cc);
					t2=t1+bb;//这便是分母的极大值
					t1=-t1+bb;//分母的极小值
					if(t1>0) printf("(-INF, %.4f] U [%.4f, INF)\n",A+b*b/t2,A+b*b/t1);//极小值大于0
					else if(t1==0) printf("(-INF, %.4f]\n",A+b*b/t2);//极小值为0
					else if(t2<0) printf("(-INF, %.4f] U [%.4f, INF)\n",A+b*b/t2,A+b*b/t1);//极大值小于0
					else if(t2==0) printf("[%.4f, INF)\n",A+b*b/t1);//极大值为0
					else printf("[%.4f, %.4f]\n",A+b*b/t1,A+b*b/t2);
				}
				else if(cc<0) printf("(-INF, INF)\n");
				else printf("(-INF, INF)\n");
			}
		}
	}
	return 0;
}