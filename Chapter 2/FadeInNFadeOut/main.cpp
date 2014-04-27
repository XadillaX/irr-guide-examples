#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace video;

#pragma comment(lib, "Irrlicht.lib")

int main()
{
    IrrlichtDevice* device = createDevice(irr::video::EDT_DIRECT3D9,
        dimension2d<u32>(800, 600), 32, false, true, true, 0);

    if(!device)
    {
        printf("Failed while creating device...\n");
        return 1;
    }

    IVideoDriver* driver = device->getVideoDriver();

    f32 bg_r = 255.0f;
    f32 bg_g = 255.0f;
    f32 bg_b = 255.0f;
    bool fadeOut = true;
    int lastFPS = -1;

    u32 then = device->getTimer()->getTime();
    const f32 fadeRate = 0.1f;

    while(device->run())
    {
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then);
        then = now;

        if(bg_r <= 0.0f) fadeOut = false;
        else
        if(bg_r >= 255.0f) fadeOut = true;

        if(fadeOut)
        {
            bg_r -= fadeRate * frameDeltaTime;
            bg_g -= fadeRate * frameDeltaTime;
            bg_b -= fadeRate * frameDeltaTime;
        }
        else
        {
            bg_r += fadeRate * frameDeltaTime;
            bg_g += fadeRate * frameDeltaTime;
            bg_b += fadeRate * frameDeltaTime;
        }

        driver->beginScene(true, true, SColor(255, bg_r, bg_g, bg_b));
        driver->endScene();
    }

    device->drop();

    return 0;
}
