/*!
\file
\brief �������� ���� ���������

������ ���� ��������� ��� �������� ��������� � ���������� �� ������.
���������� ������ Sound � �����������.
*/

/*! \mainpage ������������
��� ������������ ��������� �� ��������� �������:
- \subpage intro
- \subpage advanced
- \subpage todo
*/

/*! \page intro ��������
<pre>
������ ������������ �������� ������ ������������ ����������� � ������ ������� ��.
</pre>

\section install_sec ���������
<pre>
�������� ����� � �������� � ����� ������� �����
</pre>

\section Use_sec �������������
<pre>
��������� �� ���������� ������ "BASE.exe" � ����������� ����������:
"mi_8_mtv5","mi_8_amtsh","mi_26","mi_28","ka_226","ansat","ka_27","ka_29".
������:
\code{.cpp}
		../BASE/BASE.exe mi_8_mtv5
\endcode

</pre>
*/

/*! \page advanced �������� ��������
\tableofcontents
<pre>
���� ����� �������� ��� �������� ���������, ������� ,�� ������ ������������,
����� ���� ��������� �������� ������������ ��� ������������
</pre>

\section sec0 ����� ��������� � ��������� ������������������
<pre>
������ �� ����� ������� �� 4 �����:
�	������ ������ ������� ����� ����� ������
�	����� ������������ ������ ��������� � ��� �������� ���������, ������������ ��������� � ���� �������� ������
�	����� ������������ ��������� � ������� �������� - ������ ���������
�	������������� �������� �������� �������� (�main�)
���� ������������� ������ ����������, ��������� ��� ����������� ��������, �� ����� ������� ������� ���:
1.	��������� ������ ���������, ������� ���������� ������������ ����� � ����� ���������, �� �����.
2.	����� ����� ������ ��������� �������� ����� ����������.
3.	���� ����� ���������� ������������ ������� �������� ������� �����, � �� ������������ �� ����� � �� ���������.
4.	������ ���������������� �� ������ ��������� ��� ����������� �������� � ����������� ��������� ��� ���������� ����� � ���� ���������� �� ���������� ������.
5.	��� ���������� ������� ����������� ������� ����� � ������ ��������������.
\image html seqD.png "��������� ������������������"
</pre>

\section sec1 ��������� "main"
<pre>
������ �������� ������� ���������� ������������� ����� ����������: ����� ����� ��������������� �� ���������� ������ �� ���������,
������������ ��������� ���������� OpenAL � ������ ������ ��������� � ��������������� - � �����.
������ ���� ������� ���������� ������ ����������� ���������� ��,
������� �� ���� �������� �� ��������� ������ � ��������� �������� ���������: ������� �� �������������,
���������� ������ �play�, ������� ������������� ��������.
����� ������������� ���������� ��������� ���� �������� ��������� ����������� � ����������� �����.
\code{.cpp}
{AL_init}//������������� OpenAL
while(true)//����������� ����
{
	{Calc_par1}//������� ����������, �������� �����, 1�� � 2�� �����������
	{CAlc_par2}

	{easy_sound0}//������������� ������� - ����� ����������, c ������������� �������, �������� ���
	{easy_sound1}
	{easy_sound2}
	{hard_sound0}//������������� ������� - ����� ����������, � ���������� �������, �������� ��������
	{easy_sound2}
	{hard_sound1}

	//����� �� ����� ���������� ������ ��� �������� ����������
}
{AL_deinit}//��������������� OpenAL
\endcode
</pre>

\subsection subSecCalculating ������� ����������� ����������
<pre>
� ����������� ���������� ���������:
�	������� �������� �������� ���������� (������� ���, ������� �������);
�	������ � ������ ����������� (���������, �����);
�	����������� - ������������� ��� ������������ ������ - ��������� (�����)
��� �������� �������� �������� ������������ ����� ����������� ��������:
�������� � ������ ����� ����������� ����� �������� �������� �������� ������� �� ���������� ������.
��� ����� ��� ������� ������������ ��������� ���������� ������� �������� �� ����� Sound::globalWindow,
���� ���������� �������� �������� �� ������� ���������� �������, �� ������� ������������� ������������
(�� ���� ������� ����� ��������� ��������).
\see Sound::getAverange();

����� �������� ��� ������� ��������:
\code{.cpp}
timerAvr += Sound::deltaTime;
//���� ����������� ������ ���� ��������� - ����������� �������� � ������ �������
if (timerAvr > Sound::globalWindow)
{
	if (!Sound::vectorAvrEng1Turn.empty())
	{
		Sound::vectorAvrEng1Turn.erase(Sound::vectorAvrEng1Turn.begin());
	}
	if (!Sound::vectorAvrEng2Turn.empty())
	{
		Sound::vectorAvrEng2Turn.erase(Sound::vectorAvrEng2Turn.begin());
	}
	if (!Sound::vectorAvrRedTurn.empty())
	{
		Sound::vectorAvrRedTurn.erase(Sound::vectorAvrRedTurn.begin());
	}
	if (!Sound::vectorAvrStep.empty())
	{
		Sound::vectorAvrStep.erase(Sound::vectorAvrStep.begin());
	}
	if (!Sound::vectorAvrAtk.empty())
	{
		Sound::vectorAvrAtk.erase(Sound::vectorAvrAtk.begin());
	}
}
//������ �������� � ����� ������� ������ �������� �����
Sound::vectorAvrEng1Turn.push_back(localdata.eng1_obor);
Sound::vectorAvrEng2Turn.push_back(localdata.eng2_obor);
Sound::vectorAvrRedTurn.push_back(localdata.reduktor_gl_obor);
Sound::vectorAvrStep.push_back(Sound::step);
Sound::vectorAvrAtk.push_back(Sound::calcA);
\endcode

��� �������� ����������� ������������ ��������� ������ ������������� ���������� �����������.
��� ��� ������� �������� ����������� ���������� ���������� ������ �������� ����� �����������( (Y_������� - Y_�������)/(dt) ).
��� dt = Sound::window.
������ ������� ������������ �������� ��� ����������� �� ������:
\code{.cpp}
//���� �� ������ ������� ��������� ������ - ��������� ����������
//���� ����������� ������ ���� ��������� - ����������� �������� � ������ �������
while (periodCalc >= window && Sound::vectorTime.size() > 2)
{
	if (!Sound::vectorTime.empty())
	{
		Sound::vectorHight.erase(Sound::vectorHight.begin());
		Sound::vectorTime.erase(Sound::vectorTime.begin());
	}
	periodCalc = Sound::currentTime - Sound::vectorTime.front();
}
//�������� �������� ������ ���� ����� ����������
if (Sound::vectorTime.back() != Sound::currentTime)
{
	Sound::vectorTime.push_back(Sound::currentTime);
	Sound::vectorHight.push_back(Sound::hight);
}
//���� ������ ������� �� ���� - ����� ����������, ����� ��������� �����������
if (!Sound::vectorTime.empty())
{
	//�����������
	periodCalc = Sound::currentTime - Sound::vectorTime.front();
	if (periodCalc > 0)
	{
		Sound::velocityY = (Sound::hight - Sound::vectorHight.front()) / periodCalc;
	}
}
\endcode
</pre>

\section sec2 ����� "Sound" � ���������
<pre>
������ ����� � ��� ���������� ����������, ����� ������� ��������� �������� OpenAL �� ��������� �������� ����������.
����������� ������ ��������� ����� �������, ��� ��� ���������� ������ �������� ���������� ������� ��� ���� ����� ������ ���� �Sound� � ���������������� ������� �play�.
����������� ������ �� ��������� ������� 3 ������ � 1 �������� OpenAL, ��� ���������� ��� ����������� ����������� ���������, � ���������� �� � �����������, ����� ���������� �������� ���� ������.
��� ������������� ������� �play� � ��� ���������� ������� ������ ����������.
�1� ������������� ��������� ����������, ������� �� ���������� ��������� � ���� ������, �0� ������������� ����������.
���� ������ ���������������� ������������� �� ��������� � ��� ��������� ������������ 1 ���������� (���������� � �����������),
�� ����� ���������� ����� ������ �������� (���� ��������, ������, ����� ���� ����������� ���������� �������� ����� ����������� �����������).
���� ������ ���������������� ������������� � ���������� ����������� ����������� ���������� � �������, � ����� �������� ��������,
� ��� ��������� ������������ ����������� ����������� (������, �������������� ��������, ������������ ��������, ���������, �����, � �. �.),
�� ����� ���������� ����� ������ ��������.
��� �������, ��� ������� ��������� ������� ��������� ��������� �������� ������ �Sound�,
��� ���������������� ����� �play� � ����������� ����� ����������.
</pre>

\subsection subsec0 "�������" ����������
<pre>
� ���� ������������ �������� ��������� �� ������� ����������, ��� ����������� ��������� � ���������� �������� ����� 3 ���������� ��������� ������: ������, ����� ������, ����������.
���������� � ������ ������ ����� �������� ����������� �������� �������: ���������� �����, ���������� ��������������� ����� �� ������������ ������ � ��������� �����.
������ � ��������� ��������� ����� ������������� �� 2� ���������.
������ �� ����� ������� ��������� ����� ��������� ��� ���������������� ������ �������� ��������� � ������������ ����� �������.
���������� ������ ������ ������� ��� ��������� ������� ���������� � �������� ������� ���������.
������ ������� ��������� �� ���������� ��������:
1.	��� ����������� �������� ������ �������� (1) ��������������� ������ ������������ �������
2.	�� �� ��������� ��������������� � ����� ���� ��������������� ������ �������
3.	��� ����������� �������� ���������� �������� (0) ��������������� ������ ����������
������ ������� ��������� ����������� ���������� 1�, 2� ��� ���� ���, � ����� ������� �� ����� �������� ��������� ��������������� ��������� �NULL�.
�������� ��������� �������� ��������� ������� ������� � �������:
<table>
<caption id="multi_row">������� ���������� ������� ���������� �������</caption>
<tr><th>���������� ���<th>����������� ������� (���������/�����)<th>���������
<tr>
<td>��� ���� ������������
<td>\image html 111.png width=250 height=150
<td>���������������� ��������� ��� ��� ��������� �������� ������.
(�������������� 36 � 115, ���)
<tr>
<td>������ �����������
<td>\image html 011.png width=250 height=150
<td>���������� ������� �� ����� ������ ��� �������� � 1, ������� ����� ��� 0.
<tr>
<td>��������� �����������
<td>\image html 110.png width=250 height=150
<td>������� ������� �� ����� ������, ���������� ��������� ������� ��� �������� � 0
(������ ��������� �����)
<tr>
<td>����������� ������
<td>\image html 101.png width=250 height=150
<td>�������������� ��� ������ �� ������ ������ �� ������,
� ����� ������ ����� ������������ ������ ������ ���� ��������� � ���������� ������ ��� ����������
(���� ������� �����)
<tr>
<td>������ ������
<td>\image html 010.png width=150 height=150
<td>�������� ��� �������� �� ������� �������� ���� ���������� � �������� (�����������, ��� ���, ���)
<tr>
<td>������ ������
<td>\image html 100.png width=150 height=150
<td>�������� ��� ��������������� ��������� �������� (��������, ��������, �����)
<tr>
<td>������ ����������
<td>\image html 001.png width=150 height=150
<td>�������� ��� �������� ���� ������� ���������� ������ ��� �������� 0
(���������� �� �������, �������� ����������)
<tr>
<td>��� ���� �����������
<td>0
<td>���� �� ���������������, �������������� ������
</table>
������ ������������� "��������" ����������:
\code{.cpp}
Sound *pts;
//���
if (helicopter.ptsFactor)
{
	if (localdata.p_pts)//������� �������� �������
		if (!pts)//���� ������ �� ������
		{
			pts = new Sound;
		}
		if (pts)//���� ������ ������ - ���������� ���
		{
			pts->play(localdata.p_pts, helicopter.fullName["pts_on"], helicopter.fullName["pts_w"], helicopter.fullName["pts_off"], helicopter.ptsFactor);//������������� ���� - ���������� ��������� ����� � play
			if (pts->sourceStatus[0] != AL_PLAYING)//������� �������� �������
		{
		Free(pts);//������� ������
		}
	}
}
\endcode
</pre>

\subsection subsec1 "�������" ����������
<pre>
�������, ��� ���������� �� ����� �� ����� ����������, ��� ��������,
�� � ����� ������ ����������� ������������ �������������� ��������.
������� �������� �������� ��� ���������� ��������� ��������� �������� ������ ����������� � ��������,
����������� �������� ������� ������ �������� ����� � ������������ ������������� ������ ��.
� ����� ���������: ������� ��������,
���������, ���� ������� �����, ����� �������� �����, �������� �� �������� ������.
��� ������������ ���������� ����� ����������� �� � ��������� ��������� �������-������� ��������� ������ �
������������ �������� ����� ������� � ��������� ������� ������� �� ����� ������ ��.
������ ������������� "��������" ����������:
\code{.cpp}
Engine *eng[2];
if (localdata.p_eng1_zap | localdata.eng1_obor > 0)
{
	if (!eng[0])//���� ������ �� ������
	{
		eng[0] = new Engine;//������� ������
	}
}
if (eng[0])//���� ������ ������ - ���������� ���
{
	eng[0]->channel[0] = 1;//magic numbers//1//L
	eng[0]->channel[1] = 1;//-1
	eng[0]->play(localdata.p_eng1_zap, localdata.p_eng1_ostanov, localdata.eng1_obor, helicopter);
	if (localdata.eng1_obor == 0)//������� �������� �������
		Free(eng[0]);//������� ������
}
\endcode
\sa
Reductor::play()
Engine::play()
VintFlap::play()

</pre>

\section sec3 ���������� "Helicopter"
<pre>
������ ��������� ������ ������ "Helicopter"
</pre>
\subsection subSecNames ����������� �����
<pre>
������ ����� ���������� ����� ������ ���� ������, ������� ������������ ��� �������� ������� OpenAL.
����� �������� ������� ������� ������ ���������� ����� ������, ������� ��������� � �������� �������� ��������� ���������� ������ ��,
������������ ���� � ���������� ������: %������%/%��������%.wav.
������ ������ ������ ��� mi_26:
\code
setPath("mi_26")
{
	...
	//����������
	shortName["sturm"] = "sturm.wav" --> fullName["sturm"] = ../mi_26/"sturm.wav"
	"s8.wav"						 -->					 ../mi_26/"s8.wav"
	"s13.wav"						 -->					 ../mi_26/"s13.wav"
	"rocket.wav"					 -->					 ../mi_26/"rocket.wav"
	"gun_loop.wav"					 -->					 ../mi_26/"gun_loop.wav"
	"shoot.wav"						 -->					 ../mi_26/"shoot.wav"
	"sturm.wav"						 -->					 ../mi_26/"sturm.wav"
	//����
	...
}
\endcode
</pre>

\subsection subSecFactors ����������� ������� ���������
<pre>
����� ������� ������ ����� ������������ ������������ ��������� ������.
����������� ������ �0� ��������, ��� ���� ������� �������� ��� ������� ����������� �� ������ ��.
� ����� ������ �������� �� ����������� �����, � ������� �� ��������������� ����� � 0-��� ����������,
��� �������� ������ � ������������ �����.
� ������� ������������ ��������� ��������� ����������� ��� ����������� ������ �����,
��������: ������� ���������� � ��������� �� ��������� ������� ������.
\code
if (model == "mi_8_mtv5")
{
	//���������
	engTurnoverHp = 20;
	engTurnoverMg = 75;
	engTurnoverAvt = 88;
	redTurnoverMg1 = 50;
	redTurnoverMg2 = 63;
	redTurnoverAvt = 96;
	//��������� ���������
	vsuFactor = 1//���;
	vsuHpFactor = 0.06//��� ��;
	engFactor = 1//��;
	engHpFactor = 0.35//�� ��;
	redFactor = 1//��������;
	accumFactor = 0.1//�����;
	ptsFactor = 0.18//���;
	ptsToneFactor = 0.25//��� ���;
	tr36Factor = 0.15//��36;
	tr115Factor = 0.15//��115;
	pumpLeftFactor = 0.08//���� �;
	pumpRightFactor = 0.12//���� �;
	cutoffCraneFactor = 0.18//������;
	ko50Factor = 0.5//��-50;
	runwayFactor = 1//���;
	rocketNar8Factor = 1//���8;
	rocketNar13Factor = 1//���13;
	rocketHitFactor = 0.8//��������� ������;
	upkFactor = 1//���;
	vintSwishFactor = 1//���� ����;
	vintBrakeFactor = 0.2//���� ������;
	vintFlapFactor = 0.794//���� ������;
	chassisBrakePumpFactor = 0.03//������ �����;
	chassisBrakeReleaseFactor = 0.03//����� ��������;
	consumTankFactor = 0.25//��������� ���;
	rainFactor = 0.5//�����;
}
\endcode
\sa
Helicopter

</pre>
*/

/*! \page todo TODO
<pre>
���� ����������� ���������� �� ������������ ������������� � ������� ������� ���������

	1.	DLL ���������� ��������� ������������ ���������.
	*	�������� ��������� ������ ����� ������ ��� �������������� ����� �������
	*	�������� ������������� ������ ������������ �������� ���������� �����������
	*	�������� ����������� ���������� ����������� ��� - ������ ����������� ������

	2.	������������ Alure ������ Alute.
	*	����� �����������, �������������� ������ Alute
	*	�������� ���������� ���������� �������� OpenAL
	*	�������� ��������� ���, � ���������� �� ��������� �������

	3.	������������ ������ �������� - ���������.
	*	��� ��������� ������� ������ ����������� � ������ ������,
	*	��� ��������� � ����� ������ ��������� ���������� � ��������
	*	������������ �������� - ���������, � ����� ������������ ���������� ��������� �� ����������
	*	vector<Sound *> Sounds;

	4.	������������ ������������ ��������� ������� ������ ����� "play"
	*	������� ������������������ �������
	*	�������� ��������� �������� - ������� ������������ �������

</pre>

*/

#include "BASE.h"

using namespace std;

#define MAX_AUX_SLOTS 16

SOUNDREAD soundread;/*!< ���������� ������ soundread ��� �������� ����������� ��������� */

int Sound::maxSlots;/*!< ���������� ������������������ ������������ ������ ���������� ,������� ����� ������������� ������������*/
int Sound::maxSources;/*!< ���������� ������������������ ������������ ������ ���������� ,������� ����� ������������� ������������*/
double Sound::masterGain = 1;//!< ����� ��������� �����
int Sound::sourcesInUse = 0;
int Sound::effectSlotsInUse = 0;
double Sound::currentTime = 0;
double Sound::deltaTime = 0;
double Sound::step = 0;                  //  �������
double Sound::tangaz = 0;                //    �������
double Sound::derivTangaz = 0;           // ---------
double Sound::hight = 0;
double Sound::velocityVectorXZ = 0;
double Sound::accelerationVectorXZ = 0;
double Sound::velocityY = 0;
double Sound::dashVectorXZ = 0;            // ---------
double Sound::accelerationVy = 0;
double Sound::derivStep = 0;               // ---------
double Sound::calcA = 0;                   //  ----------
double Sound::redTurnAcc = 0;              //  -----------
double Sound::groundTouch = 0;
int Engine::engCount = 0;

vector<double> Sound::vectorVy;
vector<double> Sound::vectorVXZ;
vector<double> Sound::vectorAccXZ;          // ????
vector<double> Sound::vectorStep;          // -------------
vector<double> Sound::vectorTangaz;         // ---------
vector<double> Sound::vectorTime;
vector<double> Sound::vectorRedTurn;        // -----------
vector<double> Sound::vectorAvrEng1Turn;
vector<double> Sound::vectorAvrEng2Turn;
vector<double> Sound::vectorAvrRedTurn;      // ------------
vector<double> Sound::vectorAvrStep;         // -----------
vector<double> Sound::vectorAvrAtk;         // ----------
double Sound::globalWindow = 50;

