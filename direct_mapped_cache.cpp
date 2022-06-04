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
    int i=hex.length()-1;

    while(i > -1){
        switch(hex[i--]){
            case '0': bin += "0000"; break;//index3 0000 index0
            case '1': bin += "1000"; break;//0001
            case '2': bin += "0100"; break;//0010
            case '3': bin += "1100"; break;//0011
            case '4': bin += "0010"; break;//0100
            case '5': bin += "1010"; break;//0101
            case '6': bin += "0110"; break;//0110   
            case '7': bin += "1110"; break;//0111 
            case '8': bin += "0001"; break;//1000
            case '9': bin += "1001"; break;//1001
            case 'a': bin += "0101"; break;//1010
            case 'b': bin += "1101"; break;//1011
            case 'c': bin += "0011"; break;//1100
            case 'd': bin += "1011"; break;//1101
            case 'e': bin += "0111"; break;//1110
            case 'f': bin += "1111"; break;//1111 
        }
    }

    return bin;
}
