#include "ServerManager.h"

ServerManager::ServerManager() {
	this->mServerIns = new Server(mRecvBuffer, BUFF_SIZE, 8888);
	this->mFileIns = new FileManage(mRecvBuffer, BUFF_SIZE);

	mServerIns->ConnectUDP();

}

ServerManager::~ServerManager() {
	mServerIns->~Server();
	mFileIns->~FileManage();
}

void ServerManager::FileRecvStart() {
	if (mServerIns->RecvToClient() == -1) {//ó�� ��Ŷ�� ������ �̸��� �޾ƿ�
		cout << "ERRER: Packet Recv Fail" << endl;
		exit(1);
	}
	if (mFileIns->SetFileNameFromBuf()) {//�� ������ ������ ���ȴ��� Ȯ��
		cout << "ERRER: Can't Create File" << endl;
		exit(1);
	}
	while (1) {
		if (mServerIns->RecvToClient() == -1) {
			cout << "ERRER: Packet Recv Fail" << endl;
			exit(1);
		}
		if (mFileIns->WriteFile() > 0) {//(0:����, 1:���Ṯ�ڿ�)
			cout << "File Receive Complete!" << endl;
			break;
		}
			
	}
}