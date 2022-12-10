fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
data class pair(var fi:Int,var se:Int)
fun main()
{
	var tmp=readline_int()
	var n=tmp[0]
	var m=tmp[1]
	tmp=readline_int()
	var v:MutableList<pair> =mutableListOf()
	for(i in 0 until n) v.add(pair(tmp[i],i))
	v.sortBy({it.fi})
	var now=1
	var ans=Array(200005){0}
	ans[v[0].se]=now-1
	for(i in 1 until n)
	{
		if(v[i].fi!=v[i-1].fi) now=i+1
		ans[v[i].se]=now-1
	}
	while(m-->0)
	{
		var tt=readline_int()
		var a=tt[0]
		var b=tt[1]
		a--
		b--
		if(tmp[a]<tmp[b]) ans[b]--
		else if(tmp[a]>tmp[b]) ans[a]--
	}
	for(i in 0 until n) print("${ans[i]} ")
}
