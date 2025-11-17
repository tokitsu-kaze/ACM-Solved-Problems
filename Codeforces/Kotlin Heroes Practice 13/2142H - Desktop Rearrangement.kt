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
	var res=mutableListOf<Int>()
	var tmp_line=readline_int()
	var n=tmp_line[0]
	var m=tmp_line[1]
	var q=tmp_line[2]
	var mp=mutableListOf<String>()
	for(i in 0..n-1)
	{
		var ss=readstring()
		mp.add(ss)
	}
	var id=Array(n){IntArray(m)}
	var tot=0
	for(j in 0..m-1)
	{
		for(i in 0..n-1)
		{
			id[i][j]=++tot
		}
	}
	var vis=IntArray(tot+2){0}
	var r=0
	
	for(i in 0..n-1)
	{
		for(j in 0..m-1)
		{
			if(mp[i][j]=='*')
			{
				r++
				vis[id[i][j]]=1
			}
		}
	}
	var ans=0
	for(i in r+1..tot) ans+=vis[i]
	while(q-->0)
	{
		tmp_line=readline_int()
		var x=tmp_line[0]
		var y=tmp_line[1]
		x--
		y--
		if(vis[id[x][y]]==1)
		{
			ans+=vis[r]
			r--
			if(id[x][y]>r) ans--
		}
		else
		{
			r++
			ans-=vis[r]
			if(id[x][y]>r) ans++
		}
		vis[id[x][y]]=vis[id[x][y]] xor 1
		res.add(ans)
	}
	println(res.joinToString("\n"))
}

