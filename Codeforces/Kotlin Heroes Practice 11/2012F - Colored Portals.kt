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
fun lower_bound_pos(a:MutableList<Int>,target:Int):Int
{
	if(a.size==0) return 0
	var l=0
	var r=a.size-1
	var mid:Int
	while(l<r)
	{
		mid=(l+r) shr 1
		if(a[mid]>=target) r=mid
		else l=mid+1
	}
    if(a[l]>=target) return l
    return a.size
}
fun make_string(a:Char,b:Char):String
{
	var res=""
	res+=a
	res+=b
	return res
}
fun go()
{
	var tmp="BGRY"
	var tot=0
	var id:MutableMap<String,Int> = mutableMapOf()
	for(i in 0..3)
	{
		for(j in 0..3)
		{
			id[make_string(tmp[i],tmp[j])]=tot
			id[make_string(tmp[j],tmp[i])]=tot
			tot++
		}
	}
	var res=mutableListOf<Int>()
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var q=tmp_line[1]
		var s=readline_string()
		var pos=Array(tot+1){mutableListOf<Int>()}
		for(i in 0..n-1) pos[id[s[i]]?:-1].add(i+1)
		while(q-->0)
		{
			tmp_line=readline_int()
			var x=tmp_line[0]
			var y=tmp_line[1]
			if(x==y)
			{
				res.add(0)
				continue
			}
			if(x>y) x=y.also{y=x}
			var ans=INF
			for(i in 0..1)
			{
				for(j in 0..1)
				{
					if(s[x-1][i]==s[y-1][j])
					{
						ans=y-x
						continue
					}
					var nowid=id[make_string(s[x-1][i],s[y-1][j])]?:-1
					var it=lower_bound_pos(pos[nowid],x)
					if(it!=pos[nowid].size)
					{
						var p=pos[nowid][it];
						ans=min(ans,abs(p-x)+abs(p-y));
					}
					if(it!=0)
					{
						it--;
						var p=pos[nowid][it];
						ans=min(ans,abs(p-x)+abs(p-y));
					}
				}
			}
			if(ans==INF) ans=-1
			res.add(ans)
		}
	}
	println(res.joinToString("\n"))
}
