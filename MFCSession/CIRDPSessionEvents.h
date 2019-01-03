//電腦已經從 Typelib 精靈以加入類別方式產生 IDispatch 包裝函式類別
#pragma once
#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CIRDPSessionEvents 包裝函式類別

class CIRDPSessionEvents : public COleDispatchDriver
{
public:
	CIRDPSessionEvents(){} // 呼叫 COleDispatchDriver預設建構函式
	CIRDPSessionEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CIRDPSessionEvents(const CIRDPSessionEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 屬性
public:

	// 作業
public:


	// _IRDPSessionEvents 方法
public:
	void OnAttendeeConnected(LPDISPATCH pAttendee)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pAttendee);
	}
	void OnAttendeeDisconnected(LPDISPATCH pDisconnectInfo)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pDisconnectInfo);
	}
	void OnAttendeeUpdate(LPDISPATCH pAttendee)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pAttendee);
	}
	void OnConnectionEstablished()
	{
		InvokeHelper(0x131, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnConnectionFailed()
	{
		InvokeHelper(0x134, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnConnectionTerminated(long discReason, long ExtendedInfo)
	{
		static BYTE parms[] = VTS_I4 VTS_I4;
		InvokeHelper(0x132, DISPATCH_METHOD, VT_EMPTY, NULL, parms, discReason, ExtendedInfo);
	}
	void OnConnectionAuthenticated()
	{
		InvokeHelper(0x133, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnError(VARIANT& ErrorInfo)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &ErrorInfo);
	}
	void OnApplicationOpen(LPDISPATCH pApplication)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x13c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pApplication);
	}
	void OnApplicationClose(LPDISPATCH pApplication)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x13d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pApplication);
	}
	void OnApplicationUpdate(LPDISPATCH pApplication)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x13e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pApplication);
	}
	void OnWindowOpen(LPDISPATCH pWindow)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x13f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pWindow);
	}
	void OnWindowClose(LPDISPATCH pWindow)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x140, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pWindow);
	}
	void OnWindowUpdate(LPDISPATCH pWindow)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x141, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pWindow);
	}
	void OnControlLevelChangeRequest(LPDISPATCH pAttendee, long RequestedLevel)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_I4;
		InvokeHelper(0x135, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pAttendee, RequestedLevel);
	}
	void OnGraphicsStreamPaused()
	{
		InvokeHelper(0x136, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnGraphicsStreamResumed()
	{
		InvokeHelper(0x137, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnChannelDataReceived(LPUNKNOWN pChannel, long lAttendeeId, LPCTSTR bstrData)
	{
		static BYTE parms[] = VTS_UNKNOWN VTS_I4 VTS_BSTR;
		InvokeHelper(0x13a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pChannel, lAttendeeId, bstrData);
	}
	void OnChannelDataSent(LPUNKNOWN pChannel, long lAttendeeId, long BytesSent)
	{
		static BYTE parms[] = VTS_UNKNOWN VTS_I4 VTS_I4;
		InvokeHelper(0x13b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pChannel, lAttendeeId, BytesSent);
	}
	void OnSharedRectChanged(long left, long top, long right, long bottom)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x143, DISPATCH_METHOD, VT_EMPTY, NULL, parms, left, top, right, bottom);
	}
	void OnFocusReleased(long iDirection)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x144, DISPATCH_METHOD, VT_EMPTY, NULL, parms, iDirection);
	}
	void OnSharedDesktopSettingsChanged(long width, long height, long colordepth)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x145, DISPATCH_METHOD, VT_EMPTY, NULL, parms, width, height, colordepth);
	}

	// _IRDPSessionEvents 屬性
public:

};
