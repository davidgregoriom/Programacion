package ejercicio_1al4;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
/**
 * 
 * @author david
 * ASI SE IMPLEMENTA SINGLETON
 * 
 */
/*
//Apartado 1(lazy)
public class Server {
	
	private static Server instance;

	public static Server getInstance() {
		if(instance == null) {
			synchronized(Server.class) {
				//Apartado 2(utilizable en una aplicación multiproceso)
				if(instance==null) {
					instance=new Server();
				}
			}

			
			
		}
		return instance;
	}
	
	//Apartado 3(eager)
	private static final Server INSTANCE =new Server();
	
	public Server getInstance() {
		return INSTANCE;
	}
	private final List<String> serverlista;
	
	private Server() {
		serverlista= new ArrayList<>();
	}
	*/

//Apartado 4 (enum)
public enum Server{
	INSTANCE;
	
	private final List<String> serverlista;
	
	Server(){
		serverlista=new ArrayList<>();
	}
	
	
	public boolean addServers(final String servers) {
		if((servers.startsWith("http") || servers.startsWith("https")) && !serverlista.contains(servers)) {
			return serverlista.add(servers);
		}
		return false;
	}
	public List<String>getHttpServidor(){
		return serverlista.stream().filter(servers->servers.startsWith("http")).collect(Collectors.toUnmodifiableList());
	}
	private List<String>getServidorEncendido(final String prefix){
		return serverlista.stream().filter(server -> server.startsWith(prefix)).collect(Collectors.toUnmodifiableList());
	}
	public List<String>getHttpsServidor(){
		return serverlista.stream().filter(servers->servers.startsWith("https")).collect(Collectors.toUnmodifiableList());
	}
}
