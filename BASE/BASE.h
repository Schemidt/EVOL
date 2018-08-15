/*!
\file
\brief ����� Sound

������ ���� ��������� ����� Sound � ��� �����������
*/

#define _USE_MATH_DEFINES

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

//�����
#include "Shared.h"
#include "realtime.h"

//����
#include "EFXptr.h"
#include "Sound.h"
#include "Helicopter.h"

using namespace std;

#ifndef Sound_h
#define Sound_h
/*!
\brief ����� ��������� ��������� ���������
\author �������� �.�.
\version 6.0
\date  02.03.2018

����� �������� ���������� � �������, ������������ ������ ���������
*/
class Sound {
public:

	static int sourcesInUse;//!< ���������� ��� �������� ���������� �������������� ���������� (�� ����� 256)
	static int effectSlotsInUse;//!< ���������� ��� �������� ���������� �������������� ������ ��� �������� (�� ����� 16)
	static int maxSources;//!< ���������� �������� ���������� ����������� ��������� ���������� �� ����������, 256 �����������
	static int maxSlots;//!< ���������� �������� ���������� ����������� ��������� ������ ��� �������� �� ����������, 16 �����������
	static double masterGain;//!< ���������� ����������� ���������
	static double currentTime;//!< ���������� �������� ������� ����� ���������� �� ����� ������ �� USPO
	static double deltaTime;//!< ���������� ��� ������������ ��������� �������

	static double step; //!< ���
	static double tangaz;//!< ������
	static double derivTangaz;//!<�������� ��������� ������� (dtangaz/dt)
	static double hight;//!< ������
	static double velocityVectorXZ;//!< ��������� ������ �������� � ��������� vx-vz
	static double accelerationVectorXZ;//!< ��������� �� ������� �������� (dv/dt)
	static double velocityY;//!< ������������ ��������
	static double dashVectorXZ;//!< ����� (d2v/dt)
	static double accelerationVy;//!< ������������ ��������� (dvy/dt)
	static double derivStep;//!< �������� ��������� ����
	static double calcA;//!< ����� �����
	static double redTurnAcc;//!< ��������� �������� ��������� (dturn/dt)
	static double groundTouch;//!< ������� ������� �����

	static vector<double> vectorVy;//!<������ ��� �������� ����������� �� ������������ ��������
	static vector<double> vectorVXZ;//!<������ ��� �������� ����������� �� �������������� ��������
	static vector<double> vectorAccXZ;//!<������ ��� �������� ����������� �� ��������������� ���������
	static vector<double> vectorStep;//!<������ ��� �������� ����������� �� ����
	static vector<double> vectorTangaz;//!<������ ��� �������� ����������� �� �������
	static vector<double> vectorTime;//!<������ ��� �������� �����������
	static vector<double> vectorRedTurn;//!<������ ��� �������� ����������� �� �������� ���������

	static vector<double> vectorAvrEng1Turn;//!<������ ��� �������� �������� �������� ������� ���������
	static vector<double> vectorAvrEng2Turn;//!<������ ��� �������� �������� �������� ������� ���������
	static vector<double> vectorAvrRedTurn;//!<������ ��� �������� �������� �������� ���������
	static vector<double> vectorAvrStep;//!<������ ��� �������� �������� ����
	static vector<double> vectorAvrAtk;//!<������ ��� �������� ������� �����

	static double globalWindow;//!<���������� ������� ��� ������ �������� � ������� ��� �������� ��������

	unique_ptr<int[]> sourceStatus;//!< ���������� ��� ������� ���������
	unique_ptr<double[]> pitch;//!< ���������� ��� ��������� ������ ���� ����� ��������
	unique_ptr<double[]> gain;//!< ���������� ��� ��������� ��������� ����� ��������
	unique_ptr<float[]> offset;//!< 
	unique_ptr<ALuint[]> source;//!< ���������� ��� ���������
	unique_ptr<ALuint[]> buffer;//!< ���������� ��� �������
	unique_ptr<ALuint[]> effectSlot;//!< ���������� ��� ����� �������
	unique_ptr<ALuint[]> effect;//!< ���������� ��� �������
	unique_ptr<ALuint[]> filter;//!< ���������� ��� �������
	unique_ptr<string[]> filetoBuffer;//!< 
	unique_ptr<string[]> fileBuffered;//!<
	vector<string> modeSequence = { "0","0","0" };//������ ������� ������� 
	string mode = "0";//���������� �������� ������
	double switcher = 0;//���������� - ������, ��� ���������� �� �������
	double crossFadeDuration = 1;//��������� �� ������� �� crossFadeDuration ������
	int id = 0;//������� ������������ ��������

