// ZipUnzip.cpp : Defines the entry point for the console application.
//

// SimpleZip.cpp : Defines the entry point for the console application.
// Usage: SimpleZip [flag] [source file]
//        flag: c - compress
//               d - decompress

#include <stdio.h>
#include <windows.h>
#include "zlib/zipper.h"
#include "zlib/unzipper.h"


int main(int argc, char* argv[])
{
	char *srcFileName;
	bool bSrcIsDirectory, br;
	DWORD fileAttr;

	// 파라미터 확인
	if(argc != 3) {
		printf("Usage: SimpleZip [flag] [source file]\n");
		printf("       flag: c - compress\n");
		printf("             d - decompress");
		exit(0);
	}

	srcFileName = argv[2];

	// 소스 파일 확인
	bSrcIsDirectory = ((fileAttr = GetFileAttributes(srcFileName)) & FILE_ATTRIBUTE_DIRECTORY) > 0;
	if(fileAttr == 0xFFFFFFFF) {
		printf("file not exist or has unknown problems");
		exit(0);
	}

	switch(argv[1][0]) {
			 case 'c':
			 case 'C':
				 // 디렉토리인 경우
				 if(bSrcIsDirectory) {
					 br = CZipper::ZipFolder(srcFileName, FALSE);
				 }
				 // 파일인 경우
				 else {
					 br = CZipper::ZipFile(srcFileName);
				 }

				 printf(br ? "compression completed." : "error occured.");
				 break;

			 case 'd':
			 case 'D':
				 // 디렉토리인 경우
				 if(bSrcIsDirectory) {
					 printf("%s isn't a file", srcFileName);
					 exit(0);
				 }
				 // 파일인 경우
				 else {
					 CUnzipper uz;
					 br = uz.OpenZip(srcFileName);
					 if(br) br = uz.UnzipTo(".");
					 printf(br ? "decompression completed." : "error occured.");
				 }
				 break;

			 default:
				 printf("wrong flag.");
				 break;
	}

	return 0;
}
