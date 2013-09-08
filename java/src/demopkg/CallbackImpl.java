package demopkg;

public class CallbackImpl implements ICallback {

	@Override
	public int stateProc(ProgressDataStruc state) {
		System.out.printf("structs %d/%d\n",
				state.TotalProcessedSize,state.TotalSize);		
		return 0;
	}

	@Override
	public int stateProc(long TotalProcessedSize, long TotalSize) {
		System.out.printf("params %d/%d\n", TotalProcessedSize,TotalSize);		
		return 0;
	}
}
