////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 13:51:59
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 6206
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:11632KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
import java.io.*;
class Point
{
    BigDecimal x,y;
}
class  Circle
{
    Point c;
    BigDecimal r;
}
public class Main
{
     static BigDecimal dot(Point a,Point b)
    {
        return (a.x.multiply(b.x)).add(((a.y).multiply(b.y)));
    }
    static BigDecimal length(Point a)
    {
        return dot(a,a);
    }
    static Point del(Point a,Point b)
    {
        Point temp=new Point();
        temp.x=a.x.subtract(b.x);
        temp.y=a.y.subtract(b.y);
        return temp;
    }
   static  BigDecimal dist(Point a,Point b)
    {
        return dot(del(a,b),del(a,b));
    }
    static Circle  CircumscribedCircle(Point p1,Point p2,Point p3)
    {
        BigDecimal Bx=p2.x.subtract(p1.x);
        BigDecimal By=p2.y.subtract(p1.y);
        BigDecimal Cx=p3.x.subtract(p1.x);
        BigDecimal Cy=p3.y.subtract(p1.y);
        BigDecimal two=new BigDecimal("2.0");
        BigDecimal temp1=Bx.multiply(Cy);
        BigDecimal temp2=By.multiply(Cx);
        BigDecimal temp3= temp1.subtract(temp2);
        BigDecimal D=two.multiply(temp3);
        temp1=Cy.multiply(((Bx.multiply(Bx)). add(By.multiply(By) ) ) );
        temp2=By.multiply(((Cx.multiply(Cx)).add(Cy.multiply(Cy))));
        BigDecimal cx=((temp1.subtract(temp2)).divide(D)).add(p1.x);
        temp1=Bx.multiply(((Cx.multiply(Cx)).add(Cy.multiply(Cy))));
        temp2=Cx.multiply(((Bx.multiply(Bx)).add(By.multiply(By))));
        BigDecimal cy=((temp1.subtract(temp2)).divide(D)).add(p1.y);
        Point p=new Point();
        p.x=cx;
        p.y=cy;
        Circle jige=new Circle();
        jige.c=p;
        jige.r=length(del(p1,p));
        return jige;
    }
    public static void main(String[] args) throws IOException
    {
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            Point p=new Point();
            Circle a=new Circle();
            Point p1=new Point();
            Point p2=new Point();
            Point p3=new Point();
            p1.x=sc.nextBigDecimal();
            p1.y=sc.nextBigDecimal();
            p2.x=sc.nextBigDecimal();
            p2.y=sc.nextBigDecimal();
            p3.x=sc.nextBigDecimal();
            p3.y=sc.nextBigDecimal();
            p.x=sc.nextBigDecimal();
            p.y=sc.nextBigDecimal();
            a=CircumscribedCircle(p1,p2,p3);
            if(dist(p,a.c).compareTo(a.r)>0)
            {
               out.println("Accepted");
            }
            else
            {
                out.println("Rejected");
            }
        }
        out.flush();
    }
}