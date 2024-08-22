#pragma once


extern Pistachio::Application* Pistachio::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Pistachio {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Pistachio::Application* app = Pistachio::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

// display a console for debug builds, and show only the window in release mode
// #ifdef _WIN32
// #ifdef _DEBUG // Release build
//
// int main(int argc, char** argv)
// {
// 	return Pistachio::Main(argc, argv);
// }
//
// #else
//
// #include <Windows.h>
//
// int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
// {
// 	return Pistachio::Main(__argc, __argv);
// }
//
// #endif
//
// #else

int main(int argc, char** argv)
{
	return Pistachio::Main(argc, argv);
}

// #endif



