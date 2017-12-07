#pragma comment(linker,"/entry:mainCRTStartup")
#include"Game/Game.h"

void main() {
	MyGame().run();
}