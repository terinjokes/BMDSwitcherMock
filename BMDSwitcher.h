#import <CoreFoundation/CoreFoundation.h>
#import <CoreFoundation/CFPlugInCOM.h>

#define IID_IBMDSwitcher (REFIID){0x1E,0x87,0x01,0xD0,0x25,0x8F,0x43,0xED,0x9E,0xDC,0x43,0x4F,0xD1,0x6E,0x92,0x2D}

class IBMDSwitcher : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE CreateIterator(REFIID iid, LPVOID* ppv);
    //    virtual HRESULT STDMETHODCALLTYPE AddCallback(IBMDSwitcherCallback* callback);
    //    virtual HRESULT STDMETHODCALLTYPE RemoveCallback(IBMDSwitcherCallback* callback);
    //    virtual HRESULT STDMETHODCALLTYPE SetFlag(BMDSwitcherPropertyID propertyID, bool value);
    //    virtual HRESULT STDMETHODCALLTYPE GetFlag(BMDSwitcherPropertyID propertyID, bool* value);
    //    virtual HRESULT STDMETHODCALLTYPE SetInt(BMDSwitcherPropertyID propertyID, int64_t value);
    //    virtual HRESULT STDMETHODCALLTYPE GetInt(BMDSwitcherPropertyID propertyID, int64_t* value);
    //    virtual HRESULT STDMETHODCALLTYPE SetFloat(BMDSwitcherPropertyID propertyID, double value);
    //    virtual HRESULT STDMETHODCALLTYPE GetFloat(BMDSwitcherPropertyID propertyID, double* value);
    //    virtual HRESULT STDMETHODCALLTYPE SetString(BMDSwitcherPropertyID propertyID, CFStringRef value);
    //    virtual HRESULT STDMETHODCALLTYPE GetString(BMDSwitcherPropertyID propertyID, CFStringRef* value);
  protected:
    ~IBMDSwitcher() {};
  private:
    ULONG mRefCount;
};
