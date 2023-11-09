package objetos;

import java.time.LocalDate;
import java.util.Scanner;
import java.util.regex.Pattern;

import objetos.Rectangle;
import objetos.Compania;
import objetos.Empleado;

public abstract class Launcher {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*int a=5;
		int b=2;
		int c=3;
		int result1= a-b-c;
		System.out.println(result1);

		long d = 52L;
		long e = 12L;
		long f = 109L;
		long result2=d*e/f;
		System.out.println(result2);



		final int finalint=5;
		final String finalString ="Ole";
		final boolean finalBoolean = true;
		final long finalLong=12L;
		final float finalFloat=5f;

		System.out.println(finalint+ finalString+finalBoolean+finalLong+finalFloat);



		int intVar1=35;
		int intVar2=54;

		short shortSum=(short)(intVar1+intVar2);
		System.out.println(shortSum);
		System.out.println(shortSum++);
		byte byteSum =(byte)(intVar1+intVar2);
		System.out.println(byteSum);
		System.out.println(++byteSum);



		String str1="Primer String ";
		String str2="Segundo String";
		String str3="Tercer String";
		String sum=str1.concat(str2).concat(str3);
		System.out.println(sum);
		String sum2=str1+str2+str3;
		System.out.println(sum2);


		String str1="Mirame";
		String str2="Mirame";

		boolean result =str1.equals(str2);

		System.out.println(result);



		int var=1;
		if(var%2==0) {
			System.out.println("evento numero");
		}else if(var<10){
			System.out.println("coge algo mas grande macho");
		}else{
			System.out.println("evento equivocado");
		}

		int i=1;
		while (i<100) {
			System.out.println(i++);
		}

		int sum=0;
		for(int i=5;i<460*2+1;i=i+2){
			sum=sum+i;
		}
		System.out.println(sum);


		int n=10;
		for(int i=0;i<n;i++){
			for(int j=0;j<i+1;j++){
				System.out.print("*");
			}
			System.out.println();
		}

		int n=2;
		int m=3;
		//String [] names =new String[n];
		int[][] tab = new int[n][m];
		int valor=0;
		//Scanner scanner = new Scanner(System.in);
		for(int i=0; i<n;i++) {
			//System.out.print("Enter the name: ");
			//names[i]=scanner.nextLine();
			//System.out.print("Mete tu numero");
			//tab[i][i]=scanner.nextInt();
			for(int j=0;j<m;j++) {
				tab[i][j]=valor++;
			}
		}
		//float sum=0;
		System.out.println(multiple(3,4,5));

		for(int i=0;i<tab.length;i++) {
			for(int j=0; j<tab[i].length;j++) {
				System.out.print(i+j+tab[i][j]);
			}
			//System.out.println(names[i]);
			//sum +=  tab[i][i];
			System.out.println();
		}
		//System.out.println("a a: "+(float)(sum/tab.length));
		 
		//String[] hola= new String[5];
		//getDistinct(hola);
		//Rectangle rectangulo =new Rectangle(15,30);
		//System.out.println(rectangulo.getArea());
		//System.out.println(rectangulo.getPerimetro());
		Empleado [] empleado = new Empleado[] {
				new Empleado("Ana","Martin",23),
				new Empleado("Maria","Benito",35),
				new Empleado("Lucia","Montero",19),
				new Empleado("Carla-Maria","Villaseca",16),
				new Empleado("Joseja","Moro",65),
		};
		Compania compania= new Compania("VerdeJoseja");
		compania.setEmpleado(empleado);
		System.out.println(compania);
		System.out.println(compania.getSobreEdad());
		*/
		System.out.println(sum(5));
		System.out.println(sum(5,5));
		System.out.println(sum(5,5,6));
		System.out.println(sum(5,5,6,9));
		LocalDate date= LocalDate.of(2020, 06, 20);
		Pattern patterns = Pattern.compile(null);
		
	}
	private static int sum(int ...s) {
		// TODO Auto-generated method stub
		int sum=0;
		for(int i=0; i<s.length;i++) {
			sum+=s[i];
		}
		return sum;
	}
	/*
	private static int multiple(int a,int b,int c) {
		// TODO Auto-generated method stub
		return a*b*c;
	}
	 */
	
	
	public static String[] getDistinct(String[] table) {

		String [] out = new String[table.length];
		int k=0;
		for(int i=0;i<table.length;i++) {
			boolean found= false;
			for(int j=0;j<out.length;j++) {
				if(table[i].equals(out[j])) {
					found=true;
					break;
				}
			}
			if(!found) {
				out[k++]=table[i];
			}
		}
		return out;
	}
}
