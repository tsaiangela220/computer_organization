#include <fstream>
#include <cstring>
#include <cmath>
#include "set_associative_cache.h"
#include "string"

using namespace std;

struct cache{
    bool valid;
    int time_lastUse=0;
    string tag;
    cache(){ valid = false;}
};
float set_associative(string filename, int way, int block_size, int cache_size)
{
    int total_num = -1;
    int hit_num = 0;

    /*write your code HERE*/
    fstream inf;
    inf.open(filename);
    string address, address_bin, index_bin, tag;
    struct cache *direct_mapped_cache = new cache [cache_size/block_size];
    int set_count = (cache_size/block_size)/way;//8 blocks 2 way -> 8/2=4 set(2 blocks / set) 
    struct cache **set_associative_cache;
    set_associative_cache = (cache**) malloc(sizeof(cache*)*set_count);
    for(int i=0; i< set_count; i++) set_associative_cache[i] = (cache*) malloc(sizeof(cache)*way);
    int tag_bitNum=0, offset_bitNum=0, index_bitNum=0, index_dec;

    offset_bitNum = log2(block_size);
    index_bitNum = log2(cache_size/(block_size*way));

    while(getline(inf, address)){
        cout<< "way:           "<< way<< endl;
        cout<< "cache_size:    "<< cache_size<< endl;//  
        cout<< "block_size:    "<< block_size<< endl;//
        cout<< "index_bitNum:  "<< index_bitNum<< endl;//
        cout<< "offset_bitNum: "<< offset_bitNum<< endl;//
        tag_bitNum = 32-index_bitNum-offset_bitNum;
        cout<< "tag_bitNum:    "<< tag_bitNum<< endl;//
        
        cout<< "address:       "<< address <<endl;//
        address_bin = hex2bin(address);    
        cout<< address_bin <<endl;//

        //00 000 00
        for(int i= offset_bitNum; i< offset_bitNum+index_bitNum; i++) 
            index_bin += address_bin[i];
        for(int i= offset_bitNum+index_bitNum; i< address_bin.length(); i++) 
            tag += address_bin[i];
        cout<< "index_bin: "<< index_bin<< endl;//
        index_dec = bin2dec(index_bin);
        cout<< "index_dec: "<< index_dec<< endl;//
        cout<< "tag:       "<< tag<<endl;//

        if(direct_mapped_cache[index_dec].valid==true && 
           strcmp(tag.c_str(), direct_mapped_cache[index_dec].tag.c_str())==0) 
           hit_num++;
        else{
            direct_mapped_cache[index_dec].valid = true;
            direct_mapped_cache[index_dec].tag = tag;
        }

        index_bin.clear();
        tag.clear();
        total_num++;
        cout<< endl;
    }
 
    return (float)hit_num/total_num;
}
