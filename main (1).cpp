/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <stdexcept>

using namespace std;

struct Patient {
    string id;
    char gender;
    string arrivalTime;
    string type;
    int waitTime;

    Patient(string id, char gender, string arrivalTime, string type)
        : id(id), gender(gender), arrivalTime(arrivalTime), type(type), waitTime(0) {}
};

// Generate random patient ID similar to Egyptian National IDs
string generatePatientID() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9);

    stringstream id;
    id << "2";
    for (int i = 0; i < 12; ++i) {
        id << dist(gen);
    }
    return id.str();
}

// Generate random arrival time in 24-hour format
string generateArrivalTime() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> hourDist(0, 23);
    uniform_int_distribution<> minDist(0, 59);

    int hour = hourDist(gen);
    int min = minDist(gen);

    stringstream time;
    time << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << min;

    return time.str();
}

// Generate random gender
char generateGender() {
    return (rand() % 2 == 0) ? 'M' : 'F';
}

// Generate random type
string generateType() {
    return (rand() % 2 == 0) ? "Urgent" : "Normal";
}

// Function to populate patients
vector<Patient> generatePatients(int count) {
    vector<Patient> patients;
    for (int i = 0; i < count; ++i) {
        patients.emplace_back(generatePatientID(), generateGender(), generateArrivalTime(), generateType());
    }
    return patients;
}

// Simulate patient scheduling system
void simulatePatientScheduling(vector<Patient>& patients) {
    queue<Patient> urgentQueue, normalQueue;
    vector<Patient> servedPatients;
    int totalTime = 0;

    cout << "Starting Simulation... Press Enter to advance time step.\n";

    for (auto& patient : patients) {
        if (patient.type == "Urgent") {
            urgentQueue.push(patient);
        } else {
            normalQueue.push(patient);
        }
    }

    while (!urgentQueue.empty() || !normalQueue.empty()) {
        int n = rand() % 6 + 5; // Random number of patients served (5-10)

        cout << "Time Step: " << totalTime << " minutes\n";
        cout << "Serving up to " << n << " patients.\n";

        for (int i = 0; i < n && (!urgentQueue.empty() || !normalQueue.empty()); ++i) {
            if (!urgentQueue.empty()) {
                cout << "Serving Urgent Patient: " << urgentQueue.front().id << "\n";
                servedPatients.push_back(urgentQueue.front());
                urgentQueue.pop();
            } else if (!normalQueue.empty()) {
                cout << "Serving Normal Patient: " << normalQueue.front().id << "\n";
                servedPatients.push_back(normalQueue.front());
                normalQueue.pop();
            }
        }

        cout << "\nWaiting Urgent Patients:\n";
        queue<Patient> temp = urgentQueue;
        while (!temp.empty()) {
            cout << temp.front().id << " ";
            temp.pop();
        }

        cout << "\nWaiting Normal Patients:\n";
        temp = normalQueue;
        while (!temp.empty()) {
            cout << temp.front().id << " ";
            temp.pop();
        }

        cout << "\nPress Enter to advance time.\n";
        cin.ignore();
        totalTime += 1;
    }

    cout << "\nSimulation Complete.\n";
    cout << "Total Patients Served: " << servedPatients.size() << "\n";
    cout << "Average Wait Time: " << static_cast<double>(totalTime) / servedPatients.size() << " minutes.\n";
}

int main() {
    srand(time(0));

    cout << "Select Scenario (1: Simple, 2: Moderate, 3: Crowded): ";
    int choice;
    cin >> choice;

    int patientCount = (choice == 1) ? 100 : (choice == 2) ? 300 : 700;

    vector<Patient> patients = generatePatients(patientCount);

    simulatePatientScheduling(patients);

    return 0;
}