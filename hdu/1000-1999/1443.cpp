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
    (*L)->next=(*L);//�γɻ�  
}  
int DeleteNode(LinList L,int k,int n)//n���ߵĲ�����k���ж��ٸ����˺ͻ���  
{  
    int j,i=0,badk=0,mod;  
    LinList q=L;  
  
    while(i<k)//i�Ǵ�����i�����˱�����  
    {  
        q=q->next;  
        j=1;//j=1�Ǵӵ�ǰλ�ÿ�ʼ������������Ĵ���  
        while(vist[q->data]||q->data==0)//�������������ģ�vistΪ0ʱ����ʾ���˻�����  
        {  
            q=q->next;  
        }  
        mod=n%(2*k-i);//��2*k-i��������ŵ�������mod�͵������˺ܶ�Ȧ�Ժ����µĲ������ڻ��ŵ�����  
        if(mod==0)//����ӵ�ǰλ������n����������ص���ǰλ�ã���ô�͵��ڻ��ŵ�����  
        mod=2*k-i;  
        while (j<mod)//��ʼ��  
        {  
            q=q->next;  
        if(vist[q->data]==0&&q->data!=0)//Ϊ�����������˵ģ����Ų���+1������һ��  
                j++;  
        }  
    if(q->data<=k)//���������Ǻ��ˣ�������ֻ�������ˣ������������ˣ�����ѭ��  
        break;  
    if(q->data>k)//����k��˵���������ǻ��ˣ���ô������һ��  
        badk++;  
        vist[q->data]=1;//��������  
                i++;  //��һ��  
      
        //printf("%d ",q->data);  
    }  
    return badk;//���ش������˵�����  
}  
  
void Crea_list(LinList L,int n)//����һ����n���˵�Ȧ  
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
    for(j=1;j<14;j++)//���  
    {  
         creat_L(&L);  
        Crea_list(L,2*j);  
        q=L;  
        if(j<=9)  
        for(m=j+1;;m++)//��Ҫֱ�Ĳ���  
        {  
            memset(vist,0,sizeof(vist));  
            t=DeleteNode(L,j,m);  
  
            if(t==j)//���Ե�ǰ�Ĳ����ߣ������Ļ������ڻ�����������������  
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