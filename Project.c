/*
 ============================================================================
 Name        : Project_C.c
 Author      : Ahmed El-Askary
 Description : Vehicle Control System Project
 Date        : 10/3/2023
 ============================================================================
 */

#include <stdio.h>

typedef enum
{
	AC_OFF , AC_ON
}Air_condition_State ;

typedef enum
{
	CONTROLLER_OFF, CONTROLLER_ON
}Engine_Temperature_Controller_State;

typedef enum
{
	ENGINE_OFF, ENGINE_ON
}Engine_State;


int Vehicle_Speed (char Light)
{
	int speed ;

	if ((Light == 'G') || (Light == 'g'))
	{
		speed = 100 ;
	}
	if ((Light == 'O') || (Light == 'o'))
	{
		speed = 30 ;
	}
	if ((Light == 'R') || (Light == 'r'))
	{
		speed = 0 ;
	}
	return speed ;
}

Air_condition_State Vehicle_RoomTemp (int *temp_ptr)
{
	Air_condition_State State = AC_OFF;

	if (*temp_ptr < 10)
	{
		State = AC_ON ;
		*temp_ptr = 20 ;
	}
	else if (*temp_ptr)
	{
		State = AC_ON ;
		*temp_ptr = 20 ;
	}
	else
	{
		State = AC_OFF ;
	}
	return State ;
}

Engine_Temperature_Controller_State Vehicle_EngineTemp (int *temp_ptr)
{
	Engine_Temperature_Controller_State State = CONTROLLER_OFF ;

	if (*temp_ptr < 100)
	{
		State = CONTROLLER_ON ;
		*temp_ptr = 125 ;
	}

	else if (*temp_ptr > 150)
	{
		State = CONTROLLER_ON ;
		*temp_ptr =150 ;
	}

	else
	{
		State = CONTROLLER_OFF ;
	}
	return State ;
}



int main()
{
	char input ;
	char light ;
	char sensor ;


	Engine_State Engine = ENGINE_OFF ;
	Air_condition_State AC_State = AC_OFF;
	Engine_Temperature_Controller_State Engine_Temp = CONTROLLER_OFF ;


	int speed = 0 ;
	int Temp_Room = 35 ;
	int Temp_Engine = 90 ;


	while(1)
	{
		printf("a. Turn on the vehicle engine\n");
		fflush(stdout);
		printf("b. Turn off the vehicle engine\n");
		fflush(stdout);
		printf("c. Quit the system\n\n");
		fflush(stdout);

		scanf(" %c", &input);


		if ((input == 'C') || (input == 'c'))
		{
			printf("Quit the system \n\n") ;
			fflush(stdout);
			break ;
		}

		else if ((input == 'B') || (input == 'b'))
		{
			Engine = ENGINE_OFF ;
			printf("Turn off the vehicle engine \n\n") ;
			fflush(stdout);
			break ;
		}

		else if ((input == 'A') || (input == 'a'))
		{
			while (1)
			{
				Engine = ENGINE_ON ;

				printf("a. Turn off the engine\n");
				fflush(stdout);
				printf("b. Set the traffic light color\n");
				fflush(stdout);
				printf("c. Set the room temperature\n");
				fflush(stdout);
				printf("d. Set the engine temperature\n\n");
				fflush(stdout);

				scanf(" %c", &sensor);

				if ((sensor == 'A') || (sensor == 'a'))
				{
					Engine = ENGINE_OFF;
					printf("Quit the system \n\n") ;
					fflush(stdout);
					break ;

				}
				if ((sensor == 'B') || (sensor == 'b'))
				{
					printf("Enter the traffic light 'R/O/G' \n\n") ;
					fflush(stdout);
					scanf(" %c", &light);
					speed = Vehicle_Speed (light);
				}
				if ((sensor == 'C') || (sensor == 'c'))
				{
					printf("Enter the Room Temp  \n\n") ;
					fflush(stdout);
					scanf(" %d", &Temp_Room);
					AC_State = Vehicle_RoomTemp (&Temp_Room);
				}
				if ((sensor == 'D') || (sensor == 'd'))
				{
					printf("Enter the Engine Temp  \n\n") ;
					fflush(stdout);
					scanf(" %d", &Temp_Engine);
					Engine_Temp = Vehicle_EngineTemp (&Temp_Engine);
				}
				if (speed == 30)
				{
					if(AC_State == AC_OFF)
					{
						AC_State = AC_ON;
					}
					Temp_Room = ((Temp_Room * 5) / 4) + 1;

					if(Engine_Temp == CONTROLLER_OFF)
					{
						Engine_Temp = CONTROLLER_ON;
					}
					Temp_Engine = ((Temp_Engine * 5) / 4) + 1;
				}
				if(Engine == ENGINE_OFF)
				{
					printf("Engine is OFF\n");
				}
				else
				{
					printf("Engine is ON\n");
				}
				if(AC_State == AC_OFF)
				{
					printf("AC is OFF\n");
				}
				else
				{
					printf("AC is ON\n");
				}

				printf("Vehicle Speed: %d Km/Hr\n",speed);

				printf("Room Temperature: %d C\n",Temp_Room);


				if(Engine_Temp == CONTROLLER_OFF)
				{
					printf("Engine Temp Controller is OFF\n");
				}
				else
				{
					printf("Engine Temp Controller is ON\n");
				}
				printf("Engine Temperature: %d C\n\n",Temp_Engine);

			}
		}
		else
		{
			printf("Error Input \n\n");
		}

	}
	return 0 ;
}
