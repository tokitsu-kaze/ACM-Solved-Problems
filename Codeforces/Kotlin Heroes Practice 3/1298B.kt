fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun main()
{
	var n=readint()
	var a=readline_int()
	var flag=Array(1010){0}
	var res=mutableListOf<Int>()
	for(i in n-1 downTo 0)
	{
		if(flag[a[i]]==0)
		{
			flag[a[i]]=1
			res.add(a[i])
		}
	}
	println("${res.size}")
	for(i in res.size-1 downTo 0) print("${res[i]} ")
}
