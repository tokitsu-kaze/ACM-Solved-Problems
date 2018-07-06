package work;


public class Manager extends Employee
{
	String department;
	public Manager(String name, double salary,String department)
	{
		super(name, salary);
		this.department =department;
	}
	public String getdate()
	{
		return super.getdate()+"\nDepartment:"+department;
	}
}
