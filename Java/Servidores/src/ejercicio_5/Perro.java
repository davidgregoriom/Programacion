package ejercicio_5;

import java.util.List;
/**
 * 
 * @author david
 * Apartado 5 
 * ASI SE IMPLEMENTA BUILDER
 */
public class Perro {

	private String nombre,tipo;
	

	private Integer edad;
	private List<String> juguetes;
	
	protected Perro(String nombre, String tipo, Integer edad, List<String> juguetes) {
		super();
		this.nombre = nombre;
		this.tipo = tipo;
		this.edad = edad;
		this.juguetes = juguetes;
	}
	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Integer getEdad() {
		return edad;
	}

	public void setEdad(Integer edad) {
		this.edad = edad;
	}

	public List<String> getJuguetes() {
		return juguetes;
	}

	public void setJuguetes(List<String> juguetes) {
		this.juguetes = juguetes;
	}
	public static class Constructor{
		private String nombre,tipo;
		private Integer edad;
		private List<String> juguete;
		
		public Constructor conNombre(String nombre) {
			this.nombre = nombre;
			return this;
		}
		public Constructor conTipo(String tipo) {
			this.tipo = tipo;
			return this;
		}
		public Constructor conEdad(Integer edad) {
			this.edad = edad;
			return this;
		}
		public Constructor conTipo(List<String> juguete) {
			this.juguete = juguete;
			return this;
		}
		public Perro construir() {
			return new Perro(nombre,tipo,edad,juguete);
		}
	}
	
}
