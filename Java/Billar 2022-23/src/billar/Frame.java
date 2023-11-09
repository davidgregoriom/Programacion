package billar;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Frame extends JFrame{
	public static void exFramePane() {
		JFrame frame= new JFrame();
	    frame.setTitle("Billar");
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    frame.setBounds(100, 100, 1000,500);//(pos_pantalla(x,y), size(x,y))


	    Imagen imagen = new Imagen();
	    frame.add(imagen);
	    frame.repaint();
	   

	    frame.setVisible(true);

	    
			
	};
	
	public static class Imagen extends JPanel{//http://panamahitek.com/insertar-una-imagen-dentro-de-un-jpanel-en-java/
		JPanel contentPane = new JPanel();
	    public Imagen() {
		  contentPane.setSize(860,470);
	    }
		public void paint(Graphics grafico) {
		   Dimension height=getSize();
		   ImageIcon Img = new ImageIcon(getClass().getResource("F:\\Universidad\\Tecnicas de Programación Avanzada\\Billar 2022-23\\imagenes\\billar.jpg"));
		   grafico.drawImage(Img.getImage(), 0, 0, height.width, height.height, null);
		
		   setOpaque(false);
		   super.paintComponent(grafico);
		}
	}
	
}
