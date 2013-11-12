#pragma once
#include <functional>
namespace sgl {
	//referência
	class Character;
	//compactação do código
	typedef short StatValue;
	//simplificação do código
	typedef std::function<StatValue(const Character&)> GetFunction;
	typedef std::function<void(Character&, StatValue)> ModFunction;
/*	
	O atributo (Stat) é uma característica numérica: qualquer característica 
	numérica, na verdade, pode ser tratada como um atributo no Saga. O atributo 
	é caracterizado por um tipo ou nome e um valor: o tipo identifica a sua função 
	na caracterização do personagem e o valor é o nível do atributo – a maioria 
	funciona de uma forma direta: valor maior, atributo melhor.
*/
	class StatId {
	public: static const StatId
		//declaração das instãncias da classe
		STRENGTH, AGILITY, CONSTITUTION, INTELLIGENCE, PERCEPTION, CHARISM,
		BASE_ATTACK, MELEE_ATTACK, RANGED_ATTACK, MAGIC_PRECISION,
		BASE_DEFENSE, REFLEX_DEFENSE, VIGOR_DEFENSE, WILL_DEFENSE,
		LIFE_QUANTITY, STAMINA_ENERGY, LIFE_CAPACITY, HEALTH_ENERGY, LIFE_LIMIT, 
		MAGIC_QUANTITY, FURY_ENERGY, MAGIC_CAPACITY, SPIRIT_ENERGY, MAGIC_LIMIT,
		BASE_PROTECTION, NORMAL_PROTECTION, MAGIC_PROTECTION, TOTAL_TECH,
		RANDOM_DAMAGE, MELEE_DAMAGE, RANGED_DAMAGE, MAGIC_POWER,
		PHYSIC_AFFINITY, ICE_AFFINITY, LIGHTNING_AFFINITY, FIRE_AFFINITY,
		PSYCHIC_AFFINITY, BIOLOGIC_AFFINITY, ARCANE_AFFINITY, HOLY_AFFINITY,
		INSTANT_ATTACK, INSTANT_DEFENSE, INSTANT_DAMAGE, INSTANT_PROTECTION;
	private: //os únicos atributos desta classe são na verdade funções
		const GetFunction getFunction;
		const ModFunction modFunction;
	private: //construtor privado e único
		StatId(GetFunction, ModFunction);
	public: //interface da classe (ela é só uma interface mesmo)
		StatValue getStat(const Character&) const;
		void modStat(Character&, StatValue) const;
	};
/*
	Embora a identificação do atributo já esteja resolvida e definida, 
	é normal que uma modificação seja a associação de um atributo com uma variação, 
	de forma que se faz necessária uma classe que defina essa associação. 
	Para possibilitar a ativação e a desativação da modificação, 
	é necessário ainda que ela tenha um método que faça a operação inversa da modificação. 
*/
	class StatStruct {
	private:
		const StatId& statId;
		StatValue statValue;
	public:
		const StatId& getStatId() const;
		StatValue getStatValue(bool=true) const;
	public:
		StatStruct(const StatId&, StatValue=0);
	public:
		void setStatValue(StatValue);
		void modStatValue(StatValue);
	public:
		StatValue getCharStat(const Character&) const;
		void modCharStat(Character&, bool) const;
	};
}