package threads;

/*public class Launcher extends Thread{
	int numero;
	Launcher (int n) { numero = n; }
	@Override
	public void run() {
		try {
			while (true) {
				System.out.println (numero);
				sleep((long)(1000*Math.random()));
			}
		} catch (InterruptedException e) { return; } // acaba este thread
	}
	public static void main (String args[]) {
		for (int i=0; i<10; i++)
			new Launcher(i).start();//Importante: se lanza con START para crear un nuevo hilo.
	}

}
*/

public class Launcher{
	
	
	
	public static void main (String args[]) {
		PrintDemo PD = new PrintDemo();
		myThread T1= new myThread("Thread -1 ",PD);
		myThread T2= new myThread("Thread -2 ",PD);
		
		T1.start();
		T2.start();
		try {
			T1.join();
			T2.join();
		}catch(Exception e) {
			System.out.println("Interrupted");
		}
	}
}