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
data class node(var x:Int,var y:Int)
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var x=IntArray(n*m+1){0}
		var y=IntArray(n*m+1){0}
		var a=Array<node>(n*m+1){node(0,0)}
		var b=Array<node>(n*m+1){node(0,0)}
		for(i in 1..n)
		{
			var mp=readline_int()
			for(j in 1..m)
			{
				a[mp[j-1]]=node(i,j)
			}
		}
		for(i in 1..n)
		{
			var mp=readline_int()
			for(j in 1..m)
			{
				b[mp[j-1]]=node(i,j)
				x[a[mp[j-1]].x]=i
				y[a[mp[j-1]].y]=j
			}
		}
		var f=1
		for(i in 1..n)
		{
			if(x[i]==0) f=0
		}
		for(i in 1..m)
		{
			if(y[i]==0) f=0
		}
		for(i in 1..n*m)
		{
			if(x[a[i].x]!=b[i].x || y[a[i].y]!=b[i].y) f=0
		}
		if(f==1) println("YES")
		else println("NO")
	}
}

