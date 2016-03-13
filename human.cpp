#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Human {
	
	private:
	
		string name;
		int height;
		int weight;
		static int numOfHumans;
	
	public: 
		virtual void getClass() { cout << "I am a human" << endl; }
		void setName(string humanName){
			name = humanName;
		}
		
		void setHeight(int cm) {
			height = cm;
		} 
		
		void setWeight(int kg) {
			weight = kg;
		}
		
		string getName() { return name; }
		int getHeight() { return height; }
		int getWeight() { return weight; }
		
		Human();
		Human(string, int, int);
		~Human();
		static getNumOfHumans() { return numOfHumans; }
		void toString();
		
};


//numOfHumans in total
int Human::numOfHumans = 0;
//set ctor
Human::Human(string name, int height, int weight) {
	this -> name = name;
	this -> height = height;
	this -> weight = weight;
	Human::numOfHumans++;
}

//dtor 
Human::~Human() {
	
	cout << this -> name << " is destroyed " << endl;

}

Human::Human() {
	
	Human::numOfHumans++;
}

//override toString function
void Human::toString() {
	cout <<  this -> name << " is approximately " << this -> height << "cm tall" << " and " <<
		this -> weight << "kg of weight" << endl;
}

//********************MEN**********************
class Man : public Human {
	
	private: 
		string speech;
		int walk;
		static int countOfMen;
		
	public:
		
		string getSpeech() {
			
			cout << "Hi my name is" << this -> getName() << endl;
		}
		int getWalk()
		{
			cout << walk << "m" << endl;
		}
		
		Man(string,int,int,string,int);
		
		Man() : Human(){};
		
		void toString();
		
		void getClass() {
			cout << "I am a male" << endl;
		}
		static getCountOfMen() { return countOfMen;}
};

int Man::countOfMen = 0;

Man::Man(string name, int height, int weight, string speech, int walk) :
Human(name, height, weight) {
		this -> speech = speech;
		this -> walk = walk;
		Man::countOfMen++;
	}


	
void Man::toString() {
	cout <<  this -> getName() << " is approximately " << this -> getHeight() << "cm tall and " <<
		this -> getWeight() << "kg of weight. Also " << this -> getName() << " says " << 
		this -> speech << " after walking about " << this -> walk << " miles." << endl;
}
//************FEMALES*************
class Female : public Human {
	
	private:
	
		string cleavage;
		static int countOfWomen;
		
	public:
	
		void getClass() { cout << "I am a female" << endl;}
		
		bool getGender() { return true;}
		
		Female(string, int, int);
		
		//calls superclass ctor
		Female() : Human(){};
		
		void toString();
		
		string getCleavage(Female* female) {
			if(female -> getGender() == true) {
				return "true";
			}
			else {
				return "false";
			}
			
		}
		static getCountOfWomen() { return countOfWomen;}
};
int Female::countOfWomen = 0;


Female::Female(string name, int height, int weight) :
Human::Human(name, height, weight) {
	
	Female::countOfWomen++;
}

void Female::toString() {
	Female* female = new Female();
	cout << "Hi my name is " << this -> getName() << " and I am " << this -> getHeight() << "cm tall "
		<< "and I weight about " << this -> getWeight() << "kg. Since I am a women it is " << 
		getCleavage(female) << " that I have cleavage." << endl;
}



int main(){
	
	Human sam;
	sam.setName("Sam");
	sam.setHeight(175);
	sam.setWeight(14);
	
	Human dan;
	dan.setName("Nathan");
	dan.setHeight(175);
	dan.setWeight(13);
	sam.toString();
	dan.toString();
	cout << "The number of humans created is " << Human::getNumOfHumans() << endl; 
	Man male1("James",185,10, "Salut", 15);
	Man male2("Dan",180, 14,"Hello", 12);
	male1.toString();
	male2.toString();
	cout <<"The number of men created is " <<  Man::getCountOfMen() << endl;
	
	Female female1("Jesse", 160, 10);
	female1.toString();
	
	Female francine;
	francine.toString();
	cout << "The number of women created is " << Female::getCountOfWomen() << endl;
	
	
	
	//********Test Class******
	Human* human = new Human;
	Female* female = new Female;
	Man* male = new Man;
	human -> getClass();
	female -> getClass();
	male -> getClass();
	//Explicitly downcasting
	Human david;
	Man* ptrHuman = (Man *) &david;
	ptrHuman -> getClass();
	//Implicitly Upcasting
	Female danielle;
	
	
	Human* ptrFemale = &francine;
	ptrFemale -> getClass();
	

	return 0;
}