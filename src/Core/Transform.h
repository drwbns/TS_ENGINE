#pragma once
#include "tspch.h"
#include "SceneManager/Node.h"

namespace TS_ENGINE
{
	class Node;
	class Transform
	{
	public:
		Transform();
		Transform(const char* createdFrom);
		~Transform();

		Vector3 m_Pos;
		Vector3 m_EulerAngles;//This is in degree to readability
		Vector3 m_Scale;
		Vector3 m_Right;
		Vector3 m_Up;
		Vector3 m_Forward;
		Matrix4 m_LocalTransformationMatrix;
		Matrix4 m_GlobalTransformationMatrix;

		void Follow(Ref<Node> targetNode);
		void LookAt(Ref<Node> parentNode, const Ref<Transform> target);

		Matrix4 GetLocalTransformationMatrix();
		void ComputeTransformationMatrix(Ref<Node> parentNode);
		void SetLocalTransformationMatrix(Matrix4 transformationMatrix);
		void SetGlobalTransformationMatrix(Matrix4 transformationMatrix);

		void SetLocalPosition(const Vector3& newPosition);
		void SetLocalPosition(float x, float y, float z);
		void SetLocalPosition(const float* newPosition);
		void SetLocalEulerAngles(const Vector3& newLocalEulerAngles);
		void SetLocalEulerAngles(float x, float y, float z);
		void SetLocalEulerAngles(const float* newLocalEulerAngles);
		void SetLocalScale(const Vector3& newScale);
		void SetLocalScale(float x, float y, float z);
		void SetLocalScale(const float* newScale);

		void SetLocalTransforms(Vector3 pos, Vector3 eulerAngles, Vector3 scale);

		void Reset();

		const Vector3& GetLocalPosition() const;
		const Vector3& GetLocalEulerAngles() const;
		const Vector3& GetLocalScale() const;

		Matrix4 GetInverseParentMat(Matrix4 newTransformMatrix);

		//const Vector3& GetGlobalPosition() const;
		//const Vector3& GetGlobalEulerAngles(Vector3 parentEulerAngles) const;
		//const Vector3& GetGlobalScale() const;

		const Matrix4 GetLocalTransformationMatrix() const { return m_LocalTransformationMatrix; }
		const Matrix4 GetGlobalTransformationMatrix() const { return m_GlobalTransformationMatrix; }

		Vector3 GetRight() const;
		Vector3 GetUp() const;
		Vector3 GetBackward() const;
		Vector3 GetForward() const;

		void MoveFwd(float moveSpeed, float deltaTime);
		void MoveBack(float moveSpeed, float deltaTime);
		void MoveLeft(float moveSpeed, float deltaTime);
		void MoveRight(float moveSpeed, float deltaTime);
		void MoveUp(float moveSpeed, float deltaTime);
		void MoveDown(float moveSpeed, float deltaTime);
		void Yaw(float yawSpeed, float deltaTime);
		void Pitch(float pitchSpeed, float deltaTime);
		void Roll(float rollSpeed, float deltaTime);

		Ref<Transform> mLookAtTarget;
		bool mLookAtEnabled = false;
	};
}