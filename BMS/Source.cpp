#include "Shared.h"
int main()
{
	BuilApplicationHeader("MAIN MENU", AppMenuType::MainMenu);
	cout << "\n";
	cout << "\n";
	BuilApplicationHeader("Sub  Menu", AppMenuType::SubMenu);
	cout << "\n";
	cout << "\n";
	BuilApplicationHeader("SubMenuChild", AppMenuType::SubMenuChild);
}