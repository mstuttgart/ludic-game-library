#include "equipitem.h"
using namespace std;
using namespace sgl;
const Item* EquipItemSet::getOneItem(int position) const {
	try {
		return itemList.at(position);
	} catch(std::exception& x) {
		return nullptr;
	}
}
const ItemList EquipItemSet::getItemList() const {
	return itemList;
}
const Armor* EquipItemSet::getArmor() const {
	return armor;
}
const Veil* EquipItemSet::getVeil() const {
	return veil;
}
const Weapon* EquipItemSet::getWeapon() const {
	return weapon;
}
const Accessory* EquipItemSet::getAccessory() const {
	return accessory;
}
const Shield* EquipItemSet::getShield() const {
	return shield;
}
const Charm* EquipItemSet::getCharm() const {
	return charm;
}
Item* EquipItemSet::takeOneItem(int position) {
	try {
		swap(itemList.at(position), itemList.back());
		Item* aux=itemList.back();
		modTotalLoad(-aux->getLoad());
		itemList.pop_back();
		return aux;
	} catch(exception& x) {
		return nullptr;
	}
}
bool EquipItemSet::pickOneItem(Item& item) {
	const StatValue& aux=totalLoad+item.getLoad();
	if(aux<=loadLimit) {
		itemList.push_back(&item);
		modTotalLoad(+item.getLoad());
		return true;
	} else return false;
}
bool EquipItemSet::disposeItem(int position) {
	Item* aux=takeOneItem(position);
	if(aux) {
		delete aux;
		return true;
	} else return false;
}
void EquipItemSet::modArmor() {
	if(armor) {
		armor->aux(*this, false);
		modVigorDefense(-armor->getVigorDefense());
		modNormalProtection(-armor->getNormalProtection());
		modLifeLimit(-armor->getLifeEnergy());
		armor=nullptr;
	}
}
void EquipItemSet::modVeil() {
	if(veil) {
		veil->aux(*this, false);
		modWillDefense(-veil->getWillDefense());
		modMagicProtection(-veil->getMagicProtection());
		modMagicLimit(-veil->getMagicEnergy());
		veil=nullptr;
	}
}
void EquipItemSet::modWeapon() {
	if(weapon) {
		weapon->aux(*this, false);
		setAttackType(AttackType::MELEE);
		actionTime=2;
		modRandomDamage(-weapon->getRandomDamage());
		modMeleeDamage(-weapon->getNormalDamage());
		modRangedDamage(-weapon->getNormalDamage());
		modMagicPower(-weapon->getMagicPower());
		setDamageType(DamageType::PHYSIC);
		weapon=nullptr;
	}
}
void EquipItemSet::modShield() {
	if(shield) {
		shield->aux(*this, false);
		modReflexDefense(-shield->getReflexDefense());
		modNormalProtection(-shield->getNormalProtection());
		modMagicProtection(-shield->getMagicProtection());
		shield=nullptr;
	}
}
void EquipItemSet::modAccessory() {
	if(accessory) {
		accessory->aux(*this, false);
		modMeleeAttack(-accessory->getMeleeAttack());
		modRangedAttack(-accessory->getRangedAttack());
		modMeleeDamage(-accessory->getMeleeDamage());
		modRangedDamage(-accessory->getRangedDamage());
		accessory=nullptr;
	}
}
void EquipItemSet::modCharm() {
	if(charm) {
		charm->aux(*this, false);
		modMagicPrecision(-charm->getMagicPrecision());
		modTotalTech(-charm->getTotalTech());
		modMagicPower(-charm->getMagicPower());
		charm=nullptr;
	}
}
bool EquipItemSet::modArmor(const Armor& item) {
	if(hasEnoughForce(item)) {
		modArmor();
		item.aux(*this, true);
		modVigorDefense(+item.getVigorDefense());
		modNormalProtection(+item.getNormalProtection());
		modLifeLimit(+item.getLifeEnergy());
		armor=&item;
		return true;
	} else return false;
}
bool EquipItemSet::modVeil(const Veil& item) {
	if(hasEnoughForce(item)) {
		modVeil();
		item.aux(*this, true);
		modWillDefense(+item.getWillDefense());
		modMagicProtection(+item.getMagicProtection());
		modMagicLimit(+item.getMagicEnergy());
		veil=&item;
		return true;
	} else return false;
}
bool EquipItemSet::modWeapon(const Weapon& item) {
	if(hasEnoughForce(item)) {
		modWeapon();
		switch(item.getSize()) {
			case Size::BIG: modShield();
			case Size::MEDIUM: modAccessory();
			default: break;
		}
		item.aux(*this, true);
		setAttackType(item.getAttackType());
		actionTime=item.getActionTime();
		modRandomDamage(+item.getRandomDamage());
		modMeleeDamage(+item.getNormalDamage());
		modRangedDamage(+item.getNormalDamage());
		modMagicPower(+item.getMagicPower());
		setDamageType(item.getDamageType());
		weapon=&item;
		return true;
	} else return false;
}
bool EquipItemSet::modShield(const Shield& item) {
	if(hasEnoughForce(item)) {
		modAccessory();
		modShield();
		if(weapon&&weapon->getSize()==Size::BIG) modWeapon();
		item.aux(*this, true);
		modReflexDefense(+item.getReflexDefense());
		modNormalProtection(+item.getNormalProtection());
		modMagicProtection(+item.getMagicProtection());
		shield=&item;
		return true;
	} else return false;
}
bool EquipItemSet::modAccessory(const Accessory& item) {
	if(hasEnoughForce(item)) {
		modAccessory();
		modShield();
		if(weapon&&weapon->getSize()!=Size::SMALL) modWeapon();
		item.aux(*this, true);
		modMeleeAttack(+item.getMeleeAttack());
		modRangedAttack(+item.getRangedAttack());
		modMeleeDamage(+item.getMeleeDamage());
		modRangedDamage(+item.getRangedDamage());
		accessory=&item;
		return true;
	} else return false;
}
bool EquipItemSet::modCharm(const Charm& item) {
	if(hasEnoughForce(item)) {
		modCharm();
		item.aux(*this, true);
		modMagicPrecision(+item.getMagicPrecision());
		modTotalTech(+item.getTotalTech());
		modMagicPower(+item.getMagicPower());
		charm=&item;
		return true;
	} else return false;
}