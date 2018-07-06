package work;

import java.util.ArrayList;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Spot a = new Spot(12,23);
		Spot d = new Spot(14,25);
		a.draw();
		Line b = new Line(a,d);
		b.draw();
		Circle c=new Circle(a,8);
		c.draw();
		ArrayList<Graphical> list = new ArrayList<Graphical>(); 
		list.add(a);
		list.add(b);
		list.add(c);
		for(Graphical g:list) g.draw();
	}
}