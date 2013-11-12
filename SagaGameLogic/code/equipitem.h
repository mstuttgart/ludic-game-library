#pragma once
#include <vector>
#include "life.h"
#include "energy.h"
#include "common.h"
#include "equip.h"
namespace sgl {
	typedef std::vector<Item*> ItemList;
	class EquipItemSet:
		public LifeEnergySet,
		public MagicEnergySet,
		public EquipStatSet {
	protected:
		ItemList itemList;
		const Armor* armor=nullptr;
		const Veil* veil=nullptr;
		const Weapon* weapon=nullptr;
		const Accessory* accessory=nullptr;
		const Shield* shield=nullptr;
		const Charm* charm=nullptr;
	public:
		const Item* getOneItem(int) const;
		const ItemList getItemList() const;
		const Armor* getArmor() const;
		const Veil* getVeil() const;
		const Weapon* getWeapon() const;
		const Shield* getShield() const;
		const Charm* getCharm() const;
		const Accessory* getAccessory() const;
	public:
		Item* takeOneItem(int);
		bool pickOneItem(Item&);
		bool disposeItem(int);
		void modArmor();
		void modVeil();
		void modWeapon();
		void modAccessory();
		void modShield();
		void modCharm();
		bool modArmor(const Armor&);
		bool modVeil(const Veil&);
		bool modWeapon(const Weapon&);
		bool modAccessory(const Accessory&);
		bool modShield(const Shield&);
		bool modCharm(const Charm&);

	};
}