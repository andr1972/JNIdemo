package demopkg;

public class CallbackImpl implements ICallback {

	@Override
	public int stateProc(long TotalProcessedSize, long TotalSize) {
		System.out.printf("params %d/%d\n", TotalProcessedSize, TotalSize);
		return 0;
	}
}
