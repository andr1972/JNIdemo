#include <jni.h>
#include "demopkg_Process.h"

JNIEXPORT void JNICALL Java_demopkg_Process_nativeLongOperation
  (JNIEnv *env, jobject owner, jobject param1)
{
	jclass clsICallback = env->GetObjectClass(param1);
	jmethodID method1 = env->GetMethodID(clsICallback, "onPercent", "(I)V");
	jmethodID method2 = env->GetMethodID(clsICallback, "onPercentEx", "(Ldemopkg/ComplexStruct;)V");
	jclass clsComplexStruct = env->FindClass("demopkg/ComplexStruct");

	char str[32];
	jbyte bytes[10];
	for (int i=1; i<=10; i++) bytes[i-1] = i;
	for (int i=1; i<=10; i++) {
		env->CallVoidMethod(param1, method1, i);
		jobject obj = env->AllocObject(clsComplexStruct);
		jfieldID fld = env->GetFieldID(clsComplexStruct, "fieldI","I");
		env->SetIntField(obj, fld, i);
		fld = env->GetFieldID(clsComplexStruct, "arr","[B");
		jbyteArray byteArray = env->NewByteArray(i);
		env->SetByteArrayRegion(byteArray, 0, i, bytes);
		env->SetObjectField(obj, fld, byteArray);
		fld = env->GetFieldID(clsComplexStruct, "str","Ljava/lang/String;");
		sprintf(str,"a%d", i);
		env->SetObjectField(obj, fld,  env->NewStringUTF(str));
		env->CallVoidMethod(param1, method2, obj);
	}
}