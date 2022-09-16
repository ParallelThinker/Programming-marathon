#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


// ***************************   ***************************
//
// ***************************   ***************************
int main(int argc, char **argv){
  char *bufrb = NULL;
  char *bufwb = NULL;
  FILE *ptrfile = NULL;
  FILE *write_ptr = NULL;

  if (argc <= 1) {
    printf ("ERROR: ./input-generator <filename> \n");
    return 1;
  }

  char filename[256];
  strcpy(filename, argv[1]);
  strcat(filename, ".in");
  write_ptr = fopen(filename,"wb");
  if (write_ptr==NULL) {
    printf("ERROR\n");
    return 1;
  }

  ptrfile = fopen(argv[1],"rb");
  if (ptrfile==NULL) {
    printf("ERROR\n");
    assert(1);
  }

  bufrb = malloc(sizeof(char));
  bufwb = malloc(sizeof(char)*10);
  while (bufrb!=NULL) {
    if (!fread(bufrb,1,sizeof(char),ptrfile)) {
      bufrb=NULL;
    } else {
      // printf("%c(%d)", bufrb[0],bufrb[0]);
      if (bufrb[0] < 100) {
        char tch[100];
        sprintf(tch, "0%d", bufrb[0]);
        fwrite(tch,3,sizeof(char),write_ptr);
      } else {
        char tch[100];
        sprintf(tch, "%d", bufrb[0]);
        fwrite(tch,3,sizeof(char),write_ptr);
      }
    }
  }
  free(bufrb);
  free(bufwb);
  fclose(write_ptr);
  fclose(ptrfile);
  printf("The encoded file(%s) was successfully generated!!\n",filename);
  return 0;
}
