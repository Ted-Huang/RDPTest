//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別
#pragma once
#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPISharingSession 包裝函式類別
class CRDPSRAPISharingSession : public COleDispatchDriver
{
public:
	CRDPSRAPISharingSession(){} // 呼叫 COleDispatchDriver預設建構函式
	CRDPSRAPISharingSession(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPISharingSession(const CRDPSRAPISharingSession& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 屬性
public:

	// 作業
public:


	// IRDPSRAPISharingSession 方法
public:
	void Open()
	{
		InvokeHelper(0x64, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Close()
	{
		InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void put_colordepth(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_colordepth()
	{
		long result;
		InvokeHelper(0xef, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Properties()
	{
		LPDISPATCH result;
		InvokeHelper(0xca, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Attendees()
	{
		LPDISPATCH result;
		InvokeHelper(0xcb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Invitations()
	{
		LPDISPATCH result;
		InvokeHelper(0xcc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_ApplicationFilter()
	{
		LPDISPATCH result;
		InvokeHelper(0xd7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_VirtualChannelManager()
	{
		LPDISPATCH result;
		InvokeHelper(0xce, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Pause()
	{
		InvokeHelper(0x70, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Resume()
	{
		InvokeHelper(0x71, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ConnectToClient(LPCTSTR bstrConnectionString)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bstrConnectionString);
	}
	void SetDesktopSharedRect(long left, long top, long right, long bottom)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms, left, top, right, bottom);
	}
	void GetDesktopSharedRect(long * pleft, long * ptop, long * pright, long * pbottom)
	{
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pleft, ptop, pright, pbottom);
	}
	void OnAttendeeConnected(LPDISPATCH pAttendee);
	// IRDPSRAPISharingSession 屬性
public:

};
