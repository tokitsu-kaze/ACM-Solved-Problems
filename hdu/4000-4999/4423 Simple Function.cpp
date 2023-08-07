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
���ӷ�ĸ�������Ա���x�����ô�����򵥵��뷨���ǰѷ����ϵ��Ա�����ȥ��������->һ��->��Σ���Ȼ����Ǹ���������ۡ�

1.����->һ��
f(x) =  (Ax^2 + Bx + C) / (x^2 + Dx + E)

=  A + (bx + c) / (x^2 + Dx + E) (����b=B-A*D, c=C-A*E)

=  A + g(x)

�������ǰѷ��ӵĶ����������ˡ�ע��֮��Ľ�����䶼Ҫ����A��

2.һ��-> ���
(1) ��B = 0����ôg(x) = c / (x^2 + Dx + E)

(a)���c=0����ֵ��Ϊ[0, 0].

(b)���c!=0�����ʱ��ĸ��ʽ����һ���������ϵ������ߣ����伫СֵΪmins����ȡֵ����Ϊ[mins, INF).

��ʱ��Ҫ��mins��c������������۲���д����ȷ���䡣��mins����������ʾ����

c>0ʱ

mins>0  ֵ��Ϊ (0, c/mins].
mins>0  ֵ��Ϊ (0, INF].
mins<0  ֵ��Ϊ (-INF, c/mins] U (0, INF)
c<0ʱͬ�Ϸ���������ߵ��¾Ϳ����ˡ�

(2) ��b != 0����ôg(x) = (bx + c) / (x^2 + Dx + E)
Ҫ��ȥһ������ǿ��Ի�Ԫ����t=b*x + c�õ�

g(t) = b*b*t / (t^2 + bb*t + cc)   ����bb=D*b-2*c��cc=(c*c+E*b*b-D*b*c);

(1)���tȡ0����g(t)=0;

(2)��t!=0ʱ g(x) =b*b/(t+cc/t + bb) = h(t)

��ʱҪ��h(t)= b*b/(t+cc/t + bb)��ֵ��(t!=0)��ֻ�з�ĸ���Ա������ǳ�������ˡ�ע�����Ҫ��0�㲹��ȥ��

(i) cc<0 ʱ��t+cc/t ��ȡ��(-INF, INF)������ֵ���Ϊ(-INF, INF)��

(ii) cc>0 ʱ��t+cc/t ��ֵ��Ϊ(-INF, 2��cc] U [2��cc, INF)

�ʷ�ĸ��ֵ��Ϊ(-INF, 2��cc+bb] U [2��cc+bb, INF)
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
		mins=E-D*D/4;//��ĸ�����ߵļ���ֵ
		if(b==0)//f(x)=A+((B-A*D)*x+C-A*E)/(x*x+D*x+E)��f(x)=a+(b*x+c)/(x*x+D*x+E)
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
		else//b!=0�����f(x)=A+b*b/(t+(c*c+E*b*b-D*b*c)/t+D*b-2*c)
		{
			x1=-c/b;
			if(x1*x1+D*x1+E==0)//�ų����ַ��ӷ�ĸ�й���ʽ�����
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
				if(cc>0)//��ĸ������g(t)=t+cc/t+bb��t=b*x+c,���ӱ����b*b,���Բ��ÿ��Ƿ��ӵķ�����
				{
					t1=2.0*sqrt(cc);
					t2=t1+bb;//����Ƿ�ĸ�ļ���ֵ
					t1=-t1+bb;//��ĸ�ļ�Сֵ
					if(t1>0) printf("(-INF, %.4f] U [%.4f, INF)\n",A+b*b/t2,A+b*b/t1);//��Сֵ����0
					else if(t1==0) printf("(-INF, %.4f]\n",A+b*b/t2);//��СֵΪ0
					else if(t2<0) printf("(-INF, %.4f] U [%.4f, INF)\n",A+b*b/t2,A+b*b/t1);//����ֵС��0
					else if(t2==0) printf("[%.4f, INF)\n",A+b*b/t1);//����ֵΪ0
					else printf("[%.4f, %.4f]\n",A+b*b/t1,A+b*b/t2);
				}
				else if(cc<0) printf("(-INF, INF)\n");
				else printf("(-INF, INF)\n");
			}
		}
	}
	return 0;
}