#include <string.h>
#include <stdio.h>
#include "ProvidedLib.h"
#include "demopkg_Wrapper.h"

struct sJNIstate
        {
          JNIEnv *env;
		  jobject interf;
          jmethodID method;
        };

struct sJNIstate jniState;

int __stdcall StateProc(pCallbackProgressStruc State)
{   
	return jniState.env->CallIntMethod(jniState.interf, jniState.method);		
}


JNIEXPORT jint JNICALL Java_demopkg_Wrapper_nativeInitDll
  (JNIEnv *, jobject)
{
	tGlobalDataStruc DllData;
	memset(&DllData, 0, sizeof(DllData));   // set all fields to zero
	DllData.StateCallbackProc = StateProc;
	return InitDll(&DllData);
}

JNIEXPORT void JNICALL Java_demopkg_Wrapper_nativeExtract
  (JNIEnv *env, jobject owner, jobject interf)
{
tExtractStruc ExtractStr;
    
    jniState.env = env;
	jniState.interf = interf;
	jclass clsInterf = env->GetObjectClass(interf);
	jniState.method = env->GetMethodID(clsInterf, "stateProc", "()V");
	Extract("",&ExtractStr);
}
