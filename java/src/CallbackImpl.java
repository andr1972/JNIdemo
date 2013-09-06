public class CallbackImpl implements ICallback {

	@Override
	public void OnPercent(int percent) {
		System.out.printf("%d\n", percent);
	}

	@Override
	public void OnPercentEx(CmplxStruct cs) {
		System.out.printf("ex: int=%d str=%s\n", cs.fieldI, cs.str);
	}
}
