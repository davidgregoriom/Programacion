package billar;

import java.util.ArrayList;

public class Rack {
	private ArrayList<Pelota> pelotas= new ArrayList<Pelota>();
	private int id;
	private ArrayList<Pelota> azul= new ArrayList<Pelota>();
	private ArrayList<Pelota> amarillo= new ArrayList<Pelota>();
	private ArrayList<Pelota> verde= new ArrayList<Pelota>();
	private ArrayList<Pelota> rojo= new ArrayList<Pelota>();
	private ArrayList<Pelota> negro= new ArrayList<Pelota>();

	public ArrayList<Pelota> getPelotas() {
		return this.pelotas;
	}
	public void setPelotas(ArrayList<Pelota> pelotas) {
		this.pelotas = pelotas;
	}
	public int getId() {
		return this.id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public boolean comprobar() {
		if(pelotas.size()!=15) {
			return false;
		}
		int azul=0,amarillo=0,verde=0,rojo=0,negro=0;
		for(Pelota pelota:pelotas) {
			Color cl= Color.negro;
			pelota.cl= cl;
			switch(cl) {
				case azul:
					azul++;
					break;
				case amarillo:
					amarillo++;
					break;
				case verde:
					verde++;
					break;
				case rojo:
					rojo++;
					break;
				case negro:
					negro++;
					break;
			}
		}
		if(!(azul>0&&amarillo>0&&verde>0&&rojo>0&&negro>0)) {
			return false;
		}
		
		return true;
	}
}
