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
	int mBuf_size;
	char* mRecvBuffer;
	string FileName;
	fstream File;
	char FileOpenFlag;

public:
	FileManage(char* buffer, int BUFF_SIZE);
	~FileManage();
	int SetFileName(char *name); //���ϸ��� �̹� �����ϸ� �ַ� ����(0:����, 1:��������)
	int SetFileNameFromBuf(); //���ۿ��� ���� ������
	int WriteFile(); //�������ڸ� �о��ٸ� �������� ����(0:���, 1:����, 2:����open�ȵ�)
	int IsOpen(); //������ �����ִ��� Ȯ��(1:����,0:����)
};



#endif // !__FILEMANAGE
