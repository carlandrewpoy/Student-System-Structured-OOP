
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static Scanner s = new Scanner(System.in);
	static ArrayList<Student> students = new ArrayList<Student>();
	static ArrayList<Subject> subjects = new ArrayList<Subject>();
	static ArrayList<Enroll> enrolls = new ArrayList<Enroll>();
		
	public static void main(String[] args) {
		int menu;		
		
		do {

			System.out.println("\n Main Menu");
			System.out.println("\t 1. Student Menu");
			System.out.println("\t 2. Subject Menu");
			System.out.println("\t 3. Enroll Student");
			System.out.println("\t 4. Display Subject Enrolled");
			System.out.println("\t 5. Exit Program");
			System.out.print(" Select: ");
			menu = s.nextInt();
			s.nextLine();
			
			switch(menu) {
			case 1:
				int menu1;
				do {
					System.out.println("\n 1. Student Menu");
					 System.out.println("\t 1. Add");
					 System.out.println("\t 2. Display");
					 System.out.println("\t 3. Back");
					 System.out.print(" Select: ");
					 menu1 = s.nextInt();
					 s.nextLine();
					 
					 switch(menu1) {
					 	case 1:
					 	addStud();
					 	break;

					 	case 2:
					 	displayStud();
					 	break;
					 	
					 	case 3:
					 	break;
						 	
					 	default:
					 	System.out.println("\n\tInvalid input!");
					 }
				}while(menu1 != 3);
				break;
			case 2:
				int menu2;
				do {
					System.out.println("\n 2. Subject Menu");
					System.out.println("\t 1. Add");
					System.out.println("\t 2. Display");
					System.out.println("\t 3. Back");
					System.out.print(" Select: ");
					 menu2 = s.nextInt();
					 s.nextLine();
					 
					 switch(menu2) {
					 	case 1:
					 	addSub();
					 	break;
					 	
					 	case 2:
					 	displaySub();
					 	break;
					 	
					 	case 3:
					 	break;
						 	
					 	default:
					 	System.out.println("\n\tInvalid input!");
					 }
				}while(menu2 != 3);
				break;
			case 3:
				enroll();
				break;
			case 4:
				displayEnroll();
				break;
			case 5:
				System.out.println("\n Exit!\n");
				break;
			default:
				System.out.println("\n Invalid input!");
				break;
			}
		}while(menu != 5);	
	}
	static void addStud() {
		System.out.print("\n\tAdd Student");
	   	
	   	System.out.print("\n\tID\t: ");
	   	String id = s.nextLine();
	   	
	   	if(isValidStudent(id)) {
	   		System.out.println("\tStudent ID. " + id + " already added!");
	   	}else {
	   		System.out.print("\tName\t: ");
		   	String name = s.nextLine();
		   	
		   	if(isValidStudentName(name)) {
		   		System.out.println("\tStudent Name: " + name + " already in use!");
		   	}else {
		   		System.out.print("\tGender\t: ");
			   	String gender = s.nextLine();
			   	
			   	System.out.print("\tCourse\t: ");
			   	String course = s.nextLine();

			   	System.out.print("\tYear\t: ");
			   	String year = s.nextLine();
			   	
			   	System.out.print("\n\tStudent ID. " + id + " added successfully!");
				
				System.out.println();
				students.add(new Student(id, name, gender, course, year));
		   	}
	   	}
	}
	
	static void addSub() {
		System.out.print("\n\tAdd Subject");
		  
  		 System.out.print("\n\tSubject code\t: ");
  		 String subCode = s.nextLine();
  		 
  		if(isValidSubject(subCode)) {
	   		System.out.println("\tSubject Code: " + subCode + " already added!");
	   	}else {
		   	 System.out.print("\tDescription\t: ");
	  		 String description = s.nextLine();
  		 
	  		if(isValidSubjectName(description)) {
		   		System.out.println("\tSubejct Description: " + description + " already in use!");
		   	}else {
		   	 System.out.print("\tUnit\t\t: ");
	  		 String unit = s.nextLine();
	  			   		
	  		 System.out.print("\n\tSubject Code: "+ subCode +" added successfully!\n");
			subjects.add(new Subject(subCode, description, unit));
		   	}
	   	}	
	}
	static boolean isValidStudent(String id) {
		boolean found = false;
		
		for(Student stud: students) {
			if(stud.id.equals(id)) {
				found = true;
			}
		}
		return found;
	}
	static boolean isValidStudentName(String name) {
		boolean found = false;
		
		for(Student stud: students) {
			if(stud.name.equals(name)) {
				found = true;
			}
		}
		return found;
	}
	static boolean isValidSubject(String subCode) {
		boolean found = false;
		
		for(Subject sub: subjects) {
			if(sub.subCode.equals(subCode)) {
				found = true;
			}
		}
		return found;
	}
	static boolean isValidSubjectName(String description) {
		boolean found = false;
		
		for(Subject sub: subjects) {
			if(sub.description.equals(description)) {
				found = true;
			}
		}
		return found;
	}
	static boolean isValidEnroll(String id) {
		boolean found = false;
		
		for(Enroll en: enrolls) {
			if(en.id.equals(id)) {
				found = true;
			}
		}
		return found;
	}
	static boolean isValidEnrollSub(String id,String subCode) {
		boolean found = false;
		
		for(Enroll en: enrolls) {
			if(en.id.equals(id) && en.subCode.equals(subCode)) {
				found = true;
			}
		}
		return found;
	}
	static void enroll() {
		String id;
		String subCode;

		System.out.print("\n\tEnroll Student");
		System.out.print("\n\tID\t: ");
		id = s.nextLine();

		if(!isValidStudent(id)) {
			System.out.print("\tStudent ID. "+ id +" not found!\n");
		}else {
			System.out.print("\tSubject Code\t: ");
			 subCode = s.nextLine();
			
			if(!isValidSubject(subCode)) {
				System.out.print("\tSubject Code: " + subCode + " not found!\n\n");
			}else if(isValidEnrollSub(id, subCode)) {
				System.out.print("\n\tSubject Code: "+ subCode+ " already added!\n");
			}else {
				System.out.print("\n\tSubject Code: " + subCode + " enrolled successfully!\n");	
				enrolls.add(new Enroll(id, subCode));
			}
		}
	}
	
	static void displayStud() {
		System.out.print("\n\tStudent List");
		System.out.print("\n\t|ID\t   |Name\t\t\t\t   |Gender\t  |Course\t |Year\n");
		for(Student stud: students) {
			stud.displayStud();
		}
	}
	static void displayStud1(String id) {
		System.out.print("\n\tStudent Information");
		System.out.print("\n\t|ID\t   |Name\t\t\t\t   |Gender\t  |Course\t |Year\n");
		for(Student stud: students) {
			if(stud.id.equals(id)) {
				System.out.print(String.format("\t %-11s",stud.id));
				 System.out.print(String.format("%-40s",stud.name));
				 System.out.print(String.format("%-15s",stud.gender));
				 System.out.print(String.format("%-15s",stud.course));
				 System.out.println(String.format("%-10s",stud.year));
			}
		}
	}
	static void displaySub() {
		System.out.print("\n\tSubject List");
		System.out.print("\n\t|Subject Code\t     |Description\t\t\t\t        |Unit\n");
		for(Subject sub: subjects) {
			sub.displaySub();
		}
	}
	
	static void displaySub1(String id) {
		System.out.print("\n\tSubject Enrolled List");
		System.out.print("\n\t|Subject Code\t     |Description\t\t\t\t        |Unit\n");
		for(Enroll en: enrolls) {
			if(en.id.equals(id)) {
				for(Subject sub: subjects) {
					if(en.subCode.equals(sub.subCode)) {
						System.out.print(String.format("\t %-21s",sub.subCode));
						System.out.print(String.format("%-51s",sub.description));
						System.out.println(String.format("%-5s",sub.unit));
					}
				}
			}
		}
	}

	static void displayEnroll() {
		String id;
		
		System.out.print("\n\tID\t: ");
		id = s.nextLine();
		
		if(!isValidEnroll(id)) {
			System.out.print("\tStudent ID. " + id + " is not already enrolled!\n");
		}else {
			displayStud1(id);
			displaySub1(id);
		}		
	}
}
