* Filename: divisiontable.cpp
* Description:  asks the user to enter the size of the division
table to generate.
*/ 

#include <iostream>
#include <iomanip>
#include <fstream> 

int main() {
    int size;
    // Asking the user to input the size of the division table
    std::cout << "Enter division table size: ";
    std::cin >> size; 

    // Open file to write the output
    std::ofstream file("results.dat");

    // Check if file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open file results.dat" << std::endl;
        return 1;
    }

    // Check if the input is negative or zero
    if (size < 0) {
        file << "No Negative Numbers allowed!" << std::endl; 
        file << "-- Your Custom Division Table --" << std::endl;
        return 0; 
    } 
    else if (size == 0) { 
        file << "-- Your Custom Division Table --" << std::endl;
        return 0; 
    }

    // Displaying header
    file << "-- Your Custom Division Table --" << std::endl;
    
    // The header with column numbers
    file << "   |";
    for (int i = 1; i <= size; ++i) {
        file << std::setw(5) << i;
    }
    file << std::endl;

    // Divider line
    file << "----";
    for (int i = 1; i < size; ++i) {
        file << "-----"; 
    }
    file << "-----" << std::endl;

    // Displaying the division values
    for (int i = 1; i <= size; ++i) {
        file << std::setw(3) << i << "|";
        for (int j = 1; j <= size; ++j) {
            // 2 decimal places
            file << std::setw(5) << std::fixed << std::setprecision(2) << (static_cast<double>(i) / j);
        }
        file << std::endl; 
    }

    // Close the file
    file.close();

    return 0;
}
