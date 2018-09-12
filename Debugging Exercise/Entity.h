#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	int getAtkPwr();
	void takeDamage(int damage);
	bool isAlive();

protected:
	int atkPwr;
	int health;
	int maxHealth;
};

