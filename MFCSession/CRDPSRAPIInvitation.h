//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIInvitation 包裝函式類別

class CRDPSRAPIInvitation : public COleDispatchDriver
{
public:
	CRDPSRAPIInvitation(){} // 呼叫 COleDispatchDriver預設建構函式
	CRDPSRAPIInvitation(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIInvitation(const CRDPSRAPIInvitation& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 屬性
public:

	// 作業
public:


	// IRDPSRAPIInvitation 方法
public:
	CString get_ConnectionString()
	{
		CString result;
		InvokeHelper(0xe8, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_GroupName()
	{
		CString result;
		InvokeHelper(0xe9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Password()
	{
		CString result;
		InvokeHelper(0xea, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_AttendeeLimit()
	{
		long result;
		InvokeHelper(0xeb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_AttendeeLimit(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xeb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Revoked()
	{
		BOOL result;
		InvokeHelper(0xec, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Revoked(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xec, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IRDPSRAPIInvitation 屬性
public:

};
