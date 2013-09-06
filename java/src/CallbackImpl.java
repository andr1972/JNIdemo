
public class CallbackImpl implements ICallback {

	@Override
	public void OnPercent(int percent) {
		System.out.printf("%d\n", percent);
	}
}
