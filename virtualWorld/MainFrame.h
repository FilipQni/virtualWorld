#pragma once
#include <wx/wx.h>
#include "World.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private: 
	World world;
	wxButton* worldArrayButtons[20][20];
	vector<Organism*> organismVector;
	wxTextCtrl* textField;

	void OnButtonResetClicked(wxCommandEvent& evt);
	void OnButtonSaveClicked(wxCommandEvent& evt);
	void OnButtonLoadClicked(wxCommandEvent& evt);
	void OnButtonTurnClicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
	void DrawWorld();
	wxDECLARE_EVENT_TABLE();
};