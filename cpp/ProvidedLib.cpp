/* Imagine that this file is part of provided library which has no sources and we can't
   change. This library uses callbacks as pointer to function. */

#include <string.h>
#include "ProvidedLib.h"

tGlobalDataStruc globalData;

int __stdcall InitDll(pGlobalDataStruc dllData)
{
	memcpy(&globalData, dllData, sizeof(globalData));
	return 0;
}

int __stdcall Extract(char* ArchiveName, pExtractStruc Extract)
{
tProgressDataStruc progressData;
tCallbackProgressStruc callbackProgress;

    callbackProgress.GlobalData = &globalData;
	callbackProgress.ProgressData = &progressData;
	progressData.TotalSize = 100;
	for (int i=1; i<=10; i++) {
		progressData.TotalProcessedSize = i*10;
		globalData.StateCallbackProc(&callbackProgress);
	}
	return 0;
}