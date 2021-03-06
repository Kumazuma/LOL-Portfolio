#pragma once
#include "IComponent.h"
#include "Vector3.h"

namespace PKH
{
	class Transform : public IComponent
	{
	public:
		explicit Transform(GameObject* owner);
		explicit Transform(const Transform& rhs);
		virtual ~Transform();

		virtual void Update();
		virtual IComponent* Clone() override;

		// 임의의 축 회전
		void Rotate(Vector3 _axis, float _angle);
		// 바라보기
		void LookAt(Transform _target, Vector3 _worldUp = Vector3::UP);
		void LookAt(Vector3 _target, Vector3 _worldUp = Vector3::UP);

		// 로컬 X축 회전
		void RotatePitch(float _angle);
		// 로컬 Y축 회전
		void RotateYaw(float _angle);
		// 로컬 Z축 회전
		void RotateRoll(float _angle);

		// 월드 X축 회전
		void RotateX(float _angle);
		// 월드 Y축 회전
		void RotateY(float _angle);
		// 월드 Z축 회전
		void RotateZ(float _angle);

		Vector3 GetPos() { return position; }
		Vector3* Get_Pos() { return &position; } //수정

	public:
		Vector3 position{ 0.f,0.f,0.f };
		Vector3 eulerAngles{ 0.f,0.f,0.f };
		Vector3 scale{ 1.f,1.f,1.f };
		Quaternion rotation;

		Vector3 right = Vector3::RIGHT;
		Vector3 up = Vector3::UP;
		Vector3 look = Vector3::FORWARD;
		Matrix world;

		float zOrder = 0.f;
	};
}


