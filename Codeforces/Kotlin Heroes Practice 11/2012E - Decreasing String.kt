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
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	var res=""
	while(T-->0)
	{
		var s=" "+readstring()
		var k=readll()
		var n=s.length-1
		var l=IntArray(n+3){0}
		var r=IntArray(n+3){0}
		var vis=BooleanArray(n+3){false}
		for(i in 0..n+1)
		{
			l[i]=i-1
			r[i]=i+1
		}
		var q=PriorityQueue<Int>()
		for(i in 1..n-1)
		{
			if(s[i]>s[i+1]) q.add(i)
		}
		var now=n.toLong()
		while(q.size>0)
		{
			if(k-now<=0) break
			k-=now
			now--
			var x=q.peek()
			q.poll()
			if(l[x]>=1) r[l[x]]=r[x]
			if(r[x]<=n) l[r[x]]=l[x]
			vis[x]=true
			x=l[x]
			if(x>=1 && r[x]<=n)
			{
				if(s[x]>s[r[x]]) q.add(x)
			}
		}
		while(now>1 && k-now>0)
		{
			k-=now
			now--
		}
		for(i in 1..n)
		{
			if(vis[i]) continue
			k--
			if(k==0L)
			{
				res+=s[i]
				break
			}
		}
	}
	println(res)
}
