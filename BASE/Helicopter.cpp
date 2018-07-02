/*!
\file
\brief ����� Helicopter / �����������

������ ���� ���������� ������ ������� ������ Helicopter
*/

#include "helicopter.h"

using namespace std;

void Helicopter::setPath(string pathToFile)
{
	//TXT
	//���������
	shortName["eng_on"] = "eng_on.txt"; //!<��� ����� � ���������� �������� ������� ��������� �� ������ ��
	shortName["eng_off"] = "eng_off.txt"; //!<��� ����� � ���������� �������� ��������� ��������� 
	shortName["eng_mg_avt"] = "eng_mg_avt.txt"; //!<��� ����� � ���������� �������� ������� ��������� �� ������ �������
	shortName["eng_avt_mg"] = "eng_avt_mg.txt"; //!<��� ����� c ���������� �������� ��������� �� ������ ������ ����
												//��������
	shortName["red_on"] = "red_on.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 1�� ���������
	shortName["red_on_wfe"] = "red_on_wfe.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 1�� ���������
	shortName["red_on_mg"] = "red_on_mg.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ ������ ���� �� 2� ����������
	shortName["red_mg_avt"] = "red_mg_avt.txt"; //!<��� ����� c ���������� �������� ������� ��������� �� ������ �������
	shortName["red_avt_mg"] = "red_avt_mg.txt"; //!<��� ����� c ���������� �������� ���������� ��������� �� ������ ��
	shortName["red_off"] = "red_off.txt"; //!<��� ����� c ���������� �������� ��������� ��������� ���� ������ ��
										  //WAV
										  //���������
	shortName["eng_on_w"] = "eng_on.wav"; //!<��� ����� ����� ������� ��������� �� ������ ��
	shortName["eng_w_w"] = "eng_w.wav"; //!<��� ����� ����� ������ ��������� �� ������ ��
	shortName["eng_off_w"] = "eng_off.wav"; //!<��� ����� ����� ��������� ��������� 
	shortName["eng_on_hp_w"] = "eng_hp_on.wav"; //!<��� ����� ����� ������� ��������� �� ������ ��
	shortName["eng_w_hp_w"] = "eng_hp_w.wav"; //!<��� ����� ����� ������ ��������� �� ������ ��
	shortName["eng_off_hp_w"] = "eng_hp_off.wav"; //!<��� ����� ����� ��������� ��������� �� ��
	shortName["eng_w_avt_w"] = "eng_w_avt.wav"; //!<��� ����� ����� ������ ��������� �� ������ �������
	shortName["eng_on_avt_w"] = "eng_on_avt.wav"; //!<��� ����� ����� ������� ��������� �� ������ �������
	shortName["eng_avt_mg_w"] = "eng_avt_mg.wav"; //!<��� ����� ����� ��������� �� ������ ������ ����
	shortName["eng_pomp_on"] = "pomp_on.wav"; //!<��� ����� ����� �������
	shortName["eng_pomp_w"] = "pomp_w.wav"; //!<��� ����� ����� �������
											//��������
	shortName["red_on_w"] = "red_on.wav"; //!<��� ����� ����� ������� ��������� �� ������ ������ ���� �� 1�� ���������
	shortName["red_w_w"] = "red_w.wav"; //!<��� ����� ����� ������ ��������� �� ������ ������ ���� �� 1�� ���������
	shortName["red_on_mg_w"] = "red_on_mg.wav"; //!<��� ����� ����� ������� ��������� �� ������ ������ ���� �� 2� ����������
	shortName["red_w_mg_w"] = "red_w_mg.wav"; //!<��� ����� ����� ������ ��������� �� ������ ������ ���� �� 2� ����������
	shortName["red_mg_avt_w"] = "red_mg_avt.wav"; //!<��� ����� ����� ������� ��������� �� ������ �������
	shortName["red_w_avt_w"] = "red_w_avt.wav"; //!<��� ����� ����� ������ ��������� �� ������ �������
	shortName["red_avt_mg_w"] = "red_avt_mg.wav"; //!<��� ����� ����� ���������� ��������� �� ������ ��
	shortName["red_off_w"] = "red_off.wav"; //!<��� ����� ����� ��������� ��������� ���� ������ ��
	shortName["red_crash"] = "red_crash.wav"; //!<��� ����� ����� ������� ���������
	shortName["red_w_avt_fly"] = "red_w_avt_fly.wav"; //!<��� ����� ����� ������ ��������� �� ������ �������
	shortName["red_harm"] = "red_harm.wav"; //!<��� ����� ��������� ���������
	//���
	shortName["vsu_on"] = "vsu_on.wav";//!<��� ����� ����� ������� ���
	shortName["vsu_w"] = "vsu_w.wav";//!<��� ����� ����� ������ ���
	shortName["vsu_off"] = "vsu_off.wav";//!<��� ����� ����� ���������� ���
	shortName["vsu_hp_on"] = "vsu_hp_on.wav";//!<��� ����� ����� ������� ��� ��
	shortName["vsu_hp_w"] = "vsu_hp_w.wav";//!<��� ����� ����� ������ ��� ��
	shortName["vsu_hp_off"] = "vsu_hp_off.wav";//!<��� ����� ����� ���������� ��� ��
	shortName["vsu_kran_on"] = "vsu_kran_on.wav";//!<��� ����� ����� ��������� ������������ ����� ���
	shortName["vsu_kran_w"] = "vsu_kran_w.wav";//!<��� ����� ����� ������ ������������ ����� ���
	//�����������
	shortName["accum"] = "accu.wav";//!<��� ����� ����� ������������
	shortName["accum_tr"] = "accu_tr.wav";//!<��� ����� ����� ������������
	shortName["vpryam"] = "vy_tone.wav";//!<��� ����� ����� ������������
	//���
	shortName["pts_on"] = "pts_on.wav";//!<��� ����� ����� ��������� ���
	shortName["pts_w"] = "pts_w.wav";//!<��� ����� ����� ������ ���
	shortName["pts_off"] = "pts_off.wav";//!<��� ����� ����� ���������� ���
	shortName["pts_tone"] = "pts_tone.wav";//!<��� ����� ����� ��� ���
	//������������� 36�
	shortName["tr36_on"] = "tr36_on.wav";//!<��� ����� ����� ������������� 36�
	shortName["tr36_w"] = "tr36_w.wav";//!<��� ����� ����� ������������� 36�
	shortName["tr36_off"] = "tr36_off.wav";//!<��� ����� ����� ������������� 36�
	//������������� 115�
	shortName["tr115_on"] = "tr115_on.wav";//!<��� ����� ����� ������������� 115�
	shortName["tr115_w"] = "tr115_w.wav";//!<��� ����� ����� ������������� 115�
	shortName["tr115_off"] = "tr115_off.wav";//!<��� ����� ����� ������������� 115�
	//����� ��������
	shortName["podk_r_on"] = "pump_r_on.wav";//!<��� ����� ����� ������ ��������
	shortName["podk_r_w"] = "pump_r_w.wav";//!<��� ����� ����� ������ ��������
	shortName["podk_r_off"] = "pump_r_off.wav";//!<��� ����� ����� ������ ��������
	shortName["podk_l_on"] = "pump_l_on.wav";//!<��� ����� ����� ������ ��������
	shortName["podk_l_w"] = "pump_l_w.wav";//!<��� ����� ����� ������ ��������
	shortName["podk_l_off"] = "pump_l_off.wav";//!<��� ����� ����� ������ ��������

	shortName["cons_tank_on"] = "consum_tank_on.wav";//!<��� ����� ����� ������ ���������� ����
	shortName["cons_tank_w"] = "consum_tank_w.wav";//!<��� ����� ����� ������ ���������� ����
												   //����������� ����
	shortName["perekr_l"] = "kran_l.wav";//!<��� ����� ����� ������������ �����
	shortName["perekr_r"] = "kran_r.wav";//!<��� ����� ����� ������������ �����
										 //��-50
	shortName["ko50_on"] = "ko50_on.wav";//!<��� ����� ����� KO-50
	shortName["ko50_w"] = "ko50_w.wav";//!<��� ����� ����� KO-50
	shortName["ko50_off"] = "ko50_off.wav";//!<��� ����� ����� KO-50
										   //���
	shortName["skv_on"] = "skv_on.wav";//!<��� ����� ����� ���
	shortName["skv_w"] = "skv_w.wav";//!<��� ����� ����� ���
	shortName["skv_off"] = "skv_off.wav";//!<��� ����� ����� ���
	shortName["skv_harm_29"] = "skv_harm.wav";//!<��� ����� ��������� ��� ��� ��-29
										 //�������� �� ��� � ��
	shortName["runway"] = "driving.wav";//!<��� ����� ����� ����� �������� �� ��� � ��

								 //����������
	shortName["sturm"] = "sturm.wav";//!<��� ����� ����� ������ �����
	shortName["nar8"] = "s8.wav";//!<��� ����� ����� ��� 8
	shortName["nar13"] = "s13.wav";//!<��� ����� ����� ��� 13
	shortName["rocket"] = "rocket.wav";//!<��� ����� ����� ��������� ������
	shortName["bullet0"] = "bullet_1.wav";//!<��� ����� ����� ��������� ������
	shortName["bullet1"] = "bullet_2.wav";//!<��� ����� ����� ��������� ������
	shortName["upk"] = "gun_loop.wav";//!<��� ����� ����� ��������� ���
	shortName["ppu"] = "gun_loop.wav";//!<��� ����� ����� ��������� ���
	shortName["shoot"] = "shoot.wav";//!<��� ����� ����� ��������� ���
	shortName["igla"] = "sturm.wav";//!<��� ����� ����� ������ �����
									//����
	shortName["vint_hi"] = "vint_hi.wav";//!<��� ����� ����� ������ �����
	shortName["vint_hi_avt"] = "vint_hi_avt.wav";//!<��� ����� ����� ������ �����
	shortName["vint_torm"] = "tormoz.wav";//!<��� ����� ����� ������� �����
	shortName["vint_flap"] = "vint_flap.wav";//!<��� ����� ����� ����������� ������� �����
	shortName["vint_flap_hi"] = "vint_flap_hi.wav";//!<��� ����� ����� ����� �� ������ ��������
	shortName["vint_flap_low"] = "vint_flap_lo.wav";//!<
	shortName["vint_flap_A"] = "flap_A.wav";//!<��� ����� ����� ����������� ������� �����
	shortName["vint_flap_B"] = "flap_B.wav";//!<��� ����� ����� ������������� ������� �����
	shortName["vint_flap_C"] = "flap_C.wav";//!<��� ����� ����� ������������� ������� �����
	shortName["vint_swish_on"] = "vint_hi_on.wav";//!<��� ����� ����� ������ �����
	shortName["vint_swish_w"] = "vint_hi_1eng.wav";//!<��� ����� ����� ������ �����
	shortName["vint_swish_w_mg"] = "vint_hi_mg.wav";//!<��� ����� ����� ������ �����
	shortName["vint_swish_w_avt"] = "vint_hi_avt.wav";//!<��� ����� ����� ������ �����
	shortName["beats"] = "beats.wav";//!<��� ����� ����� ������
	shortName["flapping"] = "flapping.wav";//!<��� ����� ����� ???
											//������ �����
	shortName["brake"] = "brake_on.wav";//!<��� ����� ����� ������� �����
	shortName["poff"] = "check_brake.wav";//!<��� ����� ����� ������ ��������
										  //����������
	shortName["crash"] = "crash.wav";//!<��� ����� ����� ������������ � ������������
									 //���
	shortName["nip_tone"] = "nip_tone.wav";//
										   //�������� ����
	shortName["kran_fire_l"] = "kran_fire_l.wav";
	shortName["kran_fire_r"] = "kran_fire_r.wav";
	//�������������
	shortName["girovert_on"] = "girovert_on.wav";//
	shortName["girovert_w"] = "girovert_w.wav";
	//shortName["girovert"] = "girovert_on.txt";
	//�������� �������
	shortName["pstat_on"] = "pstat_on.wav";//
	shortName["pstat_w"] = "pstat_w.wav";//
	shortName["pstat_off"] = "pstat_off.wav";//
											 //���� �����������
	shortName["kran_circle"] = "kran_l.wav";//!<��� ����� ����� ������������ �����
											//������
	shortName["rain"] = "rain.wav";//
								   //������
	shortName["beep"] = "beep.wav";//
								   //������������ ����
	shortName["undefined0_on"] = "undefined0_on.wav";//
	shortName["undefined0_w"] = "undefined0_w.wav";//
	shortName["undefined1_on"] = "undefined1_on.wav";//
	shortName["undefined1_w"] = "undefined1_w.wav";//
	shortName["undefined1_off"] = "undefined1_off.wav";
	//������
	//���
	shortName["pinkNoise"] = "vadd.wav";//
	shortName["landing"] = "landing.wav";//
	shortName["testNoise"] = "testNoise.wav";
	//������
	shortName["BumBum"] = "LF_.wav";
	//�����
	shortName["takeOff"] = "take_off.wav";
	//���� ��� ������� ����� ����
	shortName["shock"] = "shock.wav";
	//�������
	shortName["trim_on"] = "trim_on.wav";
	shortName["trim_off"] = "trim_off.wav";
	//��������
	shortName["frict"] = "brake_on.wav";

	fullName = shortName;

	map<string, string> ::iterator num;
	for (num = fullName.begin(); num != fullName.end(); num++)
	{
		(*num).second = pathToFile + (*num).second;
	}
}

