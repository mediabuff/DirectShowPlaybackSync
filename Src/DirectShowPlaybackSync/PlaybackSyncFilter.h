#pragma once

#include <streams.h>

class PlaybackSyncFilter : CBaseFilter
{
public:

	PlaybackSyncFilter(LPUNKNOWN lpunk, HRESULT *phr);
	~PlaybackSyncFilter();

	int GetPinCount();
	CBasePin *GetPin(int n);

	static CUnknown * WINAPI CreateInstance(LPUNKNOWN lpunk, HRESULT *phr);

private:

	CCritSec _stateLock;

};

