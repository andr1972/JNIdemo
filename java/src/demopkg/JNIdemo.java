package demopkg;

public class JNIdemo {
	static {
		try {
			System.loadLibrary("JNIdemo");			
		}
		catch(Throwable e) {
			System.err.printf(e.getMessage()); 
			System.exit(1);			
		}
	}

	public static void main(String[] args) {
		Process process = new Process();
		process.nativeLongOperation(new CallbackImpl());
	}
}
