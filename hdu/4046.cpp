////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-28 16:11:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4046
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:4352KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<string.h>
using namespace std;
#define MAX 50012
struct node
{
    int l,r,c;
};
struct node tree[MAX*4];
#define Mid(idx) (tree[idx].l+tree[idx].r)>>1
int num[MAX*5];
void buildTree(int idx,int l,int r)
{
    tree[idx].l=l;
    tree[idx].r=r;
    tree[idx].c=-1;
    if(r==l)
    {
        tree[idx].c=num[l];
        return ;
    }
    int mid=(l+r)>>1;
    buildTree(idx<<1,l,mid);
    buildTree(idx<<1|1,mid+1,r);
    tree[idx].c=tree[idx<<1].c+tree[idx<<1|1].c;
}
void Insert(int idx,int i,int c)
{
    if(tree[idx].l==i&&i==tree[idx].r)
    {
        tree[idx].c=c;
        return;
    }
    int mid=Mid(idx);
    if(i>mid) Insert(idx<<1|1,i,c);//i>mid 就可以了，我土血啊，
    else Insert(idx<<1,i,c);
    tree[idx].c=tree[idx<<1].c+tree[idx<<1|1].c;//计算区间和
}
int querySum(int idx,int l,int r)
{
    if(tree[idx].l==l&&tree[idx].r==r)
    {
        return tree[idx].c;
    }
    int mid=Mid(idx);
    if(mid>=r) return querySum(idx<<1,l,r);
    else if(l>mid) return querySum(idx<<1|1,l,r);
    else
    {
        return querySum(idx<<1,l,mid)+querySum(idx<<1|1,mid+1,r);
    }
}
int main()
{
    int T,n,m,i,type,l,r,indx,iCase=0;
    char str[MAX*5],temp;
    scanf("%d",&T);
    while(T--)
    {
        memset(num,0,sizeof(num));

        scanf("%d%d",&n,&m);
        scanf("%s",&str);
        num[1]=0;
        printf("Case %d:\n",++iCase);
        for(i=2; i<n; i++)
        {
            if(str[i-2]=='w'&&str[i-1]=='b'&&str[i]=='w')
                num[i]=1;
            else 
                num[i]=0;
        }
        num[n]=0;
        buildTree(1,1,n);
        for(i=0; i<m; i++)
        {
            scanf("%d",&type);
            if(0==type)
            {
                scanf("%d%d",&l,&r);
                if(l+2>r)//询问的区间长度<3直接输出0
                {
                    cout<<0<<endl;
                    continue;
                }//否则从l+2开始询问
                cout<<querySum(1,l+2,r)<<endl;
            }
            else
            {
                scanf("%d %c",&indx,&temp);
                if(temp==str[indx]) continue;//若要就该的字符跟原先相同，则不用修改了
                if(indx>=2&&str[indx-2]=='w'&&str[indx-1]=='b'&&str[indx]=='w')
                {
                    Insert(1,indx,0);
                    num[indx]=0;
                }
                if(indx>=2&&str[indx-2]=='w'&&str[indx-1]=='b'&&temp=='w')
                {
                        Insert(1,indx,1);
                        num[indx]=1;
                }
                if(indx>=1&&indx+1<n&&str[indx-1]=='w'&&str[indx]=='b'&&str[indx+1]=='w')
                {
                    Insert(1,indx+1,0);
                    num[indx+1]=0;
                }
                if(indx>=1&&indx+1<n&&str[indx-1]=='w'&&temp=='b'&&str[indx+1]=='w')
                {
                        Insert(1,indx+1,1);
                        num[indx+1]=1;
                }
                if(indx>=0&&indx+2<n&&str[indx]=='w'&&str[indx+1]=='b'&&str[indx+2]=='w')
                {
                    Insert(1,indx+2,0);
                    num[indx+2]=0;
                }
                if(indx>=0&&indx+2<n&&temp=='w'&&str[indx+1]=='b'&&str[indx+2]=='w')
                {
                        Insert(1,indx+2,1);
                        num[indx+2]=1;
                }
                str[indx]=temp;
            }
        }
    }
    return 0;
}