/*
 * dynamic_scene_object.cpp
 *
 * Copyright (C) 2014-2015  Ming Tsang, Nathan Ng
 * Refer to LICENSE for details
 */

#include <base/CCEventDispatcher.h>
#include <cocostudio/CCArmature.h>

#include "dynamic_scene_object.h"

using namespace cocostudio;

namespace mica
{

DynamicSceneObject::DynamicSceneObject()
		: m_view(nullptr)
{
	setGood(false);
}

DynamicSceneObject::~DynamicSceneObject()
{
	setView(nullptr);
}

void DynamicSceneObject::setView(Armature *view)
{
	if (m_view)
	{
		m_view->getEventDispatcher()->removeEventListenersForTarget(m_view);
		m_view->removeFromParent();
		m_view->release();
	}
	m_view = view;
	if (m_view)
	{
		m_view->retain();
		setGood(true);
	}
	else
	{
		setGood(false);
	}
}

}