/*!\brief �������� ������� ���������*/
int main()
{
	//������ 1�� ����� ���������� ����� ���� �������� ������������
	HANDLE hMutex = OpenMutex(
		MUTEX_ALL_ACCESS, 0, "BASE");

	if (!hMutex)
		// Mutex doesn�t exist. This is
		// the first instance so create
		// the mutex.
		hMutex =
		CreateMutex(0, 0, "BASE");
	else
		// The mutex exists so this is the
		// the second instance so return.
	{
		cout << "Application already exist!" << endl;
		return 1;
	}

	//�������� ��������� �� ������� EFX
	setEFXPointers();
	vector <string> helicoptersNames = { "mi_8_mtv5","mi_8_amtsh","mi_26","mi_28","ka_226","ansat","ka_27","ka_29" };                   //��������� ��������  -  �������
/*	string model = "ka_29";                                                                                                             //�� ���������  -  �������
*/
	string model = "il_112";                                                                                                           //  ��������� ��� ���������
	
	Helicopter helicopter;//���������� ������ Helicopter ��� �������� ���������� ���������� ���������
/*	if (argc > 1)// ���� �������� ���������, �� argc ����� ������ 1(� ����������� �� ���-�� ����������)
	{
		for (size_t i = 0; i < helicoptersNames.size(); i++)
		{
			if (regex_match(argv[1], regex("^(" + helicoptersNames[i] + ")")))
			{
				model = argv[1];
			}
		}
	}
*/
	ALCdevice *device;
	ALCcontext *context;

	Sound::maxSources = getMaxAvaliableSources(); //�������� ������������ ���������� ���������� ������� ����� ������������ �� ������ ����������
	cout << " " << Sound::maxSources << " - Sources avaliable" << endl;
	Sound::maxSlots = MAX_AUX_SLOTS;

	device = alcOpenDevice(0);//�������������� ����������
	if (device == 0)
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		return AL_FALSE;
	}
	context = alcCreateContext(device, 0);//�������������� �������� (�.�. ��������� - ������ ���������)
	if (context == 0)
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		alcCloseDevice(device);
		return AL_FALSE;
	}
	if (!alcMakeContextCurrent(context))//�������� �������� �������
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		alcDestroyContext(context);
		alcCloseDevice(device);
		return AL_FALSE;
	}
	if (!shaInit())// ������������� ����� ������ 
	{
		cout << "shared memory initialization error..." << endl;
		return 0;
	}
	InitRealTime(1);//������������ "��������" ����� � ��������� � 1�� (������ �������������� ������ ��� � 0.001 �)

	helicopter.setParam(model);//�������������� ��������� ���������
	system("cls");
	cout << " Using " << helicopter.modelName << endl;

	//��������� �� ������� ������������ ��������� ���������� �����
	Vsu *vsu = nullptr;
	Sound *vsuHp = nullptr;
	Crane *vsuKran = nullptr;
	Sound *engHp[2] = { nullptr };
	Sound *engPomp[2] = { nullptr };
	Sound *redCrash = nullptr;
	Sound *accum = nullptr;
	Sound *accumTr = nullptr;
	Sound *pts = nullptr;
	Sound *ptsTone = nullptr;
	Sound *tr36 = nullptr;
	Sound *tr115 = nullptr;
	Sound *nip = nullptr;
	Sound *girovert = nullptr;
	Sound *podk1 = nullptr;
	Sound *podk2 = nullptr;
	Crane *perek1 = nullptr;
	Crane *perek2 = nullptr;
	Sound *ko50 = nullptr;
	Skv *skv = nullptr;
	Crane *fire1 = nullptr;
	Crane *fire2 = nullptr;
	Sound *consTank = nullptr;
	Sound *pstat = nullptr;
	Runway *runway = nullptr;
	Sound *crash = nullptr;
	VintSwish *vintSwish = nullptr;
	Sound *vintBrake = nullptr;
	VintFlap *vintFlap = nullptr;
	Sound *brake = nullptr;
	Sound *rain = nullptr;
	Sound *sturm[50] = { nullptr };
	Sound *igla[50] = { nullptr };
	Sound *rocket[50] = { nullptr };
	Sound *bullet[50] = { nullptr };
	Sound *ppu = nullptr;
	Sound *upk = nullptr;
	Sound *nar8[50] = { nullptr };
	Sound *nar13[50] = { nullptr };
	Engine *eng[2] = { nullptr };
	Reductor *red = nullptr;
	Sound *beep = nullptr;
	Sound *undefined1 = nullptr;
	Crane *kranKolc = nullptr;
	Sound *vpryam = nullptr;
	Sound *vadd = nullptr;
	Sound *shock[4][50] = { nullptr };
	Sound *trim = nullptr;
	Sound *frict = nullptr;

	SOUNDREAD localdata = soundread;//��������� ����� ������ � USPO �����

	double timerPodk = 0;

	double timerNar8 = 0;//������ �������� ���8
	double timerNar13 = 0;//������ �������� ���8
	int counterNar8 = 0;
	int counterNar13 = 0;
	int check8 = 0;
	int check13 = 0;

	int shockLocker[4] = { 0,0,0,0 };
	int counterShock[4] = { 0,0,0,0 };

	int sturmLocker = 0;
	int counterSturm = 0;

	int iglaLocker = 0;
	int counterIgla = 0;

	int rocketHitLocker = 0;
	int counterRocketHit = 0;

	int bulletHitLocker = 0;
	int counterBulletHit = 0;
	string type[50];

	double timerAvr = 0;
	const double window = 1;//��� ���������� ������������ ����������� ����� ��������� �������� �� ������� 
	double periodCalc = 0;//���������� ��� ��������� �������� ������� ����������, ����� ��� ������� ����� window

	double avrDeltaTime = 0;
	vector<double> adt;

	//����������� ������
	adt.reserve(600);
	Sound::vectorVy.reserve(1000);
	Sound::vectorVXZ.reserve(1000);
	Sound::vectorAccXZ.reserve(1000);
	Sound::vectorStep.reserve(1000);
	Sound::vectorTangaz.reserve(1000);
	Sound::vectorTime.reserve(1000);
	Sound::vectorRedTurn.reserve(1000);

	Sound::vectorAvrEng1Turn.reserve(15000);
	Sound::vectorAvrEng2Turn.reserve(15000);
	Sound::vectorAvrRedTurn.reserve(15000);
	Sound::vectorAvrStep.reserve(15000);
	Sound::vectorAvrAtk.reserve(15000);

	double noDataFactor = 0;//��������� ����������� ����������� ������
	bool stop = 0;//������� ��������

	//���������� ��� ����� ��������� � ����������� �����
	while (true)
	{
		//�������� ������ �� ����� ������ �� ��������� ���������
		localdata = soundread;

		//������������ ����������� � ���������� ����� ��� ������� �����������
		if (abs(localdata.time - Sound::currentTime) > 0.5)
			Sound::currentTime = localdata.time;
		//��������� ��������� ������� � �������� ����� ������ ���������
		Sound::deltaTime = localdata.time - Sound::currentTime;
		Sound::currentTime = localdata.time;

		//��� ������ ������� ������� ������� � ������� ���������
		if (!Sound::deltaTime)
		{
			noDataFactor += 0.01;
			noDataFactor = (noDataFactor > 1) ? 1 : noDataFactor;
			if (noDataFactor == 1)
			{
				Sound::masterGain = 0;
			}
		}
		else
		{
			noDataFactor = 0;
		}
		if (IsProcessPresent("USPO112.exe") && !localdata.p_model_stop && noDataFactor < 1 && !stop)//���� �������� ���� uspo �������, � ������� ��������� ������ �� �������
		{
			//������ �������� ���������� ���������
			if (Sound::masterGain < localdata.master_gain)
			{
				Sound::masterGain += Sound::deltaTime;
				Sound::masterGain = (Sound::masterGain > localdata.master_gain) ? localdata.master_gain : Sound::masterGain;
			}
			else
			{
				Sound::masterGain -= Sound::deltaTime;
				Sound::masterGain = (Sound::masterGain < localdata.master_gain) ? localdata.master_gain : Sound::masterGain;
			}

			printf(" Time: %.4lf\tDT__: %.4lf\tSIU: %i\tENG1: %.3f\tENG2: %.3f\tRED_: %.3f\tVSU: %.3f\tMSG: %.3f\t\r", Sound::currentTime, avrDeltaTime, Sound::sourcesInUse, soundread.eng1_obor, soundread.eng2_obor, soundread.reduktor_gl_obor, soundread.vsu_obor, Sound::masterGain);

			//������� ����� �����
			avrDeltaTime = 0;
			adt.push_back(Sound::deltaTime);
			if (adt.size() > 500)
			{
				adt.erase(adt.begin());
			}
			for (auto tg : adt)
			{
				avrDeltaTime += tg / adt.size();
			}

			Sound::tangaz = localdata.tangaz;//������ (�������� ���������� �������� ��� �������)
			Sound::velocityVectorXZ = sqrt(pow(localdata.v_atm_x, 2) + pow(localdata.v_atm_z, 2));//��������� ��������
			Sound::step = localdata.step; //��� (�������� ���������� �������� ����������)
			Sound::hight = localdata.hight;
			Sound::velocityY = localdata.vy;
			Sound::groundTouch = (localdata.obj_hv + localdata.obj_l + localdata.obj_nos + localdata.obj_r) / 4;//������� �������

			//���� �� ������ ������� ��������� ������ - ��������� ����������
			//���� ����������� ������ ���� ��������� - ����������� �������� � ������ �������
			while (periodCalc >= window && Sound::vectorTime.size() > 2)
			{
				if (!Sound::vectorTime.empty())
				{
					Sound::vectorVy.erase(Sound::vectorVy.begin());
					Sound::vectorVXZ.erase(Sound::vectorVXZ.begin());
					Sound::vectorAccXZ.erase(Sound::vectorAccXZ.begin());
					Sound::vectorTangaz.erase(Sound::vectorTangaz.begin());
					Sound::vectorStep.erase(Sound::vectorStep.begin());
					Sound::vectorTime.erase(Sound::vectorTime.begin());
					Sound::vectorRedTurn.erase(Sound::vectorRedTurn.begin());
				}
				periodCalc = Sound::currentTime - Sound::vectorTime.front();
			}

			//�������� ������� ��� ��������
			timerAvr += Sound::deltaTime;

			//�������� �������� ������ ���� ����� ����������
			if (Sound::deltaTime)
			{
				Sound::vectorTime.push_back(Sound::currentTime);
				Sound::vectorVy.push_back(Sound::velocityY);
				Sound::vectorVXZ.push_back(Sound::velocityVectorXZ);
				Sound::vectorAccXZ.push_back(Sound::accelerationVectorXZ);
				Sound::vectorTangaz.push_back(Sound::tangaz);
				Sound::vectorStep.push_back(Sound::step);
				Sound::vectorRedTurn.push_back(localdata.reduktor_gl_obor);

				//���� ����������� ������ ���� ��������� - ����������� �������� � ������ �������
				if (timerAvr > Sound::globalWindow)
				{
					if (!Sound::vectorAvrEng1Turn.empty())
					{
						Sound::vectorAvrEng1Turn.erase(Sound::vectorAvrEng1Turn.begin());
					}
					if (!Sound::vectorAvrEng2Turn.empty())
					{
						Sound::vectorAvrEng2Turn.erase(Sound::vectorAvrEng2Turn.begin());
					}
					if (!Sound::vectorAvrRedTurn.empty())
					{
						Sound::vectorAvrRedTurn.erase(Sound::vectorAvrRedTurn.begin());
					}
					if (!Sound::vectorAvrStep.empty())
					{
						Sound::vectorAvrStep.erase(Sound::vectorAvrStep.begin());
					}
					if (!Sound::vectorAvrAtk.empty())
					{
						Sound::vectorAvrAtk.erase(Sound::vectorAvrAtk.begin());
					}
				}

				Sound::vectorAvrEng1Turn.push_back(localdata.eng1_obor);
				Sound::vectorAvrEng2Turn.push_back(localdata.eng2_obor);
				Sound::vectorAvrRedTurn.push_back(localdata.reduktor_gl_obor);
				Sound::vectorAvrStep.push_back(Sound::step);
				Sound::vectorAvrAtk.push_back(Sound::calcA);
			}
			//���� ������ ������� �� ���� - ����� ����������, ����� �������� �����������
			if (!Sound::vectorTime.empty())
			{
				//�����������
				periodCalc = Sound::currentTime - Sound::vectorTime.front();
				if (periodCalc > 0)
				{
					Sound::accelerationVy = (Sound::velocityY - Sound::vectorVy.front()) / periodCalc;
					Sound::accelerationVectorXZ = (Sound::velocityVectorXZ - Sound::vectorVXZ.front()) / periodCalc;
					Sound::dashVectorXZ = (Sound::accelerationVectorXZ - Sound::vectorAccXZ.front()) / periodCalc;
					Sound::derivStep = (Sound::step - Sound::vectorStep.front()) / periodCalc;
					Sound::derivTangaz = (Sound::tangaz - Sound::vectorTangaz.front()) / periodCalc;
					Sound::calcA = attack(Sound::velocityVectorXZ, Sound::vectorVXZ.front(), Sound::tangaz, Sound::velocityY);
					Sound::redTurnAcc = (localdata.reduktor_gl_obor - Sound::vectorRedTurn.front()) / periodCalc;
				}
			}
			//����� ��������� �������� � ���������
			//���
			if (helicopter.vsuFactor)//���� ��� �������� � ������
			{
				if (localdata.vsu_obor > 0 || localdata.p_vsu_hp || localdata.p_vsu_ostanov || localdata.p_vsu_zap)
				{
					if (!vsu)
					{
						vsu = new Vsu;
					}
				}
				if (vsu)
				{
					if (vsu->play(localdata, helicopter))
					{

					}
					else
					{
						Free(vsu);
					}
				}
			}
			//�����������
			if (helicopter.accumFactor)
			{
				if (helicopter.modelName != "ansat")//226
				{
					if (localdata.accumulator)//������� �������� �������
					{
						if (!accum)//���� ������ �� ������ 
						{
							accum = new Sound;//������� ������
						}
					}
					if (accum)//���� ������ ������ - ���������� ���
					{
						if (accum->play(localdata.accumulator, "NULL", helicopter.fullName["accum"], "NULL", helicopter.accumFactor))
						{

						}
						else
						{
							Free(accum);//������� ������
						}
					}
				}
				if (helicopter.modelName == "ka_226" || helicopter.modelName == "ansat")//226
				{
					if (localdata.accumulator)//������� �������� �������
					{
						if (!accumTr)//���� ������ �� ������ 
						{
							accumTr = new Sound;//������� ������
						}
					}
					if (accumTr)//���� ������ ������ - ���������� ���
					{
						if (accumTr->play(localdata.accumulator, "NULL", helicopter.fullName["accum_tr"], "NULL", helicopter.accumFactor))
						{

						}
						else
						{
							Free(accumTr);//������� ������
						}
					}
				}
			}
			//���
			if (helicopter.ptsFactor)
			{
				if (localdata.p_pts)//������� �������� �������
				{
					if (!pts)//���� ������ �� ������ 
					{
						pts = new Sound;
					}
				}
				if (pts)//���� ������ ������ - ���������� ���
				{
					if (pts->play(localdata.p_pts, helicopter.fullName["pts_on"], helicopter.fullName["pts_w"], helicopter.fullName["pts_off"], helicopter.ptsFactor))
					{

					}
					else
					{
						Free(pts);//������� ������
					}
				}
			}
			//��� ���
			if (helicopter.ptsToneFactor)
			{
				//��� ���
				if (localdata.p_pts)//������� �������� �������
				{
					if (!ptsTone)//���� ������ �� ������ 
					{
						ptsTone = new Sound;//������� ������
					}
				}
				if (ptsTone)//���� ������ ������ - ���������� ���
				{
					if (ptsTone->play(localdata.p_pts, "NULL", helicopter.fullName["pts_tone"], "NULL", helicopter.ptsToneFactor))
					{

					}
					else
					{
						Free(ptsTone);//������� ������
					}
				}
			}
			//��
			if (helicopter.vpryam)
			{
				//��
				if (localdata.p_vu1)//������� �������� �������
				{
					if (!vpryam)//���� ������ �� ������ 
					{
						vpryam = new Sound;//������� ������
					}
				}
				if (vpryam)//���� ������ ������ - ���������� ���
				{
					if (vpryam->play(localdata.p_vu1, "NULL", helicopter.fullName["vpryam"], "NULL", helicopter.vpryam))
					{

					}
					else
					{
						Free(vpryam);//������� ������
					}
				}
			}
			//���� ������������� 36� ������������ �� �����
			if (helicopter.tr36Factor)
			{
				if (localdata.p_trans_36_osn || localdata.p_trans_36_rez)//������� �������� �������
				{
					if (!tr36)//���� ������ �� ������ 
					{
						tr36 = new Sound;//������� ������
					}
				}
				if (tr36)//���� ������ ������ - ���������� ���
				{
					if (tr36->play(localdata.p_trans_36_osn || localdata.p_trans_36_rez, helicopter.fullName["tr36_on"], helicopter.fullName["tr36_w"], helicopter.fullName["tr36_off"], helicopter.tr36Factor))
					{

					}
					else
					{
						Free(tr36);//������� ������
					}
				}
			}
			//���� ������������� 115� ������������ �� �����
			if (helicopter.tr115Factor)
			{
				if (localdata.p_po500)//������� �������� �������
				{
					if (!tr115)//���� ������ �� ������ 
					{
						tr115 = new Sound;//������� ������
					}
				}
				if (tr115)//���� ������ ������ - ���������� ���
				{
					if (tr115->play(localdata.p_po500, helicopter.fullName["tr115_on"], helicopter.fullName["tr115_w"], helicopter.fullName["tr115_off"], helicopter.tr115Factor))
					{

					}
					else
					{
						Free(tr115);//������� ������
					}
				}
			}
			//���
			if (helicopter.nipFactor)
			{
				if (localdata.ground_power_supply)//������� �������� �������
				{
					if (!nip)//���� ������ �� ������ 
					{
						nip = new Sound;//������� ������
					}
				}
				if (nip)//���� ������ ������ - ���������� ���
				{
					if (nip->play(localdata.ground_power_supply, "NULL", helicopter.fullName["nip_tone"], "NULL", helicopter.nipFactor))
					{
						double p1 = 1, p2 = 1;
						//���� �������� ��, �� ������ ���� ���������� �� 1.5%
						if (helicopter.modelName == "mi_26")
						{
							if (localdata.p_vu1)
							{
								p1 = 1.015;
							}
							else
							{
								p1 = 1;
							}
						}
						//��������� � ������ ��� ����������� ��� �� ����
						if (localdata.p_vsu_hp || localdata.p_vsu_zap)
						{

							nip->offset[0] += Sound::deltaTime;

							//_____  
							//  1  \____   
							//     0.985\  ______
							//		0.977\/
							//		 0.946
							//	    |1c |1c|

							//����� ������
							p2 = interpolation({ 0, 1 }, { 1.5, 0.946 }, { 2, 0.977 }, nip->offset[0]);

						}
						//��������� � ������ ��� ����������� ��� �� ����
						if (!localdata.p_vsu_hp && !localdata.p_vsu_zap)
						{
							nip->offset[0] = 0;
							p2 = 1;
						}

						for (size_t i = 0; i < 2; i++)
						{
							nip->pitch[i] = 1 * p1 * p2;//��������� �������������� ���
						}
					}
					else
					{
						Free(nip);//������� ������
					}
				}
			}
			//�������������
			if (helicopter.girovertFactor)
			{
				if (nip)//������� �������� �������
				{
					if (!girovert)//���� ������ �� ������ 
					{
						girovert = new Sound;//������� ������
					}
				}
				if (girovert)//���� ������ ������ - ���������� ���
				{
					girovert->lengthOn = getLengthWAV(helicopter.fullName["girovert_on"]);
					if (girovert->pitch[girovert->id] < 1 && girovert->soundOn)
					{
						girovert->offset[girovert->id] = girovert->lengthOn * girovert->pitch[girovert->id];//�������� ������ � �������� ������ ��������
					}

					if (girovert->play(nip, helicopter.fullName["girovert_on"], helicopter.fullName["girovert_w"], helicopter.fullName["girovert_w"], helicopter.ptsFactor))
					{
						if (girovert->soundOn)
						{
							girovert->pitch[girovert->id] = 1;
						}
						if (girovert->soundOff)
						{
							alSourcei(girovert->source[girovert->id], AL_LOOPING, AL_TRUE);
							girovert->pitch[girovert->id] -= Sound::deltaTime*0.0024;//��������� ���� �� 0.0024 � ���

							//���� pitch <= 0.8 - ���� ������, �������� ����� ���������
							if (girovert->pitch[girovert->id] <= 0.8)
							{
								if (!girovert->play(localdata.ground_power_supply, "NULL", "NULL", "NULL", helicopter.ptsFactor))
								{
									Free(girovert);//������� ������
								}
							}
						}
					}
					else
					{
						Free(girovert);//������� ������
					}
				}
			}
			//���� ������ �������� ������������ �� �����
			if (helicopter.pumpLeftFactor)
			{
				if (localdata.p_nasos_podk_1)//������� �������� �������
				{
					if (!podk1)//���� ������ �� ������ 
					{
						podk1 = new Sound;//������� ������
					}
				}
				if (podk1)//���� ������ ������ - ���������� ���
				{
					podk1->channel[0] = 1;//L
					podk1->channel[1] = 0;
					if ("ka_226" == helicopter.modelName)
					{
						for (size_t i = 0; i < 2; i++)
						{
							if (localdata.p_eng1_zap | localdata.p_eng1_hp | localdata.p_eng2_hp | localdata.p_eng2_zap)
							{
								timerPodk += Sound::deltaTime;

								podk1->pitch[i] = interpolation({ 0, 1 }, { 1, 0.85 }, { 5, 0.88 }, timerPodk);

							}
							else
							{
								timerPodk = 0;
								podk1->pitch[0] = 1;
							}
						}

						if (podk1->play(localdata.p_nasos_podk_1, helicopter.fullName["podk_l_on"], helicopter.fullName["podk_l_w"], helicopter.fullName["podk_l_off"], helicopter.pumpLeftFactor))//������������� ���� - ���������� ��������� ����� � play
						{

						}
						else
						{
							Free(podk1);//������� ������
						}
					}
					else
					{
						if (podk1->play(localdata.p_nasos_podk_1, helicopter.fullName["podk_l_on"], helicopter.fullName["podk_l_w"], "NULL", helicopter.pumpLeftFactor))
						{

						}
						else
						{
							Free(podk1);//������� ������
						}
					}
				}
			}
			if (helicopter.pumpRightFactor)
			{
				if (localdata.p_nasos_podk_2)//������� �������� �������
				{
					if (!podk2)//���� ������ �� ������ 
					{
						podk2 = new Sound;//������� ������
					}
				}
				if (podk2)//���� ������ ������ - ���������� ���
				{
					podk2->channel[0] = 0;//R
					podk2->channel[1] = 1;
					if ("ka_226" == helicopter.modelName)
					{
						for (size_t i = 0; i < 2; i++)
						{
							if (localdata.p_eng1_zap | localdata.p_eng1_hp | localdata.p_eng2_hp | localdata.p_eng2_zap)
							{
								timerPodk += Sound::deltaTime;

								podk2->pitch[i] = interpolation({ 0, 1 }, { 1, 0.85 }, { 5, 0.88 }, timerPodk);

							}
							else
							{
								timerPodk = 0;
								podk2->pitch[0] = 1;
							}
						}

						if (podk2->play(localdata.p_nasos_podk_2, helicopter.fullName["podk_l_on"], helicopter.fullName["podk_l_w"], helicopter.fullName["podk_l_off"], helicopter.pumpRightFactor))//������������� ���� - ���������� ��������� ����� � play
						{

						}
						else
						{
							Free(podk2);//������� ������
						}
					}
					else
					{
						if (podk2->play(localdata.p_nasos_podk_2, helicopter.fullName["podk_l_on"], helicopter.fullName["podk_l_w"], "NULL", helicopter.pumpRightFactor))
						{

						}
						else
						{
							Free(podk2);//������� ������
						}
					}
				}
			}
			//���� ���� ����������� ������������ �� �����
			if (helicopter.circlingCraneFactor)
			{
				if (localdata.p_kran_kolcev)//������� �������� �������
				{
					if (!kranKolc)//���� ������ �� ������ 
					{
						kranKolc = new Crane;//������� ������
					}
				}
				if (kranKolc)//���� ������ ������ - ���������� ���
				{
					kranKolc->channel[0] = 1;
					kranKolc->channel[1] = 1;

					if (kranKolc->play(localdata.p_kran_kolcev, helicopter.fullName["kran_circle"], "NULL", helicopter.fullName["kran_circle"], helicopter.circlingCraneFactor))
					{

					}
					else
					{
						Free(kranKolc);//������� ������
					}
				}
			}
			//���� ����������� ����� ������������ �� �����
			if (helicopter.cutoffCraneFactor)
			{
				if (localdata.p_kran_perekr_1)//������� �������� �������
				{
					if (!perek1)//���� ������ �� ������ 
					{
						perek1 = new Crane;//������� ������
					}
				}
				if (perek1)//���� ������ ������ - ���������� ���
				{
					perek1->channel[0] = 1;//L
					perek1->channel[1] = 0;
					if (perek1->play(localdata.p_kran_perekr_1, helicopter.fullName["perekr_l"], "NULL", helicopter.fullName["perekr_l"], helicopter.cutoffCraneFactor))
					{

					}
					else
					{
						Free(perek1);//������� ������
					}
				}

				if (localdata.p_kran_perekr_2)//������� �������� �������
				{
					if (!perek2)//���� ������ �� ������ 
					{
						perek2 = new Crane;//������� ������
					}
				}
				if (perek2)//���� ������ ������ - ���������� ���
				{
					perek2->channel[0] = 0;
					perek2->channel[1] = 1;//R
					if (perek2->play(localdata.p_kran_perekr_2, helicopter.fullName["perekr_r"], "NULL", helicopter.fullName["perekr_r"], helicopter.cutoffCraneFactor))
					{

					}
					else
					{
						Free(perek2);//������� ������
					}
				}
			}
			//���� ��� ������������ �� �����
			if (helicopter.skvFactor)
			{
				if (localdata.p_skv_on)//������� �������� �������
					if (!skv)//���� ������ �� ������ 
						skv = new Skv;//������� ������
				if (skv)//���� ������ ������ - ���������� ���
				{
					if (skv->play(helicopter, localdata))
					{

					}
					else
					{
						Free(skv);//������� ������
					}

				}
			}
			//���� ��-50 ������������ �� �����
			if (helicopter.ko50Factor)
			{
				if (localdata.stove)//������� �������� �������
					if (!ko50)//���� ������ �� ������ 
						ko50 = new Sound;//������� ������
				if (ko50)//���� ������ ������ - ���������� ���
				{
					if (ko50->play(localdata.stove, helicopter.fullName["ko50_on"], helicopter.fullName["ko50_w"], helicopter.fullName["ko50_off"], helicopter.ko50Factor))
					{

					}
					else
					{
						Free(ko50);//������� ������
					}
				}
			}
			//���� ����� ���������� ����
			if (helicopter.consumTankFactor)
			{
				if (localdata.dis_tank_pump)//������� �������� �������
					if (!consTank)//���� ������ �� ������ 
						consTank = new Sound;//������� ������
				if (consTank)//���� ������ ������ - ���������� ���
				{
					if (consTank->play(localdata.dis_tank_pump, helicopter.fullName["cons_tank_on"], helicopter.fullName["cons_tank_w"], "NULL", helicopter.consumTankFactor))
					{

					}
					else
					{
						Free(consTank);//������� ������
					}
				}
			}
			//�������� ����
			if (helicopter.fireCraneFactor)
			{
				if (localdata.p_kran_poj_l)//������� �������� �������
					if (!fire1)//���� ������ �� ������ 
						fire1 = new Crane;//������� ������
				if (fire1)//���� ������ ������ - ���������� ���
				{
					fire1->channel[0] = 1;//L
					fire1->channel[1] = 0;
					if (fire1->play(localdata.p_kran_poj_l, helicopter.fullName["kran_fire_l"], "NULL", helicopter.fullName["kran_fire_l"], helicopter.fireCraneFactor))
					{

					}
					else
					{
						Free(fire1);//������� ������
					}
				}

				if (localdata.p_kran_poj_r)//������� �������� �������
					if (!fire2)//���� ������ �� ������ 
						fire2 = new Crane;//������� ������
				if (fire2)//���� ������ ������ - ���������� ���
				{
					fire2->channel[0] = 0;
					fire2->channel[1] = 1;//R
					if (fire2->play(localdata.p_kran_poj_r, helicopter.fullName["kran_fire_r"], "NULL", helicopter.fullName["kran_fire_r"], helicopter.fireCraneFactor))
					{

					}
					else
					{
						Free(fire2);//������� ������
					}
				}
			}
			//�������� �������
			if (helicopter.pumpStationFactor)
			{
				if (localdata.p_nasos)//������� �������� �������
					if (!pstat)//���� ������ �� ������ 
						pstat = new Sound;//������� ������
				if (pstat)//���� ������ ������ - ���������� ���
				{
					if (pstat->play(localdata.p_nasos, helicopter.fullName["pstat_on"], helicopter.fullName["pstat_w"], helicopter.fullName["pstat_off"], helicopter.ko50Factor))
					{

					}
					else
					{
						Free(pstat);//������� ������
					}
				}
			}
			//���� ����� �������� �� ��� �������� � ������ �����
			if (helicopter.runwayFactor)
			{
				if (localdata.v_surf_x != 0 && Sound::groundTouch > 0)//������� �������� �������
					if (!runway)//���� ������ �� ������ 
						runway = new Runway;//������� ������
				if (runway)//���� ������ ������ - ���������� ���
				{
					runway->play(helicopter, localdata);//������������� ���� - ���������� ��������� ����� � play
					if (localdata.v_surf_x == 0 || !(Sound::groundTouch > 0))//������� �������� �������
						Free(runway);//������� ������
				}
			}
			//����
			if (helicopter.vintSwishFactor)
			{
				if (localdata.reduktor_gl_obor != 0)//������� �������� �������
					if (!vintSwish)//���� ������ �� ������ 
						vintSwish = new VintSwish;//������� ������
				if (vintSwish)//���� ������ ������ - ���������� ���
				{
					vintSwish->play(helicopter, localdata);
					if (localdata.reduktor_gl_obor == 0)//������� �������� �������
						Free(vintSwish);//������� ������
				}
			}
			//���� ���� ������� ����� ������� � ������
			if (helicopter.vintBrakeFactor)
			{
				if (localdata.tormoz_vint)//������� �������� �������
					if (!vintBrake)//���� ������ �� ������ 
						vintBrake = new Sound;//������� ������
				if (vintBrake)//���� ������ ������ - ���������� ���
				{
					if (vintBrake->play(localdata.tormoz_vint, helicopter.fullName["vint_torm"], helicopter.fullName["vint_torm"], helicopter.fullName["vint_torm"], helicopter.vintBrakeFactor))
					{
						double soundOff = getParameterFromVector(vector<point>{ { 12, 1 }, { 1, 0 } }, localdata.reduktor_gl_obor);
						for (size_t i = 0; i < 2; i++)
						{
							vintBrake->pitch[i] = localdata.reduktor_gl_obor / 12.0;
							if (vintBrake->soundOn)
							{
								vintBrake->gain[i] = ((vintBrake->offset[vintBrake->id] > 1) ? 1 : vintBrake->offset[vintBrake->id] / vintBrake->lengthOn) * soundOff;
							}
							else if (vintBrake->soundOff)
							{
								vintBrake->gain[i] = ((vintBrake->offset[vintBrake->id] > 1) ? 0 : 1 - (vintBrake->offset[vintBrake->id] / vintBrake->lengthOff)) * soundOff;
							}
							else
							{
								vintBrake->gain[i] = soundOff;
							}
						}
					}
					else
					{
						Free(vintBrake);//������� ������
					}
				}
			}
			//���� ���� ������� ����� ������� � ������
			if (helicopter.vintFlapFactor)
			{
				if (Sound::groundTouch <= 0.01)//������� �������� �������
					if (!vintFlap)//���� ������ �� ������ 
						vintFlap = new VintFlap;//������� ������
				if (vintFlap)//���� ������ ������ - ���������� ���
				{
					vintFlap->play(helicopter, localdata);//������������� ���� - ���������� ��������� ����� � play
					if (Sound::groundTouch > 0.625)//������� �������� �������
						Free(vintFlap);//������� ������
				}
			}
			//���� ������� �������� �� �����
			if (helicopter.chassisBrakePumpFactor)
			{
				if (localdata.p_tormoz_press || localdata.frict)//������� �������� �������
					if (!brake)//���� ������ �� ������ 
						brake = new Sound;//������� ������
				if (brake)//���� ������ ������ - ���������� ���
				{
					if (helicopter.modelName == "ka_27" | helicopter.modelName == "ka_29")
					{
						if (brake->play(localdata.p_tormoz_press || localdata.frict, "NULL", helicopter.fullName["brake"], "NULL", helicopter.chassisBrakePumpFactor))
						{
							brake->gain[brake->id] = localdata.tormoz;
							brake->pitch[brake->id] = getParameterFromVector(vector<point>{ { 5 * 0.277, 0.67 }, { 15 * 0.277, 1 }, { 25 * 0.277, 1.33 }, { 30 * 0.277, 1.4 }}, abs(localdata.v_surf_x));
						}
						else
						{
							Free(brake);//������� ������
						}

					}
					else
					{
						if (brake->play(localdata.p_tormoz_press, helicopter.fullName["brake"], "NULL", helicopter.fullName["poff"], helicopter.chassisBrakePumpFactor))
						{

						}
						else
						{
							Free(brake);//������� ������
						}
					}
				}
			}
			//���� ������� ������� �� �����
			if (helicopter.trim)
			{
				if (localdata.trim)//������� �������� �������
					if (!trim)//���� ������ �� ������ 
						trim = new Sound;//������� ������
				if (trim)//���� ������ ������ - ���������� ���
				{
					if (trim->play(localdata.trim, helicopter.fullName["trim_on"], "NULL", helicopter.fullName["trim_off"], helicopter.trim))
					{

					}
					else
					{
						Free(trim);//������� ������
					}
				}
			}
			//�����
			if (true)
			{
				if (localdata.p_rain)//������� �������� �������
					if (!rain)//���� ������ �� ������ 
						rain = new Sound;//������� ������
				if (rain)//���� ������ ������ - ���������� ���
				{
					if (rain->play(localdata.p_rain, "NULL", helicopter.fullName["rain"], "NULL", helicopter.rainFactor))
					{

					}
					else
					{
						Free(rain);//������� ������
					}
				}
			}
			//���� ���� ��������� ������ ������� � ������
			if (helicopter.rocketHitFactor)
			{
				if (localdata.p_rocket_hit)//������� �������� �������
				{
					if (!rocket[counterRocketHit] && !rocketHitLocker)
					{
						rocket[counterRocketHit] = new Sound;//������� ������
						counterRocketHit++;
						rocketHitLocker = localdata.p_rocket_hit;
					}
					if (counterRocketHit >= 50)
					{
						counterRocketHit = 0;
					}
				}
				else
				{
					rocketHitLocker = 0;
				}

				for (size_t i = 0; i < 50; i++)
				{
					if (rocket[i])
					{
						rocket[i]->play(rocketHitLocker, helicopter.fullName["rocket"], "NULL", "NULL", helicopter.rocketHitFactor);

						if (rocket[i]->sourceStatus[rocket[i]->id] != AL_PLAYING)
						{
							Free(rocket[i]);
						}
					}
				}
			}
			//���� ���� ��������� ���� ������� � ������
			if (helicopter.bulletHitFactor)
			{
				if (localdata.p_bullet_hit)//������� �������� �������
				{
					if (!bullet[counterBulletHit] && !bulletHitLocker)
					{
						bullet[counterBulletHit] = new Sound;//������� ������
						counterBulletHit++;
						bulletHitLocker = localdata.p_bullet_hit;
					}
					if (counterBulletHit >= 50)
					{
						counterBulletHit = 0;
					}
				}
				else
				{
					bulletHitLocker = 0;
				}

				for (size_t i = 0; i < 50; i++)
				{
					if (bullet[i])
					{
						if (bullet[i]->sourceStatus[bullet[i]->id] != AL_PLAYING)
						{
							if (rand() % 10 > 5)
							{
								type[i] = helicopter.fullName["bullet0"];
							}
							else
							{
								type[i] = helicopter.fullName["bullet1"];
							}
						}

						bullet[i]->play(bulletHitLocker, type[i], "NULL", "NULL", helicopter.bulletHitFactor);

						if (bullet[i]->sourceStatus[bullet[i]->id] != AL_PLAYING)
						{
							Free(bullet[i]);
						}
					}
				}
			}
			//���� ���8 ������� �� �����
			if (helicopter.rocketNar8Factor)
			{
				timerNar8 -= Sound::deltaTime;
				if (timerNar8 <= 0)
				{
					timerNar8 = 0;
					check8 = 0;
				}
				if (localdata.p_nar_s8)//������� �������� �������
				{
					check8 = localdata.p_nar_s8;
				}
				if (check8)//������� �������� �������
				{
					if (!timerNar8)
					{
						if (!nar8[counterNar8])
						{
							nar8[counterNar8] = new Sound;//������� ������
							counterNar8++;
						}
						if (counterNar8 >= 50)
						{
							counterNar8 = 0;
						}
						timerNar8 = 0.05;
					}
				}
				for (int i = 0; i < 50; i++)
				{
					//������������� ���� �������� 1�� ���8 ������ 0.125�
					if (nar8[i])
					{
						switch (check8)
						{
						case 1:
							nar8[i]->channel[0] = 1;//L
							nar8[i]->channel[1] = 0;
							break;
						case 2:
							nar8[i]->channel[0] = 0;//R
							nar8[i]->channel[1] = 1;
							break;
						case 3:
							nar8[i]->channel[0] = 1;//centre
							nar8[i]->channel[1] = 1;
							break;
						}

						nar8[i]->play(check8, helicopter.fullName["nar8"], "NULL", "NULL", helicopter.rocketNar8Factor);

						if (nar8[i]->sourceStatus[nar8[i]->id] != AL_PLAYING)
						{
							Free(nar8[i]);
						}
					}
				}
			}
			//���� ���13 ������� �� �����
			if (helicopter.rocketNar13Factor)
			{
				timerNar13 -= Sound::deltaTime;
				if (timerNar13 <= 0)
				{
					timerNar13 = 0;
					check13 = 0;
				}
				if (localdata.p_nar_s13)//������� �������� �������
				{
					check13 = localdata.p_nar_s13;
				}
				if (check13)//������� �������� �������
				{
					if (!timerNar13)
					{
						if (!nar13[counterNar13])
						{
							nar13[counterNar13] = new Sound;//������� ������
							counterNar13++;
						}

						if (counterNar13 >= 50)
						{
							counterNar13 = 0;
						}
						timerNar13 = 0.125;
					}
				}
				for (int i = 0; i < 50; i++)
				{
					//������������� ���� �������� 1�� ���13 ������ 0.15�
					if (nar13[i])
					{
						switch (check13)
						{
						case 1:
							nar13[i]->channel[0] = 1;//L
							nar13[i]->channel[1] = 0;
							break;
						case 2:
							nar13[i]->channel[0] = 0;//R
							nar13[i]->channel[1] = 1;
							break;
						case 3:
							nar13[i]->channel[0] = 1;//centre
							nar13[i]->channel[1] = 1;
							break;
						}

						nar13[i]->play(check13, helicopter.fullName["nar13"], "NULL", "NULL", helicopter.rocketNar13Factor);

						if (nar13[i]->sourceStatus[nar13[i]->id] != AL_PLAYING)
						{
							Free(nar13[i]);
						}
					}
				}
			}
			//���� ��� ������� �� �����
			if (helicopter.ppuFactor)
			{
				if (localdata.p_spo_ppu)//������� �������� �������
					if (!ppu)//���� ������ �� ������ 
						ppu = new Sound;//������� ������
				if (ppu)//���� ������ ������ - ���������� ���
				{
					switch (localdata.p_spo_ppu)
					{
					case 1:
						ppu->channel[0] = 1;//L
						ppu->channel[1] = 0;
						break;
					case 2:
						ppu->channel[0] = 0;//R
						ppu->channel[1] = 1;
						break;
					case 3:
						ppu->channel[0] = 1;//centre
						ppu->channel[1] = 1;
						break;
					}

					if (ppu->play(localdata.p_spo_ppu, "NULL", helicopter.fullName["ppu"], "NULL", helicopter.ppuFactor))
					{

					}
					else
					{
						Free(ppu);//������� ������
					}
				}
			}
			//���� ��� ������� �� �����
			if (helicopter.upkFactor)
			{
				if (localdata.p_spo_upk)//������� �������� �������
					if (!upk)//���� ������ �� ������ 
						upk = new Sound;//������� ������
				if (upk)//���� ������ ������ - ���������� ���
				{
					switch (localdata.p_spo_upk)
					{
					case 1:
						upk->channel[0] = 1;//L
						upk->channel[1] = 0;
						break;
					case 2:
						upk->channel[0] = 0;//R
						upk->channel[1] = 1;
						break;
					case 3:
						upk->channel[0] = 1;//centre
						upk->channel[1] = 1;
						break;
					}

					if (upk->play(localdata.p_spo_upk, "NULL", helicopter.fullName["upk"], "NULL", helicopter.upkFactor))
					{

					}
					else
					{
						Free(upk);//������� ������
					}
				}
			}
			//���� �� ����� ������� �� �����
			if (helicopter.rocketSturmFactor)
			{
				if (localdata.p_ur_ataka)//������� �������� �������
				{
					if (!sturm[counterSturm] && !sturmLocker)
					{
						sturm[counterSturm] = new Sound;//������� ������
						counterSturm++;
						sturmLocker = localdata.p_ur_ataka;
					}
					if (counterSturm >= 50)
					{
						counterSturm = 0;
					}
				}
				else
				{
					sturmLocker = 0;
				}

				for (size_t i = 0; i < 50; i++)
				{
					if (sturm[i])
					{
						switch (sturmLocker)
						{
						case 1:
							sturm[i]->channel[0] = 1;//L
							sturm[i]->channel[1] = 0;
							break;
						case 2:
							sturm[i]->channel[0] = 0;//R
							sturm[i]->channel[1] = 1;
							break;
						case 3:
							sturm[i]->channel[0] = 1;//centre
							sturm[i]->channel[1] = 1;
							break;
						}

						sturm[i]->play(sturmLocker, helicopter.fullName["sturm"], "NULL", "NULL", helicopter.rocketSturmFactor);

						if (sturm[i]->sourceStatus[sturm[i]->id] != AL_PLAYING)
						{
							Free(sturm[i]);
						}
					}
				}
			}
			//���� �� ���� ������� �� �����
			if (helicopter.rocketIglaFactor)
			{
				if (localdata.p_ur_igla)//������� �������� �������
				{
					if (!igla[counterIgla] && !iglaLocker)
					{
						igla[counterIgla] = new Sound;//������� ������
						counterIgla++;
						iglaLocker = localdata.p_ur_igla;
					}
					if (counterIgla >= 50)
					{
						counterIgla = 0;
					}
				}
				else
				{
					iglaLocker = 0;
				}

				for (size_t i = 0; i < 50; i++)
				{
					if (igla[i])
					{
						switch (iglaLocker)
						{
						case 1:
							igla[i]->channel[0] = 1;//L
							igla[i]->channel[1] = 0;
							break;
						case 2:
							igla[i]->channel[0] = 0;//R
							igla[i]->channel[1] = 1;
							break;
						case 3:
							igla[i]->channel[0] = 1;//centre
							igla[i]->channel[1] = 1;
							break;
						}

						igla[i]->play(iglaLocker, helicopter.fullName["igla"], "NULL", "NULL", helicopter.rocketIglaFactor);

						if (igla[i]->sourceStatus[igla[i]->id] != AL_PLAYING)
						{
							Free(igla[i]);
						}
					}
				}
			}
			//��������
			if (helicopter.redFactor)
			{
				if (localdata.p_reduktor_gl_crash)//������� �������� �������
					if (!redCrash)//���� ������ �� ������ 
						redCrash = new Sound;//������� ������
				if (redCrash)//���� ������ ������ - ���������� ���
				{
					if (redCrash->play(localdata.p_reduktor_gl_crash, "NULL", helicopter.fullName["red_crash"], "NULL", helicopter.redFactor))
					{
						redCrash->pitch[redCrash->id] = localdata.reduktor_gl_obor / helicopter.redTurnoverAvt / 2.0;
					}
					else
					{
						Free(redCrash);//������� ������
					}
				}


				if (localdata.reduktor_gl_obor > 0)//������� �������� ������� ���������
					if (!red)//���� ������ �� ������ 
						red = new Reductor;//������� ������
				if (red)//���� ������ ������ - ���������� ���
				{
					if (red->play(helicopter, localdata))
					{

					}
					else
					{
						Free(red);//������� ������
					}
				}
			}
			//���� ��� ������� ����
			double shockInten[4] = {
					localdata.styk_l,
					localdata.styk_hv,
					localdata.styk_nos,
					localdata.styk_r };
			if (helicopter.shock)
			{
				for (size_t i = 0; i < 4; i++)
				{
					if (shockInten[i])//������� �������� �������
					{
						if (!shock[i][counterShock[i]] && !shockLocker[i])
						{
							shock[i][counterShock[i]] = new Sound;//������� ������
							shock[i][counterShock[i]]->gain[0] = shockInten[i];
							shock[i][counterShock[i]]->gain[1] = shockInten[i];
							counterShock[i]++;
							shockLocker[i] = 1;
						}
						if (counterShock[i] >= 50)
						{
							counterShock[i] = 0;
						}
					}
					else
					{
						shockLocker[i] = 0;
					}

					for (size_t j = 0; j < 50; j++)
					{
						if (shock[i][j])
						{
							if ((i + 1) % 2 == 0)
							{
								shock[i][j]->channel[0] = 0;//R
								shock[i][j]->channel[1] = 1;
							}
							else
							{
								shock[i][j]->channel[0] = 1;//L
								shock[i][j]->channel[1] = 0;
							}

							shock[i][j]->play(shockLocker[i], helicopter.fullName["shock"], "NULL", "NULL", helicopter.shock);

							if (shock[i][j]->sourceStatus[shock[i][j]->id] != AL_PLAYING)
							{
								Free(shock[i][j]);
							}
						}
					}
				}
			}
			//���������� �������
			if (helicopter.vadd)
			{
				if (localdata.v_atm_x != 0)//������� �������� �������
				{
					if (!vadd)//���� ������ �� ������ 
					{
						vadd = new Sound;
					}
				}
				if (vadd)//���� ������ ������ - ���������� ���
				{
					double g = 0;
					if (helicopter.modelName == "mi_28")
					{
						if (abs(localdata.v_atm_x) < 60)
						{
							g = interpolation({ 0, -60 }, { 50, -14 }, { 60, -6 }, abs(localdata.v_atm_x));
						}
						else
						{
							g = interpolation({ 60, -6 }, { 70, -3 }, { 80, 0 }, abs(localdata.v_atm_x));
						}
					}
					else if (helicopter.modelName == "mi_8_amtsh" || helicopter.modelName == "mi_8_mtv5")
					{
						g = interpolation({ 0, -60 }, { 42, -18 }, { 70, 0 }, abs(localdata.v_atm_x));
					}
					else if (helicopter.modelName == "ka_29")
					{
						g = (69.4 - abs(localdata.v_atm_x)) * (-0.86);
					}
					else if (helicopter.modelName == "ka_27")
					{
						g = (69.4 - abs(localdata.v_atm_x)) * (-0.86);
					}
					/*else if (helicopter.modelName == "mi_26")
					{
						g = abs(localdata.v_atm_x) * 0.428 - 36;
					}*/
					else if (helicopter.modelName == "ka_226")
					{
						g = getParameterFromVector(vector<point>{ { 36.11111, -60 }, { 50, 0 } }, abs(localdata.v_atm_x));
					}
					else if (helicopter.modelName == "ansat")
					{
						g = getParameterFromVector(vector<point>{ { 28, -60 }, { 44.44, -15 }, { 56, -6 }, { 61.11, -1 }, { 70, 0 } }, abs(localdata.v_atm_x));
					}
					else
					{
						g = -60;
					}
					vadd->gain[vadd->id] = toCoef(g);

					vadd->play(localdata.v_atm_x != 0, "NULL", helicopter.fullName["pinkNoise"], "NULL", helicopter.vadd);
					if (localdata.v_atm_x == 0)//������� �������� �������
					{
						Free(vadd);//������� ������
					}
				}
			}
			//���������
			if (helicopter.engFactor)
			{
				if (localdata.p_eng1_pomp)//������� �������� �������
				{
					if (!engPomp[0])//���� ������ �� ������ 
					{
						engPomp[0] = new Sound;//������� ������
					}
				}
				if (engPomp[0])//���� ������ ������ - ���������� ���
				{
					engPomp[0]->channel[0] = 1;//L
					engPomp[0]->channel[1] = 0;
					if (engPomp[0]->play(localdata.p_eng1_pomp, helicopter.fullName["eng_pomp_on"], helicopter.fullName["eng_pomp_w"], "NULL", helicopter.engFactor))
					{

					}
					else
					{
						Free(engPomp[0]);//������� ������
					}
				}

				if (localdata.p_eng2_pomp)//������� �������� �������
				{
					if (!engPomp[1])//���� ������ �� ������ 
					{
						engPomp[1] = new Sound;//������� ������
					}
				}
				if (engPomp[1])//���� ������ ������ - ���������� ���
				{
					engPomp[1]->channel[0] = 0;
					engPomp[1]->channel[1] = 1;//R
					if (engPomp[1]->play(localdata.p_eng2_pomp, helicopter.fullName["eng_pomp_on"], helicopter.fullName["eng_pomp_w"], "NULL", helicopter.engFactor))
					{

					}
					else
					{
						Free(engPomp[1]);//������� ������
					}
				}

				if (localdata.eng1_obor > 0)
				{
					if (!eng[0])//���� ������ �� ������ 
					{
						eng[0] = new Engine;//������� ������
					}
				}
				if (eng[0])//���� ������ ������ - ���������� ���
				{
					eng[0]->angle = 'l';
					if (eng[0]->play(localdata.p_eng1_zap, localdata.p_eng1_ostanov, localdata.p_eng1_hp, localdata.eng1_obor, helicopter))
					{

					}
					else
					{
						Free(eng[0]);//������� ������
					}
				}

				if (localdata.eng2_obor > 0)
				{
					if (!eng[1])//���� ������ �� ������ 
					{
						eng[1] = new Engine;//������� ������
					}
				}
				if (eng[1])//���� ������ ������ - ���������� ���
				{
					eng[1]->angle = 'r';
					if (eng[1]->play(localdata.p_eng2_zap, localdata.p_eng2_ostanov, localdata.p_eng2_hp, localdata.eng2_obor, helicopter))
					{

					}
					else
					{
						Free(eng[1]);//������� ������
					}
				}
			}
			//����������� ���� ���
			if (helicopter.vsuCraneFactor)
			{
				if (localdata.p_kran_perekr_vsu)//������� �������� �������
					if (!vsuKran)//���� ������ �� ������ 
						vsuKran = new Crane;//������� ������
				if (vsuKran)//���� ������ ������ - ���������� ���
				{
					if (helicopter.modelName == "ka_27" | helicopter.modelName == "ka_29")
					{
						if (vsuKran->play(localdata.p_kran_perekr_vsu, helicopter.fullName["vsu_kran_on"], "NULL", helicopter.fullName["vsu_kran_on"], helicopter.vsuCraneFactor))
						{

						}
						else
						{
							Free(vsuKran);//������� ������
						}
					}
					else
					{
						if (vsuKran->play(localdata.p_kran_perekr_vsu, helicopter.fullName["vsu_kran_on"], helicopter.fullName["vsu_kran_w"], helicopter.fullName["vsu_kran_on"], helicopter.vsuCraneFactor))
						{

						}
						else
						{
							Free(vsuKran);//������� ������
						}
					}
				}
			}
			//������
			if (helicopter.buzzerFactor)
			{
				if (localdata.zoomer)//������� �������� �������
					if (!beep)//���� ������ �� ������ 
						beep = new Sound;//������� ������
				if (beep)//���� ������ ������ - ���������� ���
				{
					if (beep->play(localdata.zoomer, "NULL", helicopter.fullName["beep"], "NULL", helicopter.buzzerFactor))
					{

					}
					else
					{
						Free(beep);//������� ������
					}
				}
			}
			//�������������� 1
			if (helicopter.undefinedFactor)
			{
				if (helicopter.modelName == "mi_28")
				{
					if (localdata.undefined)//������� �������� �������
						if (!undefined1)//���� ������ �� ������ 
							undefined1 = new Sound;//������� ������
					if (undefined1)//���� ������ ������ - ���������� ���
					{
						if (undefined1->play(localdata.undefined, "NULL", helicopter.fullName["undefined1_w"], "NULL", helicopter.undefinedFactor))
						{

						}
						else
						{
							Free(undefined1);//������� ������
						}
					}
				}
				else if (helicopter.modelName == "ka_29")
				{
					if (localdata.undefined)//������� �������� �������
						if (!undefined1)//���� ������ �� ������ 
							undefined1 = new Sound;//������� ������
					if (undefined1)//���� ������ ������ - ���������� ���
					{
						if (undefined1->play(localdata.undefined, helicopter.fullName["undefined1_on"], helicopter.fullName["undefined1_w"], "NULL", helicopter.undefinedFactor))
						{

						}
						else
						{
							Free(undefined1);//������� ������
						}
					}
				}
				else if (helicopter.modelName == "ansat")
				{
					if (localdata.undefined)//������� �������� �������
						if (!undefined1)//���� ������ �� ������ 
							undefined1 = new Sound;//������� ������
					if (undefined1)//���� ������ ������ - ���������� ���
					{
						if (undefined1->play(localdata.undefined, helicopter.fullName["undefined1_on"], helicopter.fullName["undefined1_w"], helicopter.fullName["undefined1_off"], helicopter.undefinedFactor))
						{

						}
						else
						{
							Free(undefined1);//������� ������
						}
					}
				}
			}
		}
		else
		{
			//������� ��� �������
			if (!Sound::vectorVXZ.empty())
			{
				Sound::vectorVXZ.clear();
			}
			if (!Sound::vectorAccXZ.empty())
			{
				Sound::vectorAccXZ.clear();
			}
			if (!Sound::vectorStep.empty())
			{
				Sound::vectorStep.clear();
			}
			if (!Sound::vectorTangaz.empty())
			{
				Sound::vectorTangaz.clear();
			}
			if (!Sound::vectorTime.empty())
			{
				Sound::vectorTime.clear();
			}
			if (!Sound::vectorRedTurn.empty())
			{
				Sound::vectorRedTurn.clear();
			}
			if (!Sound::vectorAvrAtk.empty())
			{
				Sound::vectorAvrAtk.clear();
			}
			if (!Sound::vectorAvrEng1Turn.empty())
			{
				Sound::vectorAvrEng1Turn.clear();
			}
			if (!Sound::vectorAvrEng2Turn.empty())
			{
				Sound::vectorAvrEng2Turn.clear();
			}
			if (!Sound::vectorAvrRedTurn.empty())
			{
				Sound::vectorAvrRedTurn.clear();
			}
			if (!Sound::vectorAvrStep.empty())
			{
				Sound::vectorAvrStep.clear();
			}

			//�������� ��� �����
			if (vsu)
			{
				Free(vsu);
			}
			if (accum)//���� ������ ������ - ���������� ���
			{
				Free(accum);//������� ������
			}
			if (accumTr)//���� ������ ������ - ���������� ���
			{
				Free(accumTr);//������� ������
			}
			if (pts)//���� ������ ������ - ���������� ���
			{
				Free(pts);//������� ������
			}
			if (ptsTone)//���� ������ ������ - ���������� ���
			{
				Free(ptsTone);//������� ������
			}
			if (vpryam)//���� ������ ������ - ���������� ���
			{
				Free(vpryam);//������� ������
			}
			if (tr36)//���� ������ ������ - ���������� ���
			{
				Free(tr36);//������� ������
			}
			if (tr115)//���� ������ ������ - ���������� ���
			{
				Free(tr115);//������� ������
			}
			if (nip)//���� ������ ������ - ���������� ���
			{
				Free(nip);//������� ������
			}
			if (girovert)//���� ������ ������ - ���������� ���
			{
				Free(girovert);//������� ������
			}
			for (size_t i = 0; i < 2; i++)
			{
				if (eng[i])
				{
					Free(eng[i]);
				}
			}
			if (red)
			{
				Free(red);
			}
			if (vintFlap)
			{
				Free(vintFlap);
			}
			if (vintSwish)
			{
				Free(vintSwish);
			}
			if (vadd)
			{
				Free(vadd);
			}
			if (runway)
			{
				Free(runway);
			}

			//�������� ����������
			timerAvr = 0;
			periodCalc = 0;
		}

		//��������
		if (true)
		{
			if (localdata.p_crash)//������� �������� �������
				if (!crash)//���� ������ �� ������ 
					crash = new Sound;//������� ������
			if (crash)//���� ������ ������ - ���������� ���
			{
				if (crash->play(localdata.p_crash, helicopter.fullName["crash"], "NULL", "NULL", 1))
				{
					stop = 1;
				}
				else
				{
					Free(crash);//������� ������
					stop = 0;
					Sound::masterGain = 0;
				}
			}
		}
	}
	atexit(freeOpenAL);//���������� ������� KillALData �� ���������� ���������
	StopRealTime();
	return 0;
}

