/// ===== user.cpp  =====
#ifndef NULL
#define NULL 0
#endif 
 
// #include <stdio.h>

#define MAX_USER 10000
#define MAX_LEN 100
#define MAX_WORD 8

char data[MAX_USER][MAX_LEN];
char dataLength[MAX_USER];

void initUser(int dataN){
    // printf("initUser: %d\n", dataN);
    for(int i =0; i <= dataN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            data[i][j] = 0;
        }
        dataLength[i] = 0;
    }

}
 
void registerData(int dataID, int dataLen, int dataArr[100]){
    // printf("registerData: %d %d\n", dataID, dataLen);

    dataLength[dataID] = dataLen;

    for(int i = 0; i < dataLen; i++) {
        data[dataID][i] = (char) dataArr[i];
    }
}
 
int findID(int args[8])
{
    int id  = 1;
    
    char chargs[8] = {0,};
    for(int i=0; i < 8; i++) {
        chargs[i] = (char) args[i];
    }

    do {
            int dcur=0;
            int found;
                
            while(dcur < dataLength[id]) {
                found = 1;
                int acur = 0;
                
                if (dataLength[id] - dcur < MAX_WORD) {
                    found = 0;
                    break;
                }

                if(data[id][dcur] == chargs[acur]) {
                    //printf("match ==> %d, %d\n", id, dcur);

                    for (int i=1; i < MAX_WORD; i++) {
                        if(data[id][dcur+i] != chargs[i]) {
                            // not match
                            //printf("not match ==> %d, %d, %d\n", id, dcur, i);

                            found = 0;
                            break;
                        }
                        //printf("i ==> [%d]\n", i);

                    }
                    if(found == 1) {
                        //printf("break 1\n");
                        break;
                    } 

                }
                //if(found == 1) break;
                dcur++;

            }
            if(found == 1) {
                //printf("break 2\n");
                break;
            }
        
    } while (id++);
    /* printf("findID: %d, arg[%d, %d, %d, %d, %d, %d, %d, %d] dl[%d]\n", 
        id, chargs[0], chargs[1], chargs[2], chargs[3], 
        chargs[4], chargs[5], chargs[6], chargs[7], dataLength[id]);
     */
    return id;
}
