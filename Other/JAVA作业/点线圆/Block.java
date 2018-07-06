package work;

import java.util.ArrayList;

public class Block extends Graphical
{
	private ArrayList<Graphical> list;
	public Block(){}
	public Block(ArrayList<Graphical> list)
	{
		super();
		this.list=list;
	}
	
	@Override
	public void draw()
	{
		// TODO Auto-generated method stub
		for( Graphical list: list)
		{
 			list.draw();
 		}
	}

}
