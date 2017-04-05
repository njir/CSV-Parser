#include "CSVRow.h"

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}   

class CSVIterator
{   
public:
	typedef std::input_iterator_tag     iterator_category;
	typedef CSVRow                      value_type;
	typedef std::size_t                 difference_type;
	typedef CSVRow*                     pointer;
	typedef CSVRow&                     reference;

	CSVIterator(std::istream& str)  :m_str(str.good()? &str : NULL) { ++(*this); }
	CSVIterator()                   :m_str(NULL) {}

	// Pre Increment
	CSVIterator& operator++() 
	{
		if (m_str) { 
			if (!((*m_str) >> m_row)) {
				m_str = NULL;
			}
		}
		return *this;
	}

	// Post increment
	CSVIterator operator++(int) 
	{
		CSVIterator tmp(*this);
		++(*this);
		return tmp;
	}

	CSVRow const& operator*() const
	{
		return m_row;
	}	

	CSVRow const* operator->() const 
	{
		return &m_row;
	}

	bool operator==(CSVIterator const& rhs) 
	{
		return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));
	}

	bool operator!=(CSVIterator const& rhs) 
	{
		return !((*this) == rhs);
	}

	std::size_t size() const
	{
		return m_row.size();
	}

private:
	std::istream*       m_str;
	CSVRow              m_row;
};