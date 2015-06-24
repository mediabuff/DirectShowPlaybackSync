#include "stdafx.h"
#include "PlaybackSyncFilter.h"

class PlaybackSyncFilterDummyStream : public CBaseOutputPin
{
public:

	PlaybackSyncFilterDummyStream(PlaybackSyncFilter* source, HRESULT *phr) : CBaseOutputPin(L"Dummy output", source, source->GetStateLock(), phr, L"Dummy output")
	{

	}

	HRESULT CheckMediaType(const CMediaType *)
	{
		return E_FAIL;
	}

	// override this to set the buffer size and count. Return an error
	// if the size/count is not to your liking.
	// The allocator properties passed in are those requested by the
	// input pin - use eg the alignment and prefix members if you have
	// no preference on these.
	HRESULT DecideBufferSize(IMemAllocator * pAlloc, __inout ALLOCATOR_PROPERTIES * ppropInputRequest)
	{
		return E_FAIL;
	}
};

PlaybackSyncFilter::PlaybackSyncFilter(LPUNKNOWN lpunk, HRESULT *phr) 
	: CBaseFilter("Sync filter", lpunk, &_stateLock, CLSID_PlaybackSyncFilter, phr), _clock(L"Sync filter clock", lpunk, phr)
{
	_dummyStream = new PlaybackSyncFilterDummyStream(this, phr);
	_clock.AddRef();
}

PlaybackSyncFilter::~PlaybackSyncFilter()
{
	delete _dummyStream;
	_dummyStream = NULL;
}

int PlaybackSyncFilter::GetPinCount()
{
	return  1;
}

CBasePin *PlaybackSyncFilter::GetPin(int n)
{
	if (n == 0)
		return _dummyStream;

	return NULL;
}

CCritSec* PlaybackSyncFilter::GetStateLock()
{
	return &_stateLock;
}

HRESULT PlaybackSyncFilter::GetStartReferenceTime(REFERENCE_TIME* time)
{
	*time = m_tStart;
	return S_OK;
}

HRESULT PlaybackSyncFilter::NonDelegatingQueryInterface(REFIID riid, __deref_out void **ppv)
{
	if (riid == IID_IPlaybackSync)
	{
		return GetInterface(static_cast<IPlaybackSync*>(this), ppv);
	}

	if (riid == IID_IPersist || riid == IID_IAMClockAdjust || riid == IID_IReferenceClock || riid == IID_IReferenceClockTimerControl)
	{
		return _clock.QueryInterface(riid, ppv);
	}
	
	return CBaseFilter::NonDelegatingQueryInterface(riid, ppv);
}

CUnknown * WINAPI PlaybackSyncFilter::CreateInstance(LPUNKNOWN lpunk, HRESULT *phr)
{
	ASSERT(phr);

	CUnknown *punk = new PlaybackSyncFilter(lpunk, phr);
	if (punk == NULL)
	{
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return punk;
}