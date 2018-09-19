#include "string.h"
#include "map"

#define FLAP_EXT_TIME_40  28                    // ����� ������� ��������� �� 40 ���� ����� 30 ��� (������� 28)
#define FLAP_RET_TIME_40  28                    // ����� ������ ��������� �� 40 ���� ����� 30 ��� (������� 28)
#define GEAR_EXT_TIME     9.2                   // ����� ������� ����� ����� 10 � (9.2 �)
#define GEAR_RET_TIME     8.7                   // ����� ������ ����� ��. 9 � (8.7 �)

using namespace std;

#pragma once

//��������� ��� ���������� ����� ����������
class Airplane
{
public:
//	string modelName;

	double engTurnoverMg; //������� ��������� �� ����� ����
	double engTurnoverAvt; //������� ��������� �� ������ �������
//	double redTurnoverMg1; //������� ��������� � 1�� ���������� �� ����� ����
//	double redTurnoverMg2; //������� ��������� � 2�� ����������� �� ����� ����
//	double redTurnoverAvt; //������� ��������� �� ������ �������

	double vsuTimeOn;
	double vsuTimeOff;
	double vsuHptimeOn;
	double vsuHPtimeOff;

	map<string, string> shortName;
	map<string, string> fullName;

	void setPath(string pathToFile)
	{
		//TXT
		//���������
		shortName["eng_on"] = "eng_on.txt"; //!<��� ����� � ���������� �������� ������� ��������� �� ������ ��
		shortName["eng_off"] = "eng_off.txt"; //!<��� ����� � ���������� �������� ��������� ��������� 
//		shortName["eng_mg_avt"] = "eng_mg_avt.txt"; //!<��� ����� � ���������� �������� ������� ��������� �� ������ �������
//		shortName["eng_avt_mg"] = "eng_avt_mg.txt"; //!<��� ����� c ���������� �������� ��������� �� ������ ������ ����
		
		shortName["eng_mg_avt"] = "eng_mg_cruis.txt";                         //   il_112
		shortName["eng_avt_mg"] = "eng_cruis_mg.txt";                         //   ------
		
//		shortName["ansatFirstEng"] = "eng1_mg.txt"; //!<
//		shortName["ansatSecondEng"] = "eng2_mg.txt"; //!<
//		shortName["ansat1EngOff"] = "eng1_off.txt"; //!<
		//��������
//		shortName["red_on"] = "red_on.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 1�� ���������
//		shortName["red_on_wfe"] = "red_on_wfe.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 1�� ���������
//		shortName["red_on_mg"] = "red_on_mg.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 2� ����������
//		shortName["red_mg_avt"] = "red_mg_avt.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ �������
//		shortName["red_avt_mg"] = "red_avt_mg.txt"; //!<��� ����� c ���������� �������� ���������� ��������� �� ������ ��
//		shortName["red_off"] = "red_off.txt"; //!<��� ����� c ���������� �������� ��������� ��������� ���� ������ ��
//		shortName["ansatRed"] = "red_mg.txt"; //!<

		fullName = shortName;

		map<string, string> ::iterator num;
		for (num = fullName.begin(); num != fullName.end(); num++)
		{
			(*num).second = pathToFile + (*num).second;
		}
	}
	void setParam();
};
