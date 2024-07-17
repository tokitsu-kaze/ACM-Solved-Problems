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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var t=readint()
	while(t-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var k=tmp_line[1]
		var cnt=0
		while((1 shl cnt)<n) cnt++
		if(k>20 || k>cnt)
		{
			println("-1")
			continue
		}
		var now=1
		var ans=IntArray(n+2){0}
		var res=mutableListOf<Int>()
		for(i in 1..n-((1 shl k)-1))
		{
			ans[i]=now
			now++
		}
		for(i in max(1,n-((1 shl k)-1)+1)..n) res.add(i)
		while(res.size>0)
		{
			if(res.size==1)
			{
				ans[res[0]]=now
				now++
				break
			}
			var i=1
			var tmp=mutableListOf<Int>()
			while(i<res.size)
			{
				ans[res[i]]=now
				now++
				i+=2
			}
			i=0
			while(i<res.size)
			{
				tmp.add(res[i])
				i+=2
			}
			res.clear()
			for(it in tmp) res.add(it)
		}
		for(i in 1..n)
		{
			print("${ans[i]}")
			if(i==n) println()
			else print(" ")
		}
	}
}
