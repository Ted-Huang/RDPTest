//�q���w�g�q Typelib ���F�H�[�J���O�覡���� IDispatch �]�˨禡���O

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIAttendee �]�˨禡���O

class CRDPSRAPIAttendee : public COleDispatchDriver
{
public:
	CRDPSRAPIAttendee(){} // �I�s COleDispatchDriver�w�]�غc�禡
	CRDPSRAPIAttendee(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIAttendee(const CRDPSRAPIAttendee& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// �ݩ�
public:

	// �@�~
public:


	// IRDPSRAPIAttendee ��k
public:
	long get_Id()
	{
		long result;
		InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_RemoteName()
	{
		CString result;
		InvokeHelper(0xf3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_ControlLevel()
	{
		long result;
		InvokeHelper(0xf2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ControlLevel(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xf2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Invitation()
	{
		LPDISPATCH result;
		InvokeHelper(0xcd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void TerminateConnection()
	{
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_Flags()
	{
		long result;
		InvokeHelper(0xe6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_ConnectivityInfo()
	{
		LPUNKNOWN result;
		InvokeHelper(0xe7, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	// IRDPSRAPIAttendee �ݩ�
public:

};
