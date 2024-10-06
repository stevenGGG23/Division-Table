#include <iostream>
#include <iomanip>
#include <fstream> 
#include <limits> // for std::numeric_limits

int main() {
    int size;
    
    // Asking the user to input the size of the division table
    std::cout << "Enter division table size: ";
    
    // Input validation loop
    while (!(std::cin >> size) || size < 0) {
        std::cout << "Invalid input! Please enter a non-negative integer." << std::endl;
        std::cout << "Enter division table size: ";
        std::cin.clear(); // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    // Open file to write the output
    std::ofstream file("results.dat");

    // Check if file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open file results.dat" << std::endl;
        return 1;
    }

    // Check if the input is zero
    if (size == 0) { 
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
    
    std::cout << "Division table has been written to results.dat" << std::endl;

    return 0;
}
