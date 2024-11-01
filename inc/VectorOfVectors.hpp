#ifndef __VECTOROFVECTORS_HPP__
#define __VECTOROFVECTORS_HPP__

#include <iostream> 
#include <vector>
#include <cstdint>
#include <common.hpp>

template <class UINT>
class VectorOfVectors
{
public:
    VectorOfVectors() { m_data.push_back(std::vector<UINT>(0)); }

    // print the values in a table format 
    void print()
    {
        for(std::vector<UINT> row: m_data)
        {
            for(UINT col: row)
            {
                prettyprintbyte(col);
            }
            std::cout << std::dec << std::endl;
        }
    }

    // get the row count
    unsigned int rowsize() { return m_data.size(); }

    // get the col count
    unsigned int colsize(unsigned int row) 
    {
        if (row < m_data.size()) { return m_data[row].size(); }
        return 0;
    }

    // get cell count
    unsigned int size() 
    {
        int cell_count = 0;

        for(std::vector<UINT> row: m_data)
            cell_count += row.size();

        return cell_count;
    }

    // get cell value
    int get(const unsigned int row, const unsigned int col) {
        if (row < m_data.size())
        {
            if (col < m_data[row].size())
            {
                return m_data[row][col];
            }
        }
        return -1;
    } 
    // set cell value
    unsigned int set(const unsigned int row, const unsigned int col, const UINT &value) {
        if (row < m_data.size())
        {
            if (col < m_data[row].size())
            {
                m_data[row][col] = value;
                return 0;
            }
            else
            {
                m_data[row].push_back(value);
                return 0;
            }
        }
        else
        {
            m_data.push_back(std::vector<UINT>{value});
            return 0;
        }
        return 1;
    }

    // push new cell value to row
    unsigned int push_back(const unsigned int row, const UINT &value)
    {
        if (row < m_data.size())
        {
            m_data[row].push_back(value);
            return 0;
        }    
        else
        {
            m_data.push_back(std::vector<UINT>{value});
            return 0;
        }    
    }

    // row iterators object and getter
    struct RowIter
    {
        typename std::vector<std::vector<UINT>>::iterator begin;
        typename std::vector<std::vector<UINT>>::iterator end;
    };
    void get_row_iters(
        RowIter &iterpair
    )
    {
        iterpair.begin = m_data.begin();
        iterpair.end = m_data.end();
    }

    // column iterators object and getter
    struct ColIter
    {
        typename std::vector<UINT>::iterator begin;
        typename std::vector<UINT>::iterator end;
    };
    void get_column_iters(
        const typename std::vector<std::vector<UINT>>::iterator &rowiter,
        ColIter &coliterpair
    )
    {
            coliterpair.begin = (*rowiter).begin();
            coliterpair.end = (*rowiter).end();

    }

private:
    std::vector<std::vector<UINT>> m_data;
};

#endif // __VECTOROFVECTORS_HPP__