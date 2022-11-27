// cmake.cpp : Defines the entry point for the application.
//

#include <Gfx/graphicsBase.h>
#include <Core/Engine.h>


using namespace std;

int main()
{
    Engine engine;

    try {
        engine.Initialize();
        engine.MainLoop();
        engine.Cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
