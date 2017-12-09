#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    fprintf(stderr, "Usage: rm (file apa yg mau didelete?)\n");
    exit();
  }

/*if (strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "-R") == 0) { // with -r
    if (argc != 3) { // wrong usage
      fprintf(stderr, "rm: terlalu banyak argumen\n");
      exit();
    } else { // remove folder yang gaada isinya
      if (remove(argv[2]) < 0) {
        fprintf(stderr, "rm: %s bukan direktori kosong\n", argv[2]);
        exit();
      }
    }
  }*/
else

  for(i = 1; i < argc; i++){
    if(unlink(argv[i]) < 0){
      fprintf(stderr, "rm: %s gagal dihapus\n", argv[i]);
      break;
    }
  }

  exit();
}