int parametricalCrossfade(double *fadeGain, double *riseGain, double parameter, double fadeLimit, double riseLimit)
{
	if ((riseLimit > fadeLimit && parameter < fadeLimit) || (riseLimit < fadeLimit && parameter > fadeLimit))
	{
		*fadeGain = 1;
		*riseGain = 0;
	}
	if ((riseLimit > fadeLimit && parameter > riseLimit) || (riseLimit < fadeLimit && parameter < riseLimit))
	{
		*fadeGain = 0;
		*riseGain = 1;
	}
	if ((riseLimit > fadeLimit && parameter <= riseLimit && parameter >= fadeLimit) || (riseLimit < fadeLimit && parameter >= riseLimit && parameter <= fadeLimit))
	{
		double crossfader = getParameterFromVector(vector<point>{ {fadeLimit, -1}, { riseLimit, 1 }}, parameter);
		*fadeGain = sqrt(0.5*(1 - crossfader));
		*riseGain = sqrt(0.5*(1 + crossfader));
	}

	if (riseLimit > fadeLimit && parameter > riseLimit)
		return 1;//���������� 1 ����� ��������� ��������

	if (riseLimit < fadeLimit && parameter < riseLimit)
		return 1;

	return 0;//���������� 0 ����� ��������� �� ��������
}

int timeCrossfade(double &fadeGain, double &riseGain, double crossFadeDuration, double timer)
{
	double crossfader = 0;
	if (crossFadeDuration == 0)
	{
		crossfader = 1;
	}
	else
	{
		crossfader = (timer * (2 / crossFadeDuration)) - 1;
	}
	crossfader = (crossfader > 1) ? 1 : crossfader;
	crossfader = (crossfader < -1) ? -1 : crossfader;
	fadeGain = sqrt(0.5*(1 - crossfader));
	riseGain = sqrt(0.5*(1 + crossfader));

	return 0;
}

void setEFXPointers()
{
	// Get function pointers
	alGenEffects = (LPALGENEFFECTS)alGetProcAddress("alGenEffects");
	alDeleteEffects = (LPALDELETEEFFECTS)alGetProcAddress("alDeleteEffects");
	alIsEffect = (LPALISEFFECT)alGetProcAddress("alIsEffect");
	alEffecti = (LPALEFFECTI)alGetProcAddress("alEffecti");
	alEffectiv = (LPALEFFECTIV)alGetProcAddress("alEffectiv");
	alEffectf = (LPALEFFECTF)alGetProcAddress("alEffectf");
	alEffectfv = (LPALEFFECTFV)alGetProcAddress("alEffectfv");
	alGetEffecti = (LPALGETEFFECTI)alGetProcAddress("alGetEffecti");
	alGetEffectiv = (LPALGETEFFECTIV)alGetProcAddress("alGetEffectiv");
	alGetEffectf = (LPALGETEFFECTF)alGetProcAddress("alGetEffectf");
	alGetEffectfv = (LPALGETEFFECTFV)alGetProcAddress("alGetEffectfv");
	alGenFilters = (LPALGENFILTERS)alGetProcAddress("alGenFilters");
	alDeleteFilters = (LPALDELETEFILTERS)alGetProcAddress("alDeleteFilters");
	alIsFilter = (LPALISFILTER)alGetProcAddress("alIsFilter");
	alFilteri = (LPALFILTERI)alGetProcAddress("alFilteri");
	alFilteriv = (LPALFILTERIV)alGetProcAddress("alFilteriv");
	alFilterf = (LPALFILTERF)alGetProcAddress("alFilterf");
	alFilterfv = (LPALFILTERFV)alGetProcAddress("alFilterfv");
	alGetFilteri = (LPALGETFILTERI)alGetProcAddress("alGetFilteri");
	alGetFilteriv = (LPALGETFILTERIV)alGetProcAddress("alGetFilteriv");
	alGetFilterf = (LPALGETFILTERF)alGetProcAddress("alGetFilterf");
	alGetFilterfv = (LPALGETFILTERFV)alGetProcAddress("alGetFilterfv");
	alGenAuxiliaryEffectSlots = (LPALGENAUXILIARYEFFECTSLOTS)alGetProcAddress("alGenAuxiliaryEffectSlots");
	alDeleteAuxiliaryEffectSlots = (LPALDELETEAUXILIARYEFFECTSLOTS)alGetProcAddress("alDeleteAuxiliaryEffectSlots");
	alIsAuxiliaryEffectSlot = (LPALISAUXILIARYEFFECTSLOT)alGetProcAddress("alIsAuxiliaryEffectSlot");
	alAuxiliaryEffectSloti = (LPALAUXILIARYEFFECTSLOTI)alGetProcAddress("alAuxiliaryEffectSloti");
	alAuxiliaryEffectSlotiv = (LPALAUXILIARYEFFECTSLOTIV)alGetProcAddress("alAuxiliaryEffectSlotiv");
	alAuxiliaryEffectSlotf = (LPALAUXILIARYEFFECTSLOTF)alGetProcAddress("alAuxiliaryEffectSlotf");
	alAuxiliaryEffectSlotfv = (LPALAUXILIARYEFFECTSLOTFV)alGetProcAddress("alAuxiliaryEffectSlotfv");
	alGetAuxiliaryEffectSloti = (LPALGETAUXILIARYEFFECTSLOTI)alGetProcAddress("alGetAuxiliaryEffectSloti");
	alGetAuxiliaryEffectSlotiv = (LPALGETAUXILIARYEFFECTSLOTIV)alGetProcAddress("alGetAuxiliaryEffectSlotiv");
	alGetAuxiliaryEffectSlotf = (LPALGETAUXILIARYEFFECTSLOTF)alGetProcAddress("alGetAuxiliaryEffectSlotf");
	alGetAuxiliaryEffectSlotfv = (LPALGETAUXILIARYEFFECTSLOTFV)alGetProcAddress("alGetAuxiliaryEffectSlotfv");
}

void freeOpenAL()
{
	alutExit();
}

int getMaxAvaliableSources()
{
	ALCdevice *device;
	ALCcontext *context;

	device = alcOpenDevice(0);
	if (device == 0)
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		return AL_FALSE;
	}

	context = alcCreateContext(device, 0);
	if (context == 0)
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		alcCloseDevice(device);
		return AL_FALSE;
	}
	if (!alcMakeContextCurrent(context))
	{
		cout << alcGetString(device, alcGetError(device)) << endl;
		alcDestroyContext(context);
		alcCloseDevice(device);
		return AL_FALSE;
	}

	ALCint size;
	alcGetIntegerv(device, ALC_ATTRIBUTES_SIZE, 1, &size);
	ALCint *attrs;
	attrs = new ALCint[size];
	alcGetIntegerv(device, ALC_ALL_ATTRIBUTES, size, attrs);

	int maxmono = 0;
	int maxstereo = 0;
	for (size_t i = 0; i < size; ++i)
	{
		/*if (attrs[i] == ALC_SYNC)
		{
			std::cout << " Flag, indicating a synchronous context : " << attrs[i + 1] << std::endl;
		}
		if (attrs[i] == ALC_REFRESH)
		{
			std::cout << " Refresh intervals, in units of Hz: " << attrs[i + 1] << std::endl;
		}
		if (attrs[i] == ALC_FREQUENCY)
		{
			std::cout << " Frequency for mixing output buffer, in units of Hz : " << attrs[i + 1] << std::endl;
		}*/
		if (attrs[i] == ALC_MONO_SOURCES)
		{
			//std::cout << " A hint indicating how many sources should be capable of supporting mono data: " << attrs[i + 1] << std::endl;
			maxmono = attrs[i + 1];
		}
		if (attrs[i] == ALC_STEREO_SOURCES)
		{
			//	std::cout << " A hint indicating how many sources should be capable of supporting stereo data: " << attrs[i + 1] << std::endl;
			maxstereo = attrs[i + 1];
		}
	}
	alcDestroyContext(context);
	alcCloseDevice(device);
	return maxmono + maxstereo;
}

