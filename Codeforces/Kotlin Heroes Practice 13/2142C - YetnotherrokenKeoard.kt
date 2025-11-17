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
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var res=mutableListOf<String>()
	var T=readint()
	while(T-->0)
	{
		var s=readstring()
		var n=s.length
		var ra=mutableListOf<Int>()
		var rb=mutableListOf<Int>()
		for(i in 0..n-1)
		{
			if(s[i]=='b')
			{
				if(ra.size>0) ra.removeLast()
			}
			else if(s[i]=='B')
			{
				if(rb.size>0) rb.removeLast()
			}
			else
			{
				if('a'<=s[i] && s[i]<='z') ra.add(i)
				else rb.add(i)
			}
		}
		var vis=IntArray(n){0}
		for(it in ra) vis[it]=1
		for(it in rb) vis[it]=1
		var ans=mutableListOf<Char>()
		for(i in 0..n-1)
		{
			if(vis[i]==1) ans.add(s[i])
		}
		res.add(ans.joinToString(""))
	}
	println(res.joinToString("\n"))
}

