#pragma once
#include "stat.h"
namespace sgl {
	class PrecisionStatSet {
	protected: 
		StatValue baseAttack, meleeAttack, rangedAttack, magicPrecision;
		StatValue baseDefense, reflexDefense, vigorDefense, willDefense;
	public:
		StatValue getBaseAttack() const;
		StatValue getMeleeAttack() const;
		StatValue getRangedAttack() const;
		StatValue getMagicPrecision() const;
		StatValue getBaseDefense() const;
		StatValue getReflexDefense() const;
		StatValue getVigorDefense() const;
		StatValue getWillDefense() const;
	protected:
		PrecisionStatSet(
			StatValue=0, StatValue=0, StatValue=0, StatValue=0, 
			StatValue=0, StatValue=0, StatValue=0, StatValue=0);
	public:
		void modBaseAttack(StatValue);
		void modMeleeAttack(StatValue);
		void modRangedAttack(StatValue);
		void modMagicPrecision(StatValue);
		void modBaseDefense(StatValue);
		void modReflexDefense(StatValue);
		void modVigorDefense(StatValue);
		void modWillDefense(StatValue);
		void modPrecisionStatSet(
			StatValue, StatValue, StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue);
	};
}