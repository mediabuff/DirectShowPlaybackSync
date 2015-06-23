#pragma once

#include <streams.h>
#include "PlaybackSyncInterface.h"

class PlaybackSyncFilterDummyStream;

class PlaybackSyncFilter : public CBaseFilter, public IPlaybackSync
{
public:

	PlaybackSyncFilter(LPUNKNOWN lpunk, HRESULT *phr);
	~PlaybackSyncFilter();

	int GetPinCount();
	CBasePin *GetPin(int n);

	CCritSec * GetStateLock();

	STDMETHOD(GetStartReferenceTime)(REFERENCE_TIME* time);

	DECLARE_IUNKNOWN

	STDMETHOD(NonDelegatingQueryInterface)(REFIID riid, __deref_out void **ppv);

	static CUnknown * WINAPI CreateInstance(LPUNKNOWN lpunk, HRESULT *phr);

private:

	CCritSec _stateLock;
	PlaybackSyncFilterDummyStream* _dummyStream;

};

