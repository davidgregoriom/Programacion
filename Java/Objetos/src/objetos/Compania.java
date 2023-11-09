package objetos;

import java.util.Arrays;

public class Compania {
	
	private String nombre;

	private Empleado[] empleado= new Empleado[5];

	public Compania(String nombre) {
		this.nombre=nombre;
	}

	public void setEmpleado(Empleado[] empleado) {
		this.empleado = empleado;
	}
	public float getSobreEdad() {
		float sum= 0;
		for(int i=0;i<empleado.length;i++) {
			sum+= empleado[i].getEdad();
		}
		return sum/empleado.length;
	}
	@Override
	public String toString() {
		return "Compania [nombre=" + nombre + ", empleado=" + Arrays.toString(empleado) + "]";
	}

}
