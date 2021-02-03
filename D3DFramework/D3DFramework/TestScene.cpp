#include "stdafx.h"
#include "TestScene.h"

#include "Label.h"

#include "SkyBox.h"
#include "Environment.h"
#include "TestMan.h"
#include "PlayerController.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "NavMeshMap.h"
#include "TestGaren.h"
#include "Wall.h"
#include "Turret.h"
#include "Bush.h"

#include "Garen.h"
#include "Blitzcrank.h"
#include "Darius.h"
#include "Diana.h"
#include "Leesin.h"
#include "Missfortune.h"
#include "Leona.h"
#include "Ahri.h"
#include "Jax.h"
#include "Jinx.h"

#include "PlayerInfoPanel.h"
#include "FloatingBar.h"

#include "OrderMinionCaster.h"
#include "OrderMinionMelee.h"
#include "OrderMinionSiege.h"
#include "OrderMinionSuper.h"
#include "ChaosMinionCaster.h"
#include "ChaosMinionSiege.h"
#include "ChaosMinionSuper.h"
#include "ChaosMinionMelee.h"

#include "BlueMonster.h"
#include "RedMonster.h"
#include "Murkwolf.h"
#include "MurkwolfMini.h"
#include "Krug.h"
#include "KrugMini.h"
#include "Gromp.h"
#include "Razorbeak.h"
#include "RazorbeakMini.h"
#include "Scuttleracer.h"

#include "MonsterAI.h"

#include "Nexus.h"
#include "MinionAI.h"

