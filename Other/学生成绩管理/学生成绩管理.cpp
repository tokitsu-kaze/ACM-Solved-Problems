#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//边的条数 
using namespace std;
typedef long long ll;
int flag=0,n=0,cnt[5],lmax[5],lmin[5],tag;
double sum[5];
struct stu
{
	int id;
	char name[51];
	char sex[11];
	int y,m,d;
	struct score
	{
		int cpt;//conputer
		int eg;//english
		int mt;//math
		int ms;//music
		int minn,maxx;
		double ave;
		void calmin()
		{
			minn=min(min(min(cpt,eg),mt),ms);
		}
		void calmax()
		{
			maxx=max(max(max(cpt,eg),mt),ms);
		}
		void calave()
		{
			ave=(cpt+eg+mt+ms)*1.0/4;
		}
		void calcnt()
		{
			if(cpt<60) cnt[0]++;
			if(eg<60) cnt[1]++;
			if(mt<60) cnt[2]++;
			if(ms<60) cnt[3]++;
		}
		void calsum()
		{
			sum[0]+=cpt;
			sum[1]+=eg;
			sum[2]+=mt;
			sum[3]+=ms;
		}
		void lesson()
		{
			lmax[0]=max(lmax[0],cpt);
			lmax[1]=max(lmax[1],eg);
			lmax[2]=max(lmax[2],mt);
			lmax[3]=max(lmax[3],ms);
			lmin[0]=min(lmin[0],cpt);
			lmin[1]=min(lmin[1],eg);
			lmin[2]=min(lmin[2],mt);
			lmin[3]=min(lmin[3],ms);
		}
	}s;
}stu[11111];
void add()
{
	int op; 
	if(!flag)
	{
		puts("请按照以下格式输入学生信息");
		puts("学号 姓名 性别 入学时间（年/月/日） 计算机原理成绩 英语成绩 数学成绩 音乐成绩");
		puts("Sample:00001 张三 男 2000/1/1 60 60 60 60"); 
	}
	puts("请输入学生信息");
	flag=1;
	scanf("%d %s %s %d/%d/%d %d %d %d %d",&stu[n].id,stu[n].name,stu[n].sex,&stu[n].y,&stu[n].m,&stu[n].d,&stu[n].s.cpt,&stu[n].s.eg,&stu[n].s.mt,&stu[n].s.ms);
	stu[n].s.calmin();
	stu[n].s.calmax();
	stu[n].s.calave();
	stu[n].s.calcnt();
	stu[n].s.calsum();
	stu[n].s.lesson();
	freopen("in.txt","w",stdout);
	printf("%05d %s %s %d/%d/%d %d %d %d %d\n",stu[n].id,stu[n].name,stu[n].sex,stu[n].y,&stu[n].m,&stu[n].d,stu[n].s.cpt,stu[n].s.eg,stu[n].s.mt,stu[n].s.ms);
	fclose(stdout);
	freopen("CON","w",stdout);
	puts("数据已存储");
	n++;
	puts("请选择操作：");
	puts("0：返回"); 
	puts("1：继续输入");
	scanf("%d",&op);
	if(op==0) return;
	else if(op==1) add();
}
void prf()
{
	int i,op;
	if(!n)
	{
		if(!tag) puts("没有数据 打印失败");
		else puts("没有数据 显示失败");
		return; 
	}
	puts("请选择操作：");
	puts("输入数字0：返回上一步");
	if(!tag) puts("输入数字1：打印已存储的学生成绩");
	else puts("输入数字1：显示已存储的学生成绩");
	if(!tag) puts("输入数字2：打印已存储的课程成绩的统计");
	else puts("输入数字2：显示已存储的课程成绩的统计");
	scanf("%d",&op);
	if(op==0) return;
	else if(op==1)
	{
		if(!tag) freopen("out1.txt","w",stdout);
		puts("学号  姓名    性别  计算机原理成绩 英语成绩 数学成绩 音乐成绩 最高分 最低分 平均分");
		for(i=0;i<n;i++)
		{
			printf("%05d %s  %s %5d %14d %8d %8d %8d %6d %9.2lf\n",stu[i].id,stu[i].name,stu[i].sex,stu[i].s.cpt,stu[i].s.eg,stu[i].s.mt,stu[i].s.ms,stu[i].s.maxx,stu[i].s.minn,stu[i].s.ave);
		}
		if(!tag) fclose(stdout);
		if(!tag) freopen("CON","w",stdout);
	}
	else if(op==2)
	{
		if(!tag) freopen("out2.txt","w",stdout);
		printf("计算机原理 最高分：%d 最低分：%d 平均分：%.2lf 不及格人数：%d\n",lmax[0],lmin[0],sum[0]/n,cnt[0]);
		printf("   英语    最高分：%d 最低分：%d 平均分：%.2lf 不及格人数：%d\n",lmax[1],lmin[1],sum[1]/n,cnt[1]);
		printf("   数学    最高分：%d 最低分：%d 平均分：%.2lf 不及格人数：%d\n",lmax[2],lmin[2],sum[2]/n,cnt[2]);
		printf("   音乐    最高分：%d 最低分：%d 平均分：%.2lf 不及格人数：%d\n",lmax[3],lmin[3],sum[3]/n,cnt[3]);
		if(!tag) fclose(stdout);
		if(!tag) freopen("CON","w",stdout);
	}
	puts("打印结束");
}
int main()
{
	int op;
	mem(cnt,0);
	mem(lmin,0x3f);
	mem(lmax,0);
	mem(sum,0);
	while(1)
	{
		puts("请选择操作：");
		puts("输入数字0：结束程序");
		puts("输入数字1：成绩输入");
		puts("输入数字2：成绩统计并打印");
		puts("输入数字3：成绩统计并显示在屏幕上");
		scanf("%d",&op);
		tag=0;
		if(op==0) return 0;
		else if(op==1) add();
		else if(op==2) prf();
		else if(op==3)
		{
			tag=1;
			prf();
		}
		puts("请选择操作：");
		puts("0：结束程序"); 
		puts("1：继续");
		scanf("%d",&op);
		if(op==0) return 0;
		else if(op==1) continue;
	}
}
/*


00001 令狐冲 男 1999/3/2 90 83 72 82
00002 林平之 男 1999/6/5 78 92 88 78

*/