	bool soundOn = 0;//!< ���������� ��� ����������� ��������� �����
	bool soundWork = 0;//!< ���������� ��� ����������� ��������� �����
	bool soundOff = 0;//!< ���������� ��� ����������� ��������� �����
	float offsetOn = 0;
	float offsetOff = 0;
	double lengthOn = 0;//!< ���������� ��� �������� ������������ ����� � ��������, ��� ������� ��� ����� ������� ��������
	double lengthOff = 0;//!< ���������� ��� �������� ������������ ����� � ��������, ��� ������� ��� ����� ��������� ��������

	vector<double> channel = { 1,1,0,0,0,0,0 };//!< ������ ��� ������������ ������ ����� (�� ��������� ����� � ����� � ������ �����)
	int sourceNumber = 2;//!< ���������� ��� �������� ���������� ���������� ������������ �������� ����� ��������
	int bufferNumber = 2;//!< ���������� ��� �������� ���������� �������� ������������ �������� ����� ��������
	int effectSlotNumber = 0;//!< ���������� ��� �������� ���������� ������ �������� ������������ �������� ����� ��������

	Sound();//!< ����������� �� ���������, ��� ������� � 1�� ����������
	Sound(const Sound &copy);//!< ����������� �����������*/
	Sound& operator =(const Sound &copy);
	Sound(int sources, int buffers, int effectslots);//!< ����������� ��� ������� � sources �����������, buffers �������� � effectslots ������� ��������
	~Sound();//!< ���������� (�� �������)

	/*!
	\brief �������������� ��������������� �����
	\details <pre>������������� ������ ��������������� ����� ��� ��������� �������� ������ �������� ��� ���.�������:
	���� ������������ ������ ������ �������� (��� �������� - "1")
		 |
		\\|/
	���� ������ �������� (��� ��������� ����� ������������ ������ � �������� - "1")
		 |
		\\|/
	���� ���������� ������ �������� (��� �������� - "0")


	\image html phases.png "���� ��������"
	</pre>
	\param[in] status ������� ������
	\param[in] path_on ��������� �� ������ � ������� ����� ������������ ������ ������
	\param[in] path_w ��������� �� ������ � ������� ����� ������ ������
	\param[in] path_off ��������� �� ������ � ������� ����� ���������� ������
	\param[in] gain_mult ����������� ��������� ��� ��������
	\return ������ ��������� OpenAL
	*/
	virtual int play(bool status, string pathOn, string pathW, string pathOff, double gainMult);

	/*!
	\brief ��������� �����, ���������� � ��������� � ���������
	\details
	<pre>
	��������� ������, ��������� ������� �� file_path, ���������� � ���������,
	��������� �������� ��������� �������� ������� � �������� offset.
	������������ ����� ������������ ��� � �������
	</pre>
	\param[in] Buffer ������ ������
	\param[in] Source ������ ���������
	\param[in] offset ����� �� ������ �����, ���
	\param[in] file_path ������ ��� �����
	\return ������ ��������� OpenAL
	*/
	int setSource(ALuint *Buffer, ALuint *Source, string file_path);

	int switchBuffer(ALuint *Buffer, ALuint *Source);

	int setAndDeploySound(ALuint *Buffer, ALuint *Source, double offset, string file_path);

	double getAverange(vector<double> &vectorOfParameters, double seconds);
};

/*!
\brief ����� ������� ���������
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ������� - ���������
*/
class Reductor : public Sound
{
public:

	//bool setup = 0;

	bool hovering = 0;/*!< ���������� ��� ������� ������ �� ������� */
	string eq[2];/*!< ���������� ��� ����������� �������� ������ */
	string pinkNoise;/*!< ���������� ��� ����������� �������� ������ */
	string beats;/*!< ���������� ��� ����������� �������� ������ */
	string takeOff;/*!< ���������� ��� ����������� �������� ������ */
	Smoother sm;
	double flapOn = 0;
	double reperTurn = 0;
	string reperSet;

	Reductor();

	~Reductor();
	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] h ������ �������� �������������� ���������
	\param[in] sr ������ �������� ������� ��������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(Helicopter &h, SOUNDREAD &sr);
};

