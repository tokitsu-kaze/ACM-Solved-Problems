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
	while(T-->0)
	{
		var n=readint()
		var a=IntArray(n+3){0}
		var d=IntArray(n+3){0}
		var tmp_line=readline_int()
		for(i in 1..n) a[i]=tmp_line[i-1]
		tmp_line=readline_int()
		for(i in 1..n) d[i]=tmp_line[i-1]
		var l=IntArray(n+3){0}
		var r=IntArray(n+3){0}
		for(i in 0..n+1)
		{
			l[i]=i-1
			r[i]=i+1
		}
		l[0]=0
		r[n+1]=n+1
		a[0]=0
		a[n+1]=0
		var flag=BooleanArray(n+3){false}
		val q:Queue<Int> = LinkedList()
		for(i in 1..n)
		{
			if(a[i-1]+a[i+1]>d[i])
			{
				q.offer(i)
				flag[i]=true
			}
		}
		var res=mutableListOf<Int>()
		for(i in 1..n)
		{
			var ans=q.size
			res.add(ans)
			var tmp=mutableListOf<Int>()
			while(ans-->0)
			{
				var x=q.peek()
				q.poll()
				r[l[x]]=r[x]
				l[r[x]]=l[x]
				tmp.add(l[x])
				tmp.add(r[x])
			}
			for(it in tmp)
			{
				if(it>=1 && it<=n && flag[it]==false)
				{
					if(a[l[it]]+a[r[it]]>d[it])
					{
						q.offer(it)
						flag[it]=true
					}
				}
			}
		}
		println(res.joinToString(" "))
	}
}
