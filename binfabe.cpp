#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct binfa
{
  int ertek;
  struct binfa *bal_nulla;
  struct binfa *jobb_egy;

} BINFA, *BINFA_PTR;

BINFA_PTR
uj_elem ()
{
  BINFA_PTR p;

  if ((p = (BINFA_PTR) malloc (sizeof (BINFA))) == NULL)
    {
      perror ("memoria");
      exit (EXIT_FAILURE);
    }
  return p;
}

extern void kiir (BINFA_PTR elem);
extern void ratlag (BINFA_PTR elem);
extern void rszoras (BINFA_PTR elem);
extern void szabadit (BINFA_PTR elem);

int
main (int argc, char **argv)
{
  char b;

  BINFA_PTR gyoker = uj_elem ();
  gyoker->ertek = '/';
  gyoker->bal_nulla = gyoker->jobb_egy = NULL;
  BINFA_PTR fa = gyoker;
  long max=0;
while (read (0, (void *) &b, 1))
    {
//      write (1, &b, 1);
      if (b == '0')
	{
	  if (fa->bal_nulla == NULL)
	    {
	      fa->bal_nulla = uj_elem ();
	      fa->bal_nulla->ertek = 0;
	      fa->bal_nulla->bal_nulla = fa->bal_nulla->jobb_egy = NULL;
	      fa = gyoker;
	    }
	  else
	    {
	      fa = fa->bal_nulla;
	    }
	}
      else
	{
	  if (fa->jobb_egy == NULL)
	    {
	      fa->jobb_egy = uj_elem ();
	      fa->jobb_egy->ertek = 1;
	      fa->jobb_egy->bal_nulla = fa->jobb_egy->jobb_egy = NULL;
	      fa = gyoker;
	    }
	  else
	    {
	      fa = fa->jobb_egy;
	    }
	}
    }

  printf ("\n");
  kiir (gyoker);

  extern int max_melyseg, atlagosszeg, melyseg, atlagdb;
  extern double szorasosszeg, atlag;

  printf ("melyseg=%d\n", max_melyseg - 1);

  /* �tlagos �ghossz kisz�m�t�sa */
  atlagosszeg = 0;
  melyseg = 0;
  atlagdb = 0;
  ratlag (gyoker);
  // atlag = atlagosszeg / atlagdb;
  // (int) / (int) "elromlik", ez�rt casoljuk
  // K&R tudatlans�gi v�delem miatt a sok () :)
  atlag = ((double) atlagosszeg) / atlagdb;

  /* �ghosszak sz�r�s�nak kisz�m�t�sa */
  atlagosszeg = 0;
  melyseg = 0;
  atlagdb = 0;
  szorasosszeg = 0.0;

  rszoras (gyoker);

  double szoras = 0.0;

  if (atlagdb - 1 > 0)
    szoras = sqrt (szorasosszeg / (atlagdb - 1));
  else
    szoras = sqrt (szorasosszeg);

  printf ("altag=%f\nszoras=%f\n", atlag, szoras);

  szabadit (gyoker);
}


 // a Javacska ONE projekt Hetedik Szem/TudatSzamitas.java mintajara
 // http://sourceforge.net/projects/javacska/
 // az atlag() hivasakor is inicializalni kell oket, a
 // a rekurziv bejaras hasznalja
int atlagosszeg = 0, melyseg = 0, atlagdb = 0;

void
ratlag (BINFA_PTR fa)
{

  if (fa != NULL)
    {
      ++melyseg;
      ratlag (fa->jobb_egy);
      ratlag (fa->bal_nulla);
      --melyseg;

      if (fa->jobb_egy == NULL && fa->bal_nulla == NULL)
	{

	  ++atlagdb;
	  atlagosszeg += melyseg;

	}

    }

}

 // a Javacska ONE projekt Hetedik Szem/TudatSzamitas.java mintajara
 // http://sourceforge.net/projects/javacska/
 // az atlag() hivasakor is inicializalni kell oket, a
 // a rekurziv bejaras hasznalja
double szorasosszeg = 0.0, atlag = 0.0;

void
rszoras (BINFA_PTR fa)
{

  if (fa != NULL)
    {
      ++melyseg;
      rszoras (fa->jobb_egy);
      rszoras (fa->bal_nulla);
      --melyseg;

      if (fa->jobb_egy == NULL && fa->bal_nulla == NULL)
	{

	  ++atlagdb;
	  szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));

	}

    }

}

//static int melyseg = 0;
int max_melyseg = 0;

void
kiir (BINFA_PTR elem)
{
  if (elem != NULL)
    {
      ++melyseg;
      if (melyseg > max_melyseg)
	max_melyseg = melyseg;
      
	kiir (elem->jobb_egy);
	kiir (elem->bal_nulla);
      // ez a postorder bej�r�shoz k�pest
      // 1-el nagyobb m�lys�g, ez�rt -1
      for (int i = 0; i < melyseg; ++i)
	printf ("---");
      printf ("%c(%d)\n", elem->ertek < 2 ? '0' + elem->ertek : elem->ertek,
	      melyseg - 1);      
--melyseg;
    }
}

void
szabadit (BINFA_PTR elem)
{
  if (elem != NULL)
    {
      szabadit (elem->jobb_egy);
      szabadit (elem->bal_nulla);
      free (elem);
    }
}