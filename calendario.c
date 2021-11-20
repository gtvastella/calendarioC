/*Gabriel V. 182803 */ 
#include <stdio.h>

int main() {
  int yp, y, g, c, e, n, mp, dp;
  float x, z, d;
  int bs = 0;
  /* inicializando as variaveis inicias para cálculo da data da páscoa e determinação
  se o ano é bissexto ou não*/

  scanf("%i", &y);
  if (y <= 1582)
  return 0;
  
  yp = y;
  if (yp % 100 == 0)
  yp = yp/100;
  if (yp % 4 == 0)
  bs = 1;
  /* determinar se o ano é bissexeto; se sim, bs =1.*/
  
  g = (int)(y % 19)+1;
  c = (int)(y/100)+1;
  x = ((3*c)/4)-12;
  z = ((8*c)/25) -5;
  e = ((int)(11*g + 20 + z - x) % 30);
  if ((e == 25 && (g > 11)) || (e == 24))
  e = e+1;
  n = 44 - e;
  if (n<21)
  n = n+30;
  d = (int)(5*y/4) - (x+10);
  n = n+7;
  n = n - ((int)(d+n) % 7);
  if (n>31){
    dp = n -31;
    mp = 04;
  } else{
    dp = n;
    mp = 03;
  }
  /* final do algoritmo para determinar a data da páscoa. dp = dia, mp = mês da páscoa*/


  int daystoEaster = 31;
  if (bs)
    daystoEaster+=29;
  else
    daystoEaster+=28;
  daystoEaster+=dp;
  if (mp != 03)
    daystoEaster+=31;

 /* determinando quantos dias se passaram do primeiro dia do ano até a páscoa (daysToEaster)*/


  int firstSunday = daystoEaster - (daystoEaster/7)*7;
  int currentDay = firstSunday;
  int dayOfWeekNow = 0;
  while (currentDay!= 1){
    if (dayOfWeekNow == 0)
      dayOfWeekNow = 6;
    else
      dayOfWeekNow--;
    currentDay--;
}
/* determinando o primeiro domingo do ano e o primeiro dia do ano (1), bem como o dia 
da semana (dayOfWeekNow)
legenda:
   domingo = 0
   segunda = 1
   terça = 2
   quarta = 3
   quinta = 4
   sexta = 5
   sabado = 6
  */


  int maxDaysMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  char monthsName[12][31] = {"Janeiro                      ",
    "Fevereiro                    ", 
    "Março                        ", 
    "Abril                        ", 
    "Maio                         ", 
    "Junho                        ", 
    "Julho                        ", 
    "Agosto                       ", 
    "Setembro                     ",
    "Outubro                      ", 
    "Novembro                     ", 
    "Dezembro                     "};
  if (bs)
    maxDaysMonth[1] = 29;
/* preparando pré variavéis que serão utilizadas na impressão do calendário, primeiramente quantos dias cada mês possui e o nome de cada mês*/


  printf("Calendario do ano %i\n",y);
  for (int i =0; i<12;i++){
    printf("|-----------------------------|\n");
    printf("|%s|\n", monthsName[i]);
    printf("|-----------------------------|\n");
    printf("| dom seg ter qua qui sex sab |\n");
   for (int z=0;z<6;z++){
     printf("| ");
      for (int x =0;x<7;x++){
        if (currentDay <= maxDaysMonth[i]){
          if (x >= dayOfWeekNow){
            printf(" %02i ", currentDay);
            currentDay++;
            dayOfWeekNow++;
/* o dia é impresso pois está dentro dos limites do mês e de cada linha. Soma-se mais
    um dia da semana e um dia do mês*/
 

          } else{
            printf(" -- ");
/* o dia não é impresso pois não está dentro dos limites do mês/semana.*/

          }
          if (x==6)
           dayOfWeekNow = 0;
/* a semana acaba e volta-se para o domingo da próxima semana*/


          } else{
            printf(" -- ");
/* o dia não é impresso pois não está dentro dos limites do mês/semana.*/

 
            if (currentDay > maxDaysMonth[i] && x==6 && z==5)
              currentDay=1;
   /* se o mês tiver acabado, reiniciar contagem para o próximo mês retornando ao dia 1*/
         }
 
      }
     printf("|\n");
   }
 

     if(i==11)
      printf("|-----------------------------|\n");
  /* fim da impressão do calendário*/
    }

/* fim do trabalho */
 
  return 0;
}