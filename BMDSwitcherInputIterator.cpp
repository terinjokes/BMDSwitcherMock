#include "BMDSwitcherInputIterator.h"
static inline bool	operator== (const REFIID& iid1, const REFIID& iid2)
{
  return CFEqual(CFUUIDCreateFromUUIDBytes(NULL,iid1), CFUUIDCreateFromUUIDBytes(NULL,iid2));
}
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