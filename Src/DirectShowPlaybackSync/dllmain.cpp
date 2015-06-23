// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <streams.h>
#include <olectl.h>
#include <initguid.h>
#include "PlaybackSyncFilter.h"

extern "C" BOOL WINAPI DllEntryPoint(HINSTANCE, ULONG, LPVOID);

BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  dwReason,
	LPVOID lpReserved)
{
	return DllEntryPoint((HINSTANCE)(hModule), dwReason, lpReserved);
}

STDAPI DllRegisterServer()
{
	while (!IsDebuggerPresent())
		Sleep(1000);
	DebugBreak();
	return AMovieDllRegisterServer2(TRUE);
}


STDAPI DllUnregisterServer()
{
	return AMovieDllRegisterServer2(FALSE);
}

const AMOVIESETUP_FILTER sudBallax =
{
	&CLSID_PlaybackSyncFilter,
	L"Sync filter",
	MERIT_DO_NOT_USE,
	0,
	NULL
};

CFactoryTemplate g_Templates[] = {
	{ L"Bouncing Ball"
	, &CLSID_PlaybackSyncFilter
	, PlaybackSyncFilter::CreateInstance
	, NULL
	, &sudBallax }
};
int g_cTemplates = sizeof(g_Templates) / sizeof(g_Templates[0]);