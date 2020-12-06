#include <stdio.h>
#include <conio.h>
#include <string.h>
char input[10], label[10], ch1, ch2;
int addr, w = 0, start, ptaddr, l, length = 0, end, count = 0, k, taddr, address, i = 0;
FILE *f1, *f2;
void check()
{
  count++;
  address++;
  taddr = taddr + 1;
  if (count == 4)
  {
    fprintf(f2, "  ");
    i++;
    if (i == 4)
    {
      fprintf(f2, "\n\n%x\t\t", taddr);
      i = 0;
    }
    count = 0;
  }
}
void main()
{
  f1 = fopen("in.txt", "r");
  f2 = fopen("out.txt", "w");
  fscanf(f1, "%s", input);
  printf("\n\n\t\t\t\tABSOLUTE LOADER\n");
  fprintf(f2, "\n-------------------------------------------------------\n");
  fprintf(f2, "MEMORY ADDRESS\t\t\tCONTENTS");
  fprintf(f2, "\n-------------------------------------------------------\n");
  while (strcmp(input, "E") != 0)
  {
    if (strcmp(input, "H") == 0)
    {
      fscanf(f1, "%s %x %x %s", label, &start, &end, input);
      address = start;
    }
    else if (strcmp(input, "T") == 0)
    {
      l = length;
      ptaddr = addr;
      fscanf(f1, "%x %x %s", &taddr, &length, input);
      addr = taddr;
      if (w == 0)
      {
        ptaddr = address;
        w = 1;
      }
      for (k = 0; k < (taddr - (ptaddr + l)); k++)
      {
        address = address + 1;
        fprintf(f2, "xx");
        count++;
        if (count == 4)
        {
          fprintf(f2, "  ");
          i++;
          if (i == 4)
          {
            fprintf(f2, "\n\n%x\t\t", address);
            i = 0;
          }
          count = 0;
        }
      }
      if (taddr == start)
        fprintf(f2, "\n\n%x\t\t", taddr);
      fprintf(f2, "%c%c", input[0], input[1]);
      check();
      fprintf(f2, "%c%c", input[2], input[3]);
      check();
      fprintf(f2, "%c%c", input[4], input[5]);
      check();
      fscanf(f1, "%s", input);
    }
    else
    {
      fprintf(f2, "%c%c", input[0], input[1]);
      check();
      fprintf(f2, "%c%c", input[2], input[3]);
      check();
      fprintf(f2, "%c%c", input[4], input[5]);
      check();
      fscanf(f1, "%s", input);
    }
  }
  fprintf(f2, "\n-------------------------------------------------------\n");
  printf("\n\n The contents of output file:\n\n");
  fclose(f2);
  f2 = fopen("out.txt", "r");
  ch2 = fgetc(f2);
  while (ch2 != EOF)
  {
    printf("%c", ch2);
    ch2 = fgetc(f2);
  }
  fclose(f1);
  fclose(f2);
  getch();
}
