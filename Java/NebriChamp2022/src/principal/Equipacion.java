package principal;

public abstract class Equipacion {
	protected static int numero;
	public Equipacion(int dorsal) {
		this.numero=dorsal;
	}

	public int getNumero(){
		return numero;
	}
}

class Pantalon extends Equipacion {

	public Pantalon() {
		super(numero);
		// TODO Auto-generated constructor stub
	}
	  // Implementaci�n espec�fica para pantalones
}

class Camiseta extends Equipacion {

	public Camiseta() {
		super(numero);
		// TODO Auto-generated constructor stub
	}
  // Implementaci�n espec�fica para camisetas
}

class Zapatillas extends Equipacion {

	public Zapatillas() {
		super(numero);
		// TODO Auto-generated constructor stub
	}
  // Implementaci�n espec�fica para zapatillas
}

class Guantes extends Equipacion {
  
	public Guantes() {
		super(numero);
		// TODO Auto-generated constructor stub
	}
}
