import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
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
var pos=Array(MAX){mutableListOf<Int>()}
fun go()
{
	var sumn=0
	var summ=0
	var t=readint()
	require(t>=1 && t<=1e5)
	while(t-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(n>=1 && n<=1e5)
		require(m>=1 && m<=1e5)
		sumn+=n
		summ+=m
		require(sumn>=1 && sumn<=2e5)
		require(summ>=1 && summ<=2e5)
		var a=readline_int()
		require(a.size==n)
		var del=mutableListOf<Int>()
		for(i in 0..n-1)
		{
			require(a[i]>=1 && a[i]<=1e6)
			del.add(a[i])
			pos[a[i]].add(i)
		}
		while(m-->0)
		{
			tmp_line=readline_int()
			require(tmp_line.size==2)
			var x=tmp_line[0]
			var y=tmp_line[1]
			require(x>=1 && x<=1e6)
			require(y>=1 && y<=1e6)
			if(x==y) continue
			if(pos[x].size<pos[y].size)
			{
				for(it in pos[x]) pos[y].add(it)
				pos[x].clear()
			}
			else
			{
				for(it in pos[y]) pos[x].add(it)
				pos[y].clear()
				pos[x]=pos[y].also{pos[y]=pos[x]}
			}
			del.add(y)
		}
		for(it in del)
		{
			for(p in pos[it])
			{
				a[p]=it
			}
			pos[it].clear()
		}
		println(a.joinToString(" "))
	}
}

