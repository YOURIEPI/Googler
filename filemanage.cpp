#include "filemanage.h"

FileManage::FileManage(char* buffer, int BUFF_SIZE) {
	FileOpenFlag = 0;
	this->mRecvBuffer = buffer;
	this->mBuf_size = BUFF_SIZE;
}

FileManage::~FileManage() {
	File.close();
}

int FileManage::SetFileName(char *name) {
	this->FileName = name;
	if (FileName.size() > 0) {
		File.open(name, ios::out);
		if (File) {
			FileOpenFlag = 1;//���� ����
		}
	}
	return FileOpenFlag;
}

int FileManage::SetFileNameFromBuf() {
	this->FileName = this->mRecvBuffer;
	if (FileName.size() > 0) {
		File.open(FileName, ios::out);
		if (File) {
			FileOpenFlag = 1;//���� ����
		}
	}
	return FileOpenFlag;
}

int FileManage::WriteFile() {
	if (!FileOpenFlag)return 2;//����open�ȵ�
	if (strcmp(mRecvBuffer, STRING_COMPARE) == 0)return 1; //���Ṯ�ڿ�
	File.write(mRecvBuffer, mBuf_size);
	return 0;
}

int FileManage::IsOpen() {
	return FileOpenFlag;
}