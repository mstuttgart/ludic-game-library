#pragma once
#include "stat.h"
namespace sgl {
	enum class MagicCondition {
		NUMB, COMA, NORMAL,
	};
	enum class ActionCondition {
		FREEZE, SHOCK, NORMAL,
	};
	class MagicEnergySet {
	private: 
		const StatValue MAGIC_INTELLIGENCE=1;
		MagicCondition magicCondition=MagicCondition::NORMAL;
		ActionCondition actionCondition=ActionCondition::NORMAL;
		StatValue magicQuantity, furyEnergy, magicCapacity, spiritEnergy, magicLimit;
	public:
		StatValue getMagicQuantity() const;
		StatValue getFuryEnergy() const;
		StatValue getMagicCapacity() const;
		StatValue getSpiritEnergy() const;
		StatValue getMagicLimit() const;
	public:
		MagicCondition getMagicCondition() const;
		ActionCondition getActionCondition() const;
		void setMagicCondition(MagicCondition);
		void setActionCondition(ActionCondition);
	protected:
		MagicEnergySet(StatValue=0, StatValue=0, StatValue=0, bool=false);
	public:
		void zeroMagicQuantity();
		void fullMagicQuantity();
		void modMagicQuantity(StatValue);
		void magicQuantityRecovery();
		void modFuryEnergy(StatValue);
		void zeroMagicCapacity();
		void fullMagicCapacity();
		void modMagicCapacity(StatValue);
		void magicCapacityRecovery();
		void modSpiritEnergy(StatValue);
		void modMagicLimit(StatValue);
	};
}