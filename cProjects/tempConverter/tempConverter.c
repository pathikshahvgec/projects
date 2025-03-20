#include <stdio.h>

int main()
{
	int choice;
	float tempCelsius, tempFahrenheit, tempKelvin;
	char answer;

	printf("Welcome to Temperature Converter!\n");
	printf("Here, you can convert temperature among Celsius, Fahrenheit and Kelvin.\n");

	while(1)
	{
		printf("Please select any one option number from list below:\n");
		printf("1. From Celsius To Fahrenheit and Kelvin Conversion - Enter 1\n");
		printf("2. From Fahrenheit To Celsius and Kelvin Conversion - Enter 2\n");
		printf("3. From Kelvin To Celsius and Fahrenheit Conversion - Enter 3\n");
		printf("Please enter your choice number from list above:");
		scanf("%d", &choice);
		printf("\n\n");

		switch(choice)
		{
			case 1:
				printf("Please enter temperature in Celsius:");
				scanf("%6f", &tempCelsius);
				tempFahrenheit = (tempCelsius * (9.0/5.0)) + 32.0;
				tempKelvin = tempCelsius + 273.15;

				printf("%6.3f Celsius converts to %6.3f Fahrenheit and %6.3f Kelvin\n", tempCelsius, tempFahrenheit, tempKelvin);
				break;

			case 2:
				printf("Please enter temperature in Fahrenheit:");
				scanf("%6f", &tempFahrenheit);
				tempCelsius = (5.0/9.0) * (tempFahrenheit - 32.0);
				tempKelvin = tempCelsius + 273.15;
				printf("%6.3f Fahrenheit converts to %6.3f Celsius and %6.3f Kelvin.\n", tempFahrenheit, tempCelsius, tempKelvin);
				break;

			case 3:
				printf("Please enter temperature in Kelvin:");
				scanf("%6f", &tempKelvin);
				tempCelsius = tempKelvin - 273.15;
				tempFahrenheit = (tempCelsius * (9.0/5.0)) + 32.0;
				printf("%6.3f Kelvin converts to %6.3f Celsius and %6.3f Fahrenheit.\n", tempKelvin, tempCelsius, tempFahrenheit);
				break;

			default:
				printf("You have entered invalid option, please enter option among 1, 2 and 3.\n");
				break;

		}

		printf("Do you still want to continue, Press Y/N:");
		scanf(" %c", &answer);
		if(answer == 'y' || answer == 'Y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}
