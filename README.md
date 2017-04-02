# Employee Management Lab
CIS22B Lab Project

## 1. Employee and ProductionWorker Classes
> Design a class named Employee. The class should keep the following information in member variables:
> * Employee name
> * Employee number
> * Hire date
> Write one or more constructors and the appropriate accessor and mutator functions for the class.
> Next, write a class named ProductionWorker that is derived from the Employee class. The ProductionWorker class should have member variables to hold the following information:
> * Shift (an integer)
> * Hourly pay rate (a double)
> The workday is divided into two shifts: day and night. The shift variable will hold an integer value representing the shift that the employee works.  The day shift is shift 1 and the night shift is shift 2. Write one or more constructors and the appropriate accessor and mutator functions for the class. Demonstrate the classes by writing a program that uses a ProductionWorker object.

## 2. ShiftSupervisor Class
> In a particular factory a shift supervisor is a salaried employee who supervises a shift. In addition to a salary, the shift supervisor earns a yearly bonus when his or her shift meets production goals. Design a ShiftSupervisor class that is derived from the Employee class. The ShiftSupervisor class should have a member variable that holds the annual salary and a member variable that holds the annual production bonus that a shift supervisor has earned. Write one or more constructors and the appropriate accessor and mutator functions for the class. Demonstrate the class by writing a program that uses a ShiftSupervisor object.

## 3. TeamLeader Class
> In a particular factory, a team leader is an hourly paid production worker who leads a small team. In addition to hourly pay, team leaders earn a fixedom nthly bonus. Team leaders are required to attend a numinimum number of hours of training per year. Design a TeamLeader class that extends the ProductionWorker class. The TeamLeader class should have member variables for the monthly bonus amount, the required number of training hours, and the number of training hours that the team leader has attended. Write one or more constructors and the appropriate accessor and mutator functions for the class. Demonstrate the class by writing a program that uses a TeamLeader object.
