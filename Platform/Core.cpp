#include "Core.h"
namespace Matrix
{
	namespace  Platform
	{
		TCHAR MatrixCore::msLogbuffer[LOG_BUFFER_SIZE];
		DWORD MatrixCore::msMainThreadID = 0;
	}
}