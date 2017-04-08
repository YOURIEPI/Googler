#pragma once

#ifndef __FILEMANAGE
#define __FILEMANAGE

#include <iostream>
#include <fstream>
#include <string>

#define STRING_COMPARE "FFFFFFFF"

using namespace std;

class FileManage {
private:
	string FileName;
	fstream File;
	char* mRecvBuffer;
	int mBuf_size;

public:
	FileManage(char *name, char* buffer, int BUFF_SIZE);
	~FileManage();
	int SetFileName(char *name); //���ϸ��� �̹� �����ϸ� �ַ� ����(0:����, 1:��������)
	int WriteFile(); //�������ڸ� �о��ٸ� �������� ����(0:���, 1:����, 2:����open�ȵ�)
};



#endif // !__FILEMANAGE
