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
fun ck(it:Char):Boolean
{
	return (it>='a'&&it<='z') || (it>='A'&&it<='Z') || (it>='0'&&it<='9')
}
data class node(var col:Int,var name:Int)
fun go()
{
	var tmp_line=readline_int()
	require(tmp_line.size==3)
	var n=tmp_line[0]
	var m=tmp_line[1]
	var k=tmp_line[2]
	require(n>=2 && n<=1e5)
	require(m>=2 && m<=n)
	require(k>=2 && k<=n)
	var sumlen=0
	var ha:MutableMap<String,Int> = mutableMapOf()
	var rha=mutableListOf<String>()
	var hatot=0
	var all:MutableMap<node,Int> = mutableMapOf()
	for(i in 1..n)
	{
		var tmp_line2=readline_string()
		require(tmp_line2.size==2)
		var col=tmp_line2[0]
		var name=tmp_line2[1]
		sumlen+=col.length
		sumlen+=name.length
		require(sumlen<=1e6)
		for(it in col) require(ck(it))
		for(it in name) require(ck(it))
		ha[col]=ha[col]?:-1
		if(ha[col]==-1)
		{
			ha[col]=hatot
			hatot++
			rha.add(col)
		}
		ha[name]=ha[name]?:-1
		if(ha[name]==-1)
		{
			ha[name]=hatot
			hatot++
			rha.add(name)
		}
		var col_id=ha[col]?:-1
		var name_id=ha[name]?:-1
		all[node(col_id,name_id)]=(all[node(col_id,name_id)]?:0)+1
	}
	var col_list=Array(hatot){mutableListOf<Int>()}
	for(it in all.keys) col_list[it.name].add(it.col)
	var now:MutableMap<node,Int> = mutableMapOf()
	for(i in 1..m)
	{
		var tmp_line2=readline_string()
		require(tmp_line2.size==2)
		var col=tmp_line2[0]
		var name=tmp_line2[1]
		sumlen+=col.length
		sumlen+=name.length
		require(sumlen<=1e6)
		for(it in col) require(ck(it))
		for(it in name) require(ck(it))
		var col_id=ha[col]?:-1
		var name_id=ha[name]?:-1
		require(all.containsKey(node(col_id,name_id)))
		now[node(col_id,name_id)]=(now[node(col_id,name_id)]?:0)+1
		require((now[node(col_id,name_id)]?:INF)<=(all[node(col_id,name_id)]?:0))
	}
	var col_set:MutableMap<Int,Int> = mutableMapOf()
	for(i in 1..k)
	{
		var col=readstring()
		sumlen+=col.length
		require(sumlen<=1e6)
		for(it in col) require(ck(it))
		if(!ha.containsKey(col)) continue
		var col_id=ha[col]?:-1
		col_set[col_id]=now[col_id]?:1
	}
	for(i in 0..hatot-1)
	{
		var name_id=i
		var now_col=-1
		var to_col=-1
		for(col_id in col_list[i])
		{
			var cnt=now[node(col_id,name_id)]?:0
			if(cnt>0 && col_set.containsKey(col_id) && now.size>1)
			{
				now_col=col_id
				to_col=col_id
				break
			}
			if(cnt>0 && now_col==-1) now_col=col_id
			if(!col_set.containsKey(col_id)) continue
			if(now_col!=col_id && cnt<(all[node(col_id,name_id)]?:0))
			{
				to_col=col_id
			}
		}
		if(now_col!=-1 && to_col!=-1)
		{
			println("Yes")
			print(rha[now_col])
			print(" ")
			println(rha[name_id])
			print(rha[to_col])
			print(" ")
			println(rha[name_id])
			return
		}
	}
	println("No")
}
/*
牌库 花色 名字
手上 花色 名字
可替换花色

枚举名字

遍历该名字的所有花色
做一些判断
换

2 2 2
sjf a
fjs b
sjf a
fjs b
sjf
sjf

*/
