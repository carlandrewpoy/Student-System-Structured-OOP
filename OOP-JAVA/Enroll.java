
public class Enroll {
	String id, subCode;
	
	Enroll(String id, String subCode) {
		this.id = id;
		this.subCode = subCode;
	}
	void displayEnroll() {
		System.out.println("");
		System.out.println("ID: " + id);
		System.out.println("Subejct Code: " + subCode);
		System.out.println("");
	}
}
