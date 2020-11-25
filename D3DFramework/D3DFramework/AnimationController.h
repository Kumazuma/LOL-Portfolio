#pragma once

namespace PKH
{
	class AnimationController : public BaseObject
	{
	private:
		explicit AnimationController(LPD3DXANIMATIONCONTROLLER pAniCtrl);
		explicit AnimationController(const AnimationController& rhs);
		virtual ~AnimationController(void);

	public:
		LPD3DXANIMATIONCONTROLLER		Get_AnimationCtrl(void) { return m_pAniCtrl; }
		bool							Is_AnimationSetEnd(void);

	public:
		HRESULT			Ready_AnimationCtrl(void);

		void			Set_AnimationSet(const UINT& iIndex);

		void			Play_Animation(const float& fTimeDelta);

	private:
		LPD3DXANIMATIONCONTROLLER			m_pAniCtrl;

		UINT								m_iCurrentTrack;
		UINT								m_iNewTrack;

		float								m_fAccTime;
		UINT								m_iOldAniIdx;

		double								m_dPeriod = 0.0;

	public:
		static AnimationController* Create(LPD3DXANIMATIONCONTROLLER pAniCtrl);
		static AnimationController* Create(const AnimationController& rhs);
		virtual void				Free(void);

	};

}

