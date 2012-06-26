#include "BMDSwitcherDiscovery.h"
static inline bool	operator== (const REFIID& iid1, const REFIID& iid2)
{ 
	return CFEqual(CFUUIDCreateFromUUIDBytes(NULL,iid1), CFUUIDCreateFromUUIDBytes(NULL,iid2));
}

HRESULT STDMETHODCALLTYPE IBMDSwitcherDiscovery::ConnectTo(CFStringRef deviceAddress, IBMDSwitcher** switcherDevice, BMDSwitcherConnectToFailure* failReason)
{
  if (CFEqual(deviceAddress, CFSTR("")))
  {
    *failReason = (BMDSwitcherConnectToFailure)bmdSwitcherConnectToFailureNoResponse;
    return E_FAIL;
  }
  failReason = 0;
  IBMDSwitcher* device = new IBMDSwitcher();
  
  device->QueryInterface(IID_IBMDSwitcher, (void**)&device);
  *switcherDevice = device;
  return S_OK;
}

#pragma mark - IUnknown Methods

HRESULT STDMETHODCALLTYPE IBMDSwitcherDiscovery::QueryInterface(REFIID riid, LPVOID *ppv)
{
  if (!ppv)
    return E_POINTER;
  
  if (riid == IID_IBMDSwitcherDiscovery)
  {
    *ppv = static_cast<IBMDSwitcherDiscovery*>(this);
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

ULONG STDMETHODCALLTYPE IBMDSwitcherDiscovery::AddRef()
{
  return ++mRefCount;
}

ULONG STDMETHODCALLTYPE IBMDSwitcherDiscovery::Release()
{
  ULONG refCount = --mRefCount;

  if (refCount == 0)
    delete this;

  return refCount;
}

IBMDSwitcherDiscovery* GetBMDSwitcherDiscoveryInstance_0000(void)
{
  IBMDSwitcherDiscovery* switcherDiscovery = new IBMDSwitcherDiscovery();
  switcherDiscovery->QueryInterface(IID_IBMDSwitcherDiscovery, (void**)&switcherDiscovery);
  return switcherDiscovery;
}
