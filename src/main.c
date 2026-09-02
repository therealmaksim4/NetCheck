#include "status.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *pFile = popen("ping -c 5 1.1.1.1", "r");
    int status_code = pclose(pFile);
    Status retval;

    if(WEXITSTATUS(status_code) == 0){
        printf("Internet Connection Exists\n");
        retval = SUCCESS;
    }

    else if(WEXITSTATUS(status_code) == 2){
        fprintf(stderr, "No Internet Connection\n");
        retval = NO_CONNECTION;
    }

    else{
        fprintf(stderr, "Unknown Error\n");
        retval = ERROR;
    }

    return retval;
}
