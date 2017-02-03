#include <iostream>
using namespace std;

class Box {
private:
	int l, b, h;
public:
	// Constructors
	Box() {
		l = b = h = 0;	
	}
	Box(int length, int breadth, int height): l(length), b(breadth), h(height) {}
	// Copy constructor
	Box(const Box& B): l(B.getLength()), b(B.getBreadth()), h(B.getHeight()){}
	// Getter
	int getLength() const{
		return l;
	}
	int getBreadth() const {
		return b;
	}
	int getHeight() const {
		return h;
	}
	// Calculate volume
	long CalculateVolume() const {
		// Take care !
		return (long long)l * b * h;
	}
	// Overload operator <
	bool operator< (Box& b) {
		if(this->l < b.getLength()) {
			return true;
		} else if(this->l == b.getLength() && this->b < b.getBreadth()) {
			return true;
		} else if(this->l == b.getLength() && this->b == b.getBreadth() && this->h < b.getHeight()) {
			return true;
		} else {
			return false;
		}
	}
};

// Outside of class!
// Overload operator <<
ostream& operator<< (ostream& out, const Box& B) {
	out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
	return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
