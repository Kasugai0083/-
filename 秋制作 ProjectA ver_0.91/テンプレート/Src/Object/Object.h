#pragma once

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"

class Object {
public:

	Object() {};
	~Object() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() {};

protected:
	Texture* m_Tex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
};
