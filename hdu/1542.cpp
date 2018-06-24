////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-28 21:33:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1542
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1456KB
//////////////////System Comment End//////////////////
/*
1.������ε����±߽磬������Ҫ�ģ���¼�����������ϻ����£�Ȼ�󰴸߶���������
2.�����������꣬����ȥ�أ���Ϊ����ɢ��
3.�Ա�������±߽�����ȥ����
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3
#define MAX 110
#define LCH(i) ((i)<<1)
#define RCH(i) ((i)<<1 | 1)

struct segment //����������±߽�
{
  double l,r,h; //���Һ����꣬������
  int f; //-1Ϊ�±߽磬1Ϊ�ϱ߽�
}ss[2*MAX];
struct node //�߶����ڵ�
{
  int l,r;
  int cnt; //�ýڵ㱻���ǵ����
  double len; //�����䱻���ǵ��ܳ���
  int mid()
  { return (l+r)>>1; }
}tt[2*MAX*4];
double pos[2*MAX];
int nums;

int cmp(struct segment a ,struct segment b)
{
  return a.h<b.h;
}

void build(int a, int b ,int rt)
{
 tt[rt].l=a; tt[rt].r=b; tt[rt].cnt=0; tt[rt].len=0;
 if(a==b) return ;
 int mid=tt[rt].mid();
 build(a,mid,LCH(rt));
 build(mid+1,b,RCH(rt));
}

int binary(double key ,int low, int high)
{
   while(low<=high)
   {
      int mid=(low+high)>>1;
      if(pos[mid] == key) return mid;
      else if(key < pos[mid]) high=mid-1;
      else                    low=mid+1;
   }
   return -1;
}

void get_len(int rt)
{
   if(tt[rt].cnt) //��0���Ѿ������θ���
      tt[rt].len = pos[tt[rt].r+1] - pos[tt[rt].l];
   else if(tt[rt].l == tt[rt].r) //�Ѿ�����һ���߶�
      tt[rt].len = 0;
   else //��һ���߶ε�����û�����θ��ǣ���ôֻ�ܴ����Һ��ӵ���Ϣ�л�ȡ
      tt[rt].len = tt[LCH(rt)].len + tt[RCH(rt)].len ;
}

void updata(int a, int b ,int val ,int rt)
{
   if(tt[rt].l==a && tt[rt].r==b) //Ŀ������
   {
      tt[rt].cnt += val; //����������䱻���ǵ����
      get_len(rt);  //����������䱻���ǵ��ܳ���
      return ;
   }
   int mid=tt[rt].mid();
   if(b<=mid) //ֻ��������
      updata(a,b,val,LCH(rt));
   else if(a>mid) //ֻ�����к���
      updata(a,b,val,RCH(rt));
   else //���Ҷ�Ҫ����
   {
      updata(a,mid,val,LCH(rt));
      updata(mid+1,b,val,RCH(rt));
   }
   get_len(rt); //��������䱻���ǵ��ܳ���
}

int main()
{
  int Case=0;
  int n;
  while(scanf("%d",&n)!=EOF && n)
  {
    nums=0;
    for(int i=0; i<n; i++)
    {
      double x1,y1,x2,y2;
      scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
      ss[nums].l=x1;  ss[nums].r=x2; ss[nums].h=y1; ss[nums].f=1;
      //��¼�ϱ߽����Ϣ
      ss[nums+1].l=x1; ss[nums+1].r=x2; ss[nums+1].h=y2; ss[nums+1].f=-1;
      //��¼�±߽����Ϣ
      pos[nums]=x1; pos[nums+1]=x2;
      //��¼������
      nums += 2;

    }

    sort(ss,ss+nums,cmp); //���߰���������������
    sort(pos,pos+nums); //��������������
    //for(int i=0; i<nums; i++) printf("%.2lf %.2lf  %.2lf\n",ss[i].l,ss[i].r,ss[i].h);
    int m=1;
    for(int i=1; i<nums; i++)
      if(pos[i]!=pos[i-1]) //ȥ��
        pos[m++]=pos[i];

    build(0,m-1,1);  //��ɢ������������[0,m-1]���Դ˽���
    double ans=0;
    for(int i=0; i<nums; i++) //�ó�ÿ�����߲��Ҹ���
    {
       int l=binary(ss[i].l,0,m-1);
       int r=binary(ss[i].r,0,m-1)-1;
       updata(l,r,ss[i].f,1); //�������߶�ȥ����
       ans += (ss[i+1].h-ss[i].h)*tt[1].len;
       //printf("%.2lf\n",ans);
    }
    printf("Test case #%d\n",++Case);
    printf("Total explored area: %.2f\n\n",ans);
  }
  return 0;
}