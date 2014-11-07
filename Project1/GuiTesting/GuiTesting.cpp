
// GuiTesting.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GuiTesting.h"
#include "GuiTestingDlg.h"

#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGuiTestingApp

BEGIN_MESSAGE_MAP(CGuiTestingApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGuiTestingApp construction

CGuiTestingApp::CGuiTestingApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CGuiTestingApp object
CGuiTestingApp theApp;


// CGuiTestingApp initialization

BOOL CGuiTestingApp::InitInstance()
{
	CppUnit::MfcUi::TestRunner runner;

	runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());

	runner.run();

	return TRUE;
}

