
import java.util.Scanner;
interface Vehicle {
	void changeGear(int a);
	void speedUp(int a);
	void applyBrakes(int a);
}

class Bicycle implements Vehicle {
	
	int speed, gear;
	
	public void changeGear(int newGear) {
		gear = newGear;
	}
	
	public void speedUp(int acceleration) {
		speed = speed + acceleration;
	}
	
	public void applyBrakes(int deceleration) {
		speed = speed - deceleration;
	}
	
	public void status() {
		System.out.printf("\nBicycle is running at speed of %d and gear is set to %d\n\n", speed, gear);
	}
}

class Bike implements Vehicle {
	
	int speed, gear;
	
	public void changeGear(int newGear) {
		gear = newGear;
	}
	
	public void speedUp(int acceleration) {
		speed = speed + acceleration;
	}
	
	public void applyBrakes(int deceleration) {
		speed = speed - deceleration;
	}
	
	public void status() {
		System.out.printf("\nBike is running at speed of %d and gear is set to %d\n\n", speed, gear);
	}
}

class Car implements Vehicle {
	int speed, gear;
	
	public void changeGear(int newGear) {
		gear = newGear;
	}
	
	public void speedUp(int acceleration) {
		speed = speed + acceleration;
	}
	
	public void applyBrakes(int deceleration) {
		speed = speed - deceleration;
	}
	
	public void status() {
		System.out.printf("\nCar is running at speed of %d and gear is set to %d\n\n", speed, gear);
	}
}
public class LabAssignment5 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		byte choice1, choice2;
		do
		{
			System.out.println("Enter Your Choice");
			System.out.println("1) Bicycle");
			System.out.println("2) Bike");
			System.out.println("3) Car");
			System.out.println("To stop press 0");
			choice1 = sc.nextByte();
			switch(choice1)
			{
				case 0:
					System.out.println("Exiting...");
					break;
				case 1:
					Bicycle bicycle = new Bicycle();
					do
					{
						System.out.println("1) Change Gear");
						System.out.println("2) Speed Up");
						System.out.println("3) Apply Brakes");
						System.out.println("To stop press 0");
						choice2 = sc.nextByte();
						switch(choice2)
						{
							case 0:
								System.out.println("Exiting...");
								break;
							case 1:
								System.out.print("Change Gear to: ");
								int gear = sc.nextInt();
								bicycle.changeGear(gear);
								bicycle.status();
								break;
							case 2:
								System.out.print("Aceleration: ");
								int speed = sc.nextInt();
								bicycle.speedUp(speed);
								bicycle.status();
								break;
							case 3:
								System.out.print("Deceleration: ");
								int slowdown = sc.nextInt();
								bicycle.applyBrakes(slowdown);
								bicycle.status();
								break;
							default:
								System.out.println("Invalid input");
								break;
						}
					}while(choice2 != 0);
					break;
				case 2:
					Bike bike = new Bike();
					do
					{
						System.out.println("1) Change Gear");
						System.out.println("2) Speed Up");
						System.out.println("3) Apply Brakes");
						choice2 = sc.nextByte();
						switch(choice2)
						{
							case 0:
								System.out.println("Exiting...");
								break;
							case 1:
								System.out.print("Change Gear to: ");
								int gear = sc.nextInt();
								bike.changeGear(gear);
								bike.status();
								break;
							case 2:
								System.out.print("Aceleration: ");
								int speed = sc.nextInt();
								bike.speedUp(speed);
								bike.status();
								break;
							case 3:
								System.out.print("Deceleration: ");
								int slowdown = sc.nextInt();
								bike.applyBrakes(slowdown);
								bike.status();
								break;
							default:
								System.out.println("Invalid input");
								break;
						}
					}while(choice2 != 0);
					break;
				case 3:
					Car car = new Car();
					do
					{
						System.out.println("1) Change Gear");
						System.out.println("2) Speed Up");
						System.out.println("3) Apply Brakes");
						choice2 = sc.nextByte();
						switch(choice2)
						{
							case 0:
								System.out.println("Exiting...");
								break;
							case 1:
								System.out.print("Change Gear to: ");
								int gear = sc.nextInt();
								car.changeGear(gear);
								car.status();
								break;
							case 2:
								System.out.print("Aceleration: ");
								int speed = sc.nextInt();
								car.speedUp(speed);
								car.status();
								break;
							case 3:
								System.out.print("Deceleration: ");
								int slowdown = sc.nextInt();
								car.applyBrakes(slowdown);
								car.status();
								break;
							default:
								System.out.println("Invalid input");
								break;
						}
					}while(choice2 == 0);
				default:
					System.out.println("Invalid input");
					break;
			}
		}while(choice1 != 0);
		sc.close();
	}
}
