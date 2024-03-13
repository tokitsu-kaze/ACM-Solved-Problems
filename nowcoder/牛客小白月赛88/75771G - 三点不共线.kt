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
data class Point(var x:Double,var y:Double)
fun dot(a:Point,b:Point):Double{return a.x*b.x+a.y*b.y}
fun length(a:Point):Double{return sqrt(dot(a,a))}
fun midseg(a:Point,b:Point):Point{return Point((a.x+b.x)/2.0,(a.y+b.y)/2.0)}
fun normal(x:Point):Point
{
	var l=length(x);
	return Point(-x.y/l,x.x/l)
}
fun go()
{
	var t=readint()
	require(t>=1 && t<=2e5)
	while(t-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==5)
		var a=Point(tmp_line[0].toDouble(),tmp_line[1].toDouble())
		var b=Point(tmp_line[2].toDouble(),tmp_line[3].toDouble())
		var k=tmp_line[4].toDouble()
		require(a.x>=-1e3 && a.x<=1e3)
		require(a.y>=-1e3 && a.y<=1e3)
		require(b.x>=-1e3 && b.x<=1e3)
		require(b.y>=-1e3 && b.y<=1e3)
		require(k>=1 && k<=180)
		var mid=midseg(a,b)
		if(tmp_line[4]==180)
		{
			println("${mid.x} ${mid.y}")
			continue
		}
		k=k/180.0*PI
		var d=normal(Point(b.x-a.x,b.y-a.y))
//		println("${d.x} ${d.y}")
		var len=length(Point(b.x-a.x,b.y-a.y))/2/tan(k/2)
		var ans=Point(mid.x+d.x*len,mid.y+d.y*len)
		println("${ans.x} ${ans.y}")
//		println("${length(Point(b.x-a.x,b.y-a.y))/2} ${length(Point(ans.x-a.x,ans.y-a.y))*sin(k/2)}")
	}
}

