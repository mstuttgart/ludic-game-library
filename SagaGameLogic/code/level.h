#pragma once
#include "stat.h"
/*
	classe (multiton) que define a profissão do personagem
*/
namespace sgl {
	class JobEnum {
	private: //multiton
		JobEnum(StatValue, StatValue, StatValue, 
			StatValue, StatValue, StatValue, StatValue);
	public: static const JobEnum NONE,
		COMMONER, WARRIOR, ROGUE, MAGE, CLERIC, SAVAGE, BARD,
		KNIGHT, NINJA, WIZARD, PRIEST, DRUID, NOBLE,
		ASSASSIN, SOLDIER, CRUSADER, BARBARIAN, SWASHBUCKLER,
		WARLOCK, NECROMANCER, RANGER, ILLUSIONIST,
		SORCERER, WITCH, ENCHANTER, SHAMAN, PACIFIER, GYPSY;
	private:
		const StatValue attack, defense, tech;
		const StatValue life, fury, spirit, magic;
	public:
		StatValue getAttack() const;
		StatValue getDefense() const;
		StatValue getTech() const;
		StatValue getLife() const;
		StatValue getFury() const;
		StatValue getSpirit() const;
		StatValue getMagic() const;
		bool operator==(const JobEnum& job) const;
	};
/*
	classe definida para ligar uma classe a um personagem
*/
	class JobClass {
	private:
		const JobEnum* job;
		StatValue level=0;
	public:
		const JobEnum& getJob() const;
		StatValue getLevel() const;
		void setJob(const JobEnum&);
		void setLevel(StatValue value);
		void modLevel(StatValue value);
	public:
		JobClass();
		JobClass(const JobEnum&);
	};
}