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

	//ファイルを指定せず開いた場合(パスの個数が1つだけの場合)強制終了
	if (argc < NumArgument) {

		printf("ファイルを指定してから実行してください\n");
		return 0;

	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	
	if (not SUCCEEDED(hr)) {

		printf("COMライブラリの初期化に失敗しました\n");
		return 0;

	}

	//テクスチャコンバータ
	TextureConverter converter;

	//変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");

	return 0;

}