int Sound::play(bool status, string pathOn, string pathW, string pathOff, double gainMult)
{
	bool start;	//���������� ��� ����� ���� �� ������
	bool work;	//���������� ��� ����� ���� �� ������
	bool end;	//���������� ��� ����� ���� �� ����������
	bool free;	//���������� ��� ����� ���� �� ������������� ������

	//������ ������ ������ ������� � ���������
	if (pathOn != "NULL")
		lengthOn = getLengthWAV(pathOn);
	if (pathOff != "NULL")
		lengthOff = getLengthWAV(pathOff);

	alGetSourcei(source[id], AL_SOURCE_STATE, &sourceStatus[id]);//��������� ������ ���������

	//������� ������� ����� ��� ����� ������������
	if (pathOn != "NULL" & pathW != "NULL" & pathOff != "NULL")
	{
		start = status & !soundOn & !soundWork;
		work = status & soundOn & !soundWork & ((lengthOn - offset[id]) <= crossFadeDuration);
		end = !status & !soundOff;
		free = !status & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ���������
	if (pathOn != "NULL" & pathW != "NULL" & pathOff == "NULL")
	{
		start = status & !soundOn & !soundWork;
		work = status & soundOn & !soundWork & ((lengthOn - offset[id]) <= crossFadeDuration);
		end = 0;
		free = !status;
	}
	//������� ������� ����� ����������� ������
	if (pathOn != "NULL" & pathW == "NULL" & pathOff != "NULL")
	{
		start = status & !soundOn;
		work = 0;
		end = !status & !soundOff;
		free = !status & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������
	if (pathOn == "NULL" & pathW != "NULL" & pathOff != "NULL")
	{
		start = 0;
		work = status & !soundWork;
		end = !status & !soundOff;
		free = !status & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������ � ������
	if (pathOn == "NULL" & pathW == "NULL" & pathOff != "NULL")
	{
		start = 0;
		work = 0;
		end = !status & !soundOff;
		free = !status & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������ � ����������
	if (pathOn == "NULL" & pathW != "NULL" & pathOff == "NULL")
	{
		start = 0;
		work = status & !soundWork;
		end = 0;
		free = !status;
	}
	//������� ������� ����� ����������� ������ � ����������
	if (pathOn != "NULL" & pathW == "NULL" & pathOff == "NULL")
	{
		start = status & !soundOn;
		work = 0;
		end = 0;
		free = !status & sourceStatus[id] != AL_PLAYING;
	}
	//��� 0
	if (pathOn == "NULL" & pathW == "NULL" & pathOff == "NULL")
	{
		start = 0;
		work = 0;
		end = 0;
		free = 1;
	}

	//��������� (���� path_o ��������� �� ������ ������� -> � �������� ����������� ���� �������)
	if (start)
	{
		soundOn = 1;
		soundWork = 0;
		soundOff = 0;
		mode = "on";
	}
	//������ (���� pathW ��������� �� ������ ������� -> � �������� ����������� ���� ������ ������)
	if (work)
	{
		soundOn = 0;
		soundWork = 1;
		soundOff = 0;
		mode = "w";
	}
	//���������� (���� pathOff ��������� �� ������ ������� -> � �������� ����������� ���� ����������)
	if (end)
	{
		soundOn = 0;
		soundWork = 0;
		soundOff = 1;
		mode = "off";
	}
	//������������ ������
	if (free)
	{
		soundOn = 0;
		soundWork = 0;
		soundOff = 0;

		return 0; //���������� 0 - ������� ��������� ������ �������
	}

	if (modeSequence.back() != mode)//���� ��������� ����� ������
	{
		switcher = 0;//�������� ������ ���������
		id = !id;//������ ����� ��������� ���������
		if (mode == "on" || mode == "off")//���� ������� ����� ������ ��� ���������� - ������������� � ������� �������
		{
			fileBuffered[id] = "NULL";
		}
		modeSequence.push_back(mode);//��������� ����� � �������
		if (modeSequence.size() > 3)//���� ���� ������� ������� ��������� 3 - ������� ������ ������
		{
			modeSequence.erase(modeSequence.begin());
		}
	}

	//�������������� ���������� � ����������� �� ������
	if (mode == "w")
	{
		filetoBuffer[id] = pathW;
		alSourcef(source[id], AL_LOOPING, AL_TRUE);
	}
	else if (mode == "on")
	{
		filetoBuffer[id] = pathOn;
		alSourcef(source[id], AL_LOOPING, AL_FALSE);
	}
	else if (mode == "off")
	{
		filetoBuffer[id] = pathOff;
		alSourcef(source[id], AL_LOOPING, AL_FALSE);
	}

	double finalGain = gain[id] * gainMult * masterGain;//��������� ������������ ��������� 
	double rise = 0;
	double fade = 0;
	switcher += deltaTime;
	timeCrossfade(fade, rise, crossFadeDuration, switcher);

	if (fileBuffered[id] == "NULL" && filetoBuffer[id] == "NULL")
	{
		rise = 0;
		fade = 1;
	}
	else if ((fileBuffered[!id] == "NULL" && filetoBuffer[!id] == "NULL") || pathW == "NULL")
	{
		rise = 1;
		fade = 0;
	}

	//��������� �������������� ���������
	alSourcef(source[!id], AL_GAIN, fade * finalGain);
	alSourcef(source[id], AL_GAIN, rise * finalGain);

	//float a;
	//float b;
	//alGetSourcef(source[0], AL_GAIN, &a);
	//alGetSourcef(source[1], AL_GAIN, &b);
	//cout.precision(3);
	//cout << fixed
	//	<< " FADE: " << a
	//	<< " RISE: " << b
	//	<< " " << modeSequence[0]
	//	<< " " << modeSequence[1]
	//	<< " " << modeSequence[2]
	//	<< "\t\t\r";

	/*static double p = 0;
	p += deltaTime;
	if (p >= 0.01)
	{
		FILE *f = fopen("cf.txt", "at");
		fprintf(f, "%.3lf\t%.3lf\t%.3lf\n", currentTime, a, b);
		p = 0;
		fclose(f);
	}*/

	for (size_t i = 0; i < 2; i++)
	{
		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			sourceStatus[i] = setAndDeploySound(&buffer[i], &source[i], offset[i], filetoBuffer[i]);
			fileBuffered[i] = filetoBuffer[i];
		}

		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);

		//��������� ������ ����
		alSourcef(source[i], AL_PITCH, pitch[i]);
	}

	//���� ���� ������ - ����������� ����� ���������
	if (soundOn)
	{
		alGetSourcef(source[id], AL_SEC_OFFSET, &offset[id]);
		offsetOn = offset[id];
		if (offset[id] != 0)
		{
			offset[!id] = lengthOff * (1 - (offset[id] / lengthOn));
		}
	}
	//���� ���� ��������� - ����������� ����� �������
	if (soundOff)
	{
		alGetSourcef(source[id], AL_SEC_OFFSET, &offset[id]);
		offsetOff = offset[id];
		if (offset[id] != 0)
		{
			offset[!id] = lengthOn * (1 - (offset[id] / lengthOff));
		}
	}

	return 1;
}

int Sound::setSource(ALuint *Buffer, ALuint *Source, string file_path)
{
	int play = 0;
	alSourceStop(*Source);//������������� ���������������
	alSourcei(*Source, AL_BUFFER, NULL);//����������� �����
	alDeleteBuffers(1, &*Buffer);//������� �����
	alGenBuffers(1, &*Buffer);//����������� �����
	if (file_path == "NULL")//���� ���� ����� "����" �������
	{
		return 0;
	}
	if (!setBuffer(*Buffer, file_path, channel))//��������� �����
		return 0;
	alSourcei(*Source, AL_BUFFER, *Buffer);//���������� ����� � ���������
	alGetSourcei(*Source, AL_SOURCE_STATE, &play);//�������� ������ ���������������
	return play;//���������� ������ ���������������
}

int Sound::switchBuffer(ALuint * Buffer, ALuint * Source)
{
	if (*Buffer == -1)//������� ����
	{
		return 0;
	}
	int play = 0;
	alSourceStop(*Source);//������������� ���������������
	alSourcei(*Source, AL_BUFFER, NULL);//����������� �����
	alSourcei(*Source, AL_BUFFER, *Buffer);//���������� ����� � ���������
	alGetSourcei(*Source, AL_SOURCE_STATE, &play);//�������� ������ ���������������
	return play;//���������� ������ ���������������
}

int Sound::setAndDeploySound(ALuint *Buffer, ALuint *Source, double offset, string file_path)
{
	int play = 0;
	alSourceStop(*Source);//������������� ���������������
	alSourcei(*Source, AL_BUFFER, NULL);//����������� �����
	alDeleteBuffers(1, &*Buffer);//������� �����
	alGenBuffers(1, &*Buffer);//����������� �����
	if (file_path == "NULL")//���� ���� ����� "����" �������
	{
		return 0;
	}
	if (!setBuffer(*Buffer, file_path, channel))//��������� �����
		return 0;
	alSourcei(*Source, AL_BUFFER, *Buffer);//���������� ����� � ���������
	alSourcef(*Source, AL_SEC_OFFSET, offset);//������������� ������ � ���
	alSourcef(*Source, AL_GAIN, 0);//������������� ��������� � 0
	alSourcePlay(*Source);//��������� ��������������
	alGetSourcei(*Source, AL_SOURCE_STATE, &play);//�������� ������ ���������������
	return play;//���������� ������ ���������������
}

double Sound::getAverange(vector<double> &vectorOfParameters, double seconds)
{
	double averange = 0;
	int size = vectorOfParameters.size();
	double window = size / globalWindow * seconds;
	for (size_t i = size - window; i < size; i++)
	{
		averange += vectorOfParameters[i] / window;
	}
	return averange;
}

Reductor::Reductor() : Sound(4, 4, 3)
{
	//�� ����� ����� ��� ������ ����������� �� 
	//����������� ���������� ��������� ����������
	//��� ������� ��� �������� ������ �������� ����������� Sound
	//����� ������ ��� if(modelName == mi_26){reductor = new Sound(4,4,2)}else{reductor = new Sound(3,3,2)}
}

Reductor::~Reductor()
{
}

int Reductor::play(Helicopter &h, SOUNDREAD &sr)
{
	//0 -> ��
	if (sr.p_eng1_hp || sr.p_eng2_hp)
	{
		mode = "on_hp";
	}
	//0 -> ��1��
	else if (sr.reduktor_gl_obor <= h.redTurnoverMg1 * 0.9 && redTurnAcc > 0 && !(sr.p_eng1_ostanov && sr.p_eng2_ostanov))
	{
		if (h.redLengthOn - offsetOn <= crossFadeDuration && offsetOn/*�� ����*/)
		{
			mode = "mg1";
		}
		else
		{
			mode = "on";
		}
	}
	//��1��
	else if (sr.reduktor_gl_obor <= h.redTurnoverMg1 && !(sr.p_eng1_ostanov && sr.p_eng2_ostanov))
	{
		if (mode == "on_hp" || mode == "w_hp" || mode == "off_hp")
		{
			mode = "w_hp";
		}
		else
		{
			mode = "mg1";
		}
	}
	//��1�� <-> ��2��
	else if (sr.reduktor_gl_obor > h.redTurnoverMg1 && sr.reduktor_gl_obor <= h.redTurnoverMg2 && !(sr.p_eng1_ostanov && sr.p_eng2_ostanov))
	{
		mode = "mg2";
	}
	//��2�� <-> ���
	else if (sr.reduktor_gl_obor > h.redTurnoverMg2)
	{
		if (h.modelName == "mi_28")
		{
			if (step >= 5)
			{
				mode = "avt_fly";
			}
			else
			{
				mode = "avt";
			}
		}
		else
		{
			mode = "avt";
		}
	}
	//��2�� -> 0
	else if (sr.p_eng1_ostanov && sr.p_eng2_ostanov && redTurnAcc < 0/* && sr.reduktor_gl_obor > 0*/)
	{
		if (mode == "w_hp" || mode == "on_hp" || mode == "off_hp")
		{
			mode = "off_hp";
		}
		else
		{
			if (sr.reduktor_gl_obor > h.redTurnoverMg2)
			{
				mode = "avtOff";
			}
			else
			{
				mode = "off";
			}
		}
	}

	if (modeSequence.back() != mode)
	{
		switcher = 0;
		id = !id;
		if (mode == "on" || mode == "off")
		{
			fileBuffered[id] = "NULL";
		}
		modeSequence.push_back(mode);
		if (modeSequence.size() >= 4)
		{
			modeSequence.erase(modeSequence.begin());
		}
	}

	if (mode == "on_hp")
	{
		filetoBuffer[id] = "NULL";
	}
	else if (mode == "w_hp")
	{
		filetoBuffer[id] = "NULL";
	}
	else if (mode == "off_hp")
	{
		filetoBuffer[id] = "NULL";
	}
	else if (mode == "on")
	{
		filetoBuffer[id] = h.fullName["red_on_w"];
	}
	else if (mode == "mg1")
	{
		filetoBuffer[id] = h.fullName["red_w_w"];
	}
	else if (mode == "mg2")
	{
		filetoBuffer[id] = h.fullName["red_w_mg_w"];
		filetoBuffer[!id] = h.fullName["red_w_w"];
	}
	else if (mode == "avt")
	{
		filetoBuffer[id] = h.fullName["red_w_avt_w"];
		filetoBuffer[!id] = h.fullName["red_w_mg_w"];
	}
	else if (mode == "avt_fly")
	{
		filetoBuffer[id] = h.fullName["red_w_avt_fly"];
		filetoBuffer[!id] = h.fullName["red_w_avt_w"];
	}
	else if (mode == "avtOff")
	{
		filetoBuffer[!id] = h.fullName["red_w_avt_w"];
		filetoBuffer[id] = h.fullName["red_w_mg_w"];
	}
	else if (mode == "off")
	{
		if (modeSequence[1] == "avt")
		{
			fileBuffered[id] = h.fullName["red_w_mg_w"];
			modeSequence[1] = "mg2";
			id = !id;
			filetoBuffer[id] = h.fullName["red_off_w"];
		}
		else
		{
			if (modeSequence[1] == "mg2" && filetoBuffer[id] != h.fullName["red_off_w"] && sr.reduktor_gl_obor < (h.redTurnoverMg1 + h.redTurnoverMg2) / 2)
			{
				id = !id;
			}
			filetoBuffer[id] = h.fullName["red_off_w"];
		}
	}

	double finalGain = h.redFactor * masterGain;
	double rise = 1;
	double fade = 1;

	if (filetoBuffer[id] == h.fullName["red_off_w"] ||
		filetoBuffer[id] == h.fullName["red_on_w"] ||
		filetoBuffer[!id] == h.fullName["red_off_w"])
	{
		switcher += deltaTime;
		timeCrossfade(fade, rise, crossFadeDuration, switcher);
	}
	else if ((filetoBuffer[!id] == h.fullName["red_on_w"]) && (filetoBuffer[id] == h.fullName["red_w_w"]))
	{
		if (reperSet != "set")
		{
			reperTurn = sr.reduktor_gl_obor;
			reperSet = "set";
		}

		double timeGain[2];
		double turnGain[2];

		if (sr.reduktor_gl_obor <= h.redTurnoverMg1)
		{
			parametricalCrossfade(&turnGain[!id], &turnGain[id], sr.reduktor_gl_obor, reperTurn, h.redTurnoverMg1);
		}
		else
		{
			turnGain[id] = 1;
			turnGain[!id] = 0;
		}

		if (offsetOn != 0)
		{
			timeCrossfade(timeGain[!id], timeGain[id], crossFadeDuration, crossFadeDuration - (h.redLengthOn - offsetOn));
		}
		else
		{
			timeGain[id] = 1;
			timeGain[!id] = 0;
		}

		rise = max(timeGain[id], turnGain[id]);
		fade = min(timeGain[!id], turnGain[!id]);
	}
	else if ((filetoBuffer[!id] == h.fullName["red_w_avt_w"]) && (filetoBuffer[id] == h.fullName["red_w_avt_fly"]))
	{
		rise = 1;
		fade = 0;
	}

	//string modes = "[" + modeSequence[0] + " " + modeSequence[1] + " " + modeSequence[2] + "]";
	//cout.precision(3);
	//cout << fixed
	//	<< " ID__: " << id
	//	//<< " gain[" << id << "]: " << gain[id]
	//	//<< " gain[" << !id << "]: " << gain[!id]
	//	<< " pitch[" << id << "]: " << pitch[id]
	//	<< " pitch[" << !id << "]: " << pitch[!id]
	//	<< " redt: " << sr.reduktor_gl_obor
	//	//<< " round: " << roundFloat(getParameterFromVector(h.redFunctionOn, offsetOn), 0.001)
	//	<< " switcher: " << switcher
	//	<< " rise: " << rise
	//	<< " fade: " << fade
	//	//<< " offset[" << id << "]: " << offset[id]
	//	<< " offsetOn: " << offsetOn
	//	//<< " offset[" << !id << "]: " << offset[!id]
	//	<< " FIB[" << id << "]: " << fileBuffered[id]
	//	<< " FIB[" << !id << "]: " << fileBuffered[!id]
	//	<< " mode: " << mode
	//	<< "\t\t\r";

	for (size_t i = 0; i < 2; i++)
	{
		//��� �������� ��������� = 0 � ������������ ����������, ������������ ���������
		if ((mode == "off" || mode == "off_hp") && sr.reduktor_gl_obor == 0 && sourceStatus[id] != AL_PLAYING)
		{
			return 0;
		}
		//���������� ����������
		if (eq[i] != "set")
		{
			alEffecti(effect[i], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[i], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[i], AL_LOWPASS_GAIN, 0);
			alSource3i(source[i], AL_AUXILIARY_SEND_FILTER, effectSlot[i], 0, NULL);
			alSourcei(source[i], AL_DIRECT_FILTER, filter[i]);
			eq[i] = "set";
		}

		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			switchBuffer(&h.bufferMap[filetoBuffer[i]], &source[i]);

			if (filetoBuffer[i] == h.fullName["red_on_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = getParameterFromVector(h.redFunctionOnSwap, sr.reduktor_gl_obor);
				crossFadeDuration = 2;
			}
			else if (filetoBuffer[i] == h.fullName["red_w_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["red_w_mg_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["red_w_avt_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["red_w_avt_fly"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["red_off_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = getParameterFromVector(h.redFunctionOffSwap, sr.reduktor_gl_obor);
				crossFadeDuration = 1;
			}

			alSourcef(source[i], AL_SEC_OFFSET, offset[i]);//������������� ������ � ���
			alSourcef(source[i], AL_GAIN, 0);//������������� ��������� � 0
			alSourcePlay(source[i]);//��������� ��������������

			fileBuffered[i] = filetoBuffer[i];
		}

		if (fileBuffered[i] == h.fullName["red_on_w"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
			pitch[i] = getPitch(h.redTurnoverMg1, sr.reduktor_gl_obor, getParameterFromVector(h.redFunctionOn, offsetOn));
			gain[i] = 1;
		}
		else if (fileBuffered[i] == h.fullName["red_w_w"])
		{
			pitch[i] = roundFloat((sr.reduktor_gl_obor / h.redTurnoverMg1), 0.001);
			gain[i] = getParameterFromVector(vector<point>{ {h.redTurnoverMg1, 1}, { h.redTurnoverMg2, 0 } }, sr.reduktor_gl_obor);
		}
		else if (fileBuffered[i] == h.fullName["red_w_mg_w"])
		{
			pitch[i] = roundFloat((sr.reduktor_gl_obor / h.redTurnoverMg2), 0.001);
			gain[i] = getParameterFromVector(vector<point>{ {h.redTurnoverMg1, 0}, { h.redTurnoverMg2, 1 }, { h.redTurnoverAvt, 0 } }, sr.reduktor_gl_obor);
		}
		else if (fileBuffered[i] == h.fullName["red_w_avt_w"])
		{
			pitch[i] = roundFloat((sr.reduktor_gl_obor / h.redTurnoverAvt), 0.001);
			gain[i] = getParameterFromVector(vector<point>{ {h.redTurnoverMg2, 0}, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);
		}
		else if (fileBuffered[i] == h.fullName["red_w_avt_fly"])
		{
			pitch[i] = roundFloat((sr.reduktor_gl_obor / h.redTurnoverAvt), 0.001);
			gain[i] = getParameterFromVector(vector<point>{ {h.redTurnoverMg2, 0}, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);
		}
		else if (fileBuffered[i] == h.fullName["red_off_w"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOff);
			pitch[i] = getPitch(h.redTurnoverMg2, sr.reduktor_gl_obor, getParameterFromVector(h.redFunctionOff, offsetOff));
			gain[i] = 1;
		}
		if (fileBuffered[id] == "NULL")
		{
			gain[id] = 0;
		}

		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);

		alSourcef(source[i], AL_PITCH, pitch[i]);
	}

	double lowFreqGain = AL_EQUALIZER_DEFAULT_LOW_GAIN;
	double mid1FreqGain = AL_EQUALIZER_DEFAULT_MID1_GAIN;
	double mid2FreqGain = AL_EQUALIZER_DEFAULT_MID2_GAIN;
	double highFreqGain = AL_EQUALIZER_DEFAULT_HIGH_GAIN;

	double lowCutoffFreq = AL_EQUALIZER_DEFAULT_LOW_CUTOFF;//�� 50-800
	double mid1CutoffFreq = AL_EQUALIZER_DEFAULT_MID1_CENTER;//����� 1 200-3000
	double mid2CutoffFreq = AL_EQUALIZER_DEFAULT_MID2_CENTER;//����� 2 1000-8000
	double highCutoffFreq = AL_EQUALIZER_DEFAULT_HIGH_CUTOFF;//�� 4000-16000

	double avrTurnRestrict = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);

	//������ �� 28
	if (h.modelName == "mi_28")
	{
		//��������� ������� ������� �� ��������� 30�
		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//�������� �� �����
		double atkXvel = calcA * interpolation({ 0, 0 }, { 16.67, 1 }, abs(velocityVectorXZ));

		double averangeAtk = getAverange(vectorAvrAtk, 20) * interpolation({ 0, 0 }, { 16.67, 1 }, abs(velocityVectorXZ));

		double atkGain = (atkXvel - averangeAtk) * -0.4;
		atkGain = (atkGain < -2) ? -2 : atkGain;
		atkGain = (atkGain > 3) ? 3 : atkGain;

		//����� �������� �� �������� 
		double velocityGain = 0;
		if (velocityVectorXZ < 70)
		{
			velocityGain = interpolation({ 20, 0 }, { 50, 2 }, { 70, 5 }, velocityVectorXZ) / 5;
		}
		else
		{
			velocityGain = (velocityVectorXZ  * 0.15 - 5.5) / 5;
		}

		//����� �������� �� ����
		double stepGain = 0;
		if (step < 16)
		{
			stepGain = interpolation({ 0, 0 }, { 11, 3 }, { 16, 5 }, step) / 3;
		}
		else
		{
			stepGain = (step * 0.4 - 1.4) / 3;
		}

		//�������� �� ��������
		double turnGain = (sr.reduktor_gl_obor - averangeTurn) * 0.75 * avrTurnRestrict;

		//�������� �� ����� ��� ������� �� ������� 2�� �������
		if (abs(velocityVectorXZ) <= 16.67) //���� 60�� �������
		{
			if (vectorVXZ.size() > 2)
			{
				if (vectorVXZ.at(vectorVXZ.size() - 2) > 16.67) //���������� ����� ���� �� �� ������� - �� �������
				{
					hovering = 0;
				}
				else //���������� ����� ���� �� �������� - �������
				{
					if (abs(accelerationVectorXZ) < 0.56) // ������� ������� ��������� ����� ��������� ������ ���� �������
					{
						hovering = 1;
					}
				}
			}
		}
		else //���� 60�� �� �������
		{
			hovering = 0;
		}

		//���� ����� ������� ������� � ���� �� ����
		double flapCGain = 0;
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)) && abs(velocityVectorXZ) <= 16.67 /*&& velocityY < 4*/)
		{
			flapCGain = ((abs(accelerationVectorXZ) - 0.56) * 4) * interpolation({ -0.25, 0 }, { 0, 0.5 }, { 0.25, 1 }, velocityY) * hovering;//��������� � �������� �� �� vy
			flapCGain = (flapCGain > 4) ? 4 : flapCGain;
		}

		lowFreqGain = pow(10, (turnGain + velocityGain * 3 + atkGain + flapCGain)*0.05);
		mid1FreqGain = pow(10, (turnGain + stepGain * 2 + velocityGain * 5)*0.05);
		mid2FreqGain = pow(10, (turnGain + stepGain * 4)*0.05);
		highFreqGain = pow(10, (turnGain + stepGain * 4)*0.05);

		lowFreqGain = (lowFreqGain <= 1) ? 1 : lowFreqGain;
		mid1FreqGain = (mid1FreqGain <= 1) ? 1 : mid1FreqGain;
		mid2FreqGain = (mid2FreqGain <= 1) ? 1 : mid2FreqGain;
		highFreqGain = (highFreqGain <= 1) ? 1 : highFreqGain;

		lowCutoffFreq = 200;//�� 50-800
		mid1CutoffFreq = 1000;//����� 1 200-3000
		mid2CutoffFreq = 3000;//����� 2 1000-8000
		highCutoffFreq = 10000;//�� 4000-16000
	}
	//������ 8 ���5, 8 ����
	else if (h.modelName == "mi_8_amtsh" || h.modelName == "mi_8_mtv5")
	{
		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["takeOff"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		//�������� ���� ����������� ��������� ������
		double stepNominal = 0;
		if (h.modelName == "mi_8_amtsh")
		{
			stepNominal = 7;
		}
		else if (h.modelName == "mi_8_mtv5")
		{
			stepNominal = 6;
		}

		double takeOffGain = toCoef(min(getParameterFromVector(vector<point>{ { 0, -12 }, { 3, -5 }, { stepNominal, 0 }}, step),
			getParameterFromVector(vector<point>{ { 0, 0 }, { 8, -12 } }, hight)))
			* getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);

		alSourcef(source[2], AL_GAIN, sm.delay(takeOffGain, deltaTime) * masterGain);

		//��������� ������� ������� �� ��������� 30�
		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//�������� �� �������� ���� 10000
		double highFreqTurnGain = (sr.reduktor_gl_obor - averangeTurn) * 1.5 * avrTurnRestrict;
		highFreqTurnGain = (highFreqTurnGain > 3) ? 3 : highFreqTurnGain;

		//�������� �� ��������
		double turnGain = (sr.reduktor_gl_obor - averangeTurn) * 0.75 * avrTurnRestrict;

		//����� �������� �� �������� ���� 28�/�
		double velocityGain = (abs(velocityVectorXZ) >= 28) ? (abs(velocityVectorXZ) - 28) * 0.1 : 0;//0.1�� �� 1 �/�

		//��������� ������� ��� �� 35�
		double averangeStep = getAverange(vectorAvrStep, 35);

		//�������� �� ����
		double stepGain = 0.75 * (step - averangeStep) * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//�������� �� ���� � ��
		//double mid2FreqStepGain = step * 0.6 * interpolation({ 0, 1 }, { 10, 0 }, hight);

		//�������
		//�������� �� ����� ��� ������� �� ������� 2�� �������
		if (abs(velocityVectorXZ) <= 16.67) //���� 60�� �������
		{
			if (vectorVXZ.size() > 2)
			{
				if (vectorVXZ.at(vectorVXZ.size() - 2) > 16.67) //���������� ����� ���� �� �� ������� - �� �������
				{
					hovering = 0;
				}
				else //���������� ����� ���� �� �������� - �������
				{
					if (abs(accelerationVectorXZ) < 0.56) // ������� ������� ��������� ����� ��������� ������ ���� �������
					{
						hovering = 1;
					}
				}
			}
		}
		else //���� 60�� �� �������
		{
			hovering = 0;
		}
		//���� ����� ������� ������� � ���� �� ����
		double flapCGain = 0;
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)) && abs(velocityVectorXZ) <= 16.67 /*&& velocityY < 4*/)
		{
			flapCGain = ((abs(accelerationVectorXZ) - 0.56) * 4) * interpolation({ -0.25, 0 }, { 0.25, 1 }, velocityY) * hovering;//��������� � �������� �� �� vy
			flapCGain = (flapCGain > 4) ? 4 : flapCGain;
		}

		//�����������
		//�������� ��������� � �� � ������ �������� �� ���
		double stalkingGain = (accelerationVectorXZ > 0) ? accelerationVectorXZ * 5 * interpolation({ 0, 1 }, { 8.3, 0 }, velocityVectorXZ) * !hight : 0;

		lowFreqGain = pow(10, (/*mid2FreqStepGain +*/ flapCGain + stalkingGain)*0.05);
		mid1FreqGain = pow(10, (turnGain + stepGain + velocityGain /*+ mid2FreqStepGain*/ + flapCGain + stalkingGain)*0.05);
		mid2FreqGain = pow(10, (turnGain + stepGain + velocityGain)*0.05);
		highFreqGain = pow(10, (turnGain + stepGain + velocityGain + highFreqTurnGain)*0.05);

		lowCutoffFreq = 250;//�� 50-800
		mid1CutoffFreq = 400;//����� 1 200-3000
		mid2CutoffFreq = 3000;//����� 2 1000-8000
		highCutoffFreq = 10000;//�� 4000-16000
	}
	//������ �� 29
	else if (h.modelName == "ka_29")
	{

		/*if (!setup)
		{
			Sound::vectorAvrEng1Turn.insert(Sound::vectorAvrEng1Turn.begin(), 10000, sr.eng1_obor);
			Sound::vectorAvrEng2Turn.insert(Sound::vectorAvrEng2Turn.begin(), 10000, sr.eng2_obor);
			Sound::vectorAvrRedTurn.insert(Sound::vectorAvrRedTurn.begin(), 10000, sr.reduktor_gl_obor);
			Sound::vectorAvrStep.insert(Sound::vectorAvrStep.begin(), 10000, step);
			Sound::vectorAvrAtk.insert(Sound::vectorAvrAtk.begin(), 10000, calcA);
			setup = 1;
		}*/

		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["takeOff"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		double takeOffGain = toCoef(min(getParameterFromVector(vector<point>{ { 0, -12 }, { 8, -5 }, { 16, 0 }}, step),
			getParameterFromVector(vector<point>{ { 0, 0 }/*, { 4, -2.5 }*/, { 8, -12 } }, hight)))
			* getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);

		alSourcef(source[2], AL_GAIN, sm.delay(takeOffGain, deltaTime) * masterGain);

		/*float toff;
		alGetSourcef(source[2], AL_GAIN, &toff);
		cout.precision(3);
		cout << fixed
			<< " TOFD: " << toff
			<< " TOFG: " << takeOffGain
			<< "\t\t\r";*/

			//�������� ������ ��� �������� �������� �� �������� �������� �������� ��������� �� 30�
		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//����� �������� �� �������� ���� 50�/�
		double velocityGain = (abs(velocityVectorXZ) >= 50) ? (abs(velocityVectorXZ) - 50)* 0.2 : 0;//0.1�� �� 1 �/�

		//�������� ������ ��� �������� �������� �� �������� �������� ���� �� 50�
		double averangeStep = getAverange(vectorAvrStep, 50);

		//������������ �������� �� ��������
		double stepGain = (step - averangeStep) * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//�������� �� ���� � ��
		//double mid2FreqStepGain = step * interpolation(0, 1, 5, 0, hight);

		//�������� �� ���� � ������� �������
		double absStepGain = step * getParameterFromVector(vector<point>{ { 0, 1 }, { 10.5, 0.5 }, { 27.78, 0 } }, abs(velocityVectorXZ));

		//�������� �� �������� ���� 10000
		double highFreqTurnGain = (sr.reduktor_gl_obor - averangeTurn) * 1 * avrTurnRestrict;
		highFreqTurnGain = (highFreqTurnGain > 3) ? 3 : highFreqTurnGain;
		//�������� �� ��������
		double turnGain = (sr.reduktor_gl_obor - averangeTurn) * 0.75 * avrTurnRestrict;

		//�������� �� ����� ��� ������� �� ������� 2�� �������
		if (abs(velocityVectorXZ) <= 16.67) //���� 60�� �������
		{
			if (vectorVXZ.size() > 2)
			{
				if (vectorVXZ.at(vectorVXZ.size() - 2) > 16.67) //���������� ����� ���� �� �� ������� - �� �������
				{
					hovering = 0;
				}
				else //���������� ����� ���� �� �������� - �������
				{
					if (abs(accelerationVectorXZ) < 0.56) // ������� ������� ��������� ����� ��������� ������ ���� �������
					{
						hovering = 1;
					}
				}
			}
		}
		else //���� 60�� �� �������
		{
			hovering = 0;
		}
		//���� ����� ������� ������� � ���� �� ����
		double flapCGain = 0;
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)) && abs(velocityVectorXZ) <= 16.67 /*&& velocityY < 4*/)
		{
			flapCGain = ((abs(accelerationVectorXZ) - 0.56) * 4) * interpolation({ -0.25, 0 }, { 0, 0.5 }, { 0.25, 1 }, velocityY) * hovering;//��������� � �������� �� �� vy
			flapCGain = (flapCGain > 4) ? 4 : flapCGain;
		}

		lowFreqGain = toCoef(turnGain + stepGain * 0.15 + absStepGain * 0.1 /*+ mid2FreqStepGain * 0.3*/ + flapCGain + velocityGain); //0.15 -> 0.15
		mid1FreqGain = toCoef(turnGain + stepGain * 0.2 + absStepGain * 0.1 /*+ mid2FreqStepGain * 0.2*/ + flapCGain);//0.3 -> 0.2
		mid2FreqGain = toCoef(turnGain + stepGain * 0.3 + absStepGain * 0.1 + velocityGain * 0.75);//0.4 -> 0.3
		highFreqGain = toCoef(turnGain + stepGain * 0.5 + absStepGain * 0.3 + highFreqTurnGain);//

		lowFreqGain = (lowFreqGain <= 1) ? 1 : lowFreqGain;
		mid1FreqGain = (mid1FreqGain <= 1) ? 1 : mid1FreqGain;
		mid2FreqGain = (mid2FreqGain <= 1) ? 1 : mid2FreqGain;
		highFreqGain = (highFreqGain <= 1) ? 1 : highFreqGain;

		lowCutoffFreq = 400;//�� 50-800
		mid1CutoffFreq = 1000;//����� 1 200-3000
		mid2CutoffFreq = 3000;//����� 2 1000-8000
		highCutoffFreq = 10000;//�� 4000-16000

		/*cout.precision(3);
		cout << fixed
			<< " STGN: " << stepGain
			<< " ABSG: " << absStepGain
			<< " AVRS: " << averangeStep
			<< " SSS_: " << vectorAvrStep.size()
			<< "\t\t\r";*/

			/*	static double period = 0;
			if (period == 0)
			{
				remove("red.txt");
			}
			period += deltaTime;
			if (period >= 0.1)
			{
				FILE *f = fopen("red.txt", "at");
				fprintf(f, "%lf\t%lf\t%lf\t%lf\n", currentTime, averangeStep, stepGain, step);
				fclose(f);
				period = 0.005;
			}*/
	}
	//������ �� 27
	else if (h.modelName == "ka_27")
	{
		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["takeOff"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		double takeOffGain = toCoef(min(getParameterFromVector(vector<point>{ { 0, -12 }, { 8, -5 }, { 16, 0 }}, step),//db
			getParameterFromVector(vector<point>{ { 0, 0 }/*, { 4, -2.5 }*/, { 8, -12 } }, hight)))//db
			* getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);//coef

		alSourcef(source[2], AL_GAIN, sm.delay(takeOffGain, deltaTime) * masterGain);

		//�������� ������ ��� �������� �������� �� �������� �������� �������� ��������� �� 30�
		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//�������� �� �������� ���� 50��/� (14�/c)
		double velocityGain = 0;
		if (abs(velocityVectorXZ) < 42)
		{
			velocityGain = interpolation({ 14, 0 }, { 42, 3 }, abs(velocityVectorXZ));
		}
		else if (abs(velocityVectorXZ) >= 42 && abs(velocityVectorXZ) < 56)
		{
			velocityGain = interpolation({ 42, 3 }, { 56, 7 }, abs(velocityVectorXZ));
		}
		else
		{
			velocityGain = 7 + (abs(velocityVectorXZ) - 56) * 0.071;
			velocityGain = (velocityGain > 9) ? 9 : velocityGain;
		}

		//�������� ������ ��� �������� �������� �� �������� �������� ���� �� 50�
		double averangeStep = getAverange(vectorAvrStep, 50);

		//������������ �������� �� ��������
		double stepGain = (step - averangeStep)* getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//�������� �� ���� � ��
		double mid2FreqStepGain = step * interpolation({ 0, 1 }, { 5, 0 }, hight);

		//�������� �� ���� � ������� �������
		double absStepGain = step * interpolation({ 0, 1 }, { 10.5, 0.5 }, { 27.78, 0 }, abs(velocityVectorXZ));

		//�������� �� �������� ���� 10000
		double highFreqTurnGain = (sr.reduktor_gl_obor - averangeTurn) * 1 * avrTurnRestrict;
		highFreqTurnGain = (highFreqTurnGain > 3) ? 3 : highFreqTurnGain;
		//�������� �� ��������
		double turnGain = (sr.reduktor_gl_obor - averangeTurn) * 0.75 * avrTurnRestrict;

		//�������� �� ����� ��� ������� �� ������� 2�� �������
		if (abs(velocityVectorXZ) <= 16.67) //���� 60�� �������
		{
			if (vectorVXZ.size() > 2)
			{
				if (vectorVXZ.at(vectorVXZ.size() - 2) > 16.67) //���������� ����� ���� �� �� ������� - �� �������
				{
					hovering = 0;
				}
				else //���������� ����� ���� �� �������� - �������
				{
					if (abs(accelerationVectorXZ) < 0.56) // ������� ������� ��������� ����� ��������� ������ ���� �������
					{
						hovering = 1;
					}
				}
			}
		}
		else //���� 60�� �� �������
		{
			hovering = 0;
		}
		//���� ����� ������� ������� � ���� �� ����
		double flapCGain = 0;
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)) && abs(velocityVectorXZ) <= 16.67 /*&& velocityY < 4*/)
		{
			flapCGain = ((abs(accelerationVectorXZ) - 0.56) * 4) * interpolation({ -0.25 , 0 }, { 0, 0.5 }, { 0.25, 1 }, velocityY) * hovering;//��������� � �������� �� �� vy
			flapCGain = (flapCGain > 4) ? 4 : flapCGain;
		}

		lowFreqGain = pow(10, (turnGain + stepGain * 0.15 + absStepGain * 0.1 /*+ mid2FreqStepGain * 0.3*/ + flapCGain + velocityGain) * 0.05); //0.15 -> 0.15
		mid1FreqGain = pow(10, (turnGain + stepGain * 0.2 + absStepGain * 0.1 /*+ mid2FreqStepGain * 0.2*/ + flapCGain) * 0.05);//0.3 -> 0.2
		mid2FreqGain = pow(10, (turnGain + stepGain * 0.3 + absStepGain * 0.1 + velocityGain * 0.75) * 0.05);//0.4 -> 0.3
		highFreqGain = pow(10, (turnGain + stepGain * 0.5 + absStepGain * 0.3 + highFreqTurnGain) * 0.05);//

		lowFreqGain = (lowFreqGain <= 1) ? 1 : lowFreqGain;
		mid1FreqGain = (mid1FreqGain <= 1) ? 1 : mid1FreqGain;
		mid2FreqGain = (mid2FreqGain <= 1) ? 1 : mid2FreqGain;
		highFreqGain = (highFreqGain <= 1) ? 1 : highFreqGain;

		lowCutoffFreq = 400;//�� 50-800
		mid1CutoffFreq = 1000;//����� 1 200-3000
		mid2CutoffFreq = 3000;//����� 2 1000-8000
		highCutoffFreq = 10000;//�� 4000-16000
	}
	//������ �� 26
	else if (h.modelName == "mi_26")
	{
		//��������� ��� ������
		if (beats != h.fullName["beats"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["beats"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			beats = h.fullName["beats"];

			alEffecti(effect[2], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[2], AL_EFFECTSLOT_EFFECT, effect[2]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[2], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[2], AL_LOWPASS_GAIN, 0);
			alSource3i(source[2], AL_AUXILIARY_SEND_FILTER, effectSlot[2], 0, NULL);
			alSourcei(source[2], AL_DIRECT_FILTER, filter[2]);
		}

		//���������� ��������� ����
		double beatsGain = pow(10, (getParameterFromVector(vector<point>{ { 60, -40 }, { 70, -12 }, { 78, -8 }, { 90, -2 }}, sr.reduktor_gl_obor)) * 0.05);

		gain[2] = beatsGain * masterGain;

		alSourcef(source[2], AL_GAIN, gain[2]);

		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[3], &source[3], 0, h.fullName["takeOff"]);
			alSourcei(source[3], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		double takeOffGain = toCoef(min(getParameterFromVector(vector<point>{ { 0, -30 }, { 6, 0 } }, step),
			getParameterFromVector(vector<point>{ { 0, 0 }/*, { 4, -2.5 }*/, { 10, -30 } }, hight)))
			* getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);

		gain[3] = sm.delay(takeOffGain, deltaTime) * masterGain;

		alSourcef(source[3], AL_GAIN, gain[3]);

		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//�������� �� �������� ���� 10000
		double highFreqTurnGain = (sr.reduktor_gl_obor - averangeTurn) * 1.5 * avrTurnRestrict;
		highFreqTurnGain = (highFreqTurnGain > 3) ? 3 : highFreqTurnGain;

		//�������� �� ��������
		double turnGain = (sr.reduktor_gl_obor - averangeTurn) * 0.75 * avrTurnRestrict;

		double averangeStep = getAverange(vectorAvrStep, 20);

		//�������� �� ����
		double stepGain = (step - averangeStep) * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//�������� �� ���� � ��
		//double mid2FreqStepGain = step * 1 * interpolation(0, 1, 10, 0, hight);

		//�������� �� Vy
		double vyG = (velocityY * (-2) - 10) - 4.43/*���� 0.6*/;
		vyG = (vyG > 0) ? 0 : vyG;
		double velocityYGain = vyG * interpolation({ 0, 1 }, { 22.22, 0 }, abs(velocityVectorXZ)) * ((velocityY < 0) ? 1 : 0);

		//�����������
		//�������� ��������� � �� � ������ �������� �� ���
		double stalkingGain = (accelerationVectorXZ > 0) ? accelerationVectorXZ * 5 * interpolation({ 0, 1 }, { 8.3, 0 }, velocityVectorXZ) * (groundTouch > 0) : 0;

		lowFreqGain = pow(10, (velocityYGain + stepGain * 0.25 + stalkingGain /*+ mid2FreqStepGain*/) * 0.05);
		mid1FreqGain = pow(10, (turnGain + stepGain * 1 + stalkingGain /*+ mid2FreqStepGain*/) * 0.05);
		mid2FreqGain = pow(10, (turnGain + stepGain * 1) * 0.05);
		highFreqGain = pow(10, (turnGain + stepGain * 1 + highFreqTurnGain) * 0.05);

		lowFreqGain = (lowFreqGain <= 1) ? 1 : lowFreqGain;
		mid1FreqGain = (mid1FreqGain <= 1) ? 1 : mid1FreqGain;
		mid2FreqGain = (mid2FreqGain <= 1) ? 1 : mid2FreqGain;
		highFreqGain = (highFreqGain <= 1) ? 1 : highFreqGain;

		lowCutoffFreq = 200;//�� 50-800
		mid1CutoffFreq = 1000;//����� 1 200-3000
		mid2CutoffFreq = 3000;//����� 2 1000-8000
		highCutoffFreq = 10000;//�� 4000-16000

		//�������� ������
		alEffectf(effect[2], AL_EQUALIZER_LOW_CUTOFF, lowCutoffFreq);
		alEffectf(effect[2], AL_EQUALIZER_MID1_CENTER, mid1CutoffFreq);
		alEffectf(effect[2], AL_EQUALIZER_MID2_CENTER, mid2CutoffFreq);
		alEffectf(effect[2], AL_EQUALIZER_HIGH_CUTOFF, highCutoffFreq);

		alEffectf(effect[2], AL_EQUALIZER_LOW_GAIN, pow(10, (stepGain * 0.25)*0.05));//

		alAuxiliaryEffectSloti(effectSlot[2], AL_EFFECTSLOT_EFFECT, effect[2]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
	}
	//������ �� 226
	else if (h.modelName == "ka_226")
	{
		//��������� ��������� ��������� ���������
		if (beats != h.fullName["red_harm"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["red_harm"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			beats = h.fullName["red_harm"];

			alEffecti(effect[2], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[2], AL_EFFECTSLOT_EFFECT, effect[2]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[2], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[2], AL_LOWPASS_GAIN, 0);
			alSource3i(source[2], AL_AUXILIARY_SEND_FILTER, effectSlot[2], 0, NULL);
			alSourcei(source[2], AL_DIRECT_FILTER, filter[2]);
		}

		//��������� ���������
		double harmGain = getParameterFromVector(vector<point>{ { 0, -40 }, { 5, -15 }, { 9, 0 }}, step);
		alSourcef(source[2], AL_GAIN, toCoef(harmGain) * 0.56 * masterGain);

		//������ ���� ��������� 0.008(5) -> 1% ������� ���������
		double harmPitch = sr.reduktor_gl_obor / h.redTurnoverAvt /*1 + (sr.reduktor_gl_obor - h.redTurnoverAvt) * 0.0085556*/;
		alSourcef(source[2], AL_PITCH, harmPitch);

		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[3], &source[3], 0, h.fullName["takeOff"]);
			alSourcei(source[3], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		double takeOffGain = toCoef(min(getParameterFromVector(vector<point>{ { 0, -12 }, { 9, 0 }}, step),//
			getParameterFromVector(vector<point>{ { 0, 0 }, { 8, -12 } }, hight)))
			* getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);

		alSourcef(source[3], AL_GAIN, sm.delay(takeOffGain, deltaTime) * masterGain);

		//
		double avrEngTurns = (sr.eng1_obor > sr.eng2_obor) ? sr.eng1_obor - getAverange(vectorAvrEng1Turn, 2) : sr.eng2_obor - getAverange(vectorAvrEng2Turn, 2);

		//�������� 1�� ������
		double harmMid1Gain = getParameterFromVector(vector<point>{ { 9, 0 }, { 10, 6 }, { 12, 12 }}, step) * getParameterFromVector(vector<point>{ { 0, 1.6 }, { 50, 0.7 }}, velocityVectorXZ);

		//�������� 2�� ������
		double harmMid2Gain = getParameterFromVector(vector<point>{ { -2, -12 }, { -1, -6 }, { 0, 0 }, { 1, 6 }, { 2, 12 }}, avrEngTurns);

		//�������� ���������
		alEffectf(effect[2], AL_EQUALIZER_MID1_CENTER, 500);
		alEffectf(effect[2], AL_EQUALIZER_MID2_CENTER, 4300);

		alEffectf(effect[2], AL_EQUALIZER_MID1_WIDTH, 0.33);
		alEffectf(effect[2], AL_EQUALIZER_MID2_WIDTH, 0.33);//������ 0.33

		alEffectf(effect[2], AL_EQUALIZER_MID1_GAIN, pow(10, (harmMid1Gain)*0.05));//
		alEffectf(effect[2], AL_EQUALIZER_MID2_GAIN, pow(10, (harmMid2Gain)*0.05));//

		alAuxiliaryEffectSloti(effectSlot[2], AL_EFFECTSLOT_EFFECT, effect[2]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)

		//�������� �� ���� � ��
		double highFreqStepGain = getParameterFromVector(vector<point>{ { 0, 0 }, { 5, 2 }, { 9, 3 }, { 12, 5 } }, step);

		//�������� �� ���� � �� (1) (������)
		//double lowFreqStepGain1 = getParameterFromVector(vector<point>{ { 0, 0 }, { 9, 15 }, { 16, 26.66 } }, step) * getParameterFromVector(vector<point>{ { 0, 1 }, { 8, 0 } }, hight);

		//�������� �� ���� � �� (2)
		double lowFreqStepGain2 = getParameterFromVector(vector<point>{ { 0, 0 }, { 12, 14 } }, step) * getParameterFromVector(vector<point>{ { 0, 0 }, { 28, 1 } }, abs(velocityVectorXZ));

		//�������� �� �������
		double hoveringGain = (hight > 0) ? abs(accelerationVectorXZ) * 6 * getParameterFromVector(vector<point>{ { 0, 1 }, { 28, 0 } }, velocityVectorXZ) : 0;

		//
		if (velocityY < 0)
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}

		//0.1 -> 2��
		double lowFreqAccGain = (accelerationVectorXZ <= -0.56) ? (((abs(accelerationVectorXZ) - 0.56) * 20) * getParameterFromVector(vector<point>{ { 4, 1 }, { 9, 0 } }, step) * getParameterFromVector(vector<point>{ { 8, 0 }, { 16, 1 } }, hight) * flapOn) : 0;

		lowFreqGain = toCoef(/*lowFreqStepGain1 +*/ lowFreqStepGain2 + hoveringGain + lowFreqAccGain);
		highFreqGain = toCoef(highFreqStepGain);

		lowFreqGain = (lowFreqGain <= 1) ? 1 : lowFreqGain;
		highFreqGain = (highFreqGain <= 1) ? 1 : highFreqGain;

		lowCutoffFreq = pow(10, getParameterFromVector(vector<point>{ { 8, log10(80) }, { 16, log10(120) } }, hight));//�� 50-800
		highCutoffFreq = 4000;//�� 4000-16000
	}
	//������ �����
	else if (h.modelName == "ansat")
	{
		//��������� ��������� ��������� �������
		if (beats != h.fullName["BumBum"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["BumBum"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			beats = h.fullName["BumBum"];
		}
		//��������� ��������� ���� ������
		if (takeOff != h.fullName["takeOff"])
		{
			setAndDeploySound(&buffer[3], &source[3], 0, h.fullName["takeOff"]);
			alSourcei(source[3], AL_LOOPING, AL_TRUE);
			takeOff = h.fullName["takeOff"];
		}

		double takeOffStep = toCoef(getParameterFromVector(vector<point>{ { 0, -60 }, { 7, -18 }, { 60, 0 }}, step))
			* getParameterFromVector(vector<point>{ { 0, 1 }, { 11.11, 0 } }, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 0, 1 }, { 8, 0 } }, hight);

		double takeOffVelY = toCoef(getParameterFromVector(vector<point>{ { -9, -3 }, { -4, -15 }}, velocityY))
			* getParameterFromVector(vector<point>{ { 5, 0 }, { 10, 1 }}, calcA)
			* getParameterFromVector(vector<point>{ { 34, 1 }, { 37, 0.5 }, { 40, 0 }}, step);

		double takeOffGain = max(takeOffStep, takeOffVelY);

		alSourcef(source[3], AL_GAIN, sm.delay(takeOffGain, deltaTime) * masterGain);

		//��������� �������
		double bumBumGain = toCoef(getParameterFromVector(vector<point>{ { -15, 0 }, { -10, -6 }, { -7, -15 }, { -5, -20 }, { 0, -60 }}, calcA))
			* getParameterFromVector(vector<point>{ { 8.3, 0 }, { 14, 1 }}, abs(velocityVectorXZ));

		alSourcef(source[2], AL_GAIN, bumBumGain * masterGain);
		//
		double avrEngTurns = (sr.eng1_obor > sr.eng2_obor) ? sr.eng1_obor - getAverange(vectorAvrEng1Turn, 2) : sr.eng2_obor - getAverange(vectorAvrEng2Turn, 2);

		//�������� 2�� ������
		double mid2FreqGainEngTurns = getParameterFromVector(vector<point>{ { -2, -8 }, { -1, -4 }, { 0, 0 }, { 2, 4 }}, avrEngTurns);

		double trueStep = (step < 7) ? 0 : step - 7;//7->0 ��� // ����� �������� ������� ���� � ������

		double lowFreqGainStep = trueStep * 0.0755;

		double lowFreqGainVelX = getParameterFromVector(vector<point>{ { 33.33, 0 }, { 56, 6 }, { 70, 3 }}, abs(velocityVectorXZ));

		double mid2GainStep = trueStep * 0.13;

		double mid2FreqGainVelX = getParameterFromVector(vector<point>{ { 33.33, 0 }, { 44.44, 6 }, { 47.2, 6 }, { 56, 3 }}, abs(velocityVectorXZ));

		double highFreqGainVelX = getParameterFromVector(vector<point>{ { 44.44, 0 }, { 56, 4 }, { 70, 6 }}, abs(velocityVectorXZ));

		//�� �� ����� ������ �����
		double lowFreqCrunchGain = getParameterFromVector(vector<point>{ { 5, 0 }, { 10, 6 }}, calcA)
			* getParameterFromVector(vector<point>{ { 5.55, 0 }, { 11.11, 1 }, { 19.4, 1 }, { 25, 0 }}, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 34, 1 }, { 37, 0.5 }, { 40, 0 }}, step)
			* getParameterFromVector(vector<point>{ { -1.3, 0 }, { -0.7, 1 }}, velocityY);

		//�� ����� �� �������
		double lowFreqCrunchHoveringGain = getParameterFromVector(vector<point>{ { 4, 0 }, { 6, 4 }}, tangaz)
			* getParameterFromVector(vector<point>{ { 0, 1 }, { 8.3, 0 }}, abs(velocityVectorXZ));

		lowFreqGain = toCoef(lowFreqGainStep + lowFreqGainVelX + lowFreqCrunchGain + lowFreqCrunchHoveringGain);
		mid2FreqGain = toCoef(mid2GainStep + mid2FreqGainVelX + mid2FreqGainEngTurns);
		highFreqGain = toCoef(highFreqGainVelX);

		alEffectf(effect[0], AL_EQUALIZER_MID2_WIDTH, 0.3);//������ ������ � �������
		alEffectf(effect[1], AL_EQUALIZER_MID2_WIDTH, 0.3);//

		lowCutoffFreq = 120;//�� 50-800
		mid2CutoffFreq = 3700;//����� 2 1000-8000
		highCutoffFreq = 4000;//�� 4000-16000
	}

	for (size_t i = 0; i < 2; i++)
	{
		alEffectf(effect[i], AL_EQUALIZER_LOW_CUTOFF, lowCutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_MID1_CENTER, mid1CutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_MID2_CENTER, mid2CutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_HIGH_CUTOFF, highCutoffFreq);

		alEffectf(effect[i], AL_EQUALIZER_LOW_GAIN, lowFreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_MID1_GAIN, mid1FreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_MID2_GAIN, mid2FreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_HIGH_GAIN, highFreqGain);//

		alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
	}

	alSourcef(source[id], AL_GAIN, gain[id] * rise * finalGain);
	alSourcef(source[!id], AL_GAIN, gain[!id] * fade * finalGain);

	return 1;
}

