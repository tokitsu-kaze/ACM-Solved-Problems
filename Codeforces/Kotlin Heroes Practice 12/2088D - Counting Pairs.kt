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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun lower_bound_pos(a:LongArray,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
fun upper_bound_pos(a:LongArray,target:Long):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]<=target) l=mid+1
		else r=mid
	}
	if(a[l]>target) return l
    return a.size
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_ll()
		var n=tmp_line[0].toInt()
		var x=tmp_line[1]
		var y=tmp_line[2]
		var sum=0L
		var a=readline_ll().sorted().toLongArray()
		for(it in a) sum=sum+it
		var ans=0L
		for(i in 0..n-1)
		{
			var r=upper_bound_pos(a,sum-a[i]-x)
			var l=lower_bound_pos(a,sum-a[i]-y)+1
			ans=ans+max(0,r-max(i+2,l)+1)
		}
		println("${ans}")
	}
}
