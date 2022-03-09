#include <stdio.h>
float sine, cosine, tangent; // for output answers
float siner, cosiner; // for radian input
float sinet, cosinet, tangentt, tangenttt; // for tangent radian
char a, c; // for switch-case statement

int main(void) { 
  sine = 0.0;
  cosine = 0.0;
  tangent = 0.0; //functions declared 0.0 for if statement

  printf("Trigonometry functions available\n");
  printf("1. sine in radian\n");
  printf("2. cosine in radian\n");
  printf("3. tangent in radian(sine & cosine)\n");
  printf("0. Exit\n");
  printf("Choose function (in number): ");
  scanf("%c", &c);

  switch (c) // switch statement that interacts with char c
  {
    case '1':
    printf("Enter value for sine: "); // case 1 is to calculate sin value in radian
    scanf("%f", &siner);

    sine = siner - ((siner*siner*siner)/(3*2*1)) + ((siner*siner*siner*siner*siner)/(5*4*3*2*1)) - ((siner*siner*siner*siner*siner*siner*siner)/(7*6*5*4*3*2*1)); 
    //Mclaurin series for sine function
    
    if (siner != 0) { // will print if input is detected for sine
      printf("Sine(%.2f) = %.4f", siner, sine);
      break;
    } else if (scanf("%f", &siner) != 1) { // if the input is not a float value it will terminate the program
      printf("Unable to compute, Invalid input: 40");//invalid num = error in which line
      break;
    }
    break;

    case '2':
    printf("Enter value for cosine: "); // case 2 is to calcualte cosine value in radian
    scanf("%f", &cosiner);

    cosine = 1 - ((cosiner*cosiner)/(2*1)) + ((cosiner*cosiner*cosiner*cosiner)/(4*3*2*1)) - ((cosiner*cosiner*cosiner*cosiner*cosiner*cosiner)/(6*5*4*3*2*1)) + ((cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner)/(8*7*6*5*4*3*2*1)) - ((cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner*cosiner)/(10*9*8*7*6*5*4*3*2*1));
    //Mclaurin series for cosine function

    if (cosiner != 0) { // prints only if input detected for cosine
    printf("Cosine(%.2f) = %f", cosiner, cosine); 
    break;
    } else if (scanf("%f", &cosiner) != 1) { // non float value detected will terminate the program
      printf("Unable to compute, Invalid input: 56");//invalid num = error in which line
      break;
    }
    break;

    case '3':
    printf("Enter value for sine: ");
    scanf("%f", &sinet);
    printf("Enter value for cosine: ");
    scanf("%f", &cosinet);

    sine = sinet - ((sinet*sinet*sinet)/(3*2*1)) + ((sinet*sinet*sinet*sinet*sinet)/(5*4*3*2*1)) - ((sinet*sinet*sinet*sinet*sinet*sinet*sinet)/(7*6*5*4*3*2*1));
    //Mclaurin series for sine value

    cosine = 1 - ((cosinet*cosinet)/(2*1)) + ((cosinet*cosinet*cosinet*cosinet)/(4*3*2*1)) - ((cosinet*cosinet*cosinet*cosinet*cosinet*cosinet)/(6*5*4*3*2*1)) + ((cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet)/(8*7*6*5*4*3*2*1)) - ((cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet*cosinet)/(10*9*8*7*6*5*4*3*2*1));
    //Mclaurin series for cosine value

    tangentt = sine/cosine;

    tangenttt = tangentt + (((2*(tangentt*tangentt*tangentt)))/6) +  + ((16*(tangentt*tangentt*tangentt*tangentt*tangentt))/120) + ((272*(tangentt*tangentt*tangentt*tangentt*tangentt*tangentt*tangentt))/5040);

    if (siner != 0 || cosinet != 0) { // detects input for cosinet and sinet and computes into tangent in radian
    printf("Tangent in radian = %.4f", tangenttt); 
    break;
    } else if (scanf("%f", &sinet) != 1 || scanf("%f", &cosinet) != 1) { // breaks if either is true
      printf("\nUnable to compute, Invalid input: 80\n"); //invalid num = error in which line
      break;
    } 
    break;

    case 'e':
    a = 1;
    break;
    default:
    printf("Program terminated\n");
    break;
  } // program will terminate in case if user inputs is non integer or more than 4.
  return 0;
}


