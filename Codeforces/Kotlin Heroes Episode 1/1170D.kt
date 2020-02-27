fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var n=readint()
	var a=readline_int()
	var tot=0
	for(it in a)
	{
		if(it==-1) tot++
	}
	var res=Array(n){mutableListOf<Int>()}
	var s=mutableSetOf<Int>()
	for(i in 0 until tot) s.add(i)
	var tmp=mutableListOf<Int>()
	var pos=0
	while(pos<n)
	{
		tmp.clear()
		for(it in s)
		{
			if(a[pos]==-1) tmp.add(it)
			else res[it].add(a[pos])
			pos++
		}
		for(it in tmp) s.remove(it)
	}
	println("${tot}")
	for(i in 0 until tot)
	{
		print("${res[i].size}")
		for(it in res[i]) print(" ${it}")
		println()
	}
}