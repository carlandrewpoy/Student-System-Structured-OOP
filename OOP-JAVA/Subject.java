
public class Subject {
	String subCode, description, unit;
	
	Subject(String subCode,
			String description,
			String unit) {
		this.subCode = subCode;
		this.description = description;
		this.unit = unit;

	}
	void displaySub() {
		System.out.print(String.format("\t %-21s",subCode));
		System.out.print(String.format("%-51s",description));
		System.out.println(String.format("%-5s",unit));
	}
}
