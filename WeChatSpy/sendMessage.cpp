#include "pch.h"
#include <Windows.h>
#include <stdio.h>
#include "utils.h"

//������Ϣ���ݽṹ��
struct wxStr
{
	wchar_t * pStr;
	int strLen;
	int strLen2;
};

//�����ı���Ϣ
VOID sendTextMessage(wchar_t * wxid, wchar_t * at_wxid, wchar_t * message)
{
	//������Ϣcall, ƫ�Ƶ�ַ��0x32A760
	DWORD sendCall = getWechatWin() + 0x32A760;

	//��װ��Ҫ�����ݸ�ʽ
	//΢��id
	wxStr pWxid = { 0 };
	pWxid.pStr = wxid;
	pWxid.strLen = wcslen(wxid);
	pWxid.strLen2 = wcslen(wxid) * 2;


	wxStr at_pWxid = { 0 };
	char * asmAt_Wxid = 0x0;  //@΢��id��ַ��ָ��
	//if (wcslen(at_wxid)!=0)
	//{
	//	//΢��@id
	//	at_pWxid.pStr = at_wxid;
	//	at_pWxid.strLen = wcslen(at_wxid);
	//	at_pWxid.strLen2 = wcslen(at_wxid) * 2;
	//	asmAt_Wxid = (char *)&at_pWxid.pStr;  //@΢��id��ַ��ָ��
	//}

	//΢���ı�����
	wxStr pMessage = { 0 };
	pMessage.pStr = message;
	pMessage.strLen = wcslen(message);
	pMessage.strLen2 = wcslen(message) * 2;

	/*-------΢�ŷ����ı���Ϣcall������-------------
		mov edx, dword ptr ss : [ebp - 0x50]      ; �����ĸ���΢��id����Ⱥid��ַָ��
		lea eax, dword ptr ds : [ebx + 0x28]
		push 0x1                                  ; 0x1
		push eax                                   ; 0���������Ⱥ��@�ˣ�����@���Ǹ��˵�id��ַ��ָ�롣
		push ebx                                  ; ��Ϣ���ݵ�ַָ��
		lea ecx, dword ptr ss : [ebp - 0x8DC]     ; 0x8DC
		call WeChatWi.5A40A760                    ; ΢�ŷ�����Ϣcall
		add esp, 0xC                              ; ƽ���ջ�����ǲ������д���ȥƽ�⣬��΢�Ż������
	*/
	char * asmWxid = (char *)&pWxid.pStr;   //΢��id��ַ��ָ��
	char * asmMessage = (char *)&pMessage.pStr;  //��Ϣ���ݵ�ַ��ָ��

	char buff[0x8DC] = { 0 };
	//char buff2[0x28] = { 0 };

	__asm {
		mov edx, asmWxid
		//lea eax, buff2
		mov eax, asmAt_Wxid
		push 0x1
		push eax
		mov ebx, asmMessage
		push ebx
		lea ecx, buff
		call sendCall
		add esp, 0xC
	}
}