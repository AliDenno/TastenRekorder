#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	MSG Msg;

	// This will be an infinite loop because it won't happen, along with the flag passed it will prevent the console from showing
	while (GetMessage(&Msg, NULL, 0, 0)) {
        // Take a message and modify the message
		TranslateMessage(&Msg);
        // forward the message to the system
		DispatchMessage(&Msg);
	}
	return 0;
}
