#include <bits/stdc++.h>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "./sortingAlg/tablesort.hpp"
#include "./templates/list.hpp"
#include "./opts/getopts.hpp"
#include "./utils/utils.hpp"

using namespace std;

int main(){

    uint32_t rows = 30;

    uint64_t* table1;
    uint64_t* table2;
    MergeTuple* sortedTable;


    default_random_engine gen;
    uniform_int_distribution<uint64_t> distribution(1,ULLONG_MAX);

    table1 = new uint64_t[rows];
    table2 = new uint64_t[rows];
   
    gen.seed(1);

    for (int i = 0 ; i < rows ; i++){
        table1[i] = distribution(gen);
        table2[i] = table1[i];
    }

    cout << "Testing sorting function..." << endl;

    sort(&table1[0] , &table1[rows]);

    // for (int i = 0 ; i < rows ; i++){
    //     cout << table1[i] << endl;
    // }

    sortedTable = TableSortOnKey(&table2 , rows , 1 , 0);

    // for (int i = 0 ; i < rows ; i++){
    //     cout << sortedTable[i].key  << " " << table1[i] << endl;
    // }

    for (int i = 0; i < rows ; i++){
        if (table1[i] != sortedTable[i].key){
            cout << "Sorting failed because the elements are not the same" << endl;
            exit(1);
        }
    }

    cout << "Sorting test successful!" << endl;

}
