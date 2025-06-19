#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s1[MAX],s2[MAX],t1[MAX],t2[MAX];
int nex1[MAX],nex2[MAX],pre1[MAX],pre2[MAX];
set<int> p1[2],p2[2];
void myswap(int f,int x,int y)
{
	if(x==y) return;
//	cout<<f<<" "<<x<<" "<<y<<endl;
	if(f==1)
	{
		if(s1[x]==s1[y]) return;
		p1[s1[x]-'0'].erase(x);
		p1[s1[y]-'0'].erase(y);
		swap(s1[x],s1[y]);
		p1[s1[x]-'0'].insert(x);
		p1[s1[y]-'0'].insert(y);
	}
	else
	{
		if(s2[x]==s2[y]) return;
		p2[s2[x]-'0'].erase(x);
		p2[s2[y]-'0'].erase(y);
		swap(s2[x],s2[y]);
		p2[s2[x]-'0'].insert(x);
		p2[s2[y]-'0'].insert(y);
	}
}
int main()
{
//	freopen("edit2.in","r",stdin);
	int T,n,i,ans,now1,now2,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		scanf("%s",t1+1);
		scanf("%s",t2+1);
		now1=now2=0;
		for(i=1;i<=n;i++)
		{
			if(t1[i]=='0') now1=0;
			else now1++;
			if(t2[i]=='0') now2=0;
			else now2++;
			pre1[i]=i;
			if(now1>0) pre1[i]=i-now1+1;
			pre2[i]=i;
			if(now2>0) pre2[i]=i-now2+1;
		}
		now1=now2=0;
		for(i=n;i;i--)
		{
			if(t1[i]=='0') now1=0;
			else now1++;
			if(t2[i]=='0') now2=0;
			else now2++;
			nex1[i]=i;
			if(now1>0) nex1[i]=i+now1-1;
			nex2[i]=i;
			if(now2>0) nex2[i]=i+now2-1;
		}
		p1[0].clear();
		p1[1].clear();
		p2[0].clear();
		p2[1].clear();
		for(i=1;i<=n;i++)
		{
			p1[s1[i]-'0'].insert(i);
			p2[s2[i]-'0'].insert(i);
		}
		for(i=1;i<=n;i++)
		{
			if(s1[i]==s2[i]) continue;
			auto itx=p2[s1[i]-'0'].lower_bound(i);
			if(itx!=p2[s1[i]-'0'].end())
			{
				x=*itx;
				if(nex1[i]>=pre2[x])
				{
					myswap(2,x,max(pre2[x],i));
					myswap(1,i,max(pre2[x],i));
				}
			}
			
			if(s1[i]==s2[i]) continue;
			itx=p1[s2[i]-'0'].lower_bound(i);
			if(itx!=p1[s2[i]-'0'].end())
			{
				x=*itx;
				if(nex2[i]>=pre1[x])
				{
					myswap(1,x,max(pre1[x],i));
					myswap(2,i,max(pre1[x],i));
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=s1[i]==s2[i];
		printf("%d\n",ans);
	}
	return 0;
}
/*
20�֣�5-8 ����A���ͷ֣�ans=sum{s1[1]==s2[i]}
20�֣�9-12 ����B���ѿɽ�����λ�ø��һЩ��ͨ�飬����ƥ�䡣 

100�֣�2.5h 
�ʼ�������ǰ������ǰ���Ǹ�λ���Ѿ�ƥ��Ͳ�����������ô�㶼�����˴�������
����������ǰƥ�������һ����һ�������ŵģ����ǿ��Ƕ����󽻻���
���󽻻�����֮��������л����ø��š�

����ҪԤ�����ܽ����ķ�Χ��Ȼ�󽻻�����һ�����ƣ�
�����㲻���ܿ�Խһ����ͬ���ַ������� 10010 ������һ�ν������ 00011��
---
���ԣ����ֽ��Ͳ�ͨΪʲô��Ҫ��������ơ�
��Ϊ�ᷢ�����ܽ������ɴν����� 10010 ��� 00011������ֱ�ӻ����С�

Ȼ����setά��λ�ã���Ϊÿ����Ҫ�ҵ� Ҫ�����ġ�
 
��Ȼ����֤��������ȷ�ԣ����ҳ����ܴ󣬵��ǹ��ˡ�
*/
