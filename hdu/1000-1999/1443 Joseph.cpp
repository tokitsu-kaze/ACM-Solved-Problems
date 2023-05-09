////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-05 22:04:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1443
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
#include<malloc.h>  
#include<string.h>  
int vist[30];  
typedef struct list  
{  
    int data;  
    struct list *next;  
}Lnode,*LinList;  
  
void creat_L(LinList *L)  
{  
    (*L)=(LinList)malloc(sizeof(Lnode));  
    (*L)->data=0;  
    (*L)->next=(*L);//形成环  
}  
int DeleteNode(LinList L,int k,int n)//n是走的步数，k是有多少个好人和坏人  
{  
    int j,i=0,badk=0,mod;  
    LinList q=L;  
  
    while(i<k)//i是代表有i个坏人被处决  
    {  
        q=q->next;  
        j=1;//j=1是从当前位置开始计数，看下面的代码  
        while(vist[q->data]||q->data==0)//跳过己经处决的，vist为0时，表示这人还活着  
        {  
            q=q->next;  
        }  
        mod=n%(2*k-i);//（2*k-i）代表活着的人数，mod就等于走了很多圈以后余下的步数少于活着的人数  
        if(mod==0)//代表从当前位置走了n步后又最后会回到当前位置，那么就等于活着的人数  
        mod=2*k-i;  
        while (j<mod)//开始走  
        {  
            q=q->next;  
        if(vist[q->data]==0&&q->data!=0)//为了跳过处决了的，活着才能+1，算是一步  
                j++;  
        }  
    if(q->data<=k)//代表处决的是好人，不满足只处决坏人，不用往下走了，跳出循环  
        break;  
    if(q->data>k)//大于k的说明处决的是坏人，那么计数加一个  
        badk++;  
        vist[q->data]=1;//代表处决了  
                i++;  //下一次  
      
        //printf("%d ",q->data);  
    }  
    return badk;//反回处决坏人的人数  
}  
  
void Crea_list(LinList L,int n)//创建一个以n个人的圈  
{  
    int i;  
    LinList q=L,p;  
    for(i=n;i>=1;i--)  
    {  
        p=(LinList)malloc(sizeof(Lnode));  
        p->data=i;  
        p->next=q->next;  
        q->next=p;  
    }  
}  
  
int main()  
{  
    int i,k,m,j,t,a[16];  
    LinList L,q;  
    for(j=1;j<14;j++)//打表  
    {  
         creat_L(&L);  
        Crea_list(L,2*j);  
        q=L;  
        if(j<=9)  
        for(m=j+1;;m++)//表法要直的步数  
        {  
            memset(vist,0,sizeof(vist));  
            t=DeleteNode(L,j,m);  
  
            if(t==j)//表法以当前的步数走，处决的坏个等于坏人总数，就跳出来  
            break;  
        }  
        else  
        {  
            m=90000;  
            for(;;m++)  
            {  
                memset(vist,0,sizeof(vist));  
                t=DeleteNode(L,j,m);  
  
                if(t==j)  
                break;  
            }  
        }  
        a[j]=m;  
    }  
    while(scanf("%d",&k)>0&&k)  
    {  
        printf("%d\n",a[k]);  
    }  
}  