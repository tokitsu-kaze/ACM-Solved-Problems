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
		var s=readstring().toCharArray()
		var p0=-1
		var p1=-1
		for(i in 0..s.size-1)
		{
			if(s[i]=='-')
			{
				p0=i
				break
			}
		}
		for(i in s.size-1 downTo 0)
		{
			if(s[i]=='+')
			{
				p1=i
				break
			}
		}
		if(p0==-1||p1==-1||p0>p1)
		{
			p0=0
			p1=0
		}
		s[p0]=s[p1].also{s[p1]=s[p0]}
		var cnt=0
		var ok=1
		for(it in s)
		{
			if(it=='+') cnt++
			else cnt--
			if(cnt<0) ok=0
		}
		if(ok==1) println("${p0+1} ${p1+1}")
		else println("-1")
	}
}
