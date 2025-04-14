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
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
data class node(var v:Int,var id:Int)
val node_cmp: Comparator<node> = Comparator{ a,b->
	a.v.compareTo(b.v)
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var m=tmp_line[1]
	require(n>=1 && n<=1e6)
	require(m>=1 && m<=1e6)
	var a=readline_int()
	require(a.size==n)
	var b=readline_int()
	require(b.size==m)
	for(it in a) require(it>=-1e9 && it<=1e9)
	for(it in b) require(it>=-1e9 && it<=1e9)
	var res=mutableListOf<node>()
	for(i in 0..n-1) res.add(node(a[i],1))
	for(i in 0..m-1) res.add(node(b[i],2))
	res.add(node(-2e9.toInt(),3))
	res.add(node(2e9.toInt(),3))
	res.sortWith(node_cmp)
	var sa=0L
	var sb=0L
	for(it in a) sa+=it.toLong()
	for(it in b) sb+=it.toLong()
	var nowa=0L
	var nowb=0L
	var cnta=0
	var cntb=0
	var pos=-2e9.toLong()
	var ans=abs((sa-pos*n)-(sb-pos*m))
	var tmp=0L
	var ta=0L
	var tb=0L
	for(i in 0..res.size-1)
	{
		if(res[i].id==1)
		{
			cnta++
			nowa+=res[i].v
		}
		else if(res[i].id==2)
		{
			cntb++
			nowb+=res[i].v
		}
		if(i+1<res.size && res[i].v==res[i+1].v) continue
		var x=res[i].v.toLong()
		if((2*cnta-n)-(2*cntb-m)==0) x=res[i].v.toLong()
		else x=-((sa-2*nowa)-(sb-2*nowb))/((2*cnta-n)-(2*cntb-m))
		for(j in -1..1)
		{
			var k=x+j
			k=max(k,res[i].v.toLong())
			if(i+1<res.size) k=min(k,(res[i+1].v-1).toLong())
			else k=min(k,res[i].v.toLong())
			ta=1L*k*(2*cnta-n)+(sa-2*nowa)
			tb=1L*k*(2*cntb-m)+(sb-2*nowb)
			tmp=abs(ta-tb)
			if(ans>tmp)
			{
				ans=tmp
				pos=k
			}
			else if(ans==tmp) pos=min(pos,k)
		}
	}
	println("${pos}")
}
/*
k*cnta-sum{ai<=k} + sum{ai>k} - k*(n-cnta)
k*(2*cnta-n) - nowa + (sa-nowa)
k*(2*cnta-n) + (sa-2*nowa)

k*((2*cnta-n)-(2*cntb-m)) + ((sa-2*nowa)-(sb-2*nowb))=0
k=-((sa-2*nowa)-(sb-2*nowb))/((2*cnta-n)-(2*cntb-m))
*/

