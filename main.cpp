#include "ServerManager.h"

int main(void) {
	ServerManager* InsSM;
	char* fileName;

	cout << "����� ���� �̸� :";
	cin >> fileName;
	InsSM = new ServerManager(fileName);
	InsSM->FileRecvStart();

	return 0;

}