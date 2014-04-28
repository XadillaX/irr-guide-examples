#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;

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
    ISceneManager* smgr = device->getSceneManager();
    IAnimatedMesh* mesh = smgr->getMesh("../media/if-yu/Inori.obj");
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);
    if(node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
    }

    smgr->addCameraSceneNode(0, vector3df(0, 30, -40),
        vector3df(0, 5, 0));

    while(device->run())
    {
        driver->beginScene(true, true, SColor(255, 0, 0, 0));
        smgr->drawAll();
        driver->endScene();
    }

    device->drop();

    return 0;
}