void TestScene::OnLoaded()
{
	Cursor::Show();
	//ObjectManager::GetInstance()->CreateObject<Light>();

	//SkyBox::Show();
	//SkyBox::SetTexture(TextureKey::SKY_U);
	Camera::GetInstance()->SetPosition(Vector3(0.f, 1.f ,-1.f));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	testLabel = (Label*)ObjectManager::GetInstance()->CreateObject<Label>(Layer::UI);
	testLabel->text = L"123123\n123123";
	testLabel->foreColor = D3DCOLOR_ARGB(255, 0, 255, 0);

	GameObject* obj = nullptr;
	Unit* unit = nullptr;
	// 오브젝트
	obj = ObjectManager::GetInstance()->CreateObject<Environment>();
	obj->transform->position = { 0,0,0 };

	// 바닥
	obj = ObjectManager::GetInstance()->CreateObject<NavMeshMap>(Layer::Ground);

	// 벽
	obj = ObjectManager::GetInstance()->CreateObject<Wall>(Layer::Wall);

	// 부쉬
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.98f,67.71f,29.14f };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.90,67.71,29.87 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.84,67.71,29.55 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.50,67.71,28.95 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.90,67.71,28.73 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.70,67.71,28.37 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.39,67.71,28.22 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 8.01,67.71,28.06 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.71,67.71,27.92 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.41,67.71,27.83 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.99,67.71,28.52 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.54,67.71,28.44 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.68,67.71,28.77 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.15,67.71,28.61 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 7.00,67.71,28.84 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 6.83,67.71,28.54 };
	obj = ObjectManager::GetInstance()->CreateObject<Bush>(Layer::Bush);
	obj->transform->position = { 6.99,67.71,28.18 };

	// 몬스터

	// 레드
	obj = ObjectManager::GetInstance()->CreateObject<RedMonster>(Layer::Unit);
	obj->transform->position = { -6.10,67.71,24.87 };
	obj = ObjectManager::GetInstance()->CreateObject<RedMonster>(Layer::Unit);
	obj->transform->position = { -1.88,67.71,-17.87 };
	// 블루
	obj = ObjectManager::GetInstance()->CreateObject<BlueMonster>(Layer::Unit);
	obj->transform->position = { 19.79,67.72,0.64 };
	obj = ObjectManager::GetInstance()->CreateObject<BlueMonster>(Layer::Unit);
	obj->transform->position = { -26.43,67.71,6.83 };
	// 늑대 위
	obj = ObjectManager::GetInstance()->CreateObject<Murkwolf>(Layer::Unit);
	obj->transform->position = { 19.74,67.71,9.78 };
	obj = ObjectManager::GetInstance()->CreateObject<MurkwolfMini>(Layer::Unit);
	obj->transform->position = { 19.17,67.71,10.84 };
	obj = ObjectManager::GetInstance()->CreateObject<MurkwolfMini>(Layer::Unit);
	obj->transform->position = { 21.08,67.71,9.00 };
	// 늑대 아래
	obj = ObjectManager::GetInstance()->CreateObject<Murkwolf>(Layer::Unit);
	obj->transform->position = { -26.72,67.72,-2.72 };
	obj = ObjectManager::GetInstance()->CreateObject<MurkwolfMini>(Layer::Unit);
	obj->transform->position = { -26.23,67.71,-3.57 };
	obj = ObjectManager::GetInstance()->CreateObject<MurkwolfMini>(Layer::Unit);
	obj->transform->position = { -27.73,67.71,-2.44 };
	// 두꺼비
	obj = ObjectManager::GetInstance()->CreateObject<Gromp>(Layer::Unit);
	obj->transform->position = { 29.28,67.73,-2.82 };
	obj = ObjectManager::GetInstance()->CreateObject<Gromp>(Layer::Unit);
	obj->transform->position = { -36.59,67.71,10.14 };

	// 쨱쨱이 위
	obj = ObjectManager::GetInstance()->CreateObject<Razorbeak>(Layer::Unit);
	obj->transform->position = { -0.75,67.71,16.17 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -1.32,67.71,15.52 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -1.69,67.71,16.20 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -1.71,67.71,17.11 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -0.98,67.71,17.65 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { 0.08,67.71,17.21 };

	// 짹짹이 아래
	obj = ObjectManager::GetInstance()->CreateObject<Razorbeak>(Layer::Unit);
	obj->transform->position = { -6.43,67.71,-10.09 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -5.53,67.71,-9.14 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -5.56,67.71,-10.09 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -5.91,67.71,-11.04 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -6.81,67.71,-10.93 };
	obj = ObjectManager::GetInstance()->CreateObject<RazorbeakMini>(Layer::Unit);
	obj->transform->position = { -7.31,67.71,-10.48 };


	// 작골
	obj = ObjectManager::GetInstance()->CreateObject<Krug>(Layer::Unit);
	obj->transform->position = { -10.05,67.71,33.49 };

	obj = ObjectManager::GetInstance()->CreateObject<Krug>(Layer::Unit);
	obj->transform->position = { 3.13,67.71,-26.61 };

	// 바위게
	obj = ObjectManager::GetInstance()->CreateObject<Scuttleracer>(Layer::Unit);
	obj->transform->position = { 15.68,66.91,-11.16 };

	obj = ObjectManager::GetInstance()->CreateObject<Scuttleracer>(Layer::Unit);
	obj->transform->position = { -24.36,66.91,17.82 };


	// 챔피언
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Garen>(Layer::Unit);
	unit->transform->position = { 41,68,46 };
	unit->SetTeam(Team::BLUE);
	unit->AddComponent<PlayerController>(L"PlayerController");
	Camera::GetInstance()->SetTarget(unit);
	PlayerInfoPanel::GetInstance()->SetTarget((Champion*)unit);
	Champion* champ = (Champion*)unit;
	champ->bar->SetNickname(L"테스트닉네임");
	

	obj = PlayerInfoPanel::GetInstance();
	ObjectManager::GetInstance()->AddObject(obj, Layer::HUD);
	

	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Blitzcrank>(Layer::Unit);
	//unit->transform->position = { 32,68,29 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Darius>(Layer::Unit);
	//unit->transform->position = { 29,68,30 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Diana>(Layer::Unit);
	//unit->transform->position = { 26,68,32 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Leesin>(Layer::Unit);
	//unit->transform->position = { 24,68,34 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Missfortune>(Layer::Unit);
	//unit->transform->position = { 23,68,37 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Leona>(Layer::Unit);
	//unit->transform->position = { 30,68,27 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Ahri>(Layer::Unit);
	//unit->transform->position = { 31,68,28 };
	//unit->SetTeam(Team::RED);
	////unit->AddComponent<PlayerController>(L"PlayerController");
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Jax>(Layer::Unit);
	//unit->transform->position = { 29,68,28 };
	//unit->SetTeam(Team::RED);
	//unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Jinx>(Layer::Unit);
	//unit->transform->position = { 27,68,28 };
	//unit->SetTeam(Team::RED);
	//unit->AddComponent<PlayerController>(L"PlayerController");
	//Camera::GetInstance()->SetTarget(unit);
	//unit->AddComponent<PlayerController>(L"PlayerController");


	// 블루팀 타워

	// bottom1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -23.15f, 67.71f, 44.17f };
	unit->transform->eulerAngles.y = D3DXToRadian(135.f);
	unit->SetTeam(Team::BLUE);
	// bottom2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -0.30f, 67.71f, 41.20f };
	unit->transform->eulerAngles.y = D3DXToRadian(135.f);
	unit->SetTeam(Team::BLUE);
	// bottom3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 16.41f, 67.87f, 42.5f };
	unit->transform->eulerAngles.y = D3DXToRadian(135.f);
	unit->SetTeam(Team::BLUE);

	// mid1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 6.50f, 67.71f, 10.f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);
	
	// mid2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 11.61f, 67.71f, 20.f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);
	// mid3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 20.51f, 67.87f, 27.f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);

	// top1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 37.42f, 67.71f, -16.f };
	unit->transform->eulerAngles.y = D3DXToRadian(45.f);
	unit->SetTeam(Team::BLUE);
	// top2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 34.12f, 67.71f, 8.f };
	unit->transform->eulerAngles.y = D3DXToRadian(45.f);
	unit->SetTeam(Team::BLUE);

	// top3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 36.36f, 67.87f, 23.f };
	unit->transform->eulerAngles.y = D3DXToRadian(45.f);
	unit->SetTeam(Team::BLUE);


	// twin Left
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 32.35f, 68.f, 36.f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);
	// twin Right
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 29.46f, 68.f, 39.3f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);

	// nexus
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Nexus>(Layer::Building);
	unit->transform->position = { 33.90f,68.04f,39.89f };
	unit->transform->eulerAngles.y = D3DXToRadian(90.f);
	unit->SetTeam(Team::BLUE);
	

	// 퍼플팀

	// bottom1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -44.71f,67.71f,21.98f };
	unit->transform->eulerAngles.y = D3DXToRadian(225.f);
	unit->SetTeam(Team::RED);
	// bottom2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -41.30f,67.71f,-1.89f };
	unit->transform->eulerAngles.y = D3DXToRadian(225.f);
	unit->SetTeam(Team::RED);
	// bottom3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -43.20f,68.f,-16.83f };
	unit->transform->eulerAngles.y = D3DXToRadian(225.f);
	unit->SetTeam(Team::RED);

	// mid1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -13.30f,67.71f,-3.61f };
	unit->transform->eulerAngles.y = D3DXToRadian(270.f);
	unit->SetTeam(Team::RED);
	
	// mid2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -18.52f,67.71f,-13.85f };
	unit->transform->eulerAngles.y = D3DXToRadian(270.f);
	unit->SetTeam(Team::RED);
	
	// mid3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -27.21f,68.f,-20.97f };
	unit->transform->eulerAngles.y = D3DXToRadian(270.f);
	unit->SetTeam(Team::RED);
	

	// top1
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { 16.28f,67.71f,-37.99f };
	unit->transform->eulerAngles.y = D3DXToRadian(315.f);
	unit->SetTeam(Team::RED);
	// top2
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -6.93f,67.71f,-34.96f };
	unit->transform->eulerAngles.y = D3DXToRadian(315.f);
	unit->SetTeam(Team::RED);
	// top3
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -23.09f,68.f,-36.63f };
	unit->transform->eulerAngles.y = D3DXToRadian(315.f);
	unit->SetTeam(Team::RED);

	// twin left
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -39.52f,68.00f,-29.97f };
	unit->transform->eulerAngles.y = D3DXToRadian(270.f);
	unit->SetTeam(Team::RED);
	// twin right
	unit = (Unit*)ObjectManager::GetInstance()->CreateObject<Turret>(Layer::Building);
	unit->transform->position = { -36.64f,68.00f,-32.90f };
	unit->transform->eulerAngles.y = D3DXToRadian(270.f);
	unit->SetTeam(Team::RED);
	//testUnit = unit;



	// 미니언
	

	//obj = ObjectManager::GetInstance()->CreateObject<OrderMinionMelee>(Layer::Unit);
	//obj->transform->position = { 23,68,38 };
	//obj = ObjectManager::GetInstance()->CreateObject<OrderMinionSiege>(Layer::Unit);
	//obj->transform->position = { 20,68,38 };
	//obj = ObjectManager::GetInstance()->CreateObject<OrderMinionSuper>(Layer::Unit);
	//obj->transform->position = { 17,68,38 };
	//
	//obj = ObjectManager::GetInstance()->CreateObject<ChaosMinionCaster>(Layer::Unit);
	//obj->transform->position = { 26,68,39 };
	//obj = ObjectManager::GetInstance()->CreateObject<ChaosMinionMelee>(Layer::Unit);
	//obj->transform->position = { 23,68,39 };
	//obj = ObjectManager::GetInstance()->CreateObject<ChaosMinionSiege>(Layer::Unit);
	//obj->transform->position = { 20,68,39 };
	//obj = ObjectManager::GetInstance()->CreateObject<ChaosMinionSuper>(Layer::Unit);
	//obj->transform->position = { 17,68,39 };
}

void TestScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{
	if (testUnit != nullptr)
	{
		if (InputManager::GetKey(VK_UP))
		{
			testUnit->transform->position.z -= TimeManager::DeltaTime();
			printf("%.2ff,%.2ff,%.2ff\n", testUnit->transform->position.x, testUnit->transform->position.y, testUnit->transform->position.z);

		}
		if (InputManager::GetKey(VK_DOWN))
		{
			testUnit->transform->position.z += TimeManager::DeltaTime();
			printf("%.2ff,%.2ff,%.2ff\n", testUnit->transform->position.x, testUnit->transform->position.y, testUnit->transform->position.z);

		}
		if (InputManager::GetKey(VK_LEFT))
		{
			testUnit->transform->position.x += TimeManager::DeltaTime();
			printf("%.2ff,%.2ff,%.2ff\n", testUnit->transform->position.x, testUnit->transform->position.y, testUnit->transform->position.z);

		}
		if (InputManager::GetKey(VK_RIGHT))
		{
			testUnit->transform->position.x -= TimeManager::DeltaTime();
			printf("%.2ff,%.2ff,%.2ff\n", testUnit->transform->position.x, testUnit->transform->position.y, testUnit->transform->position.z);

		}
	}
	
	if (InputManager::GetKeyDown('M'))
	{
		CreateMinionCaster();
	}
}

