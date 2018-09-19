/*!
\file
\brief ������� � ������ ������ ���������� / ����������
*/
#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "fstream"
#include "string"
#include "conio.h"
#include "regex"
#include "memory"
#include "vector"
#include "math.h"
#include "windows.h"
#include "tlhelp32.h"

#define MIDL_PASS

#include "AL\al.h"
#include "AL\alc.h"
#include "AL\alut.h"
#include "AL\alext.h"
#include "AL\efx.h"

using namespace std;

template <class T>
/*!
\brief ������ ������������� �������
\details ������������ ������ � �������� ���������
*/
void Free(T &x)
{
	delete x;
	x = NULL;
}

#pragma pack ( push, 1 )

/*!
\struct WAVEHEADER

��������� ������������� ������������ wave �����
*/
typedef struct
{
	char			szRIFF[4];
	long			lRIFFSize;
	char			szWave[4];
	char			szFmt[4];
	long			lFmtSize;
	WAVEFORMATEX	wfex;
	char			szData[4];
	long			lDataSize;
} WAVEHEADER;
#pragma pack ( pop )

class Smoother
{
public:

	bool firstAttempt = 1;
	double newDbGain = 0;
	double dbPerSec = 3;//�������� ����������/�������� 3��

	double delay(double nsGain, double deltaTime);
};

/*!
\brief ����� "�����"
\details ���������� ����� �����
*/
class point {
public:
	double x = 0;//��������
	double y = 0;//��������

	point() { }

	point(double xi, double yi)
	{
		x = xi;
		y = yi;
	}

	//!<������ x � y �������
	point swap()
	{
		double _x;
		double _y;

		_x = y;
		_y = x;
		y = _y;
		x = _x;

		return *this;
	}

	point& operator =(const point &copy);
};

/*!
\brief ���������� �������� �������
\details ���������� �������� ������� �������� ���������� (�������)
\param[in] p ����� �������
\param[in] n ���������� �����
\param[in] parameter �������� ���������� � ������� �����
\return ���������� �������� �������
*/
double getValue(double parameter, int n, point p, ...);

/*!
\brief ���������� �������� �������
\details ���������� �������� ������� �������� ���������� (�������)
\param[in] p1 ����� �������
\param[in] p2 ����� �������
\param[in] x �������� ���������� � ������� �����
\return ���������� �������� �������
*/
double getValue(point p1, point p2, double x);

/*!
\brief ���������� �������� �������
\details ���������� �������� ������� �������� ���������� (�������), � ������ ����������� �������� �������
\param[in] p1 ����� �������
\param[in] p2 ����� �������
\param[in] x �������� ���������� � ������� �����
\param[in] limit ������ �������
\param[in] w ���������� ������������ ������� ��� ������ ������
\return ���������� �������� �������
*/
double getValue(point p1, point p2, double x, double limit, string w);

/*!
\brief ���������� �������� �������
\details ���������� �������� ������� �������� ���������� (�������), � ������ ����������� �������� �������
\param[in] p1 ����� �������
\param[in] p2 ����� �������
\param[in] x �������� ���������� � ������� �����
\param[in] low_limit ������ ������ �������
\param[in] hi_limit ������� ������ �������
\return ���������� �������� �������
*/
double getValue(point p1, point p2, double x, double low_limit, double hi_limit);

/*!
\brief ���������� �������� �������
\details ���������� �������� ������� � ����� offset �������� ����������, �������� �����
\param[in] &value ������ ����� �������
\param[in] offset �������� ���������� � ������� �����
\return ���������� �������� �������
*/
double getParameterFromVector(vector<point> &value, double offset);

//
vector <point> getVectorFromFile(string filename);

/*!
\brief ���������� ����� ������� ������ �������
\details ���������� ����� ������� ������ �������������� ������� � ������� ��������� ������
\param[in] &time ������ �����
\param[in] offset �������� ���������� � ������� �����
\return ����� ������� ������
*/
int binSer(vector<point> &points, double offset);

/*!
\brief ��������� ���������� ������������
\details ��������� ������������ ��� fx � ����� x,�� ������� [x0,x2], ��� ������������ ������������ x0,x1,x2 � ��������� fx0,fx1,fx2, ���� x0=x1 ��� x1=x2
����������� �������� ������������

��� ���������� ������������:
\code
a2 = ((fx2 - fx0) / ((x2 - x0)*(x2 - x1))) - ((fx1 - fx0) / ((x1 - x0)*(x2 - x1)));
a1 = ((fx1 - fx0) / (x1 - x0)) - (a2*(x1 + x0));
a0 = fx0 - a1 * x0 - a2 * x0*x0;
return fx = a0 + a1 * x + a2*x*x;
\endcode

\param[in] x0 �������� 1�� �����
\param[in] fx0 �������� 1�� �����
\param[in] x1 �������� 2�� �����
\param[in] fx1 �������� 2�� �����
\param[in] x2 �������� 3�� �����
\param[in] fx2 �������� 3�� �����
\param[in] x �������� ������� fx
\return �������� fx � ����� x
*/
double interpolation(point p1, point p2, point p3, double x);

/*!
\brief ��������� �������� ������������
\details � ������ x>x1 � x<x0 - ���������� ��������� ��������

��� ���������� ������������:
\code
fx = fx0 + ((fx1 - fx0) / (x1 - x0))*(x - x0);
\endcode

\param[in] x0 �������� 1�� �����
\param[in] fx0 �������� 1�� �����
\param[in] x1 �������� 2�� �����
\param[in] fx1 �������� 2�� �����
\param[in] x �������� ������� fx
\return �������� fx � ����� x
*/
double interpolation(point p1, point p2, double x);

/*!
\brief ��������� ������� ��������
\details ��������� ������� ��������

\param[in] szExe ��� ��������
\return True ���� ������� ����������� � �������, ����� False
*/
bool IsProcessPresent(char * szExe);

/*!
\brief ��������� ����������� ��������� � ��������

\param[in] coef ����������� ���������
\return ��������
*/
double toDb(double coef);

/*!
\brief ��������� �������� � ����������� ���������

\param[in] db ��������
\return ����������� ���������
*/
double toCoef(double db);

/*!
\brief ��������� ������������ ����� �� ����������� ��������

nullsAfterInt - ��������� �������� 1/m, ��� m = 10^n, n �������� 0��� ����� �������
/code
roundFloat(3.34678, 0.01) -> 3.35
roundFloat(3.34678, 0.001) -> 3.347
/endcode

\param[in] x �����
\param[in] nullsAfterInt ��������
\return ����������� ��������
*/
double roundFloat(double x, double nullsAfterInt);

/*!
\brief ��������� ������������ WAVE �����
\details ��������� ������������ ��������� WAVE �����
\param[in] filename ��� �����
\return ������������ WAVE �����
*/
double getLengthWAV(string filename);

/*!
\brief ��������� ����� �������
\details ������������� ������ ������ ��� ������������ ������ ��� ��������� ������������� ��������� ������ �
��������� � ����� OpenAL
\param[in] Buffer ������ ������
\param[in] path ��� �����
\param[in] channelsCount ������������ ��������� ������
\param[in] channels ������ ��� ������
\return 1 ���� �������, ����� 0
*/
int setBuffer(ALuint Buffer, string path, vector<double> channels);

double getPitch(double maxPar, double currentPar, double supposedPar);
