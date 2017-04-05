#ifndef CSVRow_H
#define CSVRow_H

#include <vector>
#include <string>

class CSVRow
{
public:
	std::string const& operator[](std::size_t index) const;
	std::size_t size() const;
	void readNextRow(std::istream& str);

private:
	std::vector<std::string>    m_data;
};

#endif // END OF: #ifndef CSVRow_H