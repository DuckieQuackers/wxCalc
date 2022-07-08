#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit() {
	window = new cMain();
	window->Show();
	return true;
}