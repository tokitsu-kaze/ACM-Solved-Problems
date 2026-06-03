import java.util.*
import kotlin.math.*
import kotlin.random.Random

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
const val MAX=1e7.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var k=tmp_line[2]
		var a=readline_int()
		var q=readline_int()
		var vis=IntArray(n+1){0}
		var res=CharArray(m){'0'}
		if(k==n)
		{
			for(i in 0..m-1) res[i]='1'
		}
		else if(k<n-1)
		{
			for(i in 0..m-1) res[i]='0'
		}
		else
		{
			for(i in 0..k-1) vis[q[i]]=1
			for(i in 0..m-1)
			{
				if(vis[a[i]]==0) res[i]='1'
				else res[i]='0'
			}
		}
		println(res.joinToString(""))
	}
}
