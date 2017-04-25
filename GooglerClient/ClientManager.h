#ifndef __CLIENTMANAGER
#define __CLIENTMANAGER

#include "Network.h"
#include "FileTransfer.h"

#define UDP 0
#define TCP 1

class ClientManager
{
private:
	Network* mNetworkIns;
	FileTransfer* mFileIns;
	
	char mSendBuffer[BUFF_SIZE];

	void FileSendStartTCP();
	void FileSendStartUDP();

	int mProtocal;

public:
	ClientManager(int protocal, int port);
	~ClientManager();

	void FileSendStart();
};

#endif // !__CLIENTMANAGER
