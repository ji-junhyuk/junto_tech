class MyThread1 extends Thread 
{
	public void run()
	{
		try
		{
			while (true)
			{
				System.out.println("Hello, Thread!");
				Thread.sleep(500);
			}
		}
		catch (InterruptedException ie)
		{
			System.out.println("I'm interrupted");
		}
	}
}

public class ThreadExample1 {

	public static final void main(String[] args)
	{
		MyThread1 thread = new MyThread1();
		thread.start();
		System.out.println("Hello, my child!");
	}
}


