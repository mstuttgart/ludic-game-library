#pragma once
#include <string>

namespace sgl {
	class Entity {
	private:
		std::string name;
		std::string description;
	public:
		const std::string& getName() const {
			return name;
		}
		const std::string& getDescription() const {
			return description;
		}
		void setName(const std::string& name) {
			this->name=name;
		}
		void setDescription(const std::string& description) {
			this->description=description;
		}
	protected:	
		//construtor parametrizado
		Entity(std::string name="Alfredo", std::string description="Barbosa"): 
			name(name), description(description) {}
		//destrutor virtual
		virtual ~Entity() {}
	};
}