/*!
\brief ����� ������� ���������
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ������� - ���������
*/
class Engine : public Sound
{
public:

	static int engCount;/*!< ���������� ��� ���������� ������������������ ���������� � ��������� */
	double phase;//!<���� ��� ����������, ����� �� ����� �� ���������(0-1, ������� �� 0.33 ��� ������� ������ �������, �.�. ��������� � 33% * n ��������� ������������)
	int engNum;//!<����� ���������
	char angle;
	string eq[2];/*!< ���������� ��� ����������� �������� ������ */
	double reperTurn = 0;
	string reperSet;

	Engine();

	~Engine();
	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] status_on ���������� ������� �������
	\param[in] status_off ���������� ������� ���������
	\param[in] parameter ������� ���������
	\param[in] h ������ �������� �������������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(bool status_on, bool status_off, bool status_hp, double parameter, Helicopter &h);
};

/*!
\brief ����� ������� ���������
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ������� - ���������
*/
class Vsu : public Sound
{
public:

	double vsuDownTimer = 0;
	double vsuUpTimer = 0;
	double vsuTurnover = 0;

	string init = "NULL";

	string eq[2];/*!< ���������� ��� ����������� �������� ������ */

	Vsu();

	~Vsu();
	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] status_on ���������� ������� �������
	\param[in] status_off ���������� ������� ���������
	\param[in] parameter ������� ���������
	\param[in] h ������ �������� �������������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(SOUNDREAD &sr, Helicopter &h);
};

/*!
\brief ����� ������� - ���� �������� �� ���
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ����� �������� �� ��� � ��
*/
class Runway : public Sound
{
public:

	string eq;/*!< ���������� ��� ����������� �������� ������ */
	Smoother sm[2];

	Runway();

	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] h ������ �������� �������������� ���������
	\param[in] sr ������ �������� ������� ��������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(Helicopter &h, SOUNDREAD &sr);
};

/*!
\brief ����� ������� - ������� �����
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ����� ������� �����
*/
class VintFlap : public Sound
{
public:

	int flapIndicator = 0;
	int prevFlapIndicator = 0;
	string key[3];/*!< ���������� ��� ����������� �������� ������ */
	double flapOn = 0;

	Smoother sm;

	VintFlap();

	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] h ������ �������� �������������� ���������
	\param[in] sr ������ �������� ������� ��������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(Helicopter &h, SOUNDREAD &sr);
};

/*!
\brief ����� ������� - ������ �����
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ����� ������ �����
*/
class VintSwish : public Sound
{
public:

	double reperTurn = 0;
	string reperSet;
	VintSwish();

	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] h ������ �������� �������������� ���������
	\param[in] sr ������ �������� ������� ��������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(Helicopter &h, SOUNDREAD &sr);
};

/*!
\brief ����� ������� - ���
\author �������� �.�.
\version 3.0
\date  06.03.2018

����� ������������ ������ ����� ������� - ��� (������� ����������������� �������)
*/
class Skv : public Sound
{
public:

	string eq[2];/*!< ���������� ��� ����������� �������� ������ */
	string harm;
	Skv();

	/*!
	\brief ���������� ������ ������ �����
	\details ���������� ������ ��������� ���������� ������������ �������� OpenAL
	\param[in] h ������ �������� �������������� ���������
	\param[in] sr ������ �������� ������� ��������� ���������
	\return ������ ��������� OpenAL
	*/
	int play(Helicopter &h, SOUNDREAD &sr);

};

/*!
\brief ����� ������� - ����
\author �������� �.�.
\version 1.0
\date  09.06.2018

����� ������������ ������ ���� ������
*/
class Crane : public Sound
{
public:

	/*!
	\brief �������������� ��������������� �����
	\details <pre>������������� ������ ��������������� ����� ��� ��������� �������� ������ �������� ��� ���.�������:
	���� ������������ ������ ������ �������� (��� �������� - "1")
	|
	\\|/
	���� ������ �������� (��� ��������� ����� ������������ ������ � �������� - "1")
	|
	\\|/
	���� ���������� ������ �������� (��� �������� - "0")


	\image html phases.png "���� ��������"
	</pre>
	\param[in] status ������� ������
	\param[in] path_on ��������� �� ������ � ������� ����� ������������ ������ ������
	\param[in] path_w ��������� �� ������ � ������� ����� ������ ������
	\param[in] path_off ��������� �� ������ � ������� ����� ���������� ������
	\param[in] gain_mult ����������� ��������� ��� ��������
	\return ������ ��������� OpenAL
	*/
	int play(char status, string path_on, string path_w, string path_off, double gain_mult);

};

