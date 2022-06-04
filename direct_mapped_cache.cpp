#include <fstream>
#include <string>
#include "direct_mapped_cache.h"
#include "string"

using namespace std;

string hex2bin(string);

float direct_mapped(string filename, int block_size, int cache_size)
{
    int total_num = -1;
    int hit_num = 0;
    
    /*write your code HERE*/
    fstream inf;
    inf.open(filename);
    string instr, instr_bin;

    while(getline(inf, instr)){
        cout<< instr <<endl;//
        instr_bin = hex2bin(instr);    
        cout<< instr_bin <<endl;//
    }
  
    return (float)hit_num/total_num;
}
string hex2bin(string hex)
{
    string bin;
    int i=0;

    while(i < hex.length()){
        switch(hex[i++]){
            case '0': bin += "0000"; break;
            case '1': bin += "0001"; break;
            case '2': bin += "0010"; break;
            case '3': bin += "0011"; break;
            case '4': bin += "0000"; break;
            case '5': bin += "0101"; break;
            case '6': bin += "0110"; break;     
            case '7': bin += "0111"; break; 
            case '8': bin += "1000"; break;
            case '9': bin += "1001"; break;
            case 'a': bin += "1010"; break;
            case 'b': bin += "1011"; break;
            case 'c': bin += "1100"; break;
            case 'd': bin += "1101"; break;
            case 'e': bin += "1110"; break;
            case 'f': bin += "1111"; break; 
        }
    }

    return bin;
}