Engine::Engine() : Sound(2, 2, 2)
{
	//��� ������������� ������� ���������� �������� ������ ���������, ������ ��������� �����
	//������� ������ ������ ��������� ����� ���� �������� ���� �������
	engCount++;
	phase = (engCount - 1) * 0.33;
	engNum = engCount;
}

Engine::~Engine()
{
	engCount--;
}

int Engine::play(bool status_on, bool status_off, bool status_hp, double parameter, Helicopter &h)
{
	if (status_hp)
	{
		if (h.engLengthHpOn - offsetOn <= crossFadeDuration && offsetOn)
		{
			mode = "w_hp";
		}
		else
		{
			mode = "on_hp";
		}
	}
	else if (!status_on && !status_off && !status_hp && (mode == "on_hp" || mode == "off_hp" || mode == "w_hp"))
	{
		mode = "w_hp";
	}
	else if (status_off && (mode == "on_hp" || mode == "w_hp" || mode == "off_hp"))
	{
		mode = "off_hp";
	}
	else if (status_on && parameter <= h.engTurnoverMg * 0.9)
	{
		if (h.engLengthOn - offsetOn <= crossFadeDuration && offsetOn)
		{
			mode = "mg";
		}
		else
		{
			mode = "on";
		}
	}
	else if (!status_on && !status_off && !status_hp)
	{
		if (parameter <= h.engTurnoverMg)
		{
			mode = "mg";
		}
		else
		{
			mode = "avt";
		}
	}
	else if (status_off)
	{
		if (parameter <= h.engTurnoverMg)
		{
			mode = "off";
		}
		else
		{
			mode = "avtOff";
		}
	}

	if (modeSequence.back() != mode)
	{
		switcher = 0;
		id = !id;
		if (mode == "on" || mode == "off" || mode == "off_hp" || mode == "on_hp")
		{
			fileBuffered[id] = "NULL";
		}
		modeSequence.push_back(mode);
		if (modeSequence.size() >= 4)
		{
			modeSequence.erase(modeSequence.begin());
		}
	}

	//on hp
	if (mode == "on_hp")
	{
		filetoBuffer[id] = h.fullName["eng_on_hp_w"];
	}
	//w hp
	else if (mode == "w_hp")
	{
		filetoBuffer[id] = h.fullName["eng_w_hp_w"];
	}
	//off hp
	else if (mode == "off_hp")
	{
		filetoBuffer[id] = h.fullName["eng_off_hp_w"];
	}

	//0 -> ��
	if (mode == "on")
	{
		filetoBuffer[id] = h.fullName["eng_on_w"];
	}
	//�� 
	else if (mode == "mg")
	{
		filetoBuffer[id] = h.fullName["eng_w_w"];
	}
	//�� <-> ���
	else if (mode == "avt")
	{
		if (h.modelName == "ansat")
		{
			filetoBuffer[id] = h.fullName["eng_w_w"];
		}
		else
		{
			filetoBuffer[id] = h.fullName["eng_w_avt_w"];
			filetoBuffer[!id] = h.fullName["eng_w_w"];
		}
	}
	//�� -> 0 
	else if (mode == "off")
	{
		//���� �����-�� ����������� ������� ������������� ����
		//��� �������� � ����� �������� ����������� ����������
		if (modeSequence[1] == "avt")
		{
			fileBuffered[id] = h.fullName["eng_w_w"];
			modeSequence[1] = "mg";
			id = !id;
			filetoBuffer[id] = h.fullName["eng_off_w"];
		}
		else
		{
			filetoBuffer[id] = h.fullName["eng_off_w"];
		}
	}
	//��� -> 0
	else if (mode == "avtOff")
	{
		filetoBuffer[!id] = h.fullName["eng_w_avt_w"];
		filetoBuffer[id] = h.fullName["eng_w_w"];
	}

	double finalGain = 0;
	if (mode == "on_hp" || mode == "w_hp" || mode == "off_hp")
	{
		finalGain = masterGain * h.engHpFactor;
	}
	else
	{
		finalGain = masterGain * h.engFactor;
	}

	double rise = 0;
	double fade = 0;
	if (filetoBuffer[id] == h.fullName["eng_on_w"]
		|| filetoBuffer[id] == h.fullName["eng_off_w"]
		|| filetoBuffer[!id] == h.fullName["eng_off_w"]
		|| filetoBuffer[id] == h.fullName["eng_on_hp_w"]
		|| filetoBuffer[id] == h.fullName["eng_off_hp_w"]
		|| filetoBuffer[!id] == h.fullName["eng_on_hp_w"]
		|| filetoBuffer[!id] == h.fullName["eng_off_hp_w"])
	{
		switcher += deltaTime;
		timeCrossfade(fade, rise, crossFadeDuration, switcher);
	}
	else if ((filetoBuffer[!id] == h.fullName["eng_on_w"]) && (filetoBuffer[id] == h.fullName["eng_w_w"]))
	{
		if (reperSet != "set")
		{
			reperTurn = parameter;
			reperSet = "set";
		}

		double timeGain[2];
		double turnGain[2];

		if (parameter <= h.engTurnoverMg)
		{
			parametricalCrossfade(&turnGain[!id], &turnGain[id], parameter, reperTurn, h.engTurnoverMg);
		}
		else
		{
			turnGain[id] = 1;
			turnGain[!id] = 0;
		}

		if (offsetOn != 0)
		{
			timeCrossfade(timeGain[!id], timeGain[id], crossFadeDuration, crossFadeDuration - (h.engLengthOn - offsetOn));
		}
		else
		{
			timeGain[id] = 1;
			timeGain[!id] = 0;
		}

		rise = max(timeGain[id], turnGain[id]);
		fade = min(timeGain[!id], turnGain[!id]);
	}
	else
	{
		rise = 1;
		fade = 1;
	}

	//��� ������ 2� ����������
	for (size_t i = 0; i < 2; i++)
	{
		//���������� ����������
		if (eq[i] != "set")
		{
			alEffecti(effect[i], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[i], AL_FILTER_TYPE, AL_FILTER_LOWPASS);//���������� ������ ��� ��
			alFilterf(filter[i], AL_LOWPASS_GAIN, 0);//������� ���� ������� ���������
			alSource3i(source[i], AL_AUXILIARY_SEND_FILTER, effectSlot[i], 0, 0);//�������� ����� ��������� ����� ���� � ��������
			alSourcei(source[i], AL_DIRECT_FILTER, filter[i]);//���������� ������ � ���������
			eq[i] = "set";
		}

		//cout.precision(3);
		//cout << fixed
		//	<< " ID__: " << id
		//	//<< " gain[" << id << "]: " << gain[id]
		//	//<< " gain[" << !id << "]: " << gain[!id]
		//	<< " pitch[" << id << "]: " << pitch[id]
		//	//<< " pitch[" << !id << "]: " << pitch[!id]
		//	<< " para: " << parameter
		//	<< " round: " << roundFloat(getParameterFromVector(h.engFunctionOn, offsetOn), 0.001)
		//	<< " switcher: " << switcher
		//	//<< " rise: " << rise
		//	//<< " fade: " << fade
		//	<< " offset[" << id << "]: " << getParameterFromVector(h.engFunctionOnSwap, parameter)
		//	<< " offsetOn: " << offsetOn
		//	<< " mode: " << mode
		//	//<< " offset[" << !id << "]: " << offset[!id]
		//	//<< " FIB[" << id << "]: " << fileBuffered[id]
		//	//<< " FIB[" << !id << "]: " << fileBuffered[!id]
		//	<< "\t\t\r";

		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			//setSource(&buffer[i], &source[i], filetoBuffer[i]);
			switchBuffer(&h.bufferMap[filetoBuffer[i] + angle], &source[i]);

			//�������������� ���� � ��������
			if (filetoBuffer[i] == h.fullName["eng_on_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = getParameterFromVector(h.engFunctionOnSwap, parameter);
			}
			else if (filetoBuffer[i] == h.fullName["eng_on_hp_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = h.engLengthHpOn / h.engTurnoverHp * parameter;
			}
			else if (filetoBuffer[i] == h.fullName["eng_w_w"])
			{
				offset[i] = h.engLengthMg * phase;
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
			}
			else if (filetoBuffer[i] == h.fullName["eng_w_hp_w"])
			{
				offset[i] = h.engLengthHpW * phase;
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
			}
			else if (filetoBuffer[i] == h.fullName["eng_w_avt_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = h.engLengthWAavt * phase;
			}
			else if (filetoBuffer[i] == h.fullName["eng_off_w"])
			{
				offset[i] = getParameterFromVector(h.engFunctionOffSwap, parameter);
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
			}
			else if (filetoBuffer[i] == h.fullName["eng_off_hp_w"])
			{
				offset[i] = h.engLengthHpOff / h.engTurnoverHp * abs(h.engTurnoverHp - parameter);
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
			}

			alSourcef(source[i], AL_SEC_OFFSET, offset[i]);//������������� ������ � ���
			alSourcef(source[i], AL_GAIN, 0);//������������� ��������� � 0
			alSourcePlay(source[i]);//��������� ��������������

			fileBuffered[i] = filetoBuffer[i];
		}

		//������ �� ����������� ������������ �����
		if (fileBuffered[i] == h.fullName["eng_on_w"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
			pitch[i] = getPitch(h.engTurnoverMg, parameter, getParameterFromVector(h.engFunctionOn, offsetOn));
			gain[i] = 1;
		}
		else if (fileBuffered[i] == h.fullName["eng_on_hp_w"])
		{
			pitch[i] = 1;
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
			gain[1] = 1;
		}
		else if (fileBuffered[i] == h.fullName["eng_w_w"])
		{
			if (h.modelName == "ansat")
			{
				pitch[i] = roundFloat((parameter / h.engTurnoverAvt), 0.001);
				gain[i] = 1;
			}
			else
			{
				pitch[i] = roundFloat((parameter / h.engTurnoverMg), 0.001);
				gain[i] = getParameterFromVector(vector<point>{ {h.engTurnoverMg, 1}, { h.engTurnoverAvt, 0 } }, parameter);
			}
		}
		else if (fileBuffered[i] == h.fullName["eng_w_hp_w"])
		{
			pitch[i] = 1/*parameter / h.engTurnoverHp*/;
			gain[i] = 1;
		}
		else if (fileBuffered[i] == h.fullName["eng_w_avt_w"])
		{
			pitch[i] = roundFloat((parameter / h.engTurnoverAvt), 0.001);//������ pitch (���� ���������� ������ ��� ��������� ������� ��)
			gain[i] = getParameterFromVector(vector<point>{ {h.engTurnoverMg, 0}, { h.engTurnoverAvt, 1 } }, parameter);
		}
		else if (fileBuffered[i] == h.fullName["eng_off_w"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOff);
			pitch[i] = getPitch(h.engTurnoverMg, parameter, getParameterFromVector(h.engFunctionOff, offsetOff));
			gain[i] = 1;
		}
		else if (fileBuffered[i] == h.fullName["eng_off_hp_w"])
		{
			pitch[i] = 1;
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOff);
			gain[i] = 1;
		}

		//��������� ��������� ���� ������� ����� 0 � ��������� �� �����������
		if ((mode == "off" || mode == "off_hp") && parameter == 0 && sourceStatus[id] != AL_PLAYING)
		{
			return 0;
		}

		//��������� ������ ������
		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);

		alSourcef(source[i], AL_PITCH, pitch[i]);
	}

	double lowFreqGain = AL_EQUALIZER_DEFAULT_LOW_GAIN;
	double mid1FreqGain = AL_EQUALIZER_DEFAULT_MID1_GAIN;
	double mid2FreqGain = AL_EQUALIZER_DEFAULT_MID2_GAIN;
	double highFreqGain = AL_EQUALIZER_DEFAULT_HIGH_GAIN;

	double lowCutoffFreq = AL_EQUALIZER_DEFAULT_LOW_CUTOFF;//�� 50-800
	double mid1CutoffFreq = AL_EQUALIZER_DEFAULT_MID1_CENTER;//����� 1 200-3000
	double mid2CutoffFreq = AL_EQUALIZER_DEFAULT_MID2_CENTER;//����� 2 1000-8000
	double highCutoffFreq = AL_EQUALIZER_DEFAULT_HIGH_CUTOFF;//�� 4000-16000

	double avrTurnRestrict = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);

	//������ 8 ���5, 8 ����, �� 27�, �� 29
	if (h.modelName == "mi_8_amtsh" || h.modelName == "mi_8_mtv5" || h.modelName == "mi_28" || h.modelName == "mi_26" || h.modelName == "ka_27" || h.modelName == "ka_29")
	{
		double averangeTurn;
		if (engNum == 1)
		{
			averangeTurn = getAverange(vectorAvrEng1Turn, 25);
		}
		else if (engNum == 2)
		{
			averangeTurn = getAverange(vectorAvrEng2Turn, 25);
		}

		//�������� �� ��������
		double turnGain = toCoef((parameter - averangeTurn) * 0.35 * avrTurnRestrict);

		lowFreqGain = turnGain;
		mid1FreqGain = turnGain;
		mid2FreqGain = turnGain;
		highFreqGain = turnGain;
	}
	else if (h.modelName == "ansat")
	{
		//��������� ���������� � ����������� �� ��������
		double turnsGainControl = toCoef(getParameterFromVector(vector<point>{ { 60, -6 }, { 80, -4 }, { 100, 0 }}, parameter)
		);

		lowFreqGain = turnsGainControl;
		mid1FreqGain = turnsGainControl;
		mid2FreqGain = turnsGainControl;
		highFreqGain = turnsGainControl;
	}

	for (size_t i = 0; i < 2; i++)
	{
		alEffectf(effect[i], AL_EQUALIZER_LOW_CUTOFF, lowCutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_MID1_CENTER, mid1CutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_MID2_CENTER, mid2CutoffFreq);
		alEffectf(effect[i], AL_EQUALIZER_HIGH_CUTOFF, highCutoffFreq);

		alEffectf(effect[i], AL_EQUALIZER_LOW_GAIN, lowFreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_MID1_GAIN, mid1FreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_MID2_GAIN, mid2FreqGain);//
		alEffectf(effect[i], AL_EQUALIZER_HIGH_GAIN, highFreqGain);//

		alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
	}

	alSourcef(source[!id], AL_GAIN, gain[!id] * fade  * finalGain);
	alSourcef(source[id], AL_GAIN, gain[id] * rise * finalGain);

	/*static double period = 0;
	if (period == 0)
	{
		remove("eng.txt");
	}
	period += deltaTime;
	if (period >= 0.01)
	{
		FILE *f = fopen("eng.txt", "at");
		fprintf(f, "%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", currentTime, parameter, roundFloat(getParameterFromVector(h.engFunctionOn, offset[id]), 0.001), pitch[0], pitch[1], offset[id], getParameterFromVector(h.engFunctionOnSwap, parameter));
		fclose(f);
		period = 0.005;
	}*/

	return 1;
}

