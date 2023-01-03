#include <GameEngine.h>
#include <stdlib.h>
#include <vld.h>
#include"StateMachine.h";
#include"ResourceManager.h"
#include"Object.h"
#include"State.h"

using namespace std;

int main()
{
    // Init Graphics 
    Device *device = Device::GetInstance();
	device->InitWindow(EnumDisplay::E_Width, EnumDisplay::E_Height);
    Graphics *graphics = device->GetGraphics();
	//Init object
	StateMachine* machine = StateMachine::GetInstance();
	machine->Init("Data.bin");
	ResourceManager* resource = ResourceManager::GetInstance();
    while (device->IsRunning())
    {  
		//Game update
		machine->Update(GameTime::GetFrameTime());
		//Game render
		machine->Render(graphics);
    }
	//Game destroy
    InputManager::DestroyInstance();
    Device::DestroyInstance();
	machine->DestroyInstance();
	resource->DestroyInstance();
    return 0;
}