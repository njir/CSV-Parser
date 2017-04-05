#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVRow.h"
#include "CSVIterator.h"

int main()
{
	std::ifstream file("Summay_15C-RS_B15.csv");
	double sum = 0;
	double value = 0;
	int size = 0;

	CSVIterator loop(file);
	for(CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        std::cout << "2nd Element(" << (*loop)[1] << ")\n";

		value = atof((*loop)[1].c_str());
		sum += value;
		size++;
    }

	std::cout << "AVERAGE: " << sum / size << std::endl;

	return 0;
}

