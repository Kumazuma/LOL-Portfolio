#pragma once



#define SERVER_PORT 1222


enum USER_MESSAGE
{
	UM_NETWORK = (WM_USER + 1),
};

enum PROTOCOL
{
	TEST_REQ = 11,
	TEST_RES,
	//=================================
	// ★ 게임 서버 ★
	//=================================
	GAME_SERVER = 1000,
	//---------------------------------
	// 닉네임 중복체크 요청(게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	WCHAR	nickName[20]	// NULL포함
	//---------------------------------
	GAME_REQ_NICK,
	//---------------------------------
	// 닉네임 중복체크 응답(게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	WCHAR	nickName[20]	// NULL포함
	//	BYTE	status
	//---------------------------------
	GAME_RES_NICK,
	//---------------------------------
	// 로그인 요청(게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	WCHAR	nickName[20]	// NULL포함
	//---------------------------------
	GAME_REQ_LOGIN,
	//---------------------------------
	// 로그인 응답(게임서버 -> 클라이언트)
	//
	// WORD	type
	// WCHAR	nickName[20]	// NULL포함
	// INT64	sessionID
	// BYTE	status	//0:실패 1:성공
	//---------------------------------
	GAME_RES_LOGIN,
	//---------------------------------
	// 게임 참가 요청(게임서버 <- 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_REQ_JOIN_GAME,
	//---------------------------------
	// 게임 참가 응답(게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	
	//	UINT	userCount
	//	{
	//		WCHAR	nickName[20] // NULL포함
	//		UINT	number
	//	}
	//	
	//---------------------------------
	GAME_RES_JOIN_GAME,
	//---------------------------------
	// 챔피언 선택 요청(게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	BYTE	champ
	//---------------------------------
	GAME_REQ_SELECT_CHAMP,
	//---------------------------------
	// 챔피언 선택 응답(게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	UINT	userNum
	//	BYTE	champ
	//---------------------------------
	GAME_RES_SELECT_CHAMP,
	//---------------------------------
	// 준비 요청(게임서버 <- 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_REQ_READY,
	//---------------------------------
	// 준비 응답(게임서버 -> 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_RES_READY,
	//---------------------------------
	// 시작 응답(게임서버 -> 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_RES_START,
	//======================== 인게임 로딩 =====================
	//---------------------------------
	// 인게임 접속 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	WCHAR	nickName[20]	// NULL포함
	//---------------------------------
	GAME_REQ_ENTER_GAME,
	//---------------------------------
	// 인게임 접속 응답 (게임서버 -> 클라이언트)
	// (로딩씬에 표시할 정보들)
	//
	//	WORD	type
	//	INT		userCount
	//	{
	//		WCHAR	nickName[20]	// NULL포함
	//		INT		numInRoom
	//		BYTE	champ
	//	}
	//---------------------------------
	GAME_RES_ENTER_GAME,
	//---------------------------------
	// 로딩 진행률 요청 (게임서버 <- 클라이언트)
	// (해당 진행률이 1이면 완료)
	//
	//	WORD	type
	//	FLOAT	progress
	//---------------------------------
	GAME_REQ_LOADING,
	//---------------------------------
	// 로딩 진행률 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	INT		userNumber
	//	FLAOT	progress
	//---------------------------------
	GAME_RES_LOADING,
	//---------------------------------
	// 로딩 완료 요청 (게임서버 <- 클라이언트)
	// (해당 진행률이 1이면 완료)
	//
	//	WORD	type
	//---------------------------------
	GAME_REQ_COMPLETE_LOADING,
	//---------------------------------
	// 로딩 완료 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_RES_COMPLETE_LOADING,

	//============================================ 게임씬 =============
	//---------------------------------
	// 지연시간 측정 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	DWORD	time
	//---------------------------------
	GAME_REQ_TIME,
	//---------------------------------
	// 지연시간 측정 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	DWORD	time
	//---------------------------------
	GAME_RES_TIME,
	
	//---------------------------------
	// 이동 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	INT		userNO
	//	FLOAT	x
	//	FLOAT	y
	//	FLOAT	z
	//---------------------------------
	GAME_REQ_MOVE,
	//---------------------------------
	// 이동 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	INT		userNO
	//	FLOAT	x
	//	FLOAT	y
	//	FLOAT	z
	//---------------------------------
	GAME_RES_MOVE,

	//---------------------------------
	// 공격 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	INT		unitNO
	//	INT		targetNO
	//---------------------------------
	GAME_REQ_ATTACK,
	//---------------------------------
	// 공격 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	INT		unitNO
	//	INT		targetNO
	//---------------------------------
	GAME_RES_ATTACK,

	//---------------------------------
	// 데미지 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//	INT		unitNO
	//	INT		targetNO
	//	FLAOT	damage
	//---------------------------------
	GAME_REQ_DAMAGE,
	//---------------------------------
	// 데미지 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//	INT		unitNO
	//	INT		targetNO
	//	FLAOT	damage
	//---------------------------------
	GAME_RES_DAMAGE,

	//---------------------------------
	// 미니언 생성 요청 (게임서버 <- 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_REQ_CREATE_MINION_CASTER,
	//---------------------------------
	// 미니언 생성 응답 (게임서버 -> 클라이언트)
	//
	//	WORD	type
	//---------------------------------
	GAME_RES_CREATE_MINION_CASTER,
};