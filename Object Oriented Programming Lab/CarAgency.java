
import java.util.*;
interface Passengers {
	void setPassengers(int c);
	int getPassengers();
}
abstract class Vehicle {
	private
	int numSerieMotor;
	private
	int year;
	private
	String brand;
	private
	double price;

	Vehicle(int numSerieMotor, int year, String brand, double price) {

		this.numSerieMotor = numSerieMotor;
		this.year = year;
		this.brand = brand;
		this.price = price;
	}

	public
	String toString() {
		return " numSerieMotor=" + numSerieMotor + ", year=" + year + ",
		       brand = " + brand + ",
		       price = "
		       + price;
	}

}

abstract class VehicPsj extends Vehicle implements Passengers {

	private
	int psj;

	VehicPsj(int numSerieMotor, int year, String brand, double price, int psj) {
		super(numSerieMotor, year, brand, price);
		this.psj = psj;
	}

	public
	void setPassengers(int c) {
		psj = c;
	}

	public
	int getPassengers() {
		return psj;
	}

	public
	String toString() {
		return super.toString() + "Passegers: " + psj;
	}

}

class Acmpct extends VehicPsj {

	Acmpct(int numSerieMotor, int year, String brand, double price, int psj) {
		super(numSerieMotor, year, brand, price, psj);
	}
}

class Alux extends VehicPsj {

	Alux(int numSerieMotor, int year, String brand, double price, int psj) {
		super(numSerieMotor, year, brand, price, psj);
	}
}

class Vagon extends VehicPsj {

	Vagon(int numSerieMotor, int year, String brand, double price, int psj) {
		super(numSerieMotor, year, brand, price, psj);
	}
}

class Truck extends Vehicle {

	private
	int capCharge;
	private
	int axes;
	private
	int wheel;

	Truck(int numSerieMotor, int year, String brand, double price, int capCharge, int axes,
	      int wheel) {
		super(numSerieMotor, year, brand, price);
		this.capCharge = capCharge;
		this.axes = axes;
		this.wheel = wheel;
	}

	public
	String toString() {
		return "Truck: capCharge=" + capCharge + ",
		       axes = " + axes
		       + ",wheels=" + wheel +
		       super.toString();
	}
}

public class CarAgency {

	public
	static void main(String[] args) {
		Scanner x = new Scanner(System.in);

		Vehicle v[] = new Vehicle[4];

		System.out.println("Vagon data:" + "\n");

		System.out.println("motor code:");
		int numSerieMotor = x.nextInt();
		System.out.println("brand");
		x.nextLine();
		String brand = x.nextLine();
		System.out.println("year");
		int year = x.nextInt();
		System.out.println("price");
		double price = x.nextDouble();
		System.out.println("passengers");
		int passengers = x.nextInt();

		v[0] = new Vagon(numSerieMotor, year, brand, price, passengers);
		x.nextLine();
		System.out.println("luxury car data:" + "\n");

		System.out.println("motor code");
		int a = x.nextInt();
		System.out.println("brand");
		x.nextLine();
		String b = x.nextLine();
		System.out.println("year:");
		int c = x.nextInt();
		System.out.println("price:");
		double d = x.nextDouble();
		System.out.println("passengers:");
		int e = x.nextInt();

		v[1] = new Alux(a, c, b, d, e);
		x.nextLine();
		System.out.println("compact auto data:" + "\n");

		System.out.println("motor code");
		int f = x.nextInt();
		System.out.println("brand");
		x.nextLine();
		String g = x.nextLine();
		System.out.println("year");
		int h = x.nextInt();
		System.out.println("price:");
		double i = x.nextDouble();
		System.out.println("passengers:");
		int j = x.nextInt();

		v[2] = new Acmpct(f, h, g, i, j);
		x.nextLine();
		System.out.println(" truck data:" + "\n");

		System.out.println("motor code");
		int k = x.nextInt();
		System.out.println("brand");
		x.nextLine();
		String l = x.nextLine();
		System.out.println("year:");
		int m = x.nextInt();
		System.out.println("price:");
		double n = x.nextDouble();

		System.out.println("charge capacity:");
		int p = x.nextInt();
		System.out.println("axes:");
		int q = x.nextInt();
		System.out.println("wheels:");
		int r = x.nextInt();

		v[3] = new Truck(k, m, l, n, p, q, r);
		x.nextLine();
		for (int z = 0; z < 4; z++) {
			System.out.println(v[z].toString() + " ");
		}
	}
}