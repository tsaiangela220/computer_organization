#include <fstream>
#include <string>
#include "direct_mapped_cache.h"
#include "string"

using namespace std;

float direct_mapped(string filename, int block_size, int cache_size)
{
    int total_num = -1;
    int hit_num = 0;
    
    /*write your code HERE*/
    fstream inf;
    inf.open(filename);
    string instr;

    while(getline(inf, instr)){
        cout<< instr <<endl;
    
    
    }
  
    return (float)hit_num/total_num;
}
