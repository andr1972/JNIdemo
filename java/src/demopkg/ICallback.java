package demopkg;

public interface ICallback {
	int stateProc(ProgressDataStruc state);
	int stateProc(long TotalProcessedSize,	long TotalSize);
}
