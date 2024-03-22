#include <iostream>
#include <fstream>

// take a double x in [1,5] interval and riscale them into [-1,2] interval
double riscale(double x)
{
    double y = (2+1)*(x-1)/(5-1) -1 ;
    return y;
}

int main()
{
    // open file data.csv
    std::string filename1 = "data.csv";
    std::ifstream dataFile;
    dataFile.open(filename1);

    // check if file opens correctly
    if( dataFile.fail() )
    {
        std::cerr << "file: " << filename1 << "not found" << std::endl;
        return 1;
    }

    // open/create writing file
    std::string filename2 = "result.csv";
    std::ofstream outputFile(filename2);

    // check if file created/opened correctly
    if( outputFile.fail() )
    {
        std::cerr << "unable to create/open the file: " << filename2 << std::endl;
        return 2;
    }

    outputFile << "# N Mean" << "\n";

    // read file row
    double val = 0.0;
    double sumValue = 0.0;
    int counter = 1;

    while(dataFile >> val)
    {
        double number = riscale(val); // riscale number in [-1,2] interval
        sumValue += number;
        double meanValue = sumValue/counter;
        outputFile << counter << " "
                   << std::setprecision(16) << std::scientific << meanValue <<  "\n"; // print on result.csv
        ++counter;
    }

    // closing file
    outputFile.close();
    dataFile.close();

    return 0;
}
