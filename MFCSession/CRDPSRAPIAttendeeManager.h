//�q���w�g�q Typelib ���F�H�[�J���O�覡���� IDispatch �]�˨禡���O

#import "C:\\Windows\\System32\\rdpencom.dll" no_namespace
// CRDPSRAPIAttendeeManager �]�˨禡���O

class CRDPSRAPIAttendeeManager : public COleDispatchDriver
{
public:
	CRDPSRAPIAttendeeManager(){} // �I�s COleDispatchDriver�w�]�غc�禡
	CRDPSRAPIAttendeeManager(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRDPSRAPIAttendeeManager(const CRDPSRAPIAttendeeManager& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// �ݩ�
public:

	// �@�~
public:


	// IRDPSRAPIAttendeeManager ��k
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

	// IRDPSRAPIAttendeeManager �ݩ�
public:

};
