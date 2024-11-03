#include "Behaviour.hpp"

class Entity
{
};

int main() 
{
	Entity entity;
	Behaviour<Entity> behaviour(&entity);

	behaviour.Start();
	behaviour.Update();
	behaviour.End();

	return 0;
}