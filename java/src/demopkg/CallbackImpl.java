package demopkg;
public class CallbackImpl implements ICallback {

	@Override
	public void onPercent(int percent) {
		System.out.printf("%d\n", percent);
	}

	@Override
	public void onPercentEx(ComplexStruct cs) {
		int sum = 0;
		for (int i=0; i<cs.arr.length; i++) 
			sum+=cs.arr[i];
		if (cs.prior!=null)
			System.out.printf("(%d) ",cs.prior.fieldI);
		System.out.printf("ex: int=%d str=%s sum=%d\n",
				cs.fieldI, cs.str, sum);
	}
}
