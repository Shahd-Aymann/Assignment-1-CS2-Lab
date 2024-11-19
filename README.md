# Assignment-1-CS2-Lab
Objective:
Develop a simple patient scheduling system using C++ STL, incorporating OOP principles. This
system will simulate a healthcare queue prioritization, where patients are served based on urgency.
The project will help you apply data structures and exception handling, understand Linux and VM
environments, and practice collaborative coding via GitHub.
System Requirements:
1. Patient Details:
•ID: Follows a structure similar to Egyptian National IDs (e.g., 28501012345678). It
should include validation to ensure the correct format.
•Gender: Male or Female (using ‘M’ or ‘F’).
•Arrival Time: Recorded 24-hour format (e.g., 14:30 for 2:30 PM).
•Type: Urgent or Normal.
2.Queueing System:
•Urgent Queue: Always served before the Normal queue.
•Normal Queue: Served only when no Urgent patients are in the queue.
•Time Constraints:
•Maximum Serve Time per Patient: (10 minutes).
3. Functional Requirements:
•Initial Data Setup: Populate a vector with randomly generated patient details.
.Simple sceniro: at least 100 paitents.
.Modrate sceniro: at least 300 paitents.
.Crowded scenario: at least 700 patients.
•Dispatching Patients:
•Every minute, patients in the vector are transferred to their respective queues
based on arrival time.
•Urgent patients are prioritized over Normal patients.
•Serving Patients:
•Serve only a limited number of patients (N) per time step, giving preference to
Urgent patients and the N is randomly generated with in range N = 5 -> 10.
•Track average waiting time and other statistics.

Usage Examples

Starting the Simulation
When you run the program, it will prompt you to select a simulation scenario:
Select Scenario (1: Simple, 2: Moderate, 3: Crowded):

Scenario 1 (Simple): Simulates a healthcare facility with 100 patients.
Scenario 2 (Moderate): Simulates a healthcare facility with 300 patients.
Scenario 3 (Crowded): Simulates a healthcare facility with 700 patients.
Enter your choice (e.g., 1 for a simple simulation) and press Enter.

Simulation Process
The program generates a random dataset of patients, each with:
A unique 13-digit ID (resembling Egyptian National IDs).
Gender (M or F).
Arrival time in HH:MM format.
A classification as either Urgent or Normal.
The system simulates a real-time patient scheduling process:
Urgent patients are prioritized in the queue.
A random number (between 5-10) of patients is served in each time step.
The remaining patients are displayed at each step.
To advance time in the simulation, press Enter.

Simulation Output
During the simulation, the program displays the following:
Patients being served at each time step.
Patients still waiting in the Urgent and Normal queues.
At the end of the simulation, a summary is displayed:
Simulation Complete. Total Patients Served: 700 Average Wait Time: 2.4 minutes.

Code Features

Patient Data Generation
Randomly generates unique 13-digit IDs, genders, arrival times, and urgency types.
Mimics real-world healthcare scenarios by introducing variability in data.
Queue Management
Uses two separate queues:
Urgent Queue: For patients requiring immediate attention.
Normal Queue: For routine cases.
Prioritizes urgent patients for service.
Interactive Simulation
Displays real-time updates of patient queues.
Allows users to step through the simulation interactively.
Performance Metrics
Calculates and displays the total number of patients served.
Computes the average wait time for all patients.

Example Walkthrough

User Input:
Select Scenario (1: Simple, 2: Moderate, 3: Crowded): 2
Simulation Process:
Time Step: 0 minutes
Serving up to 7 patients.
Serving Urgent Patient: 20123456789012
Serving Normal Patient: 20123456789045
...
Waiting Urgent Patients:
20123456789089 20123456789011
Waiting Normal Patients:
20123456789032 20123456789033
Simulation Summary:
Simulation Complete. Total Patients Served: 300 Average Wait Time: 3.2 minutes.
