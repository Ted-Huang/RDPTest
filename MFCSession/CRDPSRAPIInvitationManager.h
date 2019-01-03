//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIInvitationManager 包裝函式類別

class CRDPSRAPIInvitationManager : public COleDispatchDriver
{
public:
	CRDPSRAPIInvitationManager(){} // 呼叫 COleDispatchDriver預設建構函式
	CRDPSRAPIInvitationManager(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIInvitationManager(const CRDPSRAPIInvitationManager& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 屬性
public:

	// 作業
public:


	// IRDPSRAPIInvitationManager 方法
public:
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(VARIANT& Item)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Item);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0xf4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateInvitation(LPCTSTR bstrAuthString, LPCTSTR bstrGroupName, LPCTSTR bstrPassword, long AttendeeLimit)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAuthString, bstrGroupName, bstrPassword, AttendeeLimit);
		return result;
	}

	// IRDPSRAPIInvitationManager 屬性
public:

};
