#pragma once

#include "Interactable.h"

class Eatable : public Interactable
{
public:
	virtual void interactable()
	{
		m_iType = INTERACT_EAT;
	}
};