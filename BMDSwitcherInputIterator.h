#import <CoreFoundation/CoreFoundation.h>
#import <CoreFoundation/CFPlugInCOM.h>

#define IID_IBMDSwitcherInputIterator (REFIID){0x92,0xAB,0x7A,0x73,0xC6,0xF6,0x47,0xFC,0x92,0xA7,0xC8,0xEE,0xAD,0xC9,0xEA,0xAC}

class IBMDSwitcherInputIterator : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE Next(IBMDSwitcherInput** input);
	virtual HRESULT GetById(BMDSwitcherInputId inputId, IBMDSwitcherInput** input);
  protected:
    ~IBMDSwitcherInputIterator() {};
  private:
    ULONG mRefCount;
};
