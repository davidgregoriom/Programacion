package threads;

public class myThread extends Thread{
	
	private
	Thread t;
	String threadName;
	PrintDemo PD;
	
	myThread(String name, PrintDemo pd){
		threadName = name;
		PD = pd;
	}
	

	@Override
	public void run() {
		synchronized(PD) {//si elimino esto...
			PD.printCount();
		}
		System.out.println("Thread"+threadName+"existiendo.");
	}
	public void start() {
		System.out.println("Empezando"+threadName);
		if(t==null) {
			t=new Thread(this,threadName);
			t.start();
		}
	}
	
}
