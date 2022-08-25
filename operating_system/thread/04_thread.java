public class ThreadExample5 {
	public static final void main(String[] args) throws InterruptedException {
		Runnable task = () -> {
			try {
				while (true) {
					System.out.println("Hello, lambda Runnable!");
					Thread.sleep(100);
				}
			}
			catch (InterruptedException ie) {
				System.out.println("I'm interrupted");
			}
		};
		Thread thread = new Thread(task);
		thread.start();
		Thread.sleep(500);
		thread.interrupt();
		System.out.println("Hello, my Interrupted Child!");
	}
}
