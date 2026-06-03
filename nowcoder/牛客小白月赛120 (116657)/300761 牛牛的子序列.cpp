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
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(T>=1 && T<=10)
	var sumn=0
	var summ=0
	var res=mutableListOf<Int>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var m=tmp_line[1]
		require(1<=n && n<=2e5)
		require(1<=m && m<=2e5)
		sumn+=n
		summ+=m
		require(sumn<=2e5)
		require(summ<=2e5)
		var a=readline_int()
		var b=readline_int()
		require(a.size==n)
		require(b.size==m)
		var ra=mutableListOf<Int>()
		var cnta=mutableListOf<Int>()
		var cnt=0
		var pre=-1
		for(it in a)
		{
			if(it==pre) cnt++
			else
			{
				if(pre!=-1)
				{
					ra.add(pre)
					cnta.add(cnt)
				}
				cnt=1
				pre=it
			}
		}
		ra.add(pre)
		cnta.add(cnt)
		
		var rb=mutableListOf<Int>()
		var cntb=mutableListOf<Int>()
		cnt=0
		pre=-1
		for(it in b)
		{
			if(it==pre) cnt++
			else
			{
				if(pre!=-1)
				{
					rb.add(pre)
					cntb.add(cnt)
				}
				cnt=1
				pre=it
			}
		}
		rb.add(pre)
		cntb.add(cnt)
		if(ra.size!=rb.size)
		{
			res.add(-1)
			continue
		}
		var ok=true
		for(i in 0..ra.size-1)
		{
			if(ra[i]!=rb[i]) ok=false
			if(cnta[i]>cntb[i]) ok=false
		}
		if(!ok)
		{
			res.add(-1)
			continue
		}
		var ans=0
		for(i in 0..ra.size-1)
		{
			cnt=0
			while(cnta[i]<cntb[i])
			{
				cnt++
				cnta[i]*=2
			}
			ans=max(ans,cnt)
		}
		res.add(ans)
	}
	println(res.joinToString("\n"))
}

