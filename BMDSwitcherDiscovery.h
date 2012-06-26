#import <CoreFoundation/CoreFoundation.h>
#import <CoreFoundation/CFPlugInCOM.h>
#include "BMDSwitcher.h"

#define IID_IBMDSwitcherDiscovery (REFIID){0xA6,0x76,0x04,0x7A,0xD3,0xA4,0x44,0xB1,0xB8,0xB5,0x31,0xD7,0x28,0x9D,0x26,0x6A}

typedef uint32_t BMDSwitcherConnectToFailure;
enum _BMDSwitcherConnectToFailure {
  bmdSwitcherConnectToFailureNoResponse = 'cfnr',
  bmdSwitcherConnectToFailureIncompatibleFirmware = 'cfif'
};

class IBMDSwitcherDiscovery : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE ConnectTo(CFStringRef deviceAddress, IBMDSwitcher** switcherDevice, BMDSwitcherConnectToFailure* failReason);
  protected:
    virtual ~IBMDSwitcherDiscovery() {};
  private:
    ULONG mRefCount;
};

extern "C" {
  IBMDSwitcherDiscovery* GetBMDSwitcherDiscoveryInstance_0000(void);
}