Vsu::Vsu() : Sound(2, 2, 0)
{

}

Vsu::~Vsu()
{

}

int Vsu::play(SOUNDREAD &sr, Helicopter &h)
{
	if (init != "set")
	{
		vsuTurnover = sr.vsu_obor;
		init = "set";
	}

	double vsuGainDown = 1;
	//��� 27 29 � 8
	if (h.modelName == "ka_27" || h.modelName == "ka_29" || h.modelName == "mi_8_mtv5" || h.modelName == "mi_8_amtsh")
	{
		//�������� ��� ��� ���������� ���������, �� �� ������� ���������
		if (sr.reduktor_gl_obor > 0)
		{
			vsuGainDown = interpolation({ 0, 0.7 }, { 2.5, 0.85 }, { 5, 1 }, vsuUpTimer);
			vsuUpTimer += Sound::deltaTime;
			vsuDownTimer = 0;
		}
		else
		{
			if (sr.p_eng1_zap || sr.p_eng1_hp || sr.p_eng2_zap || sr.p_eng2_hp)
			{
				vsuGainDown = interpolation({ 0, 1 }, { 0.25, 0.85 }, { 0.5, 0.7 }, vsuDownTimer);
				vsuDownTimer += Sound::deltaTime;
				vsuUpTimer = 0;
			}
			else
			{
				vsuGainDown = interpolation({ 0, 0.7 }, { 2.5, 0.85 }, { 5, 1 }, vsuUpTimer);
				vsuUpTimer += Sound::deltaTime;
				vsuDownTimer = 0;
			}
		}
	}

	if (sr.p_vsu_hp && mode != "w_hp")
	{
		if (h.vsuLengthHpOn - offsetOn <= crossFadeDuration)
		{
			mode = "w_hp";
		}
		else
		{
			mode = "on_hp";
		}
	}
	else if (!sr.p_vsu_hp && !sr.p_vsu_zap && !sr.p_vsu_ostanov && sr.vsu_obor != 0 && (mode == "on_hp" || mode == "off_hp" || mode == "w_hp"))
	{
		mode = "w_hp";
	}
	else if (sr.p_vsu_ostanov && (mode == "on_hp" || mode == "w_hp" || mode == "off_hp"))
	{
		mode = "off_hp";
	}
	else if (sr.p_vsu_zap && mode != "w")
	{
		if (h.vsuLengthOn - offsetOn <= crossFadeDuration)
		{
			mode = "w";
		}
		else
		{
			mode = "on";
		}
	}
	else if (!sr.p_vsu_hp && !sr.p_vsu_zap && !sr.p_vsu_ostanov && sr.vsu_obor != 0)
	{
		mode = "w";
	}
	else if (sr.p_vsu_ostanov)
	{
		mode = "off";
	}

	if (modeSequence.back() != mode)
	{
		switcher = 0;
		id = !id;
		if (mode == "on" || mode == "off" || mode == "on_hp" || mode == "off_hp")
		{
			fileBuffered[id] = "NULL";
		}
		modeSequence.push_back(mode);
		if (modeSequence.size() >= 4)
		{
			modeSequence.erase(modeSequence.begin());
		}
	}

	//on hp
	if (mode == "on_hp")
	{
		filetoBuffer[id] = h.fullName["vsu_hp_on"];
		vsuTurnover += 35.0 / h.vsuLengthHpOn * deltaTime;
		vsuTurnover = (vsuTurnover > 35) ? 35 : vsuTurnover;
	}
	//w hp
	else if (mode == "w_hp")
	{
		filetoBuffer[id] = h.fullName["vsu_hp_w"];
		vsuTurnover += 35.0 / h.vsuLengthHpOn * deltaTime;
		vsuTurnover = (vsuTurnover > 35) ? 35 : vsuTurnover;
	}
	//off hp
	else if (mode == "off_hp")
	{
		filetoBuffer[id] = h.fullName["vsu_hp_off"];
		vsuTurnover -= 35.0 / h.vsuLengthHpOff * deltaTime;
		vsuTurnover = (vsuTurnover < 0) ? 0 : vsuTurnover;
	}
	//0 -> ��
	else if (mode == "on")
	{
		filetoBuffer[id] = h.fullName["vsu_on"];
		vsuTurnover += 100.0 / h.vsuLengthOn * deltaTime;
		vsuTurnover = (vsuTurnover > 100) ? 100 : vsuTurnover;
	}
	//100
	else if (mode == "w")
	{
		filetoBuffer[id] = h.fullName["vsu_w"];
		vsuTurnover += 100.0 / h.vsuLengthOn * deltaTime;
		vsuTurnover = (vsuTurnover > 100) ? 100 : vsuTurnover;
	}
	//100 -> 0 || �� -> 0
	else if (mode == "off")
	{
		filetoBuffer[id] = h.fullName["vsu_off"];
		vsuTurnover -= 100.0 / h.vsuLengthOff * deltaTime;
		//������� ��� �� ������ ������ ���� 0
		vsuTurnover = (vsuTurnover < 0) ? 0 : vsuTurnover;
	}

	double finalGain = 0;

	if (mode == "w_hp" || mode == "on_hp" || mode == "off_hp")
	{
		finalGain = masterGain * h.vsuHpFactor * gain[id];
	}
	else
	{
		finalGain = masterGain * h.vsuFactor * gain[id];
	}

	double fade = 0;
	double rise = 0;

	switcher += deltaTime;
	timeCrossfade(fade, rise, crossFadeDuration, switcher);
	if (filetoBuffer[id] == "NULL" && filetoBuffer[id] == "NULL")
	{
		rise = 0;
		fade = 1;
	}
	else if (filetoBuffer[!id] == "NULL" && filetoBuffer[!id] == "NULL")
	{
		rise = 1;
		fade = 0;
	}

	alSourcef(source[!id], AL_GAIN, fade * vsuGainDown * finalGain);
	alSourcef(source[id], AL_GAIN, rise * vsuGainDown * finalGain);

	for (size_t i = 0; i < 2; i++)
	{
		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			setSource(&buffer[i], &source[i], filetoBuffer[i]);

			if (filetoBuffer[i] == h.fullName["vsu_on"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = h.vsuLengthOn / h.vsuTurnoverFull * vsuTurnover;
				alSourcef(source[i], AL_PITCH, 1);
			}
			else if (filetoBuffer[i] == h.fullName["vsu_hp_on"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = h.vsuLengthHpOn / h.vsuTurnoverHp * vsuTurnover;
				alSourcef(source[i], AL_PITCH, 1);
			}
			else if (filetoBuffer[i] == h.fullName["vsu_w"])
			{
				alSourcef(source[i], AL_PITCH, 1);
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["vsu_hp_w"])
			{
				alSourcef(source[i], AL_PITCH, 1);
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["vsu_off"])
			{
				offset[i] = h.vsuLengthOff / h.vsuTurnoverFull * abs(h.vsuTurnoverFull - vsuTurnover);
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				alSourcef(source[i], AL_PITCH, 1);
			}
			else if (filetoBuffer[i] == h.fullName["vsu_hp_off"])
			{
				offset[i] = h.vsuLengthHpOff / h.vsuTurnoverHp * abs(h.vsuTurnoverHp - vsuTurnover);
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				alSourcef(source[i], AL_PITCH, 1);
			}

			alSourcef(source[i], AL_SEC_OFFSET, offset[i]);//������������� ������ � ���
			alSourcef(source[i], AL_GAIN, 0);//������������� ��������� � 0
			alSourcePlay(source[i]);//��������� ��������������

			fileBuffered[i] = filetoBuffer[i];
		}

		if (fileBuffered[i] == h.fullName["vsu_on"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
		}
		else if (fileBuffered[i] == h.fullName["vsu_hp_on"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
		}

		//��������� ��������� ���� ������� ����� 0 � �� �����������
		if (!sr.p_vsu_zap && !sr.p_vsu_ostanov && !sr.p_vsu_hp && vsuTurnover == 0)
		{
			alSourceStop(source[i]);
			alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);		// ���������� ������� 
			return 0;
		}

		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);
	}

	//float a;
	//float b;
	//alGetSourcef(source[0], AL_GAIN, &a);
	//alGetSourcef(source[1], AL_GAIN, &b);
	//cout.precision(3);
	//cout << fixed
	//	/*<< " FADE: " << a
	//	<< " RISE: " << b
	//	<< " " << modeSequence[0]
	//	<< " " << modeSequence[1]
	//	<< " " << modeSequence[2]*/
	//	<< " VSTO: " << vsuTurnover
	//	<< " offon: " << offsetOn
	//	<< " offid: " << offset[id]
	//	<< "\t\t\r";

	return 1;
}

VintFlap::VintFlap() : Sound(3, 3, 2)
{

}

int VintFlap::play(Helicopter &h, SOUNDREAD &sr)
{
	//������� �������
	//��� ������������� �������� ������� ����������
	const double accelerationXBorder = 0.28;//!<��/�*�
	const double velocityYBorder = -2;//!<��/�
	const double dashBorder = -0.672;

	if (velocityVectorXZ < 0)
	{
		//dv>1 � vy<-2
		if (accelerationVectorXZ >= -accelerationXBorder && velocityY <= velocityYBorder)//1
		{
			if ((calcA > 0) & (dashVectorXZ < -dashBorder) & (accelerationVy < 3))
			{
				flapIndicator = 1;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//dv>1 � vy>-2
		if (accelerationVectorXZ >= -accelerationXBorder && velocityY > velocityYBorder)//2
		{

			if ((accelerationVectorXZ > 0.56 & velocityY < 0) || ((velocityY > 4) & (dashVectorXZ > 0.5) & (accelerationVy > 3)))
			{
				flapIndicator = 2;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//
		if (accelerationVectorXZ < -accelerationXBorder && velocityY <= velocityYBorder)//3
		{
			if ((accelerationVectorXZ < -1.4) & (abs(derivStep) > 2))
			{
				flapIndicator = 3;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//
		if (accelerationVectorXZ < -accelerationXBorder && velocityY > velocityYBorder)//4
		{
			if ((accelerationVectorXZ < -0.56) & ((velocityY > 2 && abs(velocityVectorXZ) > 28) | ((abs(velocityVectorXZ) > 50) & (step > 20))))
			{
				flapIndicator = 4;
			}
			else
			{
				flapIndicator = 0;
			}
		}
	}
	else
	{
		//dv<1 � vy<-2
		if (accelerationVectorXZ <= accelerationXBorder && velocityY <= velocityYBorder)//1
		{
			if ((calcA > 0) & (dashVectorXZ > dashBorder) & (accelerationVy < 3))
			{
				flapIndicator = 1;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//dv<1 � vy>-2
		if (accelerationVectorXZ <= accelerationXBorder && velocityY > velocityYBorder)//2
		{

			if ((accelerationVectorXZ < -0.56 & velocityY < 0) || ((velocityY > 4) & (dashVectorXZ < -0.5) & (accelerationVy > 3)))
			{
				flapIndicator = 2;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//
		if (accelerationVectorXZ > accelerationXBorder && velocityY <= velocityYBorder)//3
		{
			if ((accelerationVectorXZ > 1.4) & (abs(derivStep) > 2))
			{
				flapIndicator = 3;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		//
		if (accelerationVectorXZ > accelerationXBorder && velocityY > velocityYBorder)//4
		{
			if ((accelerationVectorXZ > 0.56) & ((velocityY > 2 && abs(velocityVectorXZ) > 28) | ((abs(velocityVectorXZ) > 50) & (step > 20))))
			{
				flapIndicator = 4;
			}
			else
			{
				flapIndicator = 0;
			}
		}
	}

	//���������� ������� �������
	mode = to_string(flapIndicator);

	if (modeSequence.back() != mode)
	{
		modeSequence.push_back(mode);
		if (modeSequence.size() >= 4)
		{
			modeSequence.erase(modeSequence.begin());
		}
	}

	double avrTurnRestrict = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);

	//������ 8 ���5
	if (h.modelName == "mi_8_mtv5")
	{
		if (key[0] != h.fullName["vint_flap"])
		{
			sourceStatus[0] = setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap"];
		}

		double atkXvel = calcA * interpolation({ 0, 0 }, { 16.67, 1 }, abs(velocityVectorXZ));

		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		//�������� �� ��������
		//������ ���� ����� ������ 2�
		//������ ��������� ����� ����� ����������
		double turnsGain = 1;
		if (atkXvel >= 2)
		{
			//�������� �� ��������
			turnsGain = toCoef((sr.reduktor_gl_obor - averangeTurn) * 2) * avrTurnRestrict;
		}

		//������ ������ ����������
		double h_g = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);
		double v_g = interpolation({ 10, 0 }, { 14, 0.25 }, { 28, 1 }, abs(velocityVectorXZ));//� 28 �/�

		//��������� ������� ������� �� �����
		double gain_a = interpolation({ -1, -15 }, { 1, -9 }, { 3, -3 }, atkXvel);

		double atkFls = turnsGain  * toCoef(gain_a) * h_g * v_g;

		// �� �������, ���������� ��������� � �������� ���������� ������� �������
		//��� � = 6 �/�^2 ��������� ������� �����������, ��� �������, ��� �������� ����� ����, � �������� ���� 60 ��/� (16.67)
		double flapCGainAccX = interpolation({ 0.56, 0 }, { 6, 1 }, abs(accelerationVectorXZ))
			* interpolation({ -0.25, 1 }, { 0.25, 0 }, velocityY)
			* interpolation({ 0, 1 }, { 16.67, 0 }, velocityVectorXZ);//��������� � �������� �� �� vy

		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)))//�������
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}

		double gainC = (atkFls > flapCGainAccX) ? atkFls : flapCGainAccX * flapOn;

		//��������� ��������� ������� �� 6�� �� ������ ������ ���� ���� 3.5
		double stepDamping = pow(10, ((step < 3.5) ? ((3.5 - step) * (-6)) : 0)*0.05);

		alSourcef(source[0], AL_GAIN, gainC * h.vintFlapFactor * masterGain * stepDamping);

	}
	//������ 8 ����
	else if (h.modelName == "mi_8_amtsh")
	{
		if (key[0] != h.fullName["vint_flap"])
		{
			sourceStatus[0] = setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap"];

		}
		if (key[1] != h.fullName["vint_flap_low"])
		{
			sourceStatus[1] = setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["vint_flap_low"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			key[1] = h.fullName["vint_flap_low"];
		}

		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		double atkXvel = calcA * interpolation({ 0, 0 }, { 16.67, 1 }, abs(velocityVectorXZ));

		//������������ ������� � �� ������, ��� ����� ��������� ���� (4-5)
		double flap_h = 0;
		double flap_lo = 0;
		parametricalCrossfade(&flap_lo, &flap_h, step, 4, 5);

		//������������ ������� � �� ������, ��� ����� ��������� �������� (14-16.67�/�)
		double flap_hv = 0;
		double flap_lov = 0;
		parametricalCrossfade(&flap_lov, &flap_hv, abs(velocityVectorXZ), 14, 16.67);

		//�� 2� ������� �� ������� �������� �������������
		double low = max(flap_lo, flap_lov);

		//�������� �� ��������
		//������ ���� ����� ������ 2�
		//������ ��������� ����� ����� ����������
		double turnsGain = 0;
		if (atkXvel >= 2)
		{
			//�������� �� ��������
			turnsGain = (sr.reduktor_gl_obor - averangeTurn) * 2 * avrTurnRestrict;
		}

		//������������ ������� �� �������� ��� ������� �� �����
		//vL ��� ��
		//vH ��� ��
		double vL = 0;
		double vH = 0;
		if (abs(velocityVectorXZ) < 11)
		{
			vL = interpolation({ 10, 0 }, { 11, 0.5 }, abs(velocityVectorXZ));//
			vH = interpolation({ 10, 0 }, { 11, 0.25 }, abs(velocityVectorXZ));//
		}
		else
		{
			vL = interpolation({ 11, 0.5 }, { 21, 1 }, abs(velocityVectorXZ));//
			vH = interpolation({ 11, 0.25 }, { 21, 1 }, abs(velocityVectorXZ));//
		}
		double vG = vL * low + vH * (1 - low);//����������� �� �������� 

		double hG = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);//����������� �� ������ 

		double gainAtk = interpolation({ -1, -15 }, { 1, -9 }, { 3, -3 }, atkXvel);

		//��������� ��������� ������� �� �����
		double atkFls = toCoef(turnsGain + gainAtk) * vG * hG;

		//������ �� ������� ��������� ��� 2�� ������� �������
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)))
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}

		//��� ������ �������, �� �������, ���������� ��������� � �������� ���������� ������� �������
		//��������� � �������� �� ��������� �� vy
		double flapCGainAccX = interpolation({ 0.56, 0 }, { 3, 1 }, abs(accelerationVectorXZ))
			* interpolation({ -0.25 , 1 }, { 0.25, 0 }, velocityY)
			* flapOn
			* interpolation({ 0, 1 }, { 16.67, 0 }, velocityVectorXZ);

		//�� 2� ����� ������� �������� ����� �������
		double gainF = max(atkFls, flapCGainAccX);

		//������������� ��������� �� � �� �������
		alSourcef(source[0], AL_GAIN, gainF * h.vintFlapFactor * masterGain * (1 - low));
		alSourcef(source[1], AL_GAIN, gainF * h.vintFlapFactor * masterGain * low);     

	}
	//������ 28
	else if (h.modelName == "mi_28")
	{
		if (key[0] != h.fullName["vint_flap"])
		{
			setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap"];
		}
		if (key[1] != h.fullName["vint_flap_low"])
		{
			setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["vint_flap_low"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			key[1] = h.fullName["vint_flap_low"];
		}

		double averangeTurn = getAverange(vectorAvrRedTurn, 30);

		double gain_a = 0;
		double h_g = 0;
		double v_g = 0;
		const double floor = 5;//�������� ������������ ������� ����� �� floor ������

		//���������� ������������ �������� �����, ��� ��������� ��������� ���������
		double atkXvel = calcA * interpolation({ 0, 0 }, { 16.67, 1 }, abs(velocityVectorXZ));

		h_g = getParameterFromVector(vector<point>{ { 0, 1 }, { 0.625, 0 }}, groundTouch);
		v_g = interpolation({ 14, 0 }, { 17, 0.5 }, { 20, 1 }, abs(velocityVectorXZ));//72(1) - 50(0)
		gain_a = interpolation({ -1 + floor ,  -18 }, { 1 + floor, -12 }, { 3 + floor, -6 }, atkXvel);

		//��� ������ �������, �� �������, ���������� ��������� � �������� ���������� ������� �������
		double flapCGainAccX = interpolation({ 0.56, 0 }, { 1, 1 }, abs(accelerationVectorXZ))
			* interpolation({ -0.25, 1 }, { 0, 0.5 }, { 0.25, 0 }, velocityY)
			* interpolation({ 0, 1 }, { 16.67, 0 }, velocityVectorXZ);//��������� � �������� �� �� vy

		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)))//�������
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}

		//�������� �� ��������
		double turnsGain = 0;
		if (atkXvel >= 2)
		{
			//�������� �� ��������
			turnsGain = (sr.reduktor_gl_obor - averangeTurn) * 2 * avrTurnRestrict;
		}
		double atkFls = pow(10, (turnsGain + gain_a)*0.05) * h_g * v_g;

		double gainAac = (atkFls > flapCGainAccX) ? atkFls : flapCGainAccX * flapOn;

		double flap_h = 0;
		double flap_lo = 0;
		double flap_hv = 0;
		double flap_lov = 0;
		parametricalCrossfade(&flap_lo, &flap_h, step, 5, 6);
		parametricalCrossfade(&flap_lov, &flap_hv, velocityVectorXZ, 14, 16.67);
		double low = max(flap_lo, flap_lov);
		alSourcef(source[0], AL_GAIN, gainAac * h.vintFlapFactor *masterGain *(h.vintFlapFactor*masterGain - low));
		alSourcef(source[1], AL_GAIN, gainAac * h.vintFlapFactor *masterGain * low);


	}
	//������ �� 27 - 29
	else if (h.modelName == "ka_27" || h.modelName == "ka_29")
	{
		if (key[0] != h.fullName["vint_flap_A"] || key[1] != h.fullName["vint_flap_B"] || key[2] != h.fullName["vint_flap_C"])
		{
			//��������� ����������� �� ������
			setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap_A"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			//��������� ������������� �� ������
			setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["vint_flap_B"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			//��������� �� ������
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["vint_flap_C"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);

			alEffecti(effect[1], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[1]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[1], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[1], AL_LOWPASS_GAIN, 0);
			alSource3i(source[1], AL_AUXILIARY_SEND_FILTER, effectSlot[1], 0, 0);
			alSourcei(source[1], AL_DIRECT_FILTER, filter[1]);

			alEffecti(effect[0], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[0], AL_EFFECTSLOT_EFFECT, effect[0]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[0], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[0], AL_LOWPASS_GAIN, 0);
			alSource3i(source[0], AL_AUXILIARY_SEND_FILTER, effectSlot[0], 0, 0);
			alSourcei(source[0], AL_DIRECT_FILTER, filter[0]);

			alSourceStop(source[0]);
			alSourceStop(source[1]);
			alSourceStop(source[2]);
			//��������� ������������ (�����������)
			alSourcePlay(source[0]);
			alSourcePlay(source[1]);
			alSourcePlay(source[2]);
			alGetSourcei(source[0], AL_SOURCE_STATE, &sourceStatus[0]);		// ���������� ������� 
			alGetSourcei(source[1], AL_SOURCE_STATE, &sourceStatus[1]);		// ���������� �������
			alGetSourcei(source[2], AL_SOURCE_STATE, &sourceStatus[2]);		// ���������� �������
			key[0] = h.fullName["vint_flap_A"];
			key[1] = h.fullName["vint_flap_B"];
			key[2] = h.fullName["vint_flap_C"];
		}

		//��������� �������� ����� ������� �� �������� ���������
		double lowerFreqLimit = log10(1000);//��������� � �������� �����
		double highterFreqLimit = log10(6000);
		double freqCutoffFromTurns = 0;
		if (sr.reduktor_gl_obor >= 89 & sr.reduktor_gl_obor <= 90)
		{
			freqCutoffFromTurns = interpolation({ 89, lowerFreqLimit }, { 90, highterFreqLimit }, sr.reduktor_gl_obor);
		}
		else if (sr.reduktor_gl_obor > 90)
		{
			freqCutoffFromTurns = (sr.reduktor_gl_obor / (90. / 100.))*highterFreqLimit / 100.;
		}
		else
		{
			freqCutoffFromTurns = lowerFreqLimit;
		}
		freqCutoffFromTurns = pow(10, freqCutoffFromTurns);//������������ � ������

		//���� ����������� ������� �������, ������� ������
		if (flapIndicator)//�������
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}
		double lowFreqGain = 1;
		double mid1FreqGain = interpolation({ log10(1000), 0.126 }, { log10(2000), 0.5 }, { log10(3000), 1 }, log10(freqCutoffFromTurns));
		double mid2FreqGain = interpolation({ log10(2000), 0.126 }, { log10(3000), 0.5 }, { log10(4000), 1 }, log10(freqCutoffFromTurns));//���� 4� �������� �������� �������
		double highFreqGain = 0.126;

		double lowCutoff = 800;
		double mid1Cutoff = 2000;//1-3
		double mid2Cutoff = 3000;//4-6
		double highCutoff = (freqCutoffFromTurns > AL_EQUALIZER_MIN_HIGH_CUTOFF) ? freqCutoffFromTurns : AL_EQUALIZER_MIN_HIGH_CUTOFF;//���� 4� ������� ������� �����

		alEffectf(effect[0], AL_EQUALIZER_LOW_CUTOFF, lowCutoff);
		alEffectf(effect[0], AL_EQUALIZER_MID1_CENTER, mid1Cutoff);
		alEffectf(effect[0], AL_EQUALIZER_MID2_CENTER, mid2Cutoff);
		alEffectf(effect[0], AL_EQUALIZER_HIGH_CUTOFF, highCutoff);

		alEffectf(effect[0], AL_EQUALIZER_LOW_GAIN, lowFreqGain);//
		alEffectf(effect[0], AL_EQUALIZER_MID1_GAIN, mid1FreqGain);//
		alEffectf(effect[0], AL_EQUALIZER_MID2_GAIN, mid2FreqGain);//
		alEffectf(effect[0], AL_EQUALIZER_HIGH_GAIN, highFreqGain);//

		alAuxiliaryEffectSloti(effectSlot[0], AL_EFFECTSLOT_EFFECT, effect[0]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
		alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[0]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)

		//������� � ��������� �� ������� � ��������� ������� ������������ ���������� � ������� ���������
		double mirror = 1.385;//5���
		double accMirrored = (accelerationVectorXZ >= mirror) ? mirror - (accelerationVectorXZ - mirror) : accelerationVectorXZ;
		double accelerationGain = 10.83 * accMirrored - 15;
		accelerationGain = toCoef(accelerationGain);//����

		//������ �� ������� ��������
		double hiSpeedGain = 0;
		if (abs(velocityVectorXZ) <= 61.6)
		{
			hiSpeedGain = interpolation({ 50, 0 }, { 61.6, 0.67 }, abs(velocityVectorXZ));
		}
		else
		{
			hiSpeedGain = interpolation({ 61.6, 0.67 }, { 75, 1 }, abs(velocityVectorXZ));
		}
		double resFlapCGain = max(hiSpeedGain, accelerationGain);//�� ���� ����������� ��������� �� ������� �������� �������������

		//����������� �������� �� �������� ����� - 3�� �� ������
		double turnsGain = toCoef((sr.reduktor_gl_obor - 91) * 3);
		turnsGain = (turnsGain > 1) ? 1 : turnsGain;

		//������� ��������� �������
		double off = interpolation({ 14, 1 }, { 0, 0 }, abs(velocityVectorXZ));

		//������� ������ �����������-������������� �������
		double flapA = 0;
		double flapB = 0;
		if (velocityVectorXZ < 0)
		{
			flapA = (accelerationVectorXZ >= -accelerationXBorder) ? 1 : 0;//������� ����������� �������
			flapB = (accelerationVectorXZ < -accelerationXBorder) ? 1 : 0;//������� ������������� �������
		}
		else
		{
			flapA = (accelerationVectorXZ <= accelerationXBorder) ? 1 : 0;//������� ����������� �������
			flapB = (accelerationVectorXZ > accelerationXBorder) ? 1 : 0;//������� ������������� �������
		}

		//������� ������� ����� �� � �� �������� �� ����
		double flapABStep = 0;
		double flapCStep = 0;
		parametricalCrossfade(&flapCStep, &flapABStep, step, 8, 12);
		//������� ������ ���� �� ��� �������,���������� �� ��������, ��� ��� ���� �������� ����� ������������
		if (abs(velocityVectorXZ) < 16.67)
		{
			flapABStep = 1;
			flapCStep = 1;
		}
		//������� ������� ����� �� � �� �������� �� ��������
		double flapABVX = 0;
		double flapCVX = 0;
		parametricalCrossfade(&flapCVX, &flapABVX, abs(velocityVectorXZ), 15.28, 16.67);

		//�� �������, ���������� ��������� � �������� ���������� ������� �������
		double flapCGainAccX = 1;
		if (((velocityVectorXZ < 0 && accelerationVectorXZ > 0.56) || (velocityVectorXZ > 0 && accelerationVectorXZ < -0.56)) && abs(velocityVectorXZ) < 16.67)
		{
			flapCGainAccX = interpolation({ 0.56, 0 }, { 1, 1 }, abs(accelerationVectorXZ))
				* interpolation({ -0.25, 1 }, { 0, 0.5 }, { 0.25, 0 }, velocityY);//��������� � �������� �� �� vy
		}

		// ������ ��� 1-�� ������� ������� ��������� ��������� �� Vy: ��� ��������� Vy �� -5 �/� �� -2 �/� ��������� ������� ������ �� ~16 dB
		double envelopVelY = 1;
		envelopVelY = (flapIndicator == 1 || (!flapIndicator && modeSequence[1] == "1")) ? getValue({ -5, 1 }, { -2, 0.14 }, velocityY, 0.14, 1) : 1;

		//������������ �������������� ��������� ������� � ������ ������ �������
		double flapAGain = (flapOn * off * turnsGain * envelopVelY) * (flapA * flapABStep * flapABVX)  * masterGain * h.vintFlapFactor;
		double flapBGain = (flapOn * off * turnsGain * envelopVelY) * (flapB * flapABStep * flapABVX)  * masterGain * h.vintFlapFactor;
		double flapCGain = ((flapIndicator) ?
			(flapCGainAccX * flapCStep * flapCVX * flapOn * off * turnsGain
				* masterGain
				* (h.vintFlapFactor + (1 - h.vintFlapFactor)*0.5))
			: (masterGain
				* (h.vintFlapFactor + (1 - h.vintFlapFactor)*0.5) * (1 - flapOn) * resFlapCGain * off));

		alSourcef(source[0], AL_GAIN, flapAGain);//�����������
		alSourcef(source[1], AL_GAIN, flapBGain);//�������������
		alSourcef(source[2], AL_GAIN, flapCGain);//�����
	}
	//������ �� 26
	else if (h.modelName == "mi_26")
	{
		if (key[0] != h.fullName["vint_flap"])
		{
			setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap"];
		}
		if (key[1] != h.fullName["flapping"])
		{
			setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["flapping"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			key[1] = h.fullName["flapping"];
		}

		//���������� ���������������� �����
		double attack = calcA * getValue({ 0, 0 }, { 22.22, 1 }, velocityVectorXZ, 1, "H")
			+ (step - getAverange(vectorAvrStep, 25)) * 5 * ((velocityY < 0) ? 1 : 0)
			* getValue({ 0, 0 }, { 13.89, 1 }, velocityVectorXZ, 0, 1)
			* getValue({ 13.89, 1 }, { 22.22, 0 }, velocityVectorXZ, 0, 1);

		//������������ ������� �������� ������� �� �����
		double atkGain = pow(10, (getValue({ 0, -18 }, { 12, 0 }, attack, 0, "H")) * 0.05);

		//�������� ������� ��� ����� ����
		double flapStepGain = pow(10, interpolation({ 2, 2 }, { 4, 0 }, step)*0.05);

		//���������� �����(����)(������)(������)(???) ��� ����� ����
		double flappingStepGain = pow(10, interpolation({ 2, -3 }, { 4, 0 }, step)*0.05);

		//�������� �� Vy ��� ������ ���������
		double vyG = getParameterFromVector(vector<point>{ {-6, 0}, { 0,-11 }, { 6,-24 }}, velocityY);
		vyG = (vyG > -3) ? -3 : vyG;
		double flappingVyGain = pow(10, vyG *0.05) * interpolation({ 0, 1 }, { 22.22, 0 }, abs(velocityVectorXZ));

		//�������� �� Vx
		double flappingVxGain = pow(10, getParameterFromVector(vector<point>{ {0, -60}, { 49,-12 }, { 56,-6 }, { 70,-3 }, { 84,0 } }, abs(velocityVectorXZ))*0.05);

		//����� ������� �� 3� ����������� ��� flapping
		double flappingGainUnhover = max(max(flappingVyGain, atkGain), flappingVxGain);

		//�������� �� dvx
		double accGain = pow(10, (getParameterFromVector(vector<point>{ {2, 0}, { 0, -12 } }, abs(accelerationVectorXZ)))*0.05)
			* interpolation({ 0, 1 }, { 22.22, 0 }, abs(velocityVectorXZ));

		//�� �������, ���������� ��������� � �������� ���������� ������� �������
		double hoveringGain = (velocityVectorXZ * accelerationVectorXZ <= 0) ? accGain : 0;

		//���������� ��������� � ��������� �������
		double smoothHoveringGain = sm.delay(hoveringGain, deltaTime);

		//printf(" DT__: %.3lf\tFLP: %.3lf\tFLPP: %.3lf\tATK: %.3lf\t\r", Sound::deltaTime, gain[0], gain[1], attack);

		/*static double period = 0;
		if (period == 0)
		{
			remove("flap.txt");
		}
		period += deltaTime;
		if (period > 0.05)
		{
			FILE *f=fopen("flap.txt","at");
			fprintf(f, "%.3lf\t%.3lf\t%.3lf\t%.3lf\t\n", Sound::currentTime, gain[0], gain[1], attack);
			fclose(f);
			period = 0.01;
		}*/

		//���������� ����� ��� ������� ���� �� 1
		double lowStepMuting = interpolation({ 1,0.5 }, { 2,1 }, step) * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//�������� ������� �� vy
		double velocityYGainFlap = pow(10, velocityY * 1 * 0.05) * (accelerationVectorXZ != 0);
		double velocityYGainFlapping = pow(10, velocityY * -1 * 0.05) * (accelerationVectorXZ != 0);

		//�������� ����� �������� �� ������� � ���
		double flappingFinalGain = max(smoothHoveringGain * velocityYGainFlapping, flappingGainUnhover * flappingStepGain);
		double flapFinalGain = max(smoothHoveringGain * velocityYGainFlap, atkGain * flapStepGain);

		gain[0] = flapFinalGain * h.vintFlapFactor * masterGain * lowStepMuting * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);
		gain[1] = flappingFinalGain * masterGain * lowStepMuting * getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		alSourcef(source[0], AL_GAIN, gain[0]);
		alSourcef(source[1], AL_GAIN, gain[1]);
	}
	//������ �� 226
	else if (h.modelName == "ka_226")
	{
		//������� ����������� �������
		if (velocityVectorXZ > 0)
		{
			if (velocityVectorXZ > 28 && accelerationVectorXZ > -0.28 && velocityY > 2)
			{
				flapIndicator = 1;
			}
			else
			{
				flapIndicator = 0;
			}
		}
		else
		{
			if (velocityVectorXZ < -28 && accelerationVectorXZ < 0.28 && velocityY > 2)
			{
				flapIndicator = 1;
			}
			else
			{
				flapIndicator = 0;
			}
		}

		//���� ����������� ������� �������, ������� ������
		if (flapIndicator)//�������
		{
			flapOn += deltaTime;
			flapOn = (flapOn > 1) ? 1 : flapOn;//������ ������� ��������� �� 1�
		}
		else
		{
			flapOn -= deltaTime;
			flapOn = (flapOn < 0) ? 0 : flapOn;
		}

		if (key[1] != h.fullName["flapping"])
		{
			setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["flapping"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			key[1] = h.fullName["flapping"];
		}

		//������� ������� ����� ������� �� ��������
		double flappingVelxGain = toCoef(getParameterFromVector(vector<point>{ { 28, -18 }, { 50, -13 }}, velocityVectorXZ)) * getParameterFromVector(vector<point>{ { 0, 0 }, { h.redTurnoverAvt, 1 }}, sr.reduktor_gl_obor);

		//��������� ������ ��� ������� ����������� �������
		double dTangazGain = (derivTangaz > 0) ? derivTangaz * 10 * flapOn : 0;

		//�������������� ��������� ������� ( �� ����� -5 )
		double flappingGain = (toDb(flappingVelxGain) + dTangazGain > -5) ? -5 : toDb(flappingVelxGain) + dTangazGain;

		alSourcef(source[1], AL_GAIN, toCoef(flappingGain) * masterGain * h.vintFlapFactor);

		alSourcef(source[1], AL_PITCH, sr.reduktor_gl_obor / h.redTurnoverAvt);
	}
	//������ �����
	else if (h.modelName == "ansat")
	{
		if (key[0] != h.fullName["vint_flap_hi"])
		{
			setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap_hi"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap_hi"];
		}
		if (key[1] != h.fullName["vint_flap"])
		{
			setAndDeploySound(&buffer[1], &source[1], 0, h.fullName["vint_flap"]);
			alSourcei(source[1], AL_LOOPING, AL_TRUE);
			key[1] = h.fullName["vint_flap"];

			alEffecti(effect[1], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[1]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[1], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[1], AL_LOWPASS_GAIN, 0);
			alSource3i(source[1], AL_AUXILIARY_SEND_FILTER, effectSlot[1], 0, NULL);
			alSourcei(source[1], AL_DIRECT_FILTER, filter[1]);
		}
		if (key[2] != h.fullName["pinkNoise"])
		{
			setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["pinkNoise"]);
			alSourcei(source[2], AL_LOOPING, AL_TRUE);
			key[2] = h.fullName["pinkNoise"];
		}

		double lowShelf = getParameterFromVector(vector<point>{ { 44.44, -15 }, { 56, -12 }, { 61.1, -8 }, { 70, -7 }}, abs(velocityVectorXZ));

		double atkMiddlePoint = getParameterFromVector(vector<point>{ { -15, -2 }, { -12, 0 }, { -8, 3 }, { -6, 4.99 }}, lowShelf);

		double attackFlapGain = toCoef(getParameterFromVector(vector<point>{ { -10, lowShelf }, { atkMiddlePoint, lowShelf }, { 5, -6 }, { 10, -4 }}, calcA))
			* getParameterFromVector(vector<point>{ { 5.55, 0 }, { 8.33, 0.5 }, { 11.11, 1 }}, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 34, 0 }, { 37, 0.5 }, { 40, 1 }}, step)
			* getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch);

		//���������� ������� ��� ������
		double crunchGainMod = getParameterFromVector(vector<point>{ { -1.3, 0 }, { -0.7, -3 }}, velocityY)
			* getParameterFromVector(vector<point>{ { 5.55, 0 }, { 11.11, 1 }, { 19.4, 1 }, { 25, 0 }}, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 34, 1 }, { 37, 0.5 }, { 40, 0 }}, step)
			* getParameterFromVector(vector<point>{ { 0.625, 0 }, { 0, 1 }}, groundTouch)
			* getParameterFromVector(vector<point>{ { 3, 0 }, { 5, 1 }}, calcA);

		//���������� ������� ��� ���� ����
		double velYGainMod = getParameterFromVector(vector<point>{ { -8, -3 }, { -4, 0 }}, velocityY)
			* getParameterFromVector(vector<point>{ { 34, 1 }, { 37, 0.5 }, { 40, 0 }}, step)
			* getParameterFromVector(vector<point>{ { 5, 0 }, { 10, 1 }}, calcA);

		double velYFlapHiGain = toCoef(getParameterFromVector(vector<point>{ { -1.3, -13 }, { -0.7, 0 }}, velocityY))
			* getParameterFromVector(vector<point>{ { 5.55, 0 }, { 11.11, 1 }, { 19.4, 1 }, { 25, 0 }}, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 34, 0 }, { 37, 0.5 }, { 40, 1 }}, step)
			* getParameterFromVector(vector<point>{ { 3, 0 }, { 5, 1 }}, calcA);

		//����� �� �������
		double vintFlapCrunchHoveringGain = getParameterFromVector(vector<point>{ { 3, 0 }, { 6, 8 }}, tangaz)
			* getParameterFromVector(vector<point>{ { 0, 1 }, { 8.3, 0 }}, abs(velocityVectorXZ));

		//�������������� ��������� ������� 
		double vintFlapGain = max(toCoef(lowShelf), attackFlapGain) * toCoef(crunchGainMod + velYGainMod + vintFlapCrunchHoveringGain);

		//����� �� �������
		double vintFlapHiCrunchHoveringGain = toCoef(getParameterFromVector(vector<point>{ { 4, -13 }, { 6, 0 }}, tangaz))
			* getParameterFromVector(vector<point>{ { 0, 1 }, { 8.3, 0 }}, abs(velocityVectorXZ));

		//�������������� ��������� ������� 
		double vintFlapHiGain = max(velYFlapHiGain, vintFlapHiCrunchHoveringGain);

		double vaddGain = toCoef(getParameterFromVector(vector<point>{ { -2, -18 }, { -1.3, -15 }, { -0.7, -6 }}, velocityY))
			* getParameterFromVector(vector<point>{ { 5.55, 0 }, { 11.11, 1 }, { 19.4, 1 }, { 25, 0 }}, abs(velocityVectorXZ))
			* getParameterFromVector(vector<point>{ { 34, 0 }, { 37, 0.5 }, { 40, 1 }}, step)
			* getParameterFromVector(vector<point>{ { 3, 0 }, { 5, 1 }}, calcA);

		double highFreqVintFlapGain = toCoef(getParameterFromVector(vector<point>{ { -0.6, -18 }, { -0.5, -15 }, { 0, 0 }}, derivTangaz))
			* getParameterFromVector(vector<point>{ { 3, 0 }, { 7, 1 }}, calcA);

		alSourcef(source[1], AL_GAIN, vintFlapGain * masterGain * h.vintFlapFactor);
		alSourcef(source[1], AL_PITCH, sr.reduktor_gl_obor / h.redTurnoverAvt);
		alEffectf(effect[1], AL_EQUALIZER_HIGH_CUTOFF, 4000);
		alEffectf(effect[1], AL_EQUALIZER_HIGH_GAIN, highFreqVintFlapGain);//
		alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[1]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)

		alSourcef(source[0], AL_GAIN, vintFlapHiGain * masterGain * h.vintFlapFactor);
		alSourcef(source[0], AL_PITCH, sr.reduktor_gl_obor / h.redTurnoverAvt);

		alSourcef(source[2], AL_GAIN, vaddGain * masterGain * h.vintFlapFactor);
	}
	//��������� �����
	else
	{
		if (key[0] != h.fullName["vint_flap"])
		{
			sourceStatus[0] = setAndDeploySound(&buffer[0], &source[0], 0, h.fullName["vint_flap"]);
			alSourcei(source[0], AL_LOOPING, AL_TRUE);
			key[0] = h.fullName["vint_flap"];
		}
		alSourcef(source[0], AL_GAIN, gain[0] * h.vintFlapFactor * masterGain);
	}

	return 1;
}

