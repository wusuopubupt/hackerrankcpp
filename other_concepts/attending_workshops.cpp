#include <iostream>
#include <vector>

using namespace std;

class Workshop {
public:
	int start_time;
	int duration;
	int end_time;
};

class Available_Workshops {
public:
	int n;
	vector<Workshop> workshops;
	
	Available_Workshops(int n) {
		this->n = n;
		this->workshops = vector<Workshop>(n);
	}
};

bool comp(const Workshop& w1, const Workshop& w2) {
	return w1.end_time < w2.end_time;
}

Available_Workshops* initialize(int start_time[], int duration[], int n) {
	Available_Workshops* aw = new Available_Workshops(n);
	for(int i = 0; i < n; i++) {
		Workshop w;
		w.start_time = start_time[i];
		w.duration = duration[i];
		w.end_time = start_time[i] + duration[i];
		// std::vector::operator[]: "access specified element"
		// std::vector::push_back: "adds an element to the end"
		//aw->workshops.push_back(w);
		aw->workshops[i] = w;
	}
	sort(aw->workshops.begin(), aw->workshops.end(), comp);
	return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
	if(ptr->n < 1) return 0;

	int cnt = 1;
	int end_time = ptr->workshops[0].end_time;

	for(int i = 1; i < ptr->n; i++) {
		//printf("i:%d, start_time:%d, end_time:%d, ET:%d\n", i, ptr->workshops[i].start_time, ptr->workshops[i].end_time, end_time);
		if(ptr->workshops[i].start_time >= end_time) {
			end_time = ptr->workshops[i].end_time;	
			cnt++;
		}
	}
	return cnt;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

