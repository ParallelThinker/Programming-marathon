#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>


int main(int argc, char **argv){
  FILE *write_ptr = NULL;
  FILE *ptrfile = NULL;
  char *word;
  size_t len=0;
  ssize_t read;
  time_t t;
  char tch[10];

  if (argc <= 1) {
    printf ("ERROR: ./text-file-generator <number of characteres> \n");
    return 1;
  }

  write_ptr = fopen("newtext","wb");
  if (write_ptr==NULL) {
    printf("ERROR\n");
    return 1;
  }

  ptrfile = fopen("tools/words.map","rb");
  if (ptrfile==NULL) {
    printf("ERROR\n");
    assert(1);
  }

  srand ((unsigned) time(&t));

  while ((read = getline(&word, &len, ptrfile)) != -1) {
    for (int i=0; i < atoi(argv[1]); i++) {

      int n=0;

      n = (rand() % 90)+32;
      if ((n > 122) || (n < 32)) {
        printf("ERRO\n");
      }
      sprintf(tch, "%c", n);
      fwrite(tch,1,sizeof(char),write_ptr);
    }
    sprintf(tch, "%c", 32);
    fwrite(tch,1,sizeof(char),write_ptr);
    fwrite(word,read-1,sizeof(char),write_ptr);
    fwrite(tch,1,sizeof(char),write_ptr);
  }
  if (word)
     free(word);
  printf("The generated file is newfile.\n");
  fclose(write_ptr);
  return 0;
}
