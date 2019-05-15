#include <Leavs.h>

class Sandbox : public Leavs::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Leavs::Application* Leavs::CreateApplication()
{
	return new Sandbox();
}