package objetos;

public class Rectangle {
	private int a,b;

	public Rectangle(int a_,int b_) {
		this.a= a_;
		this.b= b_;
	}
	public int getArea() {
		return a*b;
	}
	public int getPerimetro() {
		return 2*a+2*b;
	}
}
