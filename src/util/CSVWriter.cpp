#include "util/CSVWriter.h"

CSVWriter::CSVWriter(std::string file_name, int num_columns)
{
    csv_file.open(file_name);
}

void CSVWriter::write_row(const std::vector<std::string>& values)
{
    for (const std::string& value : values)
    {
        csv_file << value << ",";
    }
    csv_file << "\n";
}
