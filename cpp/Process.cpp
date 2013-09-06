#include <jni.h>
#include "demopkg_Process.h"

JNIEXPORT void JNICALL Java_demopkg_Process_nativeLongOperation
  (JNIEnv *env, jobject owner, jobject param1)
{
	jclass cls = env->GetObjectClass(param1);
	jmethodID mid = env->GetMethodID(cls, "OnPercent", "(I)V");
	for (int i=1; i<=10; i++)
		env->CallVoidMethod(param1, mid, i);
	mid = env->GetMethodID(cls, "OnPercentEx", "(Ldemopkg/CmplxStruct;)V");
	jclass clazz = env->FindClass("demopkg/CmplxStruct");
	jobject obj = env->AllocObject(clazz);
	jfieldID fld = env->GetFieldID(clazz, "fieldI","I");
	env->SetIntField(obj, fld, 3);
	fld = env->GetFieldID(clazz, "arr","[B");
	jbyteArray byteArray = env->NewByteArray(5);
	jbyte bytes[5];
	env->GetByteArrayRegion(byteArray, 0, 5, bytes);
	bytes[3] = 3;
    bytes[4] = 4;
	env->SetByteArrayRegion(byteArray, 0, 5, bytes);
    env->SetObjectField(obj, fld, byteArray);
	fld = env->GetFieldID(clazz, "str","Ljava/lang/String;");
	env->SetObjectField(obj, fld,  env->NewStringUTF("abc"));
	env->CallVoidMethod(param1, mid, obj);
}