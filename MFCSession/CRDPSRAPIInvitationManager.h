//�q���w�g�q Typelib ���F�H�[�J���O�覡���� IDispatch �]�˨禡���O

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIInvitationManager �]�˨禡���O

class CRDPSRAPIInvitationManager : public COleDispatchDriver
{
public:
	CRDPSRAPIInvitationManager(){} // �I�s COleDispatchDriver�w�]�غc�禡
	CRDPSRAPIInvitationManager(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIInvitationManager(const CRDPSRAPIInvitationManager& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// �ݩ�
public:

	// �@�~
public:


	// IRDPSRAPIInvitationManager ��k
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

	// IRDPSRAPIInvitationManager �ݩ�
public:

};
