#include <jni.h>
#include "demopkg_Process.h"

JNIEXPORT void JNICALL Java_demopkg_Process_nativeLongOperation
  (JNIEnv *env, jobject owner, jobject param1)
{
	jclass cls = env->GetObjectClass(param1);
	jmethodID mid = env->GetMethodID(cls, "OnPercent", "(I)V");
    if (mid == NULL) {
		printf("1. not found method..\n");
        return; 
    } else printf("1. found method!\n");
	//env->CallVoidMethod(owner, mid);//error
	for (int i=1; i<=10; i++)
		env->CallVoidMethod(param1, mid, i);//ok
	mid = env->GetMethodID(cls, "OnPercentEx", "(Ldemopkg/CmplxStruct;)V");
    if (mid == NULL) {
		printf("2. not found method..\n");
        return; 
    } else printf("2. found method!\n");
	jclass clazz = env->FindClass("demopkg/CmplxStruct");
	jobject obj = env->AllocObject(clazz);
	if (obj == NULL) {
		printf("2. can't alloc..\n");
        return; 
    } else printf("2. alloc ok!\n");
	jfieldID fld = env->GetFieldID(clazz, "fieldI","I");
	env->SetIntField(obj, fld, 3);
	env->CallVoidMethod(param1, mid, obj);
}