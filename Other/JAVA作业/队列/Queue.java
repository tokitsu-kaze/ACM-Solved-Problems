
public class Queue
{
	int Data[];
	private int front,rear,maxsize;
	public Queue(int maxsize)
	{
		Data=new int[maxsize];
		front=0;
		rear=0;
		this.maxsize=maxsize;
	}
	public void AddQ(int item)
	{
		if((rear+1)%maxsize==front) return;
		else
		{
			rear=(rear+1) % maxsize;
			Data[rear]=item;
		}
	}
	public int DeleteQ()
	{
		if(front==rear) return -1;
		else
		{
			front=(front+1) % maxsize;
			return Data[front];
		}
	}
}