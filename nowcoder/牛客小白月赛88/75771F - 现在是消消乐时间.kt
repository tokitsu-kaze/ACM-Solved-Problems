import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
    	mid=(l+r) shr 1
    	if(a[mid].toLong()>=target.toLong()) r=mid
    	else l=mid+1
    }
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
/*------------------------------------------------------------*/
fun get_id(x:Int,y:Int,dx:Int,dy:Int,n:Int,m:Int):Int
{
	return (x*(m+1)+y+1)+(2*max(0,dx)+max(0,dy))*(n+1)*(m+1)
}
fun work(_x:Int,_y:Int,_dx:Int,_dy:Int,n:Int,m:Int,d:Int):Int
{
	var x=_x
	var y=_y
	var dx=_dx
	var dy=_dy
	var vis=BooleanArray((n+2)*(m+2)*4+10){false}
	vis[get_id(x,y,dx,dy,n,m)]=true
	while(true)
    {
    	var f=0
    	if((x+dx<0||x+dx>n)&&(y+dy<0||y+dy>m)) break
    	if(x+dx<0||x+dx>n)
        {
        	dx*=-1
        	f=1
        }
    	if(y+dy<0||y+dy>m)
        {
        	dy*=-1
        	f=1
        }
    	if(f==0)
        {
        	x+=dx
        	y+=dy
        }
    	if(vis[get_id(x,y,dx,dy,n,m)]) break
    	vis[get_id(x,y,dx,dy,n,m)]=true
    }
	var cnt=0
	for(i in d+1..n)
    {
    	for(j in 1..m)
        {
        	if(vis[get_id(i,j,-1,-1,n,m)]|| 
               vis[get_id(i-1,j-1,1,1,n,m)]|| 
               vis[get_id(i-1,j,1,-1,n,m)]|| 
               vis[get_id(i,j-1,-1,1,n,m)]) cnt++ 
        }
    }
//	println("${cnt}")
	if(cnt==(n-d)*m) return 1
	return 0
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	require(n>=1 && n<=5e3)
	var m=tmp_line[1]
	require(m>=1 && m<=5e3)
	var d=tmp_line[2]
	require(d>=0 && d<=n)
	if(d==n)
    {
    	println("YES")
    	println("0 0")
    	println("UR")
    	return
    }
	if(work(0,1,1,-1,n,m,d)==1)
    {
        println("YES")
        println("0 1")
        println("UL")
        return
    }
    if(work(0,0,1,1,n,m,d)==1)
    {
        println("YES")
        println("0 0")
        println("UR")
        return
    }
	println("NO")
}

