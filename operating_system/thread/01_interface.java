class MyThread2 implements Runnable {
	public void run() {
		try {
			while (true) {
				System.out.println("Hello, Runnable!");
				Thread.sleep(500);
			}
		}
		catch (InterruptedException ie) {
			System.out.println("I'm interrupted");
		}
	}
}

public class ThreadExample2 {
	public static final void main(String[] args) {
		Thread thread = new Thread(new MyThread2());
		thread.start();
		System.out.println("Hello, My runnable Child!");
	}
}
