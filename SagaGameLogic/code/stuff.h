#pragma once
namespace sgl {
	typedef short TimeUnit;
	typedef TimeUnit RoundTime;
	typedef short SpaceUnit;
	enum class Size {
		NONE, SMALL, MEDIUM, BIG, HUGE,
	};
	enum class AttackType {
		NONE=-1, MELEE=0, THROWING=2, RANGED=6, MAGIC=12,
	};
	enum class DamageType {
		NONE, PHYSIC, ICE, LIGHTNING, FIRE,
		PSYCHIC, BIOLOGIC, ARCANE, HOLY,
	};
}

