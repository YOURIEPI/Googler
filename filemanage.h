#pragma once

#ifndef __FILEMANAGE
#define __FILEMANAGE

#include <iostream>
#include <fstream>
#include <string>
#include "md5wrapper.h"
#define BUFF_SIZE (1024)
#define STRUCT_SIZE (BUFF_SIZE - 4)

struct packet {
	int meta;
	char buff[STRUCT_SIZE];
};

using namespace std;

class FileManage {
private:
	char* mRecvBuffer;
	string FileName;
	string make_md5;
	string receive_md5;
	fstream File;
	char FileOpenFlag;
	packet *pk;
	int SetFileName(char *name); //���ϸ��� �̹� �����ϸ� �ַ� ����(0:����, 1:��������)
	int SetFileNameFromBuf(); //���ۿ��� ���� ������
	int WriteFile(); //�������ڸ� �о��ٸ� �������� ����(0:���, 1:����, 2:����open�ȵ�)
	int FileEnd();
	int FileClose();
	int GetMd5();
	int MakeMd5();
public:
	FileManage(char* buffer);
	~FileManage();
	int IsOpen(); //������ �����ִ��� Ȯ��(1:����,0:����)
	int RecvPacket();
};



#endif // !__FILEMANAGE
