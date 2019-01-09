#include "stdafx.h"
#include "RDPSession.h"

void OnAttendeeConnectedNew(IDispatch *pAttendee){
	IRDPSRAPIAttendee *pRDPAtendee;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendee), (void**)&pRDPAtendee);
	if (pRDPAtendee)
		pRDPAtendee->put_ControlLevel(CTRL_LEVEL::CTRL_LEVEL_INTERACTIVE);
	//AddText(infoLog, "An attendee connected!\r\n");
}
void OnAttendeeDisconnectedNew(IDispatch *pAttendee){
	IRDPSRAPIAttendeeDisconnectInfo *info;
	ATTENDEE_DISCONNECT_REASON reason;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendeeDisconnectInfo), (void**)&info);
	if (info->get_Reason(&reason) == S_OK){
		char *textReason = NULL;
		switch (reason){
		case ATTENDEE_DISCONNECT_REASON_APP:
			textReason = "Viewer terminated session!";
			break;
		case ATTENDEE_DISCONNECT_REASON_ERR:
			textReason = "Internal Error!";
			break;
		case ATTENDEE_DISCONNECT_REASON_CLI:
			textReason = "Attendee requested termination!";
			break;
		default:
			textReason = "Unknown reason!";
		}
		//AddText(infoLog, dupcat("Attendee disconnected\r\n   Reason: ", textReason, "\r\n", 0));
	}
	pAttendee->Release();
	//picp = 0;
	//picpc = 0;
	//disconnect();
}


void OnControlLevelChangeRequestNew(IDispatch  *pAttendee, CTRL_LEVEL RequestedLevel){
	IRDPSRAPIAttendee *pRDPAtendee;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendee), (void**)&pRDPAtendee);
	if (pRDPAtendee->put_ControlLevel(RequestedLevel) == S_OK){
		switch (RequestedLevel){
		case CTRL_LEVEL_NONE:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_NONE!\r\n");
			break;
		case CTRL_LEVEL_VIEW:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_VIEW!\r\n");
			break;
		case CTRL_LEVEL_INTERACTIVE:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_INTERACTIVE!\r\n");
			break;
		}
	}
}

CRDPSession::CRDPSession()
{
	if (FAILED(CoInitialize(NULL)))
	{
		TRACE(_T("Fatal Error: OLE initialization failed \n"));
		return;
	}
	Init();
}

CRDPSession::~CRDPSession()
{
	CoUninitialize();
}

CString CRDPSession::GetConnectionString()
{
	BSTR bsConnectionString;
	HRESULT hr = m_pInvatition->get_ConnectionString(&bsConnectionString);

	if (FAILED(hr))
		return L"";

	CString strConnectionString = bsConnectionString;
	SysFreeString(bsConnectionString);

	return strConnectionString;
}

void CRDPSession::Init()
{
	HRESULT hr;
	hr = CoCreateInstance(__uuidof(RDPSession), NULL, CLSCTX_INPROC_SERVER, __uuidof(IRDPSRAPISharingSession), (void**)&m_pSession);
	if (FAILED(hr))
		return;

	hr = m_pSession->Open();

	if (FAILED(hr))
		return;

	IRDPSRAPIInvitationManager* pInvitationMgr;

	hr = m_pSession->get_Invitations(&pInvitationMgr);

	if (FAILED(hr))
		return;

	CString strAuth = _T("baseAuth"), strGroup = _T("groupName"), strPwd = _T("");
	BSTR bsAuth = strAuth.AllocSysString(), bsGroup = strGroup.AllocSysString(), bsPwd = strPwd.AllocSysString();

	hr = pInvitationMgr->CreateInvitation(bsAuth, bsGroup, bsPwd, 64, &m_pInvatition);
	SysFreeString(bsAuth);
	SysFreeString(bsGroup);
	SysFreeString(bsPwd);
	if (FAILED(hr))
		return;

	ConnectEvent((IUnknown*)m_pSession, __uuidof(_IRDPSessionEvents), (IUnknown*)&m_ev, &m_picpc, &m_picp);
}

int CRDPSession::ConnectEvent(IUnknown* Container, REFIID riid, IUnknown* Advisor, IConnectionPointContainer** picpc, IConnectionPoint** picp)
{
	HRESULT hr = 0;
	unsigned long tid = 0;
	IConnectionPointContainer* icpc = 0;
	IConnectionPoint* icp = 0;
	*picpc = 0;
	*picp = 0;

	Container->QueryInterface(IID_IConnectionPointContainer, (void **)&icpc);
	if (icpc)
	{
		*picpc = icpc;
		icpc->FindConnectionPoint(riid, &icp);
		if (icp)
		{
			*picp = icp;
			hr = icp->Advise(Advisor, &tid);
			//icp->Release();
		}
		//icpc->Release();
	}
	return tid;
}

