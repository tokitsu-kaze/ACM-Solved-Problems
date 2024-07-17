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
const val MAX=1e5.toInt()+10
const val mod=(1e9).toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=1 && n<=1e6)
	require(m>=1 && m<=1e6)
	require(n.toLong()*m>=1 && n.toLong()*m<=1e6)
	var f=LongArray(m+1){LLINF}
	var g=LongArray(m+1){LLINF}
	f[0]=0
	g[0]=0
	for(i in 1..n)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var x=tmp_line[0]
		var y=tmp_line[1]
		require(x>=1 && x<=1e9)
		require(y>=2 && y<=1e9 && y%2==0)
		for(j in m downTo 0)
		{
			f[j]=min(f[j],f[max(0,j-x)]+y);
			g[j]=min(g[j],g[max(0,j-x)]+y);
			g[j]=min(g[j],f[max(j-2*x,0)]+y/2);
		}
	}
	println("${g[m]}")
}

