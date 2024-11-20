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
	var res=mutableListOf<Long>()
	var T=readint()
	while(T-->0)
	{
		var n=readint()
		var a=readline_int()
		var pre=IntArray(n+2){-1}
		var ans=0L
		var now=0
		var pos=IntArray(n+2){0}
		var top=0
		for(i in 0..n-1)
		{
			while(top>0)
			{
				if(abs(a[i]-a[pos[top]])<=1) break
				if(pre[a[i]-1]>=pos[top] || pre[a[i]+1]>=pos[top] || pre[a[i]]>=pos[top]) break;
				top--
			}
			top++
			pos[top]=i
			pre[a[i]]=i
			ans+=top;
		}
		res.add(ans)
	}
	println(res.joinToString("\n"))
}
/*
8
3
1 1 3
4
3 2 3 1
1
1
8
4 5 6 5 3 2 3 1
3
3 1 2
4
2 3 1 2
5
2 3 3 1 2
4
4 3 1 2

5 4 3 3 5 4 1 2
*/
