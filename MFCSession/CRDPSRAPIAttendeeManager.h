//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIAttendeeManager 包裝函式類別

class CRDPSRAPIAttendeeManager : public COleDispatchDriver
{
public:
	CRDPSRAPIAttendeeManager(){} // 呼叫 COleDispatchDriver預設建構函式
	CRDPSRAPIAttendeeManager(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIAttendeeManager(const CRDPSRAPIAttendeeManager& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 屬性
public:

	// 作業
public:


	// IRDPSRAPIAttendeeManager 方法
public:
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(long Id)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, Id);
		return result;
	}

	// IRDPSRAPIAttendeeManager 屬性
public:

};
