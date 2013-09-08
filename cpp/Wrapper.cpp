#include <string.h>
#include <stdio.h>
#include "ProvidedLib.h"
#include "demopkg_Wrapper.h"

int __stdcall StateProc(pCallbackProgressStruc State)
{   
	printf("from C callback size=%d\n",State->ProgressData->TotalProcessedSize);
	return 0;
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
  (JNIEnv *, jobject)
{
tExtractStruc ExtractStr;
	Extract("",&ExtractStr);
}
