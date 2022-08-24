public class ThreadExample04 {
	public static final void main(String[] args) {
		Runnable task = () -> {
			for (int i = 0; i < 5; i++) {
				System.out.println("Hello, Lambda Runnable!");
			}
		};
		Thread thread = new Thread(task);
		thread.start();
		try {
			thread.join(); // wait
		}
		catch (InterruptedException ie) {
			System.out.println("Parent thread is interrupted");
		}
		System.out.println("Hello, My Joined Child!");
	}
}
