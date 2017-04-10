#ifndef __FILETRANSFER
#define __FILETRANSFER

#include <iostream>
#include <winsock.h>
#include <stdlib.h>
#include <share.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")
#define BUFF_SIZE (1024)

class FileTransfer
{
private:
	int sock;
	FILE* fp;
	struct sockaddr_in echoServAddr;
	unsigned short echoServPort;
	
	char servIP[11];

	char fileName[BUFF_SIZE];
	char buf[BUFF_SIZE];
	char fileSizeBuf[BUFF_SIZE];
	char readBuffer[BUFF_SIZE];

	int cliLen;
	int fileSize;
	int fileNameLen;
	int readn;
	int sendton;
	int recvMsgSize;
	WSADATA wasData;

public:
	FileTransfer();
	~FileTransfer();

	void IsStartup();
	void IsSocket();
	void ClientStart();
	void StartTransfer();
};
#endif