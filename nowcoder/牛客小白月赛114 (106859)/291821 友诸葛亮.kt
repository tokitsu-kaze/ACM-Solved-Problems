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
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var x=tmp_line[0]
	var y=tmp_line[1]
	var z=tmp_line[2]
	require(x>=0 && x<=1e5)
	require(y>=0 && y<=1e5)
	require(z>=0 && z<=1e5)
	var a=readline_int()
	require(a.size==x+y+z)
	var cnt=IntArray(5){0}
	for(it in a) cnt[it]++
	require(cnt[1]==x && cnt[2]==y && cnt[3]==z)
	var res=IntArray(x+y+z){0}
	var tmp=mutableListOf<pair>()
	tmp.add(pair(x,1))
	tmp.add(pair(y,2))
	tmp.add(pair(z,3))
	tmp.sortWith(pair_cmp)
	for(i in 0..a.size-1)
	{
		if(a[i]==tmp[0].se)
		{
			if(tmp[2].fi>0)
			{
				tmp[2].fi--
				res[i]=tmp[2].se
			}
			else if(tmp[1].fi>0)
			{
				tmp[1].fi--
				res[i]=tmp[1].se
			}
			else
			{
				tmp[0].fi--
				res[i]=tmp[0].se
			}
		}
	}
	for(i in 0..a.size-1)
	{
		if(a[i]==tmp[1].se)
		{
			if(tmp[2].fi>0)
			{
				tmp[2].fi--
				res[i]=tmp[2].se
			}
			else if(tmp[0].fi>0)
			{
				tmp[0].fi--
				res[i]=tmp[0].se
			}
			else
			{
				tmp[1].fi--
				res[i]=tmp[1].se
			}
		}
	}
	for(i in 0..a.size-1)
	{
		if(a[i]==tmp[2].se)
		{
			if(tmp[1].fi>0)
			{
				tmp[1].fi--
				res[i]=tmp[1].se
			}
			else if(tmp[0].fi>0)
			{
				tmp[0].fi--
				res[i]=tmp[0].se
			}
			else
			{
				tmp[2].fi--
				res[i]=tmp[2].se
			}
		}
	}
	println(res.joinToString(" "))
}

/*
1 1 2
1 2 3 3

1 2 2
1 2 2 3 3

1 2 2
2 2 3 3 1
*/
