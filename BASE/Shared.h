/*!
\file
\brief ��������� ����� ������ / ����������
*/
#ifndef __SHARED__
#define __SHARED__

#include "Sound.h"

struct pSharedData {
   SOUNDREAD sr;	// ������

};

extern pSharedData *shaData;

char shaInit ( void );
void shaClose( void );

#endif