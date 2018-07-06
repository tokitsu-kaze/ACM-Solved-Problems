package work;

public class Line extends Graphical
{
	Spot start,end;
	Line(Spot a,Spot b)
	{
		start=a;end=b;
	}
	public void draw()
	{
		System.out.print("This is line!");
		start.draw(1);
		end.draw(1);
		System.out.print("\n");
	}
	
}
