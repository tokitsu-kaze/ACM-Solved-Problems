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
const val MAX=1e5.toInt()+10
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
class hash_table
{
	var m=0
	var ha1=LongArray(1)
	var ha2=LongArray(1)
	var t1=LongArray(1)
	var t2=LongArray(1)
	val p1=1e9.toLong()+9L
	val p2=998244353L
	val sd1=131L
	val sd2=233L
	val offset=1e9.toLong()
	fun init(n:Int)
	{
		t1=LongArray(n+5)
		t2=LongArray(n+5)
		t1[0]=1L
		t2[0]=1L
		m=n
		for(i in 1..m)
		{
			t1[i]=t1[i-1]*sd1%p1
			t2[i]=t2[i-1]*sd2%p2
		}
	}
	fun work(s:String,n:Int)
	{
		require(m>=n)
		ha1=LongArray(n+5)
		ha2=LongArray(n+5)
		ha1[0]=0
		ha2[0]=0
		for(i in 1..n)
		{
			ha1[i]=(ha1[i-1]*sd1+s[i-1].toLong())%p1
			ha2[i]=(ha2[i-1]*sd2+s[i-1].toLong())%p2
		}
	}
	fun get(l:Int,r:Int):Long
	{
		var res1=(ha1[r]-ha1[l-1]*t1[r-l+1])%p1
		if(res1<0) res1+=p1
		var res2=(ha2[r]-ha2[l-1]*t2[r-l+1])%p2
		if(res2<0) res2+=p2
		var res=res1*offset+res2
		return res
	}
}
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(n>=1 && n<=1e5)
	require(q>=1 && q<=1e5)
	var s=readstring()
	var mp:Array<MutableMap<Long,TreeSet<pair>>> = Array(n+2){mutableMapOf()}
	var ha=hash_table()
	ha.init(MAX)
	var len_set=TreeSet<Int>()
	for(i in 0..q-1)
	{
		var q_line=readstring().split(" ")
		require(q_line.size==2)
		var t=q_line[0]
		var k=q_line[1].toInt()
		ha.work(t,t.length)
		mp[t.length].getOrPut(ha.get(1,t.length)){TreeSet<pair>(cmp)}.add(pair(k,i))
		len_set.add(t.length)
	}
	ha.work(s,n)
	var ans=IntArray(q){-1}
	var cnt:Array<MutableMap<Long,Int>> = Array(n+2){mutableMapOf()}
	for(i in 1..n)
	{
		for(len in len_set)
		{
			if(len>i) break
			var res=ha.get(i-len+1,i)
			var now_set=mp[len][res]?:TreeSet<pair>(cmp)
			if(now_set.size==0) continue
			cnt[len][res]=(cnt[len][res]?:0)+1
			var tmp=cnt[len][res]?:0
			while(true)
			{
				var now=now_set.ceiling(pair(tmp,0))
				if(now==null) break
				if(now.fi>tmp) break
				ans[now.se]=i
				now_set.remove(now)
			}
		}
	}
	println(ans.joinToString("\n"))
}