void Helicopter::setParam(string model)
{
	modelName = model;

	setPath(modelName + "/");

	setBufferMap();

	if (model == "mi_8_mtv5")
	{
		//���������		
		engTurnoverMg = 75;
		engTurnoverAvt = 88;
		redTurnoverMg1 = 50;
		redTurnoverMg2 = 63;
		redTurnoverAvt = 96;
		//��������� ���������		
		vsuFactor = 1/*���*/;
		vsuHpFactor = 0.06/*��� ��*/;
		engFactor = 1/*��*/;
		engHpFactor = 0.35/*�� ��*/;
		redFactor = 1/*��������*/;
		accumFactor = 0.1/*�����*/;
		ptsFactor = 0.18/*���*/;
		ptsToneFactor = 0.25/*��� ���*/;
		tr36Factor = 0.15/*��36*/;
		tr115Factor = 0.15/*��115*/;
		pumpLeftFactor = 0.08/*���� �*/;
		pumpRightFactor = 0.12/*���� �*/;
		cutoffCraneFactor = 0.18/*������*/;
		ko50Factor = 0.5/*��-50*/;
		runwayFactor = 1/*���*/;
		rocketNar8Factor = 1/*���8*/;
		rocketNar13Factor = 1/*���13*/;
		rocketHitFactor = 0.8/*��������� ������*/;
		upkFactor = 1/*���*/;
		vintSwishFactor = 0.3/*���� ����*/;
		vintBrakeFactor = 0.2/*���� ������*/;
		vintFlapFactor = 0.794/*���� ������*/;
		chassisBrakePumpFactor = 0.03/*������ �����*/;
		chassisBrakeReleaseFactor = 0.03/*����� ��������*/;
		consumTankFactor = 0.25/*��������� ���*/;
		rainFactor = 0.5/*�����*/;
		vadd = 1/*���������� �������*/;
	}
	else if (model == "mi_8_amtsh")
	{
		//���������		
		engTurnoverMg = 75;
		engTurnoverAvt = 88;
		redTurnoverMg1 = 50;
		redTurnoverMg2 = 63;
		redTurnoverAvt = 96;
		//��������� ���������		
		vsuFactor = 1/*���*/;
		vsuHpFactor = 0.06/*��� ��*/;
		engFactor = 1/*��*/;
		engHpFactor = 0.35/*�� ��*/;
		redFactor = 1/*��������*/;
		accumFactor = 0.1/*�����*/;
		ptsFactor = 0.18/*���*/;
		ptsToneFactor = 0.25/*��� ���*/;
		tr36Factor = 0.15/*��36*/;
		tr115Factor = 0.15/*��115*/;
		pumpLeftFactor = 0.08/*���� �*/;
		pumpRightFactor = 0.12/*���� �*/;
		cutoffCraneFactor = 0.18/*������*/;
		ko50Factor = 0.5/*��-50*/;
		runwayFactor = 0.75/*���*/;
		rocketNar8Factor = 1/*���8*/;
		rocketNar13Factor = 1/*���13*/;
		rocketHitFactor = 0.8/*��������� ������*/;
		upkFactor = 1/*���*/;
		vintSwishFactor = 0.15/*���� ����*/;
		vintBrakeFactor = 0.2/*���� ������*/;
		vintFlapFactor = 0.794/*���� ������*/;
		chassisBrakePumpFactor = 0.03/*������ �����*/;
		chassisBrakeReleaseFactor = 0.03/*����� ��������*/;
		consumTankFactor = 0.25/*��������� ���*/;
		rainFactor = 0.5/*�����*/;
		vadd = 1/*���������� �������*/;
	}
	else if (model == "mi_26")
	{
		//���������		
		engTurnoverMg = 69;
		engTurnoverAvt = 84;
		redTurnoverMg1 = 37;
		redTurnoverMg2 = 47;
		redTurnoverAvt = 85;
		//��������� ���������
		vsuFactor = 0.35/*���*/;
		vsuHpFactor = 0.04/*��� ��*/;
		engFactor = 0.446/*��*/;//-7
		engHpFactor = 0.11/*�� ��*/;
		redFactor = 0.35/*��������*/;
		tr115Factor = 0.08/*��115*/;
		skvFactor = 0.21/*���*/;
		runwayFactor = 0.35/*���*/;
		//rocketHitFactor = 0.8/*��������� ������*/;
		vintSwishFactor = 0.55/*���� ����*/;
		vintBrakeFactor = 0.12/*���� ������*/;
		vintFlapFactor = 0.4/*���� ������*/;
		chassisBrakePumpFactor = 0.03/*������ �����*/;
		chassisBrakeReleaseFactor = 0.03/*����� ��������*/;
		nipFactor = 0.0875/*���*/;
		fireCraneFactor = 0.0875/*�������� ����*/;
		girovertFactor = 0.105/*�������������*/;
		pumpStationFactor = 0.05/*�������� �������*/;
		consumTankFactor = 0.17/*��������� ���*/;
		rainFactor = 0.5/*�����*/;
		//vadd = 0.5/*���������� �������*/;
	}
	else if (model == "mi_28")
	{
		//���������		
		engTurnoverMg = 73;
		engTurnoverAvt = 86;
		redTurnoverMg1 = 48;
		redTurnoverMg2 = 60;
		redTurnoverAvt = 93;
		//��������� ���������
		vsuFactor = 0.08/*���*/;
		vsuHpFactor = 0.6/*��� ��*/;
		vsuCraneFactor = 0.8/*��� ����*/;
		engFactor = 0.446/*��*/;
		engHpFactor = 0.35/*�� ��*/;
		redFactor = 0.446/*��������*/;
		accumFactor = 0.1/*�����*/;
		ptsToneFactor = 0.25/*��� ���*/;
		tr115Factor = 0.15/*��115*/;
		skvFactor = 0.708/*���*/;
		runwayFactor = 1/*���*/;
		rocketSturmFactor = 1/*�����*/;
		rocketNar8Factor = 1/*���8*/;
		rocketNar13Factor = 1/*���13*/;
		rocketHitFactor = 0.8/*��������� ������*/;
		ppuFactor = 1/*���*/;
		vintBrakeFactor = 0.6/*���� ������*/;
		vintFlapFactor = 0.5/*���� ������*/;
		vintSwishFactor = 0.63;
		chassisBrakePumpFactor = 0.03/*������ �����*/;
		chassisBrakeReleaseFactor = 0.03/*����� ��������*/;
		fireCraneFactor = 0.9/*�������� ����*/;
		pumpStationFactor = 0.0725/*�������� �������*/;
		rainFactor = 0.5/*�����*/;
		buzzerFactor = 0.9 /*beep*/;
		fenFactor = 0.1 /*undefined0*/;
		undefinedFactor = 0.2 /*undefined1*/;
		rocketIglaFactor = 1 /*����*/;
		vadd = 1/*���������� �������*/;
	}
	else if (model == "ka_226")
	{
		//���������		
		engTurnoverMg = 61;
		engTurnoverAvt = 79;
		redTurnoverMg1 = 49;
		redTurnoverMg2 = 62;
		redTurnoverAvt = 99;
		//��������� ���������
		engFactor = 0.398/*��*/;
		engHpFactor = 0.141/*�� ��*/;
		redFactor = 0.398/*��������*/;
		accumFactor = 0.100/*�����*/;
		pumpLeftFactor = 0.100/*���� �*/;
		pumpRightFactor = 0.100/*���� �*/;
		cutoffCraneFactor = 0.126/*������*/;
		runwayFactor = 1/*���*/;
		vintBrakeFactor = 1/*���� ������*/;
		vintFlapFactor = 1/*���� ������*/;
		vintSwishFactor = 1/*���� �����*/;
		chassisBrakePumpFactor = 0.178/*������ �����*/;
		chassisBrakeReleaseFactor = 0.178/*����� ��������*/;
		rainFactor = 1/*�����*/;
		circlingCraneFactor = 0.126 /*���� �����������*/;
		vadd = 1/*���������� �������*/;
	}
	else if (model == "ansat")
	{
		//���������		
		engTurnoverMg = 65;
		engTurnoverAvt = 73;
		redTurnoverMg1 = 65;
		redTurnoverMg2 = 65;
		redTurnoverAvt = 100;
		//��������� ���������
		engFactor = 0.63/*��*/;//-4
		engHpFactor = 0.141/*�� ��*/;
		redFactor = 0.63/*��������*/;//-4
		accumFactor = 0.089/*�����*/;//-21
		vintBrakeFactor = 0.015/*���� ������*/;
		vintFlapFactor = 1/*���� ������*/;
		vintSwishFactor = 1;//
		chassisBrakePumpFactor = 0.178/*������ �����*/;
		chassisBrakeReleaseFactor = 0.178/*����� ��������*/;
		rainFactor = 1/*�����*/;
		vadd = 1/*���������� �������*/;
		runwayFactor = 1/*���*/;
		undefinedFactor = 1; /*��1*/
	}
	else if (model == "ka_27")
	{
		//���������		
		engTurnoverMg = 75;
		engTurnoverAvt = 85;
		redTurnoverMg1 = 44;
		redTurnoverMg2 = 60;
		redTurnoverAvt = 90;
		//��������� ���������		
		vsuFactor = 0.05/*���*/;//-26
		vsuHpFactor = 0.25/*��� ��*/;//-12
		vsuCraneFactor = 0.354/*��� ����*/;//-9
		engFactor = 1/*��*/; //0
		engHpFactor = 0.334/*�� ��*/;//-9.5
		redFactor = 0.794/*��������*/; //-2
		vpryam = 0.199/*��*/;//-14
		cutoffCraneFactor = 0.354/*������*/;//-9
		vintBrakeFactor = 0.2/*���� ������*/;
		vintFlapFactor = 0.5/*���� ������*/;
		chassisBrakePumpFactor = 0.1/*������ �����*/;
		chassisBrakeReleaseFactor = 0.1/*����� ��������*/;
		undefinedFactor = 0.25; /*��1*///-12
		runwayFactor = 0.63/*���*/;
		vadd = 1/*���������� �������*/;
		skvFactor = 1;

		rainFactor = 0.5/*�����*/;

		//ptsToneFactor = 0.25/*��� ���*/;
		//vintSwishFactor = 0.5/*���� ����*/;
		fireCraneFactor = 0.354/*�������� ����*/;
	}
	else if (model == "ka_29")
	{
		//���������		
		engTurnoverMg = 75;
		engTurnoverAvt = 85;
		redTurnoverMg1 = 44;
		redTurnoverMg2 = 60;
		redTurnoverAvt = 90;
		//��������� ���������		
		vsuFactor = 0.237/*���*/;//-12.5
		vsuHpFactor = 0.25/*��� ��*/;//-12
		vsuCraneFactor = 0.354/*��� ����*/;//-9
		engFactor = 1/*��*/; //0
		engHpFactor = 0.334/*�� ��*/;//-9.5
		redFactor = 0.794/*��������*/; //-2
		vpryam = 0.199/*��*/;//-14
		cutoffCraneFactor = 0.354/*������*/;//-9
		vintBrakeFactor = 0.5/*���� ������*/;
		vintFlapFactor = 0.5/*���� ������*/;
		chassisBrakePumpFactor = 0.1/*������ �����*/;
		chassisBrakeReleaseFactor = 0.1/*����� ��������*/;
		undefinedFactor = 0.25; /*��1*///-12
		runwayFactor = 0.63/*���*/;
		vadd = 1/*���������� �������*/;
		skvFactor = 1;
		trim = 0.28;
		//frict = 1;

		rocketSturmFactor = 1/*�����*/;
		rocketNar8Factor = 1/*���8*/;
		rocketNar13Factor = 1/*���13*/;
		rocketHitFactor = 0.8/*��������� ������*/;
		upkFactor = 1/*���*/;
		ppuFactor = 1/*���*/;

		rainFactor = 0.5/*�����*/;

		fireCraneFactor = 0.354/*�������� ����*/;
	}
	else
	{
		cout << " Unknown argument" << endl;
		throw 0;
	}

	//
	redLengthOn = getLengthWAV(fullName["red_on_w"]);
	redLengthOff = getLengthWAV(fullName["red_off_w"]);
	redLengthMg1 = getLengthWAV(fullName["red_w_w"]);
	redLengthMg2 = getLengthWAV(fullName["red_w_mg_w"]);
	redLengthAvt = getLengthWAV(fullName["red_w_avt_w"]);
	//
	engLengthOn = getLengthWAV(fullName["eng_on_w"]);
	engLengthOff = getLengthWAV(fullName["eng_off_w"]);
	engLengthHpOn = getLengthWAV(fullName["eng_on_hp_w"]);
	engLengthMg = getLengthWAV(fullName["eng_w_w"]);
	engLengthWAavt = getLengthWAV(fullName["eng_w_avt_w"]);
	engLengthHpW = getLengthWAV(fullName["eng_w_hp_w"]);
	engLengthHpOff = getLengthWAV(fullName["eng_off_hp_w"]);
	//
	vsuLengthOn = getLengthWAV(fullName["vsu_on"]);
	vsuLengthHpOn = getLengthWAV(fullName["vsu_hp_on"]);
	vsuLengthOff = getLengthWAV(fullName["vsu_off"]);
	vsuLengthHpOff = getLengthWAV(fullName["vsu_hp_off"]);
	//
	redFunctionOn = getVectorFromFile(fullName["red_on"]);
	redFunctionOnSwap = redFunctionOn;
	redFunctionOff = getVectorFromFile(fullName["red_off"]);
	redFunctionOffSwap = redFunctionOff;
	//
	engFunctionOn = getVectorFromFile(fullName["eng_on"]);
	engFunctionOnSwap = engFunctionOn;
	engFunctionOff = getVectorFromFile(fullName["eng_off"]);
	engFunctionOffSwap = engFunctionOff;

	for (auto &swp : redFunctionOnSwap)
	{
		swp.swap();
	}
	for (auto &swp : redFunctionOffSwap)
	{
		swp.swap();
	}
	for (auto &swp : engFunctionOnSwap)
	{
		swp.swap();
	}
	for (auto &swp : engFunctionOffSwap)
	{
		swp.swap();
	}
}

