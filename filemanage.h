#pragma once

#ifndef __FILEMANAGE
#define __FILEMANAGE

#include <iostream>
#include <fstream>
#include <string>

#define BUFF_SIZE (1024)
#define STRUCT_SIZE (BUFF_SIZE-4)

struct packet {
	int meta;
	char buff[STRUCT_SIZE];
};

using namespace std;

class FileManage {
private:
	int mBuf_size;
	char* mRecvBuffer;
	string FileName;
	fstream File;
	char FileOpenFlag;
	packet *pk;
	int SetFileName(char *name); //���ϸ��� �̹� �����ϸ� �ַ� ����(0:����, 1:��������)
	int SetFileNameFromBuf(); //���ۿ��� ���� ������
	int WriteFile(); //�������ڸ� �о��ٸ� �������� ����(0:���, 1:����, 2:����open�ȵ�)
	int FileEnd();

public:
	FileManage(char* buffer, int buf_size);
	~FileManage();
	int IsOpen(); //������ �����ִ��� Ȯ��(1:����,0:����)
	int RecvPacket();
};



#endif // !__FILEMANAGE
