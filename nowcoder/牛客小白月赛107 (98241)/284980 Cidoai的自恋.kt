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
const val MAX=300000+10
/*------------------------------------------------------------*/
var seed=0L
fun rnd():Long
{
	var p=(1L shl 32)
	var res=seed
	seed=(seed xor ((seed shl 13) and (p-1))) and (p-1)
	seed=(seed xor ((seed shr 17) and (p-1))) and (p-1)
	seed=(seed xor ((seed shl 5) and (p-1))) and (p-1)
	return res
}
/*
fun go()
{
	var tmp_line=readline_ll()
	var n=tmp_line[0].toInt()
	var k=tmp_line[1].toInt()
	seed=tmp_line[2]
	var a=IntArray(k)
	for(i in 0..k-1) a[i]=(rnd()%n).toInt()+1
//	println(a.joinToString(" "))
	var res=IntArray(n+5){0}
	var s=TreeSet<Int>()
	s.add(INF)
	s.add(0)
	for(i in 0..k-1)
	{
		var tmp=s.ceiling(a[i])
		if(tmp+1<=n)
		{
			res[tmp+1]++
			res[n+1]--
		}
		tmp=s.floor(a[i])
		if(tmp>=1)
		{
			res[1]++
			res[tmp]--
		}
		s.add(a[i])
	}
	for(i in 1..n) res[i]+=res[i-1]
	for(it in a) res[it]=-1
	var pos=1
	for(i in 1..n)
	{
		if(res[i]>res[pos]) pos=i
	}
	println("${pos}")
}

*/
fun go()
{
	var tmp_line=readline_ll()
	require(tmp_line.size==3)
	var n=tmp_line[0].toInt()
	var k=tmp_line[1].toInt()
	seed=tmp_line[2]
	require(n>=1 && n<=5e6)
	require(k>=1 && k<=5e6)
	require(seed>=0 && seed<(1L shl 32))
	var a=IntArray(k)
	var p=IntArray(n+1){0}
	for(i in 0..k-1)
	{
		a[i]=(rnd()%n).toInt()+1
		if(p[a[i]]==0) p[a[i]]=i+1
	}
//	println(a.joinToString(" "))
	var st=IntArray(k)
	var top=0
	var res=IntArray(n+5){0}
	for(i in 1..n)
	{
		if(p[i]==0) continue
		while(top>0 && p[st[top-1]]>p[i]) top--
		if(top>0)
		{
			res[1]++
			res[st[top-1]]--
		}
		st[top]=i
		top++
	}
	top=0
	for(i in n downTo 1)
	{
		if(p[i]==0) continue
		while(top>0 && p[st[top-1]]>p[i]) top--
		if(top>0)
		{
			res[st[top-1]+1]++
			res[n+1]--
		}
		st[top]=i
		top++
	}
	for(i in 1..n) res[i]+=res[i-1]
	for(it in a) res[it]=-1
	var pos=1
	for(i in 1..n)
	{
		if(res[i]>res[pos]) pos=i
	}
	require(res[pos]!=-1)
	println("${pos}")
}
/*
x>ai>aj
x<ai<aj
*/
