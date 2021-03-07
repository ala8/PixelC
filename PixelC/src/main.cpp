// This is a little pixel game made with C++ SFML.
// The code is obviously not optimized for good performance. It's just for demonstration and not recommended for real projects.

#ifdef _DEBUG
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(lib, "sfml-network-d.lib")
#else
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-audio.lib")
#pragma comment(lib, "sfml-network.lib")
#endif

#include "headers/Game.h"

int main()
{
    Game game(1200.0f, 800.0f, "PixelC v1.0");
    return 0;
}