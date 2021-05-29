public class Array1
{
	public static void main(String args[])
	{
		int []list={10,20,30,40,50};
		java.util.Random rand=new java.util.Random();
		int x=rand.nextInt(5);
		int y=rand.nextInt(5);
		int temp=list[x]+list[y];
		System.out.println(x+"  "+y);
		list[x]=temp-list[x];
		list[y]=temp-list[y];
		for(int i:list)
		{
			System.out.print(i+" ");
		}
	}
}