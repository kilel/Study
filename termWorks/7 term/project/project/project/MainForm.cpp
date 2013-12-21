#include "MainForm.h"

using namespace project;

int main(){
	Application::SetCompatibleTextRenderingDefault(true);
	Application::EnableVisualStyles();

	Application::Run(gcnew MainForm());
}