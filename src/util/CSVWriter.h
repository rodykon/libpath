#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class CSVWriter
{
public:
    CSVWriter(std::string file_name, int num_columns);

    void write_row(const std::vector<std::string>& values);

private:
    int num_columns;
    std::ofstream csv_file;
};