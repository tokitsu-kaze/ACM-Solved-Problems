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
/*------------------------------------------------------------*/
data class node(var v:Int)
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(n>=1 && n<=1e5)
	require(q>=1 && q<=100)
	var a=readline_int()
	require(a.size==n)
	var b=readline_int()
	require(b.size==n)
	for(i in 0..n-1)
	{
		require(a[i]>=1 && a[i]<=1e9)
		require(b[i]>=1 && b[i]<=1e9)
	}
	while(q-->0)
	{
		var k=readint()
		require(k>=1 && k<=n)
		var ans=LLINF
		var pq=PriorityQueue<node>(compareBy({it.v}))
		var sa=0L
		var sb=0L
		for(i in 0..n-1)
		{
			sa+=a[i]
			sb+=b[i]
			pq.add(node(-b[i]))
			if(pq.size>k)
			{
				sb+=pq.peek().v
				pq.poll()
			}
			if(pq.size==k) ans=min(ans,sa+sb)
		}
		while(pq.size>0) pq.poll()
		println("${ans}")
	}
}

