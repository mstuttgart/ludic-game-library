#pragma once
#include "stat.h"
namespace sgl {
	class BaseStatSet {
	protected: StatValue
		strength, agility, constitution, intelligence, perception, charism;
	public:
		StatValue getStrength() const;
		StatValue getAgility() const;
		StatValue getConstitution() const;
		StatValue getIntelligence() const;
		StatValue getPerception() const;
		StatValue getCharism() const;
	protected:
		BaseStatSet(StatValue=0, StatValue=0, 
			StatValue=0, StatValue=0, StatValue=0, StatValue=0);
	public:
		virtual void modStrength(StatValue)=0;
		virtual void modAgility(StatValue)=0;
		virtual void modConstitution(StatValue)=0;
		virtual void modIntelligence(StatValue)=0;
		virtual void modPerception(StatValue)=0;
		virtual void modCharism(StatValue)=0;
		void modBaseStatSet(
			StatValue, StatValue, StatValue, StatValue, StatValue, StatValue);
	};


}