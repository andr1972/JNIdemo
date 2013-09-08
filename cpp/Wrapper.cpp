#include <string.h>
#include <stdio.h>
#include "ProvidedLib.h"

int __stdcall StateProc(/*pCallbackProgressStruc State*/void)
{
	printf("from C callback\n");
	return 0;
}

int CallInitDll(void)
{
	tGlobalDataStruc DllData;
	memset(&DllData, 0, sizeof(DllData));   // set all fields to zero
	DllData.StateCallbackProc = StateProc;
	return InitDll(&DllData);
}	