package billar;

import java.util.ArrayList;

public class Mesa {
	private static ArrayList<Pelota> pelotas= new ArrayList<Pelota>();
	private int bolasEquipo1=0, bolasEquipo2=0;
	private int largo , ancho;
	private ArrayList<Jugador> equipo1= new ArrayList<Jugador>();
	private ArrayList<Jugador> equipo2= new ArrayList<Jugador>();
	private Rack pelo;
	
	public Mesa(Rack pelo){
		super();
		this.pelo=pelo;
	}
	
	public static ArrayList<Pelota> getPelotas() {
		return pelotas;
	}

	public static void setPelotas(ArrayList<Pelota> pelotas) {
		Mesa.pelotas = pelotas;
	}

	public int getLargo() {
		return largo;
	}

	public void setLargo(int largo) {
		this.largo = largo;
	}

	public int getAncho() {
		return ancho;
	}

	public void setAncho(int ancho) {
		this.ancho = ancho;
	}

	public ArrayList<Jugador> getEquipo1() {
		return equipo1;
	}

	public void setEquipo1(ArrayList<Jugador> equipo1) {
		this.equipo1 = equipo1;
	}

	public ArrayList<Jugador> getEquipo2() {
		return equipo2;
	}

	public void setEquipo2(ArrayList<Jugador> equipo2) {
		this.equipo2 = equipo2;
	}
	public boolean comprobar() {
		if(!(ancho==100||largo==200)) {
			return false;
		}
		if(bolasEquipo1>9||bolasEquipo2>9) {
			return false;
		}
		if(!(pelo.comprobar())){
			return false;
		}
		return true;
	}
}
