#include "ServerManager.h"

ServerManager::ServerManager() {
	this->mServerIns = new Server(mRecvBuffer, BUFF_SIZE, 8888);
	this->mFileIns = new FileManage(mRecvBuffer, BUFF_SIZE);
	RecvFlg = 0;
	mServerIns->ConnectUDP();

}

ServerManager::~ServerManager() {
	mServerIns->~Server();
	mFileIns->~FileManage();
}

void ServerManager::FileRecvStart() {
	
	while (1) {
		if (RecvFlg == 0) {
			if (mServerIns->RecvToClient() == -1) {//ó�� ��Ŷ�� ������ �̸��� �޾ƿ�
				cout << "ERRER: Packet Recv Fail" << endl;
				exit(1);
			}
			if (mFileIns->SetFileNameFromBuf()) {//�� ������ ������ ���ȴ��� Ȯ��
				cout << "ERRER: Can't Create File" << endl;
				exit(1);
			}
			RecvFlg = 1;
		}
		else {
			if (mServerIns->RecvToClient() == -1) {
				cout << "ERRER: Packet Recv Fail" << endl;
				exit(1);
			}
			if (mFileIns->WriteFile() > 0) {//(0:����, 1:���Ṯ�ڿ�)
				cout << "File Receive Complete!" << endl;
				RecvFlg = 0; //���ϼ��� �Ϸ�, �����̸� �޴»��·�
			}
		}
			
	}
}