void Helicopter::setBufferMap()
{
	buffers = new ALuint[fullName.size() * 2];
	vector<double> channel = { 1,1,0,0,0,0,0 };

	int i = 0;
	for (auto it : fullName)
	{
		if (it.first == "eng_on_w" ||
			it.first == "eng_w_w" ||
			it.first == "eng_off_w" ||
			it.first == "eng_on_hp_w" ||
			it.first == "eng_w_hp_w" ||
			it.first == "eng_off_hp_w" ||
			it.first == "eng_w_avt_w" ||
			it.first == "eng_on_avt_w" ||
			it.first == "eng_avt_mg_w")
		{
			alGenBuffers(1, &buffers[i]);
			channel = { 1,-1,0,0,0,0,0 };
			setBuffer(buffers[i], it.second, channel);
			bufferMap[it.second + "l"] = buffers[i];
			i++;

			alGenBuffers(1, &buffers[i]);
			channel = { 0,2,0,0,0,0,0 };
			setBuffer(buffers[i], it.second, channel);
			bufferMap[it.second + "r"] = buffers[i];
			i++;
		}
		else if (it.first == "vsu_on" ||
			it.first == "vsu_w" ||
			it.first == "vsu_off" ||
			it.first == "vsu_hp_on" ||
			it.first == "vsu_hp_w" ||
			it.first == "vsu_hp_off")
		{
			alGenBuffers(1, &buffers[i]);
			if (modelName == "mi_26")
			{
				channel = { 0,0,1,1,0,0,0 };
			}
			else
			{
				channel = { 1,1,0,0,0,0,0 };
			}
			setBuffer(buffers[i], it.second, channel);
			bufferMap[it.second] = buffers[i];
			i++;
		}
		else if (it.first == "red_on_w" ||
			it.first == "red_w_w" ||
			it.first == "red_on_mg_w" ||
			it.first == "red_w_mg_w" ||
			it.first == "red_mg_avt_w" ||
			it.first == "red_w_avt_w" ||
			it.first == "red_avt_mg_w" ||
			it.first == "red_w_avt_fly" ||
			it.first == "red_off_w")
		{
			alGenBuffers(1, &buffers[i]);
			channel = { 1,1,0,0,0,0,0 };
			setBuffer(buffers[i], it.second, channel);
			bufferMap[it.second] = buffers[i];
			i++;
		}
	}
	bufferMap["NULL"] = -1;//��������� ��������
}

Helicopter::Helicopter()
{

}

Helicopter::~Helicopter()
{

}

