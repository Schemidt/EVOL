/*!
\file
\brief ����� Helicopter / ����������

������ ���� ��������� ����� Helicopter
*/
#pragma once

#include "string"
#include "map"
#include "iostream"
#include "vector"

#include "Utility.h"

#pragma pack ( push, 1 )
using namespace std;

#ifndef Helicopter_h
#define Helicopter_h
/*!
\brief ����� ���������� ���������
\author �������� �.�
\version 6.0
\date  02.03.2018

����� ������������ ������ �������� ��������� ��������, ������������ ����������� ���������,
� ����� ������ ������ ���������� ������� ��������� ���������� ����������� ��� ���������� ������ ��������� � ������ �������� ������ .WAV
*/
class Helicopter
{
public:

	string modelName;//!<�������� � ����������� ���������
	//���������
	double engTurnoverHp = 25; //!<������� ��������� �� �������� ���������
	double engTurnoverMg = 0; //!<������� ��������� �� ����� ����
	double engTurnoverAvt = 0; //!<������� ��������� �� ������ �������
	double redTurnoverMg1 = 0; //!<������� ��������� � 1�� ���������� �� ����� ����
	double redTurnoverMg2 = 0; //!<������� ��������� � 2�� ����������� �� ����� ����
	double redTurnoverAvt = 0; //!<������� ��������� �� ������ �������
	double vsuTurnoverFull = 100;//!<������� ��� �� ���� ��������
	double vsuTurnoverHp = 35;//!<������� ��� �� �������� ���������
	//��������� ���������
	double vsuFactor = 0;//!<��������� ��������� ���
	double vsuHpFactor = 0;//!<��������� ��������� ��� ��
	double vsuCraneFactor = 0;//!<��������� ��������� ����� ���
	double engFactor = 0;//!<��������� ��������� ���������
	double engHpFactor = 0;//!<��������� ��������� ���������
	double redFactor = 0;//!<��������� ��������� ���������
	double accumFactor = 0;//!<��������� ��������� ������������
	double ptsFactor = 0;//!<��������� ��������� ���
	double ptsToneFactor = 0;//!<��������� ��������� ��� ���
	double tr36Factor = 0;//!<��������� ��������� ������������� 36�
	double tr115Factor = 0;//!<��������� ��������� ������������� 115�
	double pumpLeftFactor = 0;//!<��������� ��������� ������ ��������
	double pumpRightFactor = 0;//!<��������� ��������� ������ ��������
	double cutoffCraneFactor = 0;//!<��������� ��������� ������������ �����
	double ko50Factor = 0;//!<��������� ��������� KO-50
	double skvFactor = 0;//!<��������� ��������� ���
	double runwayFactor = 1;//!<��������� ��������� ����� �������� �� ��� � ��
	double rocketSturmFactor = 0;//!<��������� ��������� ������ �����
	double rocketNar8Factor = 0;//!<��������� ��������� ��� 8
	double rocketNar13Factor = 0;//!<��������� ��������� ��� 13
	double rocketHitFactor = 1;//!<��������� ��������� ��������� ������
	double bulletHitFactor = 1;//!<��������� ��������� ��������� ����
	double upkFactor = 0;//!<��������� ��������� ��������� ���
	double ppuFactor = 0;//!<��������� ��������� ��������� ���
	double vintSwishFactor = 0;//!<��������� ��������� ����� �� ������ �������
	double vintBrakeFactor = 0;//!<��������� ��������� ������� �����
	double vintFlapFactor = 0;//!<��������� ��������� ������� �����
	double chassisBrakePumpFactor = 0;//!<��������� ��������� ������� �����
	double chassisBrakeReleaseFactor = 0;//!<��������� ��������� ������ ��������
	double consumTankFactor = 0;//!<��������� ��������� ������ ���������� ����
	double nipFactor = 0;//!<���
	double fireCraneFactor = 0;//!<�������� ����
	double girovertFactor = 0;//!<�������������
	double pumpStationFactor = 0;//!<�������� �������
	double rainFactor = 1;//!<�����
	double buzzerFactor = 0;//!<������
	double fenFactor = 0;//!<���
	double undefinedFactor = 0;//!<�����������
	double circlingCraneFactor = 0;//!<���� �����������
	double rocketIglaFactor = 0;//!<����
	double vpryam = 0;//!<�������������� ����������
	double vadd = 0;//!<���������� �������
	double shock = 1;//!<���� � ���� ����
	double trim = 0;//!<�������
	double frict = 0;//!>��������

	double flapsFactor = 0;                                              // ��������� ��������� ��������� ----------------------------
	vector<float> flapsChange;                                           // ������ ��� ����������� �������� �������/������ ���������
	double gearFactor = 0;                                               // ��������� ��������� �������/������ �����
	vector<float> vypHist_l;                                            // ������� ��� ����������� �������� �������/������ ����� left
	vector<float> vypHist_r;                                            // ----------------                                      right
	vector<float> vypHist_n;                                            // --------------------                                  ������� ������

	// ���������� ��� �������� ������������ ������ � ��������
	double redLengthOn = 0;//!<������������ ������� ��������
	double redLengthOff = 0;//!<������������ ��������� ��������
	double redLengthMg1 = 0;
	double redLengthMg2 = 0;
	double redLengthAvt = 0;
	//
	double engLengthOn = 0;
	double engLengthOff = 0;
	double engLengthHpOn = 0;
	double engLengthMg = 0;
	double engLengthWAavt = 0;
	double engLengthHpW = 0;
	double engLengthHpOff = 0;
	//
	double vsuLengthOn = 0;
	double vsuLengthHpOn = 0;
	double vsuLengthOff = 0;
	double vsuLengthHpOff = 0;
	//������� ���������� ������� (����� - �������) ������� � ��������� ���������
	//redFunctionOnSwap - ������, ��� ������ p{x,y} ������� redFunctionOn, ������������� ����� p{y,x}
	vector<point> redFunctionOn;
	vector<point> redFunctionOff;
	vector<point> redFunctionOnSwap;
	vector<point> redFunctionOffSwap;
	//
	vector<point> engFunctionOn;
	vector<point> engFunctionOff;
	vector<point> engFunctionOnSwap;
	vector<point> engFunctionOffSwap;

	//!<������������� ������ � ������� ������ - ������
	map<string, string> shortName;

	//!<������������� ������ � ������� ������� ������ - ������
	map<string, string> fullName;

	//!<������������� ������ � ������� ������� ������ - ������
	map<string, ALuint> bufferMap;

	ALuint *buffers;

	/*!
	\brief ��������� ������ � ������� ������� ������
	\details ��������� ������ fullName � ������� ������� ������: shortName + pathToFile
	\param[in] pathToFile ���� � �����������
	*/
	void setPath(string pathToFile);

	/*!
	\brief ��������� ��������� ������� ��
	\details ��������� ��������� ������� �� � ����������� �� ����������� ��������� model
	\param[in] model ������ ������������ ��������
	*/
	void setParam(string model);

	void setBufferMap();

	Helicopter();
	~Helicopter();
};

#endif