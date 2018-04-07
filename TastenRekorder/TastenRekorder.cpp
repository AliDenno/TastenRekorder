// TastenRekorder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "Helper.h"
#include "Base64.h"
#include "KeyConstants.h"  

using namespace std;

int main()
{	
	// Compiler Flag to be solved here
	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return 0;
}
