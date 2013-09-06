#include <jni.h>
#include "Process.h"

JNIEXPORT void JNICALL Java_Process_nativeLongOperation
  (JNIEnv *env, jobject owner, jobject param1)
{
	jclass cls = env->GetObjectClass(param1);
	jmethodID mid = env->GetMethodID(cls, "OnPercent", "(I)V");
    if (mid == NULL) {
		printf("1. not found method..\n");
        return; 
    } else printf("1. found method!\n");
	//env->CallVoidMethod(owner, mid);//error
	for (int i=1; i<=100; i++)
		env->CallVoidMethod(param1, mid, i);//ok
	mid = env->GetMethodID(cls, "OnPercentEx", "(LCmplxStruct;)V");
    if (mid == NULL) {
		printf("2. not found method..\n");
        return; 
    } else printf("2. found method!\n");
	jclass clazz = env->FindClass("CmplxStruct");
	jobject obj = env->AllocObject(clazz);
	if (obj == NULL) {
		printf("2. can't alloc..\n");
        return; 
    } else printf("2. alloc ok!\n");
	env->CallVoidMethod(param1, mid, obj);
}