import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
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
const val mod=998244353;
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var k=tmp_line[2]
	require(n>=1 && n<=500)
	require(m>=1 && m<=500)
	require(k>=1 && k<=n*m)
	val x0=n/2+1
	val y0=m/2+1
	var ans=0
	while(k-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var x=tmp_line[0]
		var y=tmp_line[1]
		require(x>=1 && x<=n)
		require(y>=1 && y<=m)
		if(abs(x-x0)+abs(y-y0)<max(n/2+1,m/2+1)) ans++
	}
	println("${ans}")
}

