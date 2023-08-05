#pragma once
#include "GameObject.h"

namespace TS_ENGINE {

	class Sphere : public GameObject
	{
	private:
		float mPI = 3.141f;
		float mRadius = 0.01f;
		int mStackCount = 20;
		int mSectorCount = 20;

		Ref<Mesh> mMesh;
	public:
		Sphere(const std::string& name);

		void CreateVertices();
		void CreateIndices();
		void Create();
	};
}
