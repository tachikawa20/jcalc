#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <string>

using namespace std;

wstring version = L"1.0b";
wstring lang = L"���{��";

const char* loc = "ja_JP.UTF-8";

int LANG_NORMAL  = 0;
int LANG_TABBED  = 1;
int LANG_ERROR   = 2;
int LANG_OK      = 3;
int LANG_DICTYPE = 4;
int LANG_WRONGTP = 5;

//Translations
//responses
wstring MSG00_INVALIDCOM = L"�Ԉ�����R�}���h";
wstring MSG01_NUMCHECKER = L"�����݂̂���͂��ĉ�����";
wstring MSG02_BADMEMFUNC = L"�Ԉ�����������֐�";
wstring MSG03_MEMCLEARED = L"���������N���A����܂����B";
wstring MSG04_GOODBYEAPP = L"�A�v���P�[�V�����͐���ɏI�����܂����B";
wstring MSG05_UNKNOWNTYP = L"�s���ȃ^�C�v";
wstring MSG06_LACKOFPARA = L"�p�����[�^���s�����Ă��܂�";
wstring MSG07_NUMTOOLONG = L"�������������܂�";

//dictionary
wstring DC000_TITLE00000 = L"�R�}���h���X�g";
wstring DC000_TITLE00001 = L"��{�I�ȉ��Z";
wstring DC000_TITLE00002 = L"�O�p�@";
wstring DC000_TITLE00003 = L"�G��";

wstring DC001_ADDOPABOUT = L"add [x1] [x2] [x3] ...  -> �������ϐ���������܂� (1 + 1 + 1)";
wstring DC001_SUBOPABOUT = L"sub [x1] [x2] [x3] ...  -> �������ϐ��������܂� (1 - 1 - 1)�A ��Ԃ̐����͂�������";
wstring DC001_MULOPABOUT = L"mul [x1] [x2] [x3] ...  -> �������ϐ��������܂� (1 * 1 * 1)";
wstring DC001_DIVOPABOUT = L"div [x1] [x2] [x3] ...  -> �������ϐ�������܂� (1 / 1 / 1)";
wstring DC001_POWOPABOUT = L"pow [x] [y]             -> ��p (x ^ y �� 3 ^ 2 = 9)";
wstring DC001_RTOPRABOUT = L"rt  [x] [y]             -> �`���� (x ^ (1 / y)";

wstring DC001_SINOPABOUT = L"sin  [�^�C�v] [x]         -> �p�x�̐������v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (deg)�A [�^�C�v] = deg, rad or gra";
wstring DC001_COSOPABOUT = L"cos  [�^�C�v] [x]         -> �p�x�̗]�����v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (deg)�A [�^�C�v] = deg, rad or gra";
wstring DC001_TANOPABOUT = L"tan  [�^�C�v] [x]         -> �p�x�̐��ڂ��v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (deg)�A [�^�C�v] = deg, rad or gra";
wstring DC001_ASINPABOUT = L"asin [�^�C�v] [x]         -> �p�x�̃A�[�N�T�C�����v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (deg)�A [�^�C�v] = deg, rad or gra";
wstring DC001_ACOSPABOUT = L"acos [�^�C�v] [x]         -> �p�x�̃A�[�N�R�T�C�����v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (deg)�A [�^�C�v] = deg, rad or gra";
wstring DC001_ATANPABOUT = L"atan [�^�C�v] [x]         -> �p�x�̃A�[�N�^���W�F���g���v�Z���܂��B �f�t�H���g�̃^�C�v�͓x�ł� (rad)�A [�^�C�v] = deg, rad or gra";

wstring DC001_PRCVTTOOLS = L"cvt [type1] [type2] [x] -> �L���@�Ԃŕϊ����܂��B �^�C�v�ɂ́A16�i���̏ꍇ�́uhex�v�A10�i���̏ꍇ�́udec�v�A8�i���̏ꍇ�́uoct�v�A2�i���̏ꍇ�́ubin�v���܂܂�܂��B";

//about
wstring VER00_AUTHORWHAT = L"by tachikawa20";
wstring VER01_LICENSEWHO = L"GPL v3���C�Z���X�ɂ���ĕی삳��Ă��܂��B";
wstring VER02_RELEASEDAT = L"2020�N11��";
wstring VER03_MOTTOABOUT = L"�ő�̌݊�����ڎw���Ă��܂��B�����B";

void changelang(const char* loc)
{
	setlocale(LC_ALL, loc);
}

void printlang(int type, wstring line = L"", vector<string> com = {}, int i = 1)
{
	if (type == LANG_NORMAL)
	{
		wcout << line << endl;
	}
	else if (type == LANG_TABBED)
	{
		wcout << "	" << line << endl;
	}
	else if (type == LANG_ERROR)
	{
		wcout << "	? " << line << endl;
	}
	else if (type == LANG_OK)
	{
		wcout << "	OK." << endl;
	}
	else if (type == LANG_DICTYPE)
	{
		wcout << " " << line << endl;
	}
	else if (type == LANG_WRONGTP)
	{
		wcout << "	? " << MSG05_UNKNOWNTYP << " \"";
		cout << com[i] << "\"" << endl;
	}
}

void printspc(int spaceNumber = 1)
{
	for (int i = 1; i <= spaceNumber; i++)
	{
		wcout << "" << endl;
	}
}

void printhead(wstring line)
{
	printspc();
	printlang(LANG_DICTYPE, line);
	printspc();
}

void printdic(int page = 0)
{
	if (page == 0)
	{
		wcout << L"JCALC " << version << L" - [" << lang << L"] " << DC000_TITLE00000 << endl;

		printhead(DC000_TITLE00001);

		printlang(LANG_TABBED, DC001_ADDOPABOUT);
		printlang(LANG_TABBED, DC001_SUBOPABOUT);
		printlang(LANG_TABBED, DC001_MULOPABOUT);
		printlang(LANG_TABBED, DC001_DIVOPABOUT);
		printlang(LANG_TABBED, DC001_POWOPABOUT);
		printlang(LANG_TABBED, DC001_RTOPRABOUT);
		
		printhead(DC000_TITLE00002);
		
		printlang(LANG_TABBED, DC001_SINOPABOUT);
		printlang(LANG_TABBED, DC001_COSOPABOUT);
		printlang(LANG_TABBED, DC001_TANOPABOUT);
		printlang(LANG_TABBED, DC001_ASINPABOUT);
		printlang(LANG_TABBED, DC001_ACOSPABOUT);
		printlang(LANG_TABBED, DC001_ATANPABOUT);
		
		printhead(DC000_TITLE00003);

		printlang(LANG_TABBED, DC001_PRCVTTOOLS);
		printspc();
	}
}

void printabout()
{
	printspc();
	wcout << L"    JCALC " << version << L" - [" << lang << L"] " << endl;
	printlang(LANG_TABBED, VER00_AUTHORWHAT);
	printlang(LANG_TABBED, VER01_LICENSEWHO);
	printlang(LANG_TABBED, VER02_RELEASEDAT);
	printspc();
	printlang(LANG_TABBED, VER03_MOTTOABOUT);
	printspc();
}

#endif