VintSwish::VintSwish() : Sound(2, 2, 0)
{

}

int VintSwish::play(Helicopter &h, SOUNDREAD &sr)
{
	if (h.modelName == "mi_28")
	{
		lengthOn = getLengthWAV(h.fullName["vint_swish_on"]);
		lengthOff = getLengthWAV(h.fullName["vint_swish_off"]);

		//0 -> ��1��
		if (sr.reduktor_gl_obor < h.redTurnoverMg1 && (sr.p_eng1_zap | sr.p_eng2_zap) && mode != "mg1")
		{
			if (lengthOn - offsetOn <= crossFadeDuration)
			{
				mode = "mg1";
			}
			else
			{
				mode = "on";
			}
		}
		//��1��
		else if (sr.reduktor_gl_obor < h.redTurnoverMg1 && !(sr.p_eng1_zap | sr.p_eng2_zap) && !(sr.p_eng1_ostanov && sr.p_eng2_ostanov))
		{
			mode = "mg1";
		}
		//��1�� <-> ��2��
		else if (sr.reduktor_gl_obor >= h.redTurnoverMg1 && sr.reduktor_gl_obor <= h.redTurnoverMg2)
		{
			mode = "mg2";
		}
		//��2�� <-> ���
		else if (sr.reduktor_gl_obor > h.redTurnoverMg2)
		{
			mode = "avt";
		}
		//��2�� -> 0
		else if (sr.p_eng1_ostanov && sr.p_eng2_ostanov && sr.reduktor_gl_obor > 0 && sr.reduktor_gl_obor < h.redTurnoverMg2)
		{
			mode = "off";
		}

		if (modeSequence.back() != mode)
		{
			switcher = 0;
			id = !id;
			if (mode == "on" || mode == "off")
			{
				fileBuffered[id] = "NULL";
			}
			modeSequence.push_back(mode);
			if (modeSequence.size() >= 4)
			{
				modeSequence.erase(modeSequence.begin());
			}
		}

		if (mode == "on")
		{
			filetoBuffer[id] = h.fullName["vint_swish_on"];
		}
		else if (mode == "mg1")
		{
			filetoBuffer[id] = h.fullName["vint_swish_w"];
		}
		else if (mode == "mg2")
		{
			filetoBuffer[id] = h.fullName["vint_swish_w_mg"];
			filetoBuffer[!id] = h.fullName["vint_swish_w"];
		}
		else if (mode == "avt")
		{
			filetoBuffer[id] = h.fullName["vint_swish_w_avt"];
			filetoBuffer[!id] = h.fullName["vint_swish_w_mg"];
		}
		else if (mode == "off")
		{
			if (modeSequence[1] == "avt")
			{
				fileBuffered[id] = h.fullName["vint_swish_w_mg"];
				modeSequence[1] = "mg2";
				id = !id;
				filetoBuffer[id] = h.fullName["vint_swish_off"];
			}
			else
			{
				filetoBuffer[id] = h.fullName["vint_swish_off"];
			}
		}

		double finalGain = h.redFactor * masterGain;

		if (fileBuffered[id] == h.fullName["vint_swish_w_avt"])
		{
			gain[id] = getParameterFromVector(vector<point>{ {h.redTurnoverMg2, 0}, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);
			gain[!id] = 1 - gain[id];
		}
		else if (fileBuffered[!id] == h.fullName["vint_swish_w_avt"])
		{
			gain[id] = 1 - getParameterFromVector(vector<point>{ {h.redTurnoverMg2, 0}, { h.redTurnoverAvt, 1 } }, sr.reduktor_gl_obor);
			gain[!id] = 1 - gain[id];
		}
		else if (fileBuffered[id] == h.fullName["vint_swish_w_mg"] && fileBuffered[!id] == h.fullName["vint_swish_w"])
		{
			gain[id] = getParameterFromVector(vector<point>{ {h.redTurnoverMg1, 0}, { h.redTurnoverMg2, 1 } }, sr.reduktor_gl_obor);
			gain[!id] = 1 - gain[id];
		}
		else if (fileBuffered[!id] == h.fullName["vint_swish_w_mg"] && fileBuffered[id] == h.fullName["vint_swish_w"])
		{
			gain[id] = 1 - getParameterFromVector(vector<point>{ {h.redTurnoverMg1, 0}, { h.redTurnoverMg2, 1 } }, sr.reduktor_gl_obor);
			gain[!id] = 1 - gain[id];
		}
		else if (fileBuffered[id] == "NULL" && filetoBuffer[id] == "NULL")
		{
			gain[id] = 0;
			gain[!id] = 1;
		}
		else if (fileBuffered[!id] == "NULL" && filetoBuffer[!id] == "NULL")
		{
			gain[id] = 1;
			gain[!id] = 0;
		}
		else if (fileBuffered[!id] == h.fullName["vint_swish_on"] && fileBuffered[id] == h.fullName["vint_swish_w"])
		{
			if (reperSet != "set")
			{
				reperTurn = sr.reduktor_gl_obor;
				reperSet = "set";
			}

			double timeGain[2];
			double turnGain[2];

			if (sr.reduktor_gl_obor <= h.redTurnoverMg1)
			{
				parametricalCrossfade(&turnGain[!id], &turnGain[id], sr.reduktor_gl_obor, reperTurn, h.redTurnoverMg1);
			}
			else
			{
				turnGain[id] = 1;
				turnGain[!id] = 0;
			}

			if (offsetOn != 0)
			{
				timeCrossfade(timeGain[!id], timeGain[id], crossFadeDuration, crossFadeDuration - (lengthOn - offsetOn));
			}
			else
			{
				timeGain[id] = 1;
				timeGain[!id] = 0;
			}

			gain[id] = max(timeGain[id], turnGain[id]);
			gain[!id] = min(timeGain[!id], turnGain[!id]);
		}
		else
		{
			switcher += deltaTime;
			timeCrossfade(gain[!id], gain[id], crossFadeDuration, switcher);
		}

		alSourcef(source[!id], AL_GAIN, gain[!id] * finalGain);
		alSourcef(source[id], AL_GAIN, gain[id] * finalGain);

		//����� ������ �������� �� ����������
		if (mode == "off")
		{
			alSourcef(source[id], AL_GAIN, interpolation({ h.redTurnoverMg1*0.69, 0 }, { h.redTurnoverMg1, 1 }, sr.reduktor_gl_obor));//
			alSourcef(source[!id], AL_GAIN, interpolation({ h.redTurnoverMg1*0.69, 0 }, { h.redTurnoverMg1, 1 }, sr.reduktor_gl_obor));//
		}

	}
	else if (h.modelName == "ka_226")
	{
		filetoBuffer[0] = h.fullName["vint_hi"];
		alSourcei(source[0], AL_LOOPING, AL_TRUE);

		if (sr.reduktor_gl_obor >= h.redTurnoverMg2)
		{
			//�������� ������ ���� � ����������� �� �������� ��������� � ������ ������
			pitch[0] = sr.reduktor_gl_obor / h.redTurnoverAvt;
			//��������� ������ ����� �� �������� ��������� ���� �������� ������ ���� ���������
			//������ �������� �� ���
			gain[0] = interpolation({ h.redTurnoverAvt, 1 }, { h.redTurnoverMg2, 0 }, sr.reduktor_gl_obor)
				* toCoef(getParameterFromVector(vector<point>{ { 0, -11 }, { 12, -7 }}, step));
		}
		else
		{
			pitch[0] = 1;
			gain[0] = 0;
		}

		alSourcef(source[0], AL_GAIN, masterGain * gain[0] * h.vintSwishFactor);
		alSourcef(source[0], AL_PITCH, pitch[0]);
	}
	else if (h.modelName == "ansat")
	{
		filetoBuffer[0] = h.fullName["vint_hi"];
		alSourcei(source[0], AL_LOOPING, AL_TRUE);


		if (sr.reduktor_gl_obor >= h.redTurnoverMg2)
		{
			//�������� ������ ���� � ����������� �� �������� ��������� � ������ ������
			pitch[0] = sr.reduktor_gl_obor / h.redTurnoverAvt;
			//��������� ������ ����� �� �������� ��������� ���� �������� ������ ���� ���������
			gain[0] = interpolation({ h.redTurnoverAvt, 1 }, { h.redTurnoverMg2, 0 }, sr.reduktor_gl_obor);
		}
		else
		{
			pitch[0] = 1;
			gain[0] = 0;
		}

		double velXGainMod = toCoef(getParameterFromVector(vector<point>{ { 0, -7 }, { 14, -1 }}, abs(velocityVectorXZ)));

		alSourcef(source[0], AL_PITCH, pitch[0]);

		alSourcef(source[0], AL_GAIN, gain[0] * velXGainMod * masterGain * h.vintSwishFactor);
	}
	else
	{
		filetoBuffer[0] = h.fullName["vint_hi"];
		alSourcei(source[0], AL_LOOPING, AL_TRUE);

		if (sr.reduktor_gl_obor >= h.redTurnoverMg2)
		{
			//�������� ������ ���� � ����������� �� �������� ��������� � ������ ������
			pitch[0] = sr.reduktor_gl_obor / h.redTurnoverAvt;
			//��������� ������ ����� �� �������� ��������� ���� �������� ������ ���� ���������
			gain[0] = interpolation({ h.redTurnoverAvt, 1 }, { h.redTurnoverMg2, 0 }, sr.reduktor_gl_obor);
		}
		else
		{
			pitch[0] = 1;
			gain[0] = 0;
		}

		alSourcef(source[0], AL_GAIN, masterGain * gain[0] * h.vintSwishFactor);
		alSourcef(source[0], AL_PITCH, pitch[0]);
	}

	for (size_t i = 0; i < 2; i++)
	{
		//��� �������� ��������� = 0 � ������������ ����������, ������������ ���������
		if (sr.reduktor_gl_obor == 0 && !sr.p_eng1_zap && !sr.p_eng2_zap)
		{
			alSourceStop(source[i]);
			alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);		// ���������� ������� 
		}

		if (fileBuffered[i] != filetoBuffer[i])
		{
			setSource(&buffer[i], &source[i], filetoBuffer[i]);

			if (filetoBuffer[i] == h.fullName["vint_swish_on"])
			{
				alSourcei(source[i], AL_LOOPING, AL_FALSE);
				offset[i] = getParameterFromVector(h.redFunctionOnSwap, sr.reduktor_gl_obor);
			}
			else if (filetoBuffer[i] == h.fullName["vint_swish_w"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["vint_swish_w_mg"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}
			else if (filetoBuffer[i] == h.fullName["vint_swish_w_avt"])
			{
				alSourcei(source[i], AL_LOOPING, AL_TRUE);
				offset[i] = 0;
			}

			alSourcef(source[i], AL_SEC_OFFSET, offset[i]);//������������� ������ � ���
			alSourcef(source[i], AL_GAIN, 0);//������������� ��������� � 0
			alSourcePlay(source[i]);//��������� ��������������

			fileBuffered[i] = filetoBuffer[i];
		}

		if (fileBuffered[i] == h.fullName["vint_swish_on"])
		{
			alGetSourcef(source[i], AL_SEC_OFFSET, &offsetOn);
			alSourcef(source[i], AL_PITCH, sr.reduktor_gl_obor / getParameterFromVector(h.redFunctionOn, offsetOn));
		}
		else if (fileBuffered[i] == h.fullName["vint_swish_w"])
		{
			alSourcef(source[i], AL_PITCH, roundFloat((sr.reduktor_gl_obor / h.redTurnoverMg1), 0.001));
		}
		else if (fileBuffered[i] == h.fullName["vint_swish_w_mg"])
		{
			alSourcef(source[i], AL_PITCH, roundFloat((sr.reduktor_gl_obor / h.redTurnoverMg2), 0.001));//������ pitch (���� ���������� ������ ��� ��������� ������� ��)
		}
		else if (fileBuffered[i] == h.fullName["vint_swish_w_avt"])
		{
			alSourcef(source[i], AL_PITCH, roundFloat((sr.reduktor_gl_obor / h.redTurnoverAvt), 0.001));//������ pitch[0] (���� ���������� ������ ��� ��������� ������� ��)
		}

		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);
	}

	return 1;
}

Skv::Skv() : Sound(3, 3, 2)
{

}

int Skv::play(Helicopter &h, SOUNDREAD &sr)
{
	int status = 0;

	if (h.modelName == "mi_28")
	{
		for (size_t i = 0; i < 2; i++)
		{
			//���������� ����������
			if (eq[i] != "set")
			{
				alEffecti(effect[i], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
				alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
				alFilteri(filter[i], AL_FILTER_TYPE, AL_FILTER_LOWPASS);//���������� ������ ��� ��
				alFilterf(filter[i], AL_LOWPASS_GAIN, 0);//������� ���� ������� ���������
				alSource3i(source[i], AL_AUXILIARY_SEND_FILTER, effectSlot[i], 0, 0);//�������� ����� ��������� ����� ���� � ��������
				alSourcei(source[i], AL_DIRECT_FILTER, filter[i]);//���������� ������ � ���������
				eq[i] = "set";
			}
		}

		pitch[id] = 0.029 * max(sr.eng1_obor, sr.eng2_obor) - 1.484;

		status = Sound::play(sr.p_skv_on, h.fullName["skv_on"], h.fullName["skv_w"], h.fullName["skv_off"], h.skvFactor);//������������� ���� - ���������� ��������� ����� � play

		double averangeTurn = getAverange(vectorAvrRedTurn, 25);

		double avrTurngain = (-5) + (sr.reduktor_gl_obor - averangeTurn) * 4;
		avrTurngain = (avrTurngain > 0) ? 0 : avrTurngain;

		double highFreqGain = pow(10, avrTurngain * 0.05);

		double highCutoffFreq = 4000;//�� 4000-16000

		for (size_t i = 0; i < 2; i++)
		{
			alEffectf(effect[i], AL_EQUALIZER_HIGH_CUTOFF, highCutoffFreq);

			alEffectf(effect[i], AL_EQUALIZER_HIGH_GAIN, highFreqGain);//

			alAuxiliaryEffectSloti(effectSlot[i], AL_EFFECTSLOT_EFFECT, effect[i]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
		}
	}
	else if (h.modelName == "mi_26")
	{
		pitch[id] = 1 + 0.03245 * abs(max(sr.eng1_obor, sr.eng2_obor) - h.engTurnoverAvt);

		status = Sound::play(sr.p_skv_on, h.fullName["skv_on"], h.fullName["skv_w"], h.fullName["skv_off"], h.skvFactor);//������������� ���� - ���������� ��������� ����� � play
	}
	else if (h.modelName == "ka_29" || h.modelName == "ka_27")
	{
		//�� �������� ��� ���������
		if (sr.eng1_obor > 0 || sr.eng2_obor > 0)
		{
			//��������� ��� ������
			if (harm != h.fullName["skv_harm_29"])
			{
				setAndDeploySound(&buffer[2], &source[2], 0, h.fullName["skv_harm_29"]);
				alSourcei(source[2], AL_LOOPING, AL_TRUE);
				harm = h.fullName["skv_harm_29"];

				alEffecti(effect[1], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
				alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[1]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
				alFilteri(filter[1], AL_FILTER_TYPE, AL_FILTER_LOWPASS);//���������� ������ ��� ��
				alFilterf(filter[1], AL_LOWPASS_GAIN, 0);//������� ���� ������� ���������
				alSource3i(source[2], AL_AUXILIARY_SEND_FILTER, effectSlot[1], 0, 0);//�������� ����� ��������� ����� ���� � ��������
				alSourcei(source[2], AL_DIRECT_FILTER, filter[1]);//���������� ������ � ���������
			}

			double harmOn = 0;
			if (soundOn)
			{
				harmOn = offset[id] / lengthOn;
			}
			else if (soundOff)
			{
				harmOn = 1 - (offset[id] / lengthOff);
			}
			else if (soundWork)
			{
				harmOn = 1;
			}

			//���������� ��������� ����
			double harmGain = getParameterFromVector(vector<point>{ { 0, -60 }, { 40, -35 }, { 85, -15 }, { 90, -10 }, { 100, -5 } }, sr.reduktor_gl_obor);
			alSourcef(source[2], AL_GAIN, toCoef(harmGain) * harmOn);

			//������ ���� ���������
			double harmPitch = 1 + (0.01892 * (max(sr.eng1_obor, sr.eng2_obor) - h.engTurnoverAvt));
			alSourcef(source[2], AL_PITCH, harmPitch);

			//������� ������� �� �� 2 �
			double avrEngTurns = (sr.eng1_obor > sr.eng2_obor) ? sr.eng1_obor - getAverange(vectorAvrEng1Turn, 2) : sr.eng2_obor - getAverange(vectorAvrEng2Turn, 2);

			//�������� ������ �����������
			double harmEqMid1Gain = getParameterFromVector(vector<point>{ {0, 0}, { 4, 18 } }, avrEngTurns);

			// �������� ������ �����������
			double harmEqMid2Gain = getParameterFromVector(vector<point>{ {0, 0}, { 4, 12 } }, avrEngTurns);

			alEffectf(effect[1], AL_EQUALIZER_MID1_CENTER, 1000);
			alEffectf(effect[1], AL_EQUALIZER_MID1_WIDTH, 0.2);
			alEffectf(effect[1], AL_EQUALIZER_MID1_GAIN, toCoef(harmEqMid1Gain));//

			alEffectf(effect[1], AL_EQUALIZER_MID2_CENTER, 2400);
			alEffectf(effect[1], AL_EQUALIZER_MID2_WIDTH, 0.2);
			alEffectf(effect[1], AL_EQUALIZER_MID2_GAIN, toCoef(harmEqMid2Gain));//

			alAuxiliaryEffectSloti(effectSlot[1], AL_EFFECTSLOT_EFFECT, effect[1]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)

			gain[id] = toCoef(harmGain);
			pitch[id] = harmPitch;
			status = Sound::play(sr.p_skv_on, h.fullName["skv_on"], h.fullName["skv_w"], h.fullName["skv_off"], h.skvFactor);//������������� ���� - ���������� ��������� ����� � play

			/*cout.precision(3);
			cout << fixed
				<< " HAPI: " << harmPitch
				<< " HAGA: " << harmGain
				<< " HE1G: " << harmEqMid1Gain
				<< " HE2G: " << harmEqMid2Gain
				<< " AVRT: " << avrEngTurns
				<< " AVR1: " << getAverange("eng1Turns", 2)
				<< " AVR2: " << getAverange("eng2Turns", 2)
				<< "\t\t\r"; */
		}
	}
	else
	{
		status = Sound::play(sr.p_skv_on, h.fullName["skv_on"], h.fullName["skv_w"], h.fullName["skv_off"], h.skvFactor);//������������� ���� - ���������� ��������� ����� � play
	}

	return status;
}

Runway::Runway() : Sound(2, 2, 1)
{

}

int Runway::play(Helicopter &h, SOUNDREAD &sr)
{

	for (size_t i = 0; i < 2; i++)
	{
		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);

		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			setAndDeploySound(&buffer[i], &source[i], offset[i], filetoBuffer[i]);
			fileBuffered[i] = filetoBuffer[i];
		}
	}

	if (h.modelName == "mi_8_amtsh" || h.modelName == "mi_8_mtv5")
	{
		filetoBuffer[1] = h.fullName["runway"];
		filetoBuffer[0] = h.fullName["landing"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);
		alSourcei(source[0], AL_LOOPING, AL_TRUE);

		//���� ��������� ������� ����������
		//������ ����� �����������, �������� ������ ���� ��������� ����� ���� �����������
		if (eq != "set")
		{
			alEffecti(effect[0], AL_EFFECT_TYPE, AL_EFFECT_EQUALIZER);//���������� ������ ��� ����������
			alAuxiliaryEffectSloti(effectSlot[0], AL_EFFECTSLOT_EFFECT, effect[0]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)
			alFilteri(filter[0], AL_FILTER_TYPE, AL_FILTER_LOWPASS);
			alFilterf(filter[0], AL_LOWPASS_GAIN, 0);
			alSource3i(source[0], AL_AUXILIARY_SEND_FILTER, effectSlot[0], 0, 0);
			alSourcei(source[0], AL_DIRECT_FILTER, filter[0]);
			eq = "set";
		}

		alEffectf(effect[0], AL_EQUALIZER_HIGH_CUTOFF, 4000);

		alEffectf(effect[0], AL_EQUALIZER_HIGH_GAIN, interpolation({ 8.3, 0.126 }, { 11.2, 1 }, sr.v_surf_x));//

		alAuxiliaryEffectSloti(effectSlot[0], AL_EFFECTSLOT_EFFECT, effect[0]);//�������� ������ � ���� (� 1 ���� ����� ��������� 1 ������)

		gain[1] = interpolation({ 0, 0 }, { 8.3, 1 }, abs(sr.v_surf_x)) // driving
			* 0.25
			* getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch);/*��������� �������� �� ������*/

		gain[0] = interpolation({ 2.77, 0 }, { 8.3, 1 }, abs(sr.v_surf_x)) // landing
			* 0.854
			* getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch);
	}
	else if (h.modelName == "mi_26")
	{
		filetoBuffer[0] = h.fullName["runway"];
		alSourcei(source[0], AL_LOOPING, AL_TRUE);
		filetoBuffer[1] = h.fullName["flapping"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);

		double drivingGain = getParameterFromVector(vector<point>{ { 0, -60 }, { 1, -30 }, { 2.77, -8 }, { 5, -5 }, { 8.3, -2 }, { 9, 0 } }, abs(sr.v_surf_x));

		gain[0] = toCoef(drivingGain) * getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch) * 0.707;
		gain[1] = interpolation({ 0, 0 }, { 8.3, 1 }, abs(sr.v_surf_x))
			* interpolation({ 78, 0.71 }, { 84, 1 }, sr.reduktor_gl_obor);
	}
	else if (h.modelName == "ka_226")
	{
		double drivingGain = getParameterFromVector(vector<point>{ { 0, -18 }, { 8.4, -12 }, { 14, -18 }}, abs(sr.v_surf_x));

		filetoBuffer[1] = h.fullName["runway"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);
		gain[1] = toCoef(drivingGain) * getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch);
	}
	else if (h.modelName == "ansat")
	{
		double drivingGain = getParameterFromVector(vector<point>{ { 0, -18 }, { 8.3, -3 }, { 14, 0 } }, abs(sr.v_surf_x));

		filetoBuffer[1] = h.fullName["runway"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);
		gain[1] = toCoef(drivingGain) * getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch);
	}
	else if (h.modelName == "ka_29" || h.modelName == "ka_27")
	{
		double drivingGain = getParameterFromVector(vector<point>{ { 0, -60 }, { 1, -30 }, { 2.77, -8 }, { 5, -5 }, { 8.3, -2 }, { 9, 0 } }, abs(sr.v_surf_x));

		filetoBuffer[1] = h.fullName["runway"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);
		gain[1] = toCoef(drivingGain) * getParameterFromVector(vector<point>{ { 0, 0 }, { 0.625, 1 }}, groundTouch);
	}
	else
	{
		filetoBuffer[1] = h.fullName["runway"];
		alSourcei(source[1], AL_LOOPING, AL_TRUE);
		gain[1] = interpolation({ 0, 0 }, { 13.8, 1 }, abs(sr.v_surf_x)) * groundTouch;
	}

	for (size_t i = 0; i < sourceNumber; i++)
	{
		alSourcef(source[i], AL_GAIN, masterGain * h.runwayFactor * gain[i]);
	}

	return 1;
}

