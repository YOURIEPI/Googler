#include "filemanage.h"

FileManage::FileManage(char* buffer, int buf_size) {
	FileOpenFlag = 0;
	this->mRecvBuffer = buffer;
	this->mBuf_size = buf_size;
}

FileManage::~FileManage() {
	if (File) {
		File.close();
	}
}

int FileManage::SetFileName(char *name) {
	this->FileName = name;
	if (FileName.size() > 0) {
		File.open(name, ios::out);
		if (File) {
			cout << "Recive File:" << name<<endl;
			FileOpenFlag = 1;//���� ����
		}
		else {
			cout << "ERRER Recive Wrong File Name :" << name << endl;
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
	File.write(pk->buff, STRUCT_SIZE);
	return 0;
}

int FileManage::FileEnd() {
	if (!FileOpenFlag)return 2;//����open�ȵ�
	if (pk->meta < 0 || pk->meta > STRUCT_SIZE)return 3;//�߸��� ����
	File.write(pk->buff,pk->meta);
	FileOpenFlag = 0;
	return 0;
}

int FileManage::RecvPacket() {
	pk = (packet*)mRecvBuffer;
	switch (pk->meta)
	{
	case -2://�̸�
		return SetFileName(pk->buff);
		break;
	case -1://����
		return WriteFile();
		break;
	default://0~buffsize ���볡
		return FileEnd();
		break;
	}
}

int FileManage::IsOpen() {
	return FileOpenFlag;
}