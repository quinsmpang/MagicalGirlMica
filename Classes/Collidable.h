#pragma once

#include "Interactable.h"

class Collidable : public Interactable
{
public:
	virtual void interactable()
	{
		m_iType = INTERACT_COLLISION;
	}
};