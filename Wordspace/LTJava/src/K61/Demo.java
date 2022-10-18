package K61;

class Demo0 {
	private final void flipper() {
		System.out.println("Clidder");
	}
}

public class Demo extends Demo0 {
	public final void flipper() {
		System.out.println("clidlet");
	}
	
	public static void main(String[] args) {
		new Demo().flipper();
	}
};

