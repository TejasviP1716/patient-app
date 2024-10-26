#ifndef CLINIC_H
#define CLINIC_H


//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10


// MS#3 Additional macro's:

#define MINUTE_INTERVAL 30
#define START_HOUR 10
#define END_HOUR 14

// additional macro for the calculation of addappointment & viewAllAppointment

#define START_HOUR_MIN 0
#define LAST_HOUR 23
#define LAST_MINUTE 59
#define FIRST_MONTH 1
#define FINAL_MONTH 12

//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
// (Copy your code from MS#2)
struct Phone
{
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};


// Data type: Patient 
// (Copy your code from MS#2)
struct Patient
{
    int patientNumber;
    char name[NAME_LEN + 1];
    struct Phone phone;
};

// ------------------- MS#3 -------------------

// Data type: Time

struct Time
{
    int hour;
    int minute;
};


// Data type: Date

struct Date
{
    int day;
    int month;
    int year;
};


// Data type: Appointment

struct Appointment
{
    int patientNum;
    struct Time time;
    struct Date date;


};


// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};



//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);

// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords);

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData* data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient);

// Menu: Appointment Management
void menuAppointment(struct ClinicData* data);

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt);

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max);

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max);

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max);

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data);

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data);

// Add an appointment record to the appointment array
void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients);

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients);

//////////////////////////////////////
// ADDITIONAL FUNCTIONS
//////////////////////////////////////
//
// Function to sort the values by using bubble sort method..........
void sort(struct Appointment appoints[], int max);

// from here get the appointment time..........
struct Time getTime(struct Date date);

// For the next appointment slot........
int nextSlot(struct Appointment* app, int maxAppointments);

//  Leap year
int LeapYear(int year, int month);

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient);

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone);




//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* fileData, struct Patient patients[], int max);

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* fileData, struct Appointment appoint[], int max);


#endif // !CLINIC_H
