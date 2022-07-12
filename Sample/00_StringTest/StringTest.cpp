#include "Platform/File.h"
#include <iostream>


using namespace Matrix;

int main()
{
	using namespace Platform;

	//{} 花括号默认初始化为0
	TCHAR dir[MAX_FILE_PATH_SIZE] = {};

	MXGetCurrentDirectory(dir);
	for (unsigned i = 0; i < MAX_FILE_PATH_SIZE; i++)
	{
		MXSprintf(_T("print: %d =  %x end\n"), i, dir[i]);
	}
	MXSprintf(_T("print: %s EOF\n"), dir);

	MXStrcat(dir, MAX_FILE_PATH_SIZE, _T("/FileDemo.json"));
	MXSprintf(_T("print: %s EOF\n"), dir);

	struct MyStruct
	{
		char name = 'c';
		int num = 99;
	} mystruct;
	MFile jsonFile(dir, MFile::EOpenMode::OM_AT);
	jsonFile.Write(dir, sizeof(TCHAR), MXStrLen(dir));
	jsonFile.Write(&mystruct, sizeof(MyStruct), 1);

	jsonFile.Open(_T("D:\\GitDemo\\MatrixEngine\\Samples\\Demo02/FileDemo.json"), MFile::EOpenMode::OM_AT);
	jsonFile.DebugInfo();

	return 0;
}