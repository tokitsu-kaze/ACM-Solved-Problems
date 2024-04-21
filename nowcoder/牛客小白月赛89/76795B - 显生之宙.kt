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
fun go()
{
	var t=readint()
	require(t>=1 && t<=1e5)
	var ans=LongArray(t)
	var sumn=0
	for(cas in 0..t-1)
	{
		var n=readint()
		require(n>=1 && n<=5e5)
		sumn+=n
		require(sumn<=5e5)
		var a=readline_int().sorted()
		var now=0L
		var x=0L
		ans[cas]=0L
		for(it in a)
		{
			require(it>=-1e9 && it<=1e9)
			x=it+now
			if(x>0)
			{
				ans[cas]+=x
				x=0
			}
			else now+=x
		}
		ans[cas]+=x
	}
	println(ans.joinToString("\n"))
}

