/// ===== user.cpp  =====
#ifndef NULL
#define NULL 0
#endif 
 
#include <stdio.h>

#define MAX_USER 10000
#define MAX_LEN 100
#define MAX_WORD 8

unsigned long long data[MAX_USER][MAX_LEN];
char dataLength[MAX_USER];

void initUser(int dataN){
    // printf("initUser: %d\n", dataN);
    //printf("initUser: %d\n", sizeof(long));
    for(int i =0; i <= dataN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            data[i][j] = 0;
        }
        dataLength[i] = 0;
    }

}
 
void registerData(int dataID, int dataLen, int dataArr[100]){
    // printf("registerData: %d %d\n", dataID, dataLen);

    int i = 0;
    unsigned long long tempdata = 0;
    for(i = 0; i < dataLen; i++) {
        unsigned char tmpchar = (char) dataArr[i] + 128;
        
        //printf("tempdata 1 [%d][%llx] ch[%d] dataLen[%d]\n", i, tempdata, tmpchar, dataLen);
        tempdata = ((tempdata << 8) | tmpchar );
        //printf("tempdata 2 [%d][%llx] ch[%d]\n", i, tempdata, tmpchar);

        if(i < 7) continue;
        data[dataID][i-7] = tempdata; 
    }

    dataLength[dataID] = dataLen -7;

}
 
int findID(int args[8])
{
    int id  = 1;
    unsigned long long stick = 0;

    //printf("findID 1\n");
    for(int i = 0; i < 8; i++) {
        unsigned char tmpchar = (char) args[i] + 128;
        stick = ((stick << 8) | tmpchar ); // & 0xFFFFFFFFFFFFFFFF; 
    } 

    int found = 0;
    for(; id < MAX_USER; id++) {
        
        //printf("findID 2: id[%d] dataLen[%d]\n", id, dataLength[id]);
    
        for(int i =0; i < dataLength[id]; i++) {
            if(stick == data[id][i]) { 
                found = 1;
                break;
            }
        }
        if(found == 1) break;
    } 
    

    //printf("findID 3: id[%d] found[%d]\n", id, found);

    return id;
}
