#ifndef _FSERV_H__
#define _FSERV_H__

#include "sysdefs.h"
#include "ff.h"
#include <stdio.h>
#include <string.h>


#define MAX_PATH_LEN (256)

typedef enum {
   FSERV_NONEXSIT,
   FSERV_FILE,
   FSERV_DIR
} fsElemType;

/* File server init.
    in: none
    out: none
    retval: operation status
*/
FRESULT fsInit();

/* File server element type query.
   in: path to fs element
   out: size in bytes
   retval: operation status
*/
FRESULT fsGetElementInfo(const char* path, fsElemType* elemType, DWORD* byteSize);

/* File server get element data.
   in: path to fs element, buffer to hold the data
   out: fs element data will be written to buffer container
   retval: operation status
*/
FRESULT fsGetElementData(const char* path, char* dataBuff, int offset, int bytesToRead);


/* Interface for a file system based cookie storing ip address.
    should be used at startup to resolve our prev. IP address.
*/
void fsGetIp(unsigned char* pIp);

/* Interface for manipulation of the ip cookie.
*/
void fsSetIp(const unsigned char* pIp);

#endif // _FSERV_H__

//end of file

