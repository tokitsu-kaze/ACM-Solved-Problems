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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
data class node(var s:String,var cnt:Int)
fun go()
{
	var n=readint()
	require(n>=1 && n<=1e5)
	var sumlen=0
	var res=mutableListOf<node>()
	var pre=""
	var now=0
	for(i in 1..n)
	{
		var s=readstring()
		sumlen+=s.length
		require(sumlen<=1e6)
		if(s==pre) now++
		else
		{
			if(pre!="") res.add(node(pre,now))
			pre=s
			now=1
		}
	}
	res.add(node(pre,now))
	var ans=res[0].cnt
	for(i in 1..res.size-2)
	{
		ans=max(ans,res[i].cnt)
		if(res[i].cnt==1)
		{
			if(res[i-1].s==res[i+1].s)
			{
				ans=max(ans,res[i-1].cnt+res[i+1].cnt)
			}
		}
	}
	ans=max(ans,res[res.size-1].cnt)
	println("${ans}")
}

