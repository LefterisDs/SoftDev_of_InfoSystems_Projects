/* File: utils.cpp */

#include <iostream>
#include "../templates/list.hpp"

inline uint32_t BitConversion(uint64_t num, int key)
{//key must be between 0 and 7
    return ( ( (1 << 8) - 1) & (num >> ((7-key) * 8) ) );
}

void SwitchElements(uint64_t** tableMain , int sizeY , int firstElem , int secondElem)
{
    uint64_t temp;

    for (int k = 0 ; k < sizeY ; k++) {
        temp                     = tableMain[k][firstElem];
        tableMain[k][firstElem]  = tableMain[k][secondElem];
        tableMain[k][secondElem] = temp;
    }
}

void MergeTables(List<uint64_t>& list, uint64_t** table1, uint32_t* rowIDs1, int size1X, int key1, uint64_t** table2, uint32_t* rowIDs2, int size2X, int key2)
{
    int tabelA_index = 0;
    int tableB_index = 0;

    while (tabelA_index < size1X)
    {
        if (table1[key1][tabelA_index] == table2[key2][tableB_index]) {
            uint64_t list_entry = rowIDs1[tabelA_index];
            list_entry <<= 32;
            list_entry |= rowIDs2[tableB_index];

            list.ListInsert(list_entry);

            std::cout << rowIDs1[tabelA_index] <<  " " << rowIDs2[tableB_index] << std::endl;
            std::cout << table1[key1][tabelA_index] << " " << table2[key2][tableB_index] << std::endl;
            std::cout << std::endl;

            tableB_index++;

            if (tableB_index == size2X){
                tableB_index = 0;
                tabelA_index++;
            }

        } else if (table1[key1][tabelA_index] < table2[key2][tableB_index]) {
            tabelA_index++;
            if (tabelA_index == size1X)
                break;

            if (table1[key1][tabelA_index-1] == table1[key1][tabelA_index])
                tableB_index = 0;

        } else if (table1[key1][tabelA_index] > table2[key2][tableB_index]) {
            tableB_index++;
            if (tableB_index == size2X){
                tableB_index = 0;
                tabelA_index++;
            }
        }
    }
}
