#include "BMDSwitcher.h"
#include "BMDSwitcherInputIterator.h"
static inline bool	operator== (const REFIID& iid1, const REFIID& iid2)
{ 
	return CFEqual(CFUUIDCreateFromUUIDBytes(NULL,iid1), CFUUIDCreateFromUUIDBytes(NULL,iid2));
}

HRESULT STDMETHODCALLTYPE CreateIterator(REFIID iid, LPVOID* ppv)
{
	if (!ppv)
		return E_POINTER;
	
	if (riid == IID_IBMDSwitcherInputIterator)
	{
		IBMDSwitcherInputIterator* inputIterator = new IBMDSwitcherInputIterator();
		inputIterator->QueryInterface(riid, inputIterator);
		*ppv = inputIterator;
		return S_OK;
	}
	*ppv = NULL;
	return E_NOINTERFACE;
}
// HRESULT STDMETHODCALLTYPE AddCallback(IBMDSwitcherCallback* callback);
// HRESULT STDMETHODCALLTYPE RemoveCallback(IBMDSwitcherCallback* callback);
// HRESULT STDMETHODCALLTYPE SetFlag(BMDSwitcherPropertyID propertyID, bool value);
// HRESULT STDMETHODCALLTYPE GetFlag(BMDSwitcherPropertyID propertyID, bool* value);
// HRESULT STDMETHODCALLTYPE SetInt(BMDSwitcherPropertyID propertyID, int64_t value);
// HRESULT STDMETHODCALLTYPE GetInt(BMDSwitcherPropertyID propertyID, int64_t* value);
// HRESULT STDMETHODCALLTYPE SetFloat(BMDSwitcherPropertyID propertyID, double value);
// HRESULT STDMETHODCALLTYPE GetFloat(BMDSwitcherPropertyID propertyID, double* value);
// HRESULT STDMETHODCALLTYPE SetString(BMDSwitcherPropertyID propertyID, CFStringRef value);
// HRESULT STDMETHODCALLTYPE GetString(BMDSwitcherPropertyID propertyID, CFStringRef* value);

#pragma mark - IUnknown methods

HRESULT STDMETHODCALLTYPE IBMDSwitcher::QueryInterface(REFIID riid, LPVOID *ppv)
{
  if (!ppv)
    return E_POINTER;

  if (riid == IID_IBMDSwitcher)
  {
    *ppv = static_cast<IBMDSwitcher*>(this);
    AddRef();
    return S_OK;
  }


  if (CFEqual(CFUUIDCreateFromUUIDBytes(NULL,riid), IUnknownUUID))
  {
    *ppv = static_cast<IUnknown*>(this);
    AddRef();
    return S_OK;
  }

  *ppv = NULL;
  return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE IBMDSwitcher::AddRef()
{
  return ++mRefCount;
}

ULONG STDMETHODCALLTYPE IBMDSwitcher::Release()
{
  ULONG refCount = --mRefCount;

  if (refCount == 0)
    delete this;

  return refCount;
}
