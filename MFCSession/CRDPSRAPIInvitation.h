//�q���w�g�q Typelib ���F�H�[�J���O�覡���� IDispatch �]�˨禡���O

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIInvitation �]�˨禡���O

class CRDPSRAPIInvitation : public COleDispatchDriver
{
public:
	CRDPSRAPIInvitation(){} // �I�s COleDispatchDriver�w�]�غc�禡
	CRDPSRAPIInvitation(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIInvitation(const CRDPSRAPIInvitation& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// �ݩ�
public:

	// �@�~
public:


	// IRDPSRAPIInvitation ��k
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

	// IRDPSRAPIInvitation �ݩ�
public:

};
