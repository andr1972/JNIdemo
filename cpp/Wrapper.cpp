#include <string.h>
#include <stdio.h>
#include "ProvidedLib.h"
#include "demopkg_Wrapper.h"

struct sJNIstate
        {
          JNIEnv *env;
		  jobject interf;
          jmethodID methodstateProc1;
		  jmethodID methodstateProc2;
        };

struct sJNIstate jniState;

int __stdcall StateProc(pCallbackProgressStruc State)
{   
	//jniState.env->CallIntMethod(jniState.interf, jniState.methodstateProc1);
	return jniState.env->CallIntMethod(jniState.interf, jniState.methodstateProc2, 
		(long long)State->ProgressData->TotalProcessedSize, (long long)State->ProgressData->TotalSize);
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
	jniState.methodstateProc1 = env->GetMethodID(clsInterf, "stateProc", "(Ldemopkg/ProgressDataStruc;)I");
	jniState.methodstateProc2 = env->GetMethodID(clsInterf, "stateProc", "(JJ)I");
	Extract("",&ExtractStr);
}
