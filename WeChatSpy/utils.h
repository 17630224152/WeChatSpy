#pragma once
#include "pch.h"
#include<WINSOCK2.H>

//��ȡwechatWinģ���ַ
DWORD getWechatWin();
//��ȡ΢�Ž���pid
VOID get_process_pid(wchar_t * processPid);

//��wchat_t��������ת��CHAR��������
char* UnicodeToChar(const wchar_t* unicode);
//Char��������תwchat_t��������
VOID CharToUnicode(CHAR * charList, wchar_t * wchar_t_list);
// ��DWORD(��int)���ͱ���ת��wchat_t��������
VOID DWORDToUnicode(DWORD value, wchar_t * wchar_t_list);