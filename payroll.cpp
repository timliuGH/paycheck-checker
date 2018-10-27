#include <iostream>

struct Stats
{
    double reg;  // Number of regular work hours
    double ot;   // Number of overtime hours
    double ot2;  // Number of double overtime hours
    Stats() : reg(0.0), ot(0.0), ot2(0.0) {}
};

int main()
{
    std::cout << "\nREMINDER: Use military time!\n";

    // Analyze two weeks worth of data at a time
    int numWeeks = 2;
    Stats *week = new Stats[numWeeks];

    // Iterate over each week
    for (int t = 0; t < numWeeks; ++t) {
        std::cout << "\nWeek " << (t + 1) << ":";
        std::cout << "\nNumber of days to enter hours for: ";
        int days;
        std::cin >> days;

        int inTime;
        double inHours;
        int outTime;
        double outHours;
        double lunch;
        double drive;
        double totalReg = 0;
        double totalOt = 0;
        double totalOt2 = 0;

        // Iterate over each day of current week
        for (int i = 0; i < days; ++i) {
            std::cout << "\nDay " << (i + 1) << ":\n";
            std::cout << "Time IN: ";
            std::cin >> inTime;
            std::cout << "Time OUT: ";
            std::cin >> outTime;
            std::cout << "Lunch duration: ";
            std::cin >> lunch;
            std::cout << "Drive time: ";
            std::cin >> drive;

            // Convert time to hours 
            if (inTime > 100) {
                inHours = (inTime / 100) + ((inTime % 100)/60.0);
                if (inHours > 12) {
                    inHours -= 12;
                }
            }
            if (outTime > 100) {
                outHours = (outTime / 100) + ((outTime % 100)/60.0);
            }
            if (lunch > 1) {
                lunch = 0.5;
            }

            double intReg = drive + outHours - inHours - lunch;
            double intOt = 0;
            if (intReg > 8) {
                intOt = intReg - 8;
                intReg = 8;
            }
            double intOt2 = 0;
            if (intOt > 4) {
                intOt2 = intOt - 4;
                intOt = 4;
            }
            // Calculate total of each type of work hour
            totalReg += intReg;
            totalOt += intOt;
            totalOt2 += intOt2;
        }
        // Store hours worked for the week
        week[t].reg = totalReg;
        week[t].ot = totalOt;
        week[t].ot2 = totalOt2;
    }
    // Display results
    std::cout << "\nResults: \n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "\nWeek " << (i + 1) << ":\n";
        std::cout << "Regular: " << week[i].reg << '\n';
        std::cout << "OT: " << week[i].ot << '\n';
        std::cout << "OT2: " << week[i].ot2 << '\n';
    }
    // Free memory
    delete [] week;

    return 0;
}
