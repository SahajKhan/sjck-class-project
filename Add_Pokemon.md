# Add Pokemon:

To add a Pokémon go to the Derived Pokémon file and Add your Pokémon here.

There is a template at the bottom of the File with instructions on how to add your Pokémon

	class __________ : public Pokemon {		// <-- Name your pokemon
	private:
		string attack1Name;
		string attack2Name;
		string attack3Name;
		Element* element;
	public:
		_____________() : 					// <-- Add the name of your pokemon to the constructor
		Pokemon("_________", __) {				// input name of pokemon as first parameter(string), total HP in second parameter (int)
			this->attack1Name = "___________";		// <-- input the name of first attack; string type (string )
			this->attack2Name = "___________";		// <-- input the name of second attack; string type (string )
			this->attack3Name = "___________";		// <-- input the name of third attack or name it critical second attack; (string )
			this->element = new ___________();		// <--- input your pokemon's element TYPE
									// elements to choose from: Psychic, Colorless, Fire, Grass, Water, Lightning 
		}
		~____________() {					// <-- add your pokemon's name to the constructor
			delete element;
			element = NULL;
		}

		Element* getElement() { return this->element;}
		std::string getAttack1Name() {return this->attack1Name;}
		std::string getAttack2Name() {return this->attack2Name;}
		std::string getAttack3Name() {return this->attack3Name;}

	};

