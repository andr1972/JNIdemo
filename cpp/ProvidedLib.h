//inspired by UnACEv2.dll, see http://www.winace.com/, https://sourceforge.net/projects/junace/        

typedef struct sGlobalDataStruc
        {
          void  *Obj;           // ---- reserved for application! ----
                                // thought to be used as a pointer to
                                // an object; when a callback-function is
                                // called, the object pointer can be used to
                                // handle the callback in a specific way;
                                // the pointer has to be initialized by
                                // InitDll()

          int (__stdcall *StateCallbackProc)
                           (/*pCallbackProgressStruc State*/void);
                                //  Called to let the application know about
                                //  the progress of operations.
        } tGlobalDataStruc,
         *pGlobalDataStruc;   

typedef struct sProgressDataStruc
        {
          unsigned long TotalProcessedSize; // counted by Dll:
                                        // total uncompressed bytes processed
          unsigned long TotalSize;      // total uncompressed bytes to process
                                        // (sum of all original file sizes)
        } tProgressDataStruc,
         *pProgressDataStruc;        

typedef struct sCallbackProgressStruc
        {
          pGlobalDataStruc   GlobalData;     
          pProgressDataStruc ProgressData;  
        } tCallbackProgressStruc,
         *pCallbackProgressStruc;

typedef struct sExtractStruc
        {
          char *SourceDir;           // maybe a real or an archive directory
          char *DestinationDir;      // directory to extract files to
        } tExtractStruc,
         *pExtractStruc;
//---------------------------
int __stdcall InitDll(pGlobalDataStruc dllData);
int __stdcall Extract(char* ArchiveName, pExtractStruc Extract);