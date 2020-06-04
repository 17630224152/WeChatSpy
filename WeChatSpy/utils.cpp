// ����һЩ���õĹ��ߺ���
#include "pch.h"
#include <stdlib.h>
#include <WINSOCK2.H>
#include <stdio.h>

//��ȡwechatWinģ���ַ
DWORD getWechatWin()
{
	return (DWORD)LoadLibrary(L"WeChatWin.dll");
}

////��ȡ΢�Ž���pid
//VOID get_process_pid(wchar_t * processPid)
//{
//	CHAR pid_str[0x100] = { 0 };
//	DWORD PID = GetCurrentProcessId();
//	// ��DWORD(��int)����ת��wchat_t����
//	_itoa_s(PID, pid_str, 10);
//	swprintf(processPid, sizeof(processPid), L"%hs", pid_str);
//}
//��wchat_t��������ת��CHAR��������
char* UnicodeToChar(const wchar_t* unicode)
{
	int len;
	len = WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
	char *szCHAR = (char*)malloc(len + 1);
	memset(szCHAR, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, unicode, -1, szCHAR, len, NULL, NULL);
	return szCHAR;
}

/************************************************************************
*int CN2Unicode(char *input,wchar_t *output)
*���ܣ������ַ�ת��Ϊunicode�ַ�
*������input���������ĵ��ַ�����output��Unicode�ַ���
*
*************************************************************************/
int CN2Unicode(char *input, wchar_t *output)
{
	int len = strlen(input);

	//wchar_t *out = (wchar_t *) malloc(len*sizeof(wchar_t));

	len = MultiByteToWideChar(CP_ACP, 0, input, -1, output, MAX_PATH);

	return 1;
}

//UTF8ת��Unicode
wchar_t * UTF8ToUnicode(const char* str)
{
	int    textlen = 0;
	wchar_t * result;
	textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	result = (wchar_t *)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);
	return    result;
}

//Char��������תwchat_t��������
//VOID CharToUnicode(CHAR * charList, wchar_t * wchar_t_list)
//{
//	swprintf(wchar_t_list, sizeof(wchar_t_list), L"%hs", charList);
//}

// ��DWORD(��int)���ͱ���ת��wchat_t��������
VOID DWORDToUnicode(DWORD value, wchar_t * wchar_t_list)
{
	CHAR char_str[0x100] = { 0 };
	_itoa_s(value, char_str, 10);
	swprintf(wchar_t_list, sizeof(wchar_t_list), L"%hs", char_str);
}

