#include "filemanage.h"

#define DEBUG false

FileManage::FileManage(char* buffer) {
	FileOpenFlag = 1;
	this->mRecvBuffer = buffer;
}

FileManage::~FileManage() {
	if (File) {
		File.close();
	}
}

int FileManage::SetFileName(char *name) {
	this->FileName = name;
	if (FileName.size() > 0) {
		cout << "Recive File Name:" << name <<"<-"<< endl;
		File.open(name, ios::out|ios::binary);
		if (File) {
			FileOpenFlag = 0;//���� ����
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
		File.open(FileName, ios::out|ios::binary);
		if (File) {
			FileOpenFlag = 0;//���� ����
		}
	}
	return FileOpenFlag;
}

int FileManage::WriteFile() {
	if (FileOpenFlag)return 2;//����open�ȵ�
	File.write(pk->buff, STRUCT_SIZE);
	return 0;
}

int FileManage::FileEnd() {
	if (FileOpenFlag)return 2;//����open�ȵ�
	if (pk->meta < 0 || pk->meta > STRUCT_SIZE)return 3;//�߸��� ����
	File.write(pk->buff,pk->meta);
	File.close();
	FileOpenFlag = 1;
	cout << "comlite!" << endl;
	return 0;
}

int FileManage::RecvPacket() {
	pk = (packet*)mRecvBuffer;

	if(DEBUG)
		cout << "meta:" << pk->meta << ",buf:" << pk->buff << "<-\n";

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