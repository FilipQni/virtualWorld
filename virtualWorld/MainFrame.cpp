#include "MainFrame.h"
#include "World.h"
#include <wx/wx.h>

enum IDs {
	BUTTON_RESET_ID = 2,
	BUTTON_SAVE_ID = 3,
	BUTTON_LOAD_ID = 4,
	BUTTON_TURN_ID = 5,
	BUTTON_TEXT_FIELD_ID = 6
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(BUTTON_RESET_ID, MainFrame::OnButtonResetClicked)
EVT_BUTTON(BUTTON_SAVE_ID, MainFrame::OnButtonSaveClicked)
EVT_BUTTON(BUTTON_LOAD_ID, MainFrame::OnButtonLoadClicked)
EVT_BUTTON(BUTTON_TURN_ID, MainFrame::OnButtonTurnClicked)
EVT_BUTTON(BUTTON_TEXT_FIELD_ID, MainFrame::OnButtonTurnClicked)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	wxPanel* panel = new wxPanel(this);
	wxButton* buttonReset = new wxButton(panel, BUTTON_RESET_ID, "Reset the game", wxPoint(565, 50), wxSize(100, 35));
	wxButton* buttonSave = new wxButton(panel, BUTTON_SAVE_ID, "Save the game", wxPoint(565, 100), wxSize(100, 35));
	wxButton* buttonLoad = new wxButton(panel, BUTTON_LOAD_ID, "Load the game", wxPoint(565, 150), wxSize(100, 35));
	wxButton* buttonTurn = new wxButton(panel, BUTTON_TURN_ID, "Make a turn", wxPoint(565, 200), wxSize(100, 35));
	textField = new wxTextCtrl(panel, BUTTON_TEXT_FIELD_ID, wxEmptyString, wxPoint(20, 540), wxSize(500, 200), wxTE_MULTILINE);
	textField->SetEditable(false);
	(*textField) << "This windows shows what happend in a previous turn";
	world.makeArrayFromFile(world, "startSpawn.txt");


	int startingPosition = 35;
	for (int y = 0; y < 20; y++) {
		new wxButton(panel, wxID_ANY, std::to_string(y + 1), wxPoint((y + 1) * 25 + 10, 10), wxSize(25, 25));
		new wxButton(panel, wxID_ANY, std::to_string(y + 1), wxPoint(10, (y + 1) * 25 + 10), wxSize(25, 25));

		for (int x = 0; x < 20; x++) {
			worldArrayButtons[x][y] = new wxButton(panel, wxID_ANY, "", wxPoint(startingPosition + x * 25, startingPosition + y * 25), wxSize(25, 25));
			//worldArrayButtons[x][y]->Disable();
		}
	}

	DrawWorld();
	CreateStatusBar();
}

void MainFrame::OnButtonResetClicked(wxCommandEvent& evt)
{
	world.makeArrayFromFile(world, "startSpawn.txt");
	DrawWorld();
	textField->Clear();
	wxLogStatus("Button Reset clicked");
}

void MainFrame::OnButtonSaveClicked(wxCommandEvent& evt)
{
	world.saveGame("save.txt");
	wxLogStatus("Button Save clicked");
}

void MainFrame::OnButtonLoadClicked(wxCommandEvent& evt)
{
	world.makeArrayFromFile(world, "save.txt");
	DrawWorld();
	textField->Clear();
	wxLogStatus("Button Load clicked");
}

void MainFrame::OnButtonTurnClicked(wxCommandEvent& evt)
{
	vector<string> turnLog;
	world.takeTurn();
	textField->Clear();
	turnLog = world.getTurnLog();
	for (unsigned int i = 0; i < turnLog.size(); i++) {
		(*textField) << turnLog[i] << "\n";
	}
	DrawWorld();
	wxLogStatus("Button Turn clicked");

}

void MainFrame::DrawWorld()
{
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			worldArrayButtons[x][y]->SetLabelText("");
		}
	}

	organismVector = world.getOrganismVector();
	for (unsigned int i = 0; i < organismVector.size(); i++) {
		if (organismVector[i]->getIsAlive()) {
			worldArrayButtons[organismVector[i]->getPositionX()][organismVector[i]->getPositionY()]
				->SetLabel(organismVector[i]->getSymbol());
		}
	}
}

void MainFrame::OnClose(wxCloseEvent& evt) {
	wxMessageBox("Zamykamy");
	evt.Skip();
}
