package demopkg;

public class CallbackImpl implements ICallback {
	@Override
	public void stateProc() {
		System.out.printf("callback from Java\n");
	}
}
