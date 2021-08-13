/*
Implement a program for maintaining a database of student records using Files.Student has Student_ID, name, Roll_no, Class, marks and address. Display the data for few students.
1. Create Database
2. Display Database
3. Delete Records
4. Update Record
5. Search Record
*/
import java.io.*;
import java.util.*;

public class LabAssignment8 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public void addRecords() throws IOException {
		// Create or Modify a file from Database
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("st.txt", true)));
		String studentName, address;
		int studentId, rollNo;
		String Class;
		float marks;
		String s = "";
		boolean addMore = false;

		// Read Data
		do {
			System.out.print("\nEnter Student Name: ");
			studentName = br.readLine();

			System.out.print("Student ID: ");
			studentId = Integer.parseInt(br.readLine());

			System.out.print("Roll No. ");
			rollNo = Integer.parseInt(br.readLine());

			System.out.print("Address: ");
			address = br.readLine();

			System.out.print("Class: ");
			Class = br.readLine();

			System.out.print("Marks: ");
			marks = Float.parseFloat(br.readLine());

			// Printing the contents to the File
			pw.println(studentName + "\t" + studentId + "\t" + rollNo + "\t" + address + "\t" + Class + "\t" + marks);
			System.out.print("\nRecords added sucessfully!\n\nDo you want to add more records? (y/n): ");
			s = br.readLine();
			if (s.equalsIgnoreCase("y")) {
				addMore = true;
				System.out.println();
			} else {
				addMore = false;
			}
		} while (addMore);
		pw.close();;
		showMenu();
	}


	public void readRecord() throws IOException {
		try {
			System.out.println("==================================================");
			// Opening the file
			BufferedReader file = new BufferedReader(new FileReader("st.txt"));
			String name;
			// Reading records from the file
			while ((name = file.readLine()) != null) {
				System.out.println(name);
				System.out.println("\t\t");
			}
			file.close();
			System.out.println("==================================================");
			showMenu();
		} catch (FileNotFoundException e) {
			System.out.println("\nERROR : FILE NOT FOUND!");
		}
	}


	public void searchRecords() throws IOException {
		try {
			// Opening the file and search a record
			BufferedReader file = new BufferedReader(new FileReader("st.txt"));
			String name;
			int flag = 0;
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter an ID of the student you want to search: ");
			String searchName = sc.next();

			// Reading record from the file
			while ((name = file.readLine()) != null) {
				String[] line = name.split(" ");	//used to match a string
				if (searchName.equalsIgnoreCase(line[1])) {
					System.out.println("Record found");
					System.out.println(name);
					System.out.println("");
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				System.out.println("Record Not Found");
			file.close();
			showMenu();
		} catch (FileNotFoundException e) {
			System.out.println("\nERROR : FILE NOT FOUND!");
		}
	}


	public void deleteRecords() throws IOException {
		try {
			// Opening the file
			BufferedReader file1 = new BufferedReader(new FileReader("st.txt"));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("st1.txt", true)));
			String name;
			int flag = 0;
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the name of the Student you want to delete: ");
			String searchName = sc.next();

			// Reading Records from the file
			while ((name = file1.readLine()) != null) {
				String[] line = name.split(" ");
				if (!searchName.equalsIgnoreCase(line[0])) {
					pw.println(name);
					flag = 0;
				} else {
					System.out.println("Record Found");
					flag = 1;
				}
			}
			file1.close();
			pw.close();
			File delName = new File("st.txt");
			File oldName = new File("st1.txt");
			File newName = new File("st.txt");
			if (delName.delete())
				System.out.println("Deleted Successfully");
			else
				System.out.println("Error");
			showMenu();
		} catch (FileNotFoundException e) {
			System.out.println("\nERROR : FILE NOT FOUND!");
		}
	}


	public void updateRecords() throws IOException {
		try {
			// Opening the file
			BufferedReader file1 = new BufferedReader(new FileReader(("st.txt")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("st1.txt", true)));
			String name;
			int flag = 0;
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the Name of the Student you want to update: ");
			String searchName = sc.next();
			// Reading records from the file
			while ((name = file1.readLine()) != null) {
				String[] line = name.split(" ");
				if (!searchName.equalsIgnoreCase(line[0])) {
					pw.println(name);
					flag = 0;
				} else {
					System.out.println("Record found");
					System.out.println("Enter updated marks: ");
					String upMarks = sc.next();
					pw.println(line[0] + " " + line[1] + " " + line[2] + " " + line[3] + " " + line[4] + " " + upMarks);
					flag = 1;
				}
			}
			file1.close();
			pw.close();
			File delName = new File("st.txt");
			File oldName = new File("st1.txt");
			File newName = new File("st.txt");
			if (delName.delete())
				System.out.println("Record Updated Successfully");
			else
				System.out.println("ERROR");
			if (oldName.renameTo(newName))
				System.out.println("Renamed Successfully");
			else
				System.out.println("ERROR");

			showMenu();
		} catch (FileNotFoundException e) {
			System.out.println("\nERROR : FILE NOT FOUND!");
		}
	}


	public void clear(String fileName) throws IOException {
		// Creating a blank file
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(fileName)));
		pw.close();
		System.out.println("\nAll Records cleared successfully!");
		for (int i = 0; i < 999999999; i++);	// Waiting for some time
		showMenu();
	}


	public void showMenu() throws IOException {
		System.out.println("");
		System.out.println("1) Add Records");
		System.out.println("2) Display Records");
		System.out.println("3) Clear All Records");
		System.out.println("4) Search Secords");
		System.out.println("5) Delete Records");
		System.out.println("6) Update Records");
		System.out.println("7) Exit");
		System.out.print("\nEnter Your Choice: ");
		int choice = Integer.parseInt(br.readLine());
		System.out.println("");

		switch (choice) {
		case 1:
			addRecords();
			break;
		case 2:
			readRecord();
			break;
		case 3:
			clear("st.txt");
			break;
		case 4:
			searchRecords();
			break;
		case 5:
			deleteRecords();
			break;
		case 6:
			updateRecords();
			break;
		case 7:
			System.exit(0);
			break;
		default:
			System.out.println("\nInvalid Input");
			break;
		}
	}

	public static void main(String[] args) throws IOException {
		LabAssignment8 call = new LabAssignment8();
		call.showMenu();
	}

}
