package objetos;

public class Empleado {

	@Override
	public String toString() {
		return "Empleado [Nombre=" + Nombre + ", Apellido=" + Apellido + ", edad=" + edad + "]";
	}
	private String Nombre,Apellido;
	private int edad;


	public int getEdad() {
		return edad;
	}
	public Empleado(String nombre, String apellido, int edad) {
		super();
		this.Nombre = nombre;
		this.Apellido = apellido;
		this.edad = edad;
	}
}
