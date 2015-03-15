#pragma once

#include <string>

#include "character.h"

namespace mica
{

class Player : public Character
{
public:
	Player();

	static Player* create(const std::string& name);
	virtual bool init(const std::string& name);
	virtual void update(float) override;

	void interact(Interactable *other) override;

	void setControlable()
	{
		m_controlable = true;
	};
};

}