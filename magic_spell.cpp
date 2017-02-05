#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
	string scrollName;
public:
	Spell(): scrollName("") {}
	Spell(string name): scrollName(name) {}
	virtual ~Spell() {}
	string revealScrollName() {
		return scrollName;	
	}
};

class Fireball : public Spell {
private:
	int power;
public:
	Fireball(int power): power(power)  {}
	void revealFirepower() {
		cout << "Fireball: " << power << endl;	
	}
};

class Frostbite: public Spell {
private:
	int power;
public:
	Frostbite(int power): power(power) {}
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private:
	int power;
public:
	Thunderstorm(int power): power(power) {}
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;	
	}
};

class Waterbolt : public Spell {
private:
	int power;
public:
	Waterbolt(int power): power(power) {}
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;	
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;	
	}
};

string SpellJournal::journal = "";

int maximum( int a, int b, int c ) { 
	int max = a > b ? a : b;
	return  max > c ? max : c;
}

int same(const string& a, int i, const string& b, int j) {
	return a[i]	== b[j] ? 1 : 0;
}

int cal_lcs_length(const string& a, const string& b) {
	int m = a.length() + 1;		
	int n = b.length() + 1;		
	vector <vector<int>> matrix(m, vector<int>(n));
    for(int f=1; f<m; f++) {
        for(int c=1; c<n; c++) {
			matrix[f][c] = maximum(matrix[f-1][c-1]+same(a, f-1, b, c-1), matrix[f-1][c], matrix[f][c-1]);
        }
    }  
	return matrix[m-1][n-1];
}

void counterspell(Spell* spell) {
// Enter your code here
	if(Fireball* v = dynamic_cast<Fireball*>(spell)) {
		v->revealFirepower();
	} else if(Frostbite* v = dynamic_cast<Frostbite*>(spell)) {
		v->revealFrostpower();	
	} else if(Waterbolt* v = dynamic_cast<Waterbolt*>(spell)) {
		v->revealWaterpower();	
	} else if(Thunderstorm* v = dynamic_cast<Thunderstorm*>(spell)) {
		v->revealThunderpower();	
	} else {
		int counter = cal_lcs_length(SpellJournal::journal, spell->revealScrollName());
		cout << counter << endl;
	}
}


class Wizard {
public:
	Spell* cast() {
		Spell* spell;	
		string s;
		cin >> s;
		int power;
		cin >> power;
		if(s == "fire") {
			spell = new Fireball(power);
		} else if(s == "frost") {
			spell = new Frostbite(power);	
		} else if(s == "water") {
			spell = new Waterbolt(power);	
		} else if(s == "thunder") {
			spell = new Thunderstorm(power);	
		} else {
			spell = new Spell(s);	
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while(T--) {
		Spell* spell = Arawn.cast();	
		counterspell(spell);
	}
	return 0;
}
