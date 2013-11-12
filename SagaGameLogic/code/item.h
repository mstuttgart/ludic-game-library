#pragma once
#include "entity.h"
#include "stat.h"
#include "stuff.h"
namespace sgl {
	class Character;
	class EquipItemSet;
	typedef long Currency;
	enum class Rarity {
		COMMON, RARE, LEGENDARY,
	};
	class Item: public Entity {
	private:
		Rarity rarity;
		StatValue load;
		Currency price;
	public:
		Rarity getRarity() const;
		StatValue getLoad() const;
		Currency getPrice() const;
		Item(Rarity=Rarity::COMMON, StatValue=0, Currency=0);
		void setRarity(Rarity);
		void setLoad(StatValue);
		void setPrice(Currency);
	public:
		virtual void use(Character&)=0;
	};
	class Material: public Item {
	private:
		StatValue mineralValue, vegetalValue, animalValue, magicValue;
	public:
		StatValue getMineralValue() const;
		StatValue getVegetalValue() const;
		StatValue getAnimalValue() const;
		StatValue getMagicValue() const;
		Material(StatValue=0, StatValue=0, StatValue=0, StatValue=0);
		void setMineralValue(StatValue);
		void setVegetalValue(StatValue);
		void setAnimalValue(StatValue);
		void setMagicValue(StatValue);
		void use(Character&);
	};
	class BoostItem: public Material {
	private:
		const StatStruct modification;
		//0: recovery/final, -1: gemStone, >1: buff
		RoundTime duration;
	public:
		const StatStruct& getModification() const;
		RoundTime getDuration() const;
		BoostItem(const StatStruct&, RoundTime=0);
		void setDuration(RoundTime);
	public:
		void use(Character&);
	};
	class EquipItem: public Material {
	private:
		StatStruct* modification;
	public:
		StatStruct* getModification() const;
		EquipItem();
		void setModification(StatStruct&);
		void setModification();
	public:
		virtual void use(Character&)=0;
		void aux(EquipItemSet&, bool) const;
	};
}