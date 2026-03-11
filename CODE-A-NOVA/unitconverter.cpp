/*
Program Name : Unit Converter
Author       : Ponnam Reddy Pavan Kalyan Reddy
*/

#include <stdio.h>

/* Function declarations */
void celsiusToFahrenheit();
void fahrenheitToCelsius();
void kmToMiles();
void milesToKm();
void kgToPounds();
void poundsToKg();

int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("          UNIT CONVERTER\n");
        printf("====================================\n");

        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometer to Miles\n");
        printf("4. Miles to Kilometer\n");
        printf("5. Kilogram to Pounds\n");
        printf("6. Pounds to Kilogram\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                celsiusToFahrenheit();
                break;

            case 2:
                fahrenheitToCelsius();
                break;

            case 3:
                kmToMiles();
                break;

            case 4:
                milesToKm();
                break;

            case 5:
                kgToPounds();
                break;

            case 6:
                poundsToKg();
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 7);

    return 0;
}

/* Celsius to Fahrenheit */
void celsiusToFahrenheit()
{
    float c,f;

    printf("Enter temperature in Celsius: ");
    scanf("%f",&c);

    f = (c * 9 / 5) + 32;

    printf("Fahrenheit = %.2f\n",f);
}

/* Fahrenheit to Celsius */
void fahrenheitToCelsius()
{
    float f,c;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f",&f);

    c = (f - 32) * 5 / 9;

    printf("Celsius = %.2f\n",c);
}

/* Kilometer to Miles */
void kmToMiles()
{
    float km,miles;

    printf("Enter distance in Kilometers: ");
    scanf("%f",&km);

    miles = km * 0.621371;

    printf("Miles = %.2f\n",miles);
}

/* Miles to Kilometer */
void milesToKm()
{
    float miles,km;

    printf("Enter distance in Miles: ");
    scanf("%f",&miles);

    km = miles / 0.621371;

    printf("Kilometers = %.2f\n",km);
}

/* Kilogram to Pounds */
void kgToPounds()
{
    float kg,pounds;

    printf("Enter weight in Kilograms: ");
    scanf("%f",&kg);

    pounds = kg * 2.20462;

    printf("Pounds = %.2f\n",pounds);
}

/* Pounds to Kilogram */
void poundsToKg()
{
    float pounds,kg;

    printf("Enter weight in Pounds: ");
    scanf("%f",&pounds);

    kg = pounds / 2.20462;

    printf("Kilograms = %.2f\n",kg);
}