class Gear : public Sound                                                                              // ����� ����� (������/������)
{
public:

};
#endif

/*!\brief ������� ������� OpenAL*/
void freeOpenAL();

/*!
\brief ���������� Crossfade
\details ������������ ������� ������� 1�� ������ � ������ ����� ���������� ��������� 1�� ������ � ��������� ��������� ������, �� ���� ��������� ���������
�� �������� fadeLimit � riseLimit.
<pre>
���� ��������� ������ ���������� �� � �������� [0..1],
�� ����� ������� ��������� ��������� - �.�. ���������� ��������� ����������� ������
\image html parametricalCrossfade.png "CrossFade"
</pre>
\param[in] fadeGain ��������� ����������� ���������
\param[in] riseGain ��������� ������������ ���������
\param[in] parameter �������� ���������
\param[in] fadeLimit �������� ���������, ��� ������ ��������� ���������� ������ ������ 1
\param[in] riseLimit �������� ���������, ��� ������ ��������� ����������� ������ ������ 1
\param[in] gainMultiplicator ��������� ��������� �������
\return 1 ,���� ��������� ���������� ������ ��������� 0, � ����������� 1
*/
int parametricalCrossfade(double *fadeGain, double *riseGain, double parameter, double fadeLimit, double riseLimit);
/*!
\brief ���������� Crossfade
\details ������������ ������� ������� 1�� ������ � ������ ����� ���������� ��������� 1�� ������ � ��������� ��������� ������, �� ���� ��������� ���������
�� �������� fadeLimit � riseLimit.
<pre>
���� ��������� ������ ���������� �� � �������� [0..1],
�� ����� ������� ��������� ��������� - �.�. ���������� ��������� ����������� ������
\image html parametricalCrossfade.png "CrossFade"
</pre>
\param[in] fadeGain ��������� ����������� ���������
\param[in] riseGain ��������� ������������ ���������
\param[in] parameter �������� ���������
\param[in] fadeLimit �������� ���������, ��� ������ ��������� ���������� ������ ������ 1
\param[in] riseLimit �������� ���������, ��� ������ ��������� ����������� ������ ������ 1
\param[in] gainMultiplicator ��������� ��������� �������
\return 1 ,���� ��������� ���������� ������ ��������� 0, � ����������� 1
*/
int timeCrossfade(double &fadeGain, double &riseGain, double crossFadeDuration, double timer);
/*!\brief ���������� ��������� �� ������� ���������� EFX*/
void setEFXPointers();

/*!
\brief ���������� ������������ ���������� ��������� ����������

\return ������������ ���������� ��������� ����������, 0 � ������ ������
*/
int getMaxAvaliableSources();
/*!
\brief ��������� �����
\details ��������� ����� (���� ����� �������� ����� � ���� ����� ������������ ���������� ������ (��������������� ����������� ������) � ���������� �������� ������ �������� �����. ���� ���� ����� ����� ����� �������� (�� �180� �� +180�) � ����������� �� ����������� ������.
���� ��������� ����� �������� � ��������� �������� ����� �����(���������� �����), �� ���� ����� �������� ����� ��������� �������������.���� ��������� ����� �������� �� ������� ���� ������, �� ���� ����� ����������� �������������.)

��� ���������� �����:
\code
tangaz = tangaz * M_PI / 180.0;
calcA = atan(tan(tangaz) - (2 * deltaHigh) / ((velocityXPrevious + velocityVectorXZ) * cos(tangaz) * periodCalc));
calcA = calcA * 180 / M_PI;
\endcode

\param[in] velocityVectorXZ ��������� �������� � ������� ������ ������� t0
\param[in] velocityXPrevious ��������� �������� � ������ ������� t0 + periodCalc
\param[in] tangaz ������ � ������ ������� t0 + periodCalc
\param[in] deltaHigh ������� ������ ����� ���������� ���������
\param[in] periodCalc ������� �� ������� ����� ���������� ���������
\return �������� ����� ��� ������ ����������
*/
double attack(double velocityVectorXZ, double velocityXPrevious, double tangaz, double velocityY);





