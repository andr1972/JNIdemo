#include <jni.h>
#include "Process.h"

JNIEXPORT void JNICALL Java_Process_nativeLongOperation
  (JNIEnv *env, jobject owner, jobject param1)
{
	jclass cls = env->GetObjectClass(param1);
	jmethodID mid = env->GetMethodID(cls, "OnPercent", "(I)V");
    if (mid == NULL) {
		printf("not found method..\n");
        return; 
    } else printf("found method!\n");
	//env->CallVoidMethod(owner, mid);//error
	for (int i=1; i<=100; i++)
		env->CallVoidMethod(param1, mid, i);//ok
}