double attack(double velocityVectorXZ, double velocityXPrevious, double tangaz, double velocityY)
{
	double calcA = 0;
	if ((velocityVectorXZ + velocityXPrevious) == 0)
	{
		if (velocityY < 0)
		{
			calcA = 90;
		}
		else if (velocityY > 0)
		{
			calcA = -90;
		}
		else
		{
			calcA = 0;
		}
	}
	else if (tangaz == 90 || tangaz == -90)
	{
		if (velocityY != 0)
		{
			calcA = 0;
		}
		else
		{
			calcA = 90;
		}
	}
	else
	{
		tangaz = tangaz * M_PI / 180.0;
		calcA = atan(tan(tangaz) - (2 * velocityY) / ((velocityXPrevious + velocityVectorXZ) * cos(tangaz)));
		calcA = calcA * 180 / M_PI;
	}
	return calcA;
}

Sound::Sound() : sourceStatus(new int[2]), gain(new double[2]), pitch(new double[2]), offset(new float[2]), source(new ALuint[2]), buffer(new ALuint[2]), filetoBuffer(new string[2]), fileBuffered(new string[2])
{
	for (size_t i = 0; i < sourceNumber; i++)
	{
		sourceStatus[i] = 0;
		gain[i] = 1;
		pitch[i] = 1;
		offset[i] = 0;
		fileBuffered[i] = "NULL";
		filetoBuffer[i] = "NULL";
	}

	try
	{
		if (sourcesInUse == maxSources)
			throw 256;
	}
	catch (int e)
	{
		cout << " [" << e << "] Sources exist...cant gen more sources...\n" << endl;
	}
	alGenSources(sourceNumber, source.get());
	alGenBuffers(bufferNumber, buffer.get());

	sourcesInUse += sourceNumber;
}

Sound::Sound(int sources, int buffers, int effectslots) : sourceStatus(new int[sources]), gain(new double[sources]), pitch(new double[sources]), offset(new float[sources]), source(new ALuint[sources]), buffer(new ALuint[buffers]), effectSlot(new ALuint[effectslots]), effect(new ALuint[sources]), filter(new ALuint[sources]), filetoBuffer(new string[sources]), fileBuffered(new string[sources])
{
	try
	{
		if (sourcesInUse == maxSources)
			throw 256;
		if (effectSlotsInUse == maxSlots)
			throw 16;
	}
	catch (int z)
	{
		switch (z)
		{
		case 256: cout << " Cant gen more sources...\n" << endl; break;
		case 16: cout << " Cant gen more aux slots...\n" << endl; break;
		}
	}
	sourceNumber = sources;
	bufferNumber = buffers;
	effectSlotNumber = effectslots;

	for (size_t i = 0; i < sourceNumber; i++)
	{
		sourceStatus[i] = 0;
		gain[i] = 1;
		pitch[i] = 1;
		offset[i] = 0;
		fileBuffered[i] = "NULL";
		filetoBuffer[i] = "NULL";
	}

	if (sourcesInUse + sourceNumber > 256)
		cout << "Caution: only [" << sourcesInUse + sourceNumber - 256 << "] sources can be generated" << endl;
	alGenSources(sourceNumber, source.get());
	alGenBuffers(bufferNumber, buffer.get());
	alGenEffects(sourceNumber, effect.get());
	alGenFilters(sourceNumber, filter.get());
	alGenAuxiliaryEffectSlots(effectSlotNumber, effectSlot.get());

	sourcesInUse += sourceNumber;
	effectSlotsInUse += effectSlotNumber;
}

Sound::Sound(const Sound &copy) : Sound()
{
	/*soundOn = 0;
	soundWork = 0;
	soundOff = 0;*/
	soundOn = copy.soundOn;
	soundWork = copy.soundWork;
	soundOff = copy.soundOff;
	mode = copy.mode;//"0";
					 //modeSequence.clear();
	modeSequence = copy.modeSequence;//{ "0","0","0" };
	lengthOn = copy.lengthOn;
	lengthOff = copy.lengthOff;
	offsetOn = copy.offsetOn;
	offsetOff = copy.offsetOff;
	crossFadeDuration = copy.crossFadeDuration;
	id = copy.id;
	for (size_t i = 0; i < copy.sourceNumber; i++)
	{
		pitch[i] = copy.pitch[i];
		gain[i] = copy.gain[i];
		offset[i] = copy.offset[i];
		source[i] = copy.source[i];
		if (effectSlot)
		{
			effectSlot[i] = copy.effectSlot[i];
		}
		if (effect)
		{
			effect[i] = copy.effect[i];
		}
		if (filter)
		{
			filter[i] = copy.filter[i];
		}
		filetoBuffer[i] = copy.filetoBuffer[i];
		fileBuffered[i] = copy.fileBuffered[i];
		sourceStatus[i] = copy.sourceStatus[i];
	}
	for (size_t i = 0; i < copy.bufferNumber; i++)
	{
		buffer[i] = copy.buffer[i];
	}
	channel = copy.channel;
	sourceNumber = copy.sourceNumber;
	bufferNumber = copy.bufferNumber;
	effectSlotNumber = copy.effectSlotNumber;
}

Sound & Sound::operator =(const Sound & copy)
{
	/*soundOn = 0;
	soundWork = 0;
	soundOff = 0;*/
	soundOn = copy.soundOn;
	soundWork = copy.soundWork;
	soundOff = copy.soundOff;
	mode = copy.mode;//"0";
	//modeSequence.clear();
	modeSequence = copy.modeSequence;//{ "0","0","0" };
	lengthOn = copy.lengthOn;
	lengthOff = copy.lengthOff;
	offsetOn = copy.offsetOn;
	offsetOff = copy.offsetOff;
	crossFadeDuration = copy.crossFadeDuration;
	id = copy.id;
	for (size_t i = 0; i < copy.sourceNumber; i++)
	{
		pitch[i] = copy.pitch[i];
		gain[i] = copy.gain[i];
		offset[i] = copy.offset[i];
		source[i] = copy.source[i];
		if (effectSlot)
		{
			effectSlot[i] = copy.effectSlot[i];
		}
		if (effect)
		{
			effect[i] = copy.effect[i];
		}
		if (filter)
		{
			filter[i] = copy.filter[i];
		}
		filetoBuffer[i] = copy.filetoBuffer[i];
		fileBuffered[i] = copy.fileBuffered[i];
		sourceStatus[i] = copy.sourceStatus[i];
	}
	for (size_t i = 0; i < copy.bufferNumber; i++)
	{
		buffer[i] = copy.buffer[i];
	}
	channel = copy.channel;
	sourceNumber = copy.sourceNumber;
	bufferNumber = copy.bufferNumber;
	effectSlotNumber = copy.effectSlotNumber;
	return *this;
}

Sound::~Sound()
{
	alDeleteSources(sourceNumber, source.get());
	alDeleteBuffers(bufferNumber, buffer.get());
	if (effect)
	{
		alDeleteEffects(sourceNumber, effect.get());
	}
	if (filter)
	{
		alDeleteFilters(sourceNumber, filter.get());
	}
	if (effectSlot)
	{
		alDeleteAuxiliaryEffectSlots(effectSlotNumber, effectSlot.get());
		effectSlotsInUse -= effectSlotNumber;
	}
	sourcesInUse -= sourceNumber;
}

int Crane::play(char status, string pathOn, string pathW, string pathOff, double gainMult)
{
	bool start;
	bool work;
	bool end;
	bool free;

	//������ ������ ������ ������� � ���������
	if (pathOn != "NULL")
		lengthOn = getLengthWAV(pathOn);
	if (pathOff != "NULL")
		lengthOff = getLengthWAV(pathOff);

	alGetSourcei(source[id], AL_SOURCE_STATE, &sourceStatus[id]);

	//������� ������� ����� ��� ����� ������������
	if (pathOn != "NULL" & pathW != "NULL" & pathOff != "NULL")
	{
		start = ((int)status == 1) & !soundOn & !soundWork;
		work = ((int)status == 0) & soundOn & !soundWork & ((lengthOn - offset[id]) <= crossFadeDuration);
		end = ((int)status == -1) & !soundOff;
		free = ((int)status == 0) & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ���������
	if (pathOn != "NULL" & pathW != "NULL" & pathOff == "NULL")
	{
		start = ((int)status == 1) & !soundOn & !soundWork;
		work = ((int)status == 0)& soundOn & !soundWork & ((lengthOn - offset[id]) <= crossFadeDuration);
		end = 0;
		free = ((int)status == 0);
	}
	//������� ������� ����� ����������� ������
	if (pathOn != "NULL" & pathW == "NULL" & pathOff != "NULL")
	{
		start = ((int)status == 1) & !soundOn;
		work = 0;
		end = ((int)status == -1) & !soundOff;
		free = ((int)status == 0) & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������
	if (pathOn == "NULL" & pathW != "NULL" & pathOff != "NULL")
	{
		start = 0;
		work = ((int)status == 0) & !soundWork;
		end = ((int)status == -1) & !soundOff;
		free = ((int)status == 0) & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������ � ������
	if (pathOn == "NULL" & pathW == "NULL" & pathOff != "NULL")
	{
		start = 0;
		work = 0;
		end = ((int)status == -1) & !soundOff;
		free = ((int)status == 0) & soundOff & sourceStatus[id] != AL_PLAYING;
	}
	//������� ������� ����� ����������� ������ � ����������
	if (pathOn == "NULL" & pathW != "NULL" & pathOff == "NULL")
	{
		start = 0;
		work = ((int)status == 0) & !soundWork;
		end = 0;
		free = ((int)status == 0);
	}
	//������� ������� ����� ����������� ������ � ����������
	if (pathOn != "NULL" & pathW == "NULL" & pathOff == "NULL")
	{
		start = ((int)status == 1) & !soundOn;
		work = 0;
		end = 0;
		free = ((int)status == 0) & sourceStatus[id] != AL_PLAYING;
	}
	//��� 0
	if (pathOn == "NULL" & pathW == "NULL" & pathOff == "NULL")
	{
		start = 0;
		work = 0;
		end = 0;
		free = 1;
	}

	//��������� (���� path_o ��������� �� ������ ������� -> � �������� ����������� ���� �������)
	if (start)
	{
		soundOn = 1;
		soundWork = 0;
		soundOff = 0;
		mode = "on";
	}
	//������ (���� pathW ��������� �� ������ ������� -> � �������� ����������� ���� ������ ������)
	if (work)
	{
		soundOn = 0;
		soundWork = 1;
		soundOff = 0;
		mode = "w";
	}
	//���������� (���� pathOff ��������� �� ������ ������� -> � �������� ����������� ���� ����������)
	if (end)
	{
		soundOn = 0;
		soundWork = 0;
		soundOff = 1;
		mode = "off";
	}
	//������������ ������
	if (free)
	{
		soundOn = 0;
		soundWork = 0;
		soundOff = 0;

		return 0;
	}

	if (modeSequence.back() != mode)
	{
		switcher = 0;
		id = !id;
		if (mode == "on" || mode == "off")
		{
			fileBuffered[id] = "NULL";
		}
		modeSequence.push_back(mode);
		if (modeSequence.size() >= 4)
		{
			modeSequence.erase(modeSequence.begin());
		}
	}


	//cout.precision(3);
	//cout << fixed
	//	<< " ID__: " << id
	//	<< " OFF0: " << offset[0]
	//	<< " OFF1: " << offset[1]
	//	<< " " << modeSequence[0]
	//	<< " " << modeSequence[1]
	//	<< " " << modeSequence[2]
	//	<< "\t\t\r";

	if (mode == "w")
	{
		filetoBuffer[id] = pathW;
		alSourcef(source[id], AL_LOOPING, AL_TRUE);
	}
	else if (mode == "on")
	{
		filetoBuffer[id] = pathOn;
		alSourcef(source[id], AL_LOOPING, AL_FALSE);
	}
	else if (mode == "off")
	{
		filetoBuffer[id] = pathOff;
		alSourcef(source[id], AL_LOOPING, AL_FALSE);
	}

	double finalGain = gain[id] * gainMult * masterGain;
	double rise = 0;
	double fade = 0;
	switcher += deltaTime;
	timeCrossfade(fade, rise, crossFadeDuration, switcher);

	if (fileBuffered[id] == "NULL" && filetoBuffer[id] == "NULL")
	{
		rise = 0;
		fade = 1;
	}
	else if ((fileBuffered[!id] == "NULL" && filetoBuffer[!id] == "NULL") || pathW == "NULL")
	{
		rise = 1;
		fade = 0;
	}
	alSourcef(source[!id], AL_GAIN, fade * finalGain);
	alSourcef(source[id], AL_GAIN, rise * finalGain);

	for (size_t i = 0; i < 2; i++)
	{
		//��������� ������ � �������� ���������
		if (fileBuffered[i] != filetoBuffer[i])
		{
			sourceStatus[i] = setAndDeploySound(&buffer[i], &source[i], offset[i], filetoBuffer[i]);
			fileBuffered[i] = filetoBuffer[i];
		}

		alGetSourcei(source[i], AL_SOURCE_STATE, &sourceStatus[i]);

		alSourcef(source[i], AL_PITCH, pitch[i]);
	}

	//���� ���� ������ - ����������� ����� ���������
	if (soundOn)
	{
		alGetSourcef(source[id], AL_SEC_OFFSET, &offset[id]);
		offsetOn = offset[id];
		if (offset[id] != 0)
		{
			offset[!id] = lengthOff * (1 - (offset[id] / lengthOn));
		}
	}
	//���� ���� ��������� - ����������� ����� �������
	if (soundOff)
	{
		alGetSourcef(source[id], AL_SEC_OFFSET, &offset[id]);
		offsetOff = offset[id];
		if (offset[id] != 0)
		{
			offset[!id] = lengthOn * (1 - (offset[id] / lengthOff));
		}
	}

	return 1;
}
