#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("World Simulator");
	mainFrame->SetClientSize(700, 750);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}