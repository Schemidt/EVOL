/*!
\file
\brief ��������� ����� ������ / �����������
*/
#include <Windows.h>
#include "Shared.h"

static HANDLE H;
pSharedData *shaData;

char shaInit( void )		// ������������� ����� ������ 
{
	static LPCSTR ShaName = (LPCSTR)"SharedData";
	H = CreateFileMappingA( (HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0,
								  sizeof( pSharedData ),ShaName);
	if(!H)
		return 0;

	shaData = (pSharedData *)MapViewOfFile( H, FILE_MAP_ALL_ACCESS, 0,0,
										   sizeof( pSharedData ));

	memset(&shaData->sr, 0, sizeof(SOUNDREAD));
	return 1;
}

void shaClose( void )
{
//	CloseHandle(H);
}
