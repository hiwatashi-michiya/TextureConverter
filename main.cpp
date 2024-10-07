#include <cstdio>
#include <cstdlib>
#include "TextureConverter.h"
#include <Windows.h>

enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument

};

int main(int argc, char* argv[]) {

	//�t�@�C�����w�肹���J�����ꍇ(�p�X�̌���1�����̏ꍇ)�����I��
	if (argc < NumArgument) {

		printf("�t�@�C�����w�肵�Ă�����s���Ă�������\n");
		return 0;

	}

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	
	if (not SUCCEEDED(hr)) {

		printf("COM���C�u�����̏������Ɏ��s���܂���\n");
		return 0;

	}

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");

	return 0;

}