void TestScene::CreateMinionCaster()
{
	Minion* minion = nullptr;
	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<OrderMinionCaster>(Layer::Unit);
	minion->transform->position = { 29.47f,68.04f,41.74f };
	minion->SetTeam(Team::BLUE);
	minion->ai->nextPoint = { -30.88f,67.71f,40.80f };
	minion->ai->wayPoint.push_back(Vector3(-42.32f, 67.71f, 28.58f));
	minion->ai->wayPoint.push_back(Vector3(-42.87f, 68.01f, -36.16f));

	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<OrderMinionCaster>(Layer::Unit);
	minion->transform->position = { 30.64f,68.04f,37.51f };
	minion->SetTeam(Team::BLUE);
	minion->ai->nextPoint = { -3.49f,67.72f,3.92f };
	minion->ai->wayPoint.push_back(Vector3(-42.87f, 68.01f, -36.16f));

	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<OrderMinionCaster>(Layer::Unit);
	minion->transform->position = { 35.00f,68.04f,35.55f };
	minion->SetTeam(Team::BLUE);
	minion->ai->nextPoint = { 34.58f,67.71f,-23.79f };
	minion->ai->wayPoint.push_back(Vector3(23.98f, 67.71f, -34.88f));
	minion->ai->wayPoint.push_back(Vector3(-42.87f, 68.01f, -36.16f));

	// 레드
	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<ChaosMinionCaster>(Layer::Unit);
	minion->transform->position = { -43.05f,68.01f,-29.62f };
	minion->SetTeam(Team::RED);
	minion->ai->nextPoint = { -42.32f,67.71f,28.58f };
	minion->ai->wayPoint.push_back(Vector3(-30.88f, 67.71f, 40.80f));
	minion->ai->wayPoint.push_back(Vector3(36.59f, 68.05f, 42.96f));

	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<ChaosMinionCaster>(Layer::Unit);
	minion->transform->position = { -36.94f,68.01f,-30.35f };
	minion->SetTeam(Team::RED);
	minion->ai->nextPoint = { -3.49f,67.72f,3.92f };
	minion->ai->wayPoint.push_back(Vector3(36.59f, 68.05f, 42.96f));

	minion = (Minion*)ObjectManager::GetInstance()->CreateObject<ChaosMinionCaster>(Layer::Unit);
	minion->transform->position = { -36.68f,68.01f,-36.45f };
	minion->SetTeam(Team::RED);
	minion->ai->nextPoint = { 23.98f,67.71f,-34.88f };
	minion->ai->wayPoint.push_back(Vector3(34.58f, 67.71f, -23.79f));
	minion->ai->wayPoint.push_back(Vector3(36.59f, 68.05f, 42.96f));
}
