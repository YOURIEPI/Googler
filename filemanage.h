#pragma once

#ifndef __FILEMANAGE
#define __FILEMANAGE

#include <iostream>
#include <fstream>
#include <string>
#define BUFFERSIZE (1024)
#define STRING_COMPARE "FFFFFFFF"

using namespace std;

class FileManage {
private:
	string FileName;
	fstream File;
public:
	FileManage(char *name);
	~FileManage();
	int SetFileName(char *name); //���ϸ��� �̹� �����ϸ� �ַ� ����(0:����, 1:��������)
	int WriteFile(char *buffer); //�������ڸ� �о��ٸ� �������� ����(0:���, 1:����, 2:����open�ȵ�)
};



#endif // !__FILEMANAGE
