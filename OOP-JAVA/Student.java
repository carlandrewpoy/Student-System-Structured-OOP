
public class Student {

	String id, name, gender, course, year;
	
	Student(String id,
			String name,
			String gender,
			String course,
			String year) {
		this.id = id;
		this.name = name;
		this.gender = gender;
		this.course = course;
		this.year = year;
	}
	void displayStud() {
		 
		 System.out.print(String.format("\t %-11s",id));
		 System.out.print(String.format("%-40s",name));
		 System.out.print(String.format("%-15s",gender));
		 System.out.print(String.format("%-15s",course));
		 System.out.println(String.format("%-10s",year));
	}
}
