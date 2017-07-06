// 
// http://www.povinelli.org/teaching/eece2710/lmc.html
//

#include <stdio.h>

int mem[99];
int memtmp[99];

void run(int verbose){
	int calculator, i;
    for(i = 1; i<=99; i++){
    	if(mem[i] >= 100 && mem[i] <= 199){
			if(verbose)
				printf("[%d]: ADD %d TO %d\n", i, mem[mem[i] -100], calculator);
    		calculator = calculator + mem[mem[i] - 100];
    	}
    	else if(mem[i] >= 200 && mem[i] <= 299){
			if(verbose)
				printf("[%d]: SUB %d FROM %d\n", i, mem[mem[i] - 200], calculator);
    		calculator = calculator - mem[mem[i] - 200];
    	}
    	else if(mem[i] >= 300 && mem[i] <= 399){
			if(verbose)
				printf("[%d]: STO %d IN %d\n", i, calculator, mem[i] - 300);
    		mem[mem[i] - 300] = calculator;
    	}
    	else if(mem[i] >= 500 && mem[i] <= 599){
			if(verbose)
				printf("[%d]: LDA %d FROM %d\n", i, mem[mem[i] - 500], mem[i] - 500);
    		calculator = mem[mem[i] - 500];
    	}
    	else if(mem[i] >= 600 && mem[i] <= 699){
			if(verbose)
				printf("[%d]: BR %d\n", i, mem[i] - 600);
    		i = mem[i] - 599;
    	}
    	else if(mem[i] >= 700 && mem[i] <= 799 && calculator == 0){
			if(verbose)
				printf("[%d]: BRZ %d\n", i, mem[i] - 700);
    		i = mem[i] - 699;
    	}
    	else if(mem[i] >= 800 && mem[i] <= 899 && calculator >= 0){
			if(verbose)
				printf("[%d]: BRP %d\n", i, mem[i] - 800);
    		i = mem[i] - 799;
    	}
		else if(mem[i] == 901){
			if(verbose)
				printf("[%d]: REQUESTING INPUT\n", i);
			printf("* ");
			scanf("%d", &calculator);
		}
		else if(mem[i] == 902){
			if(verbose)
				printf("[%d]: OUTPUT\n", i);
			printf("%d", calculator);
		}
		else if(mem[i] == 0){
			printf("\n[%d] BREAK\n", i);
			break;
		}
    }
}

void reset(){
	int i;
	for(i = 1; i <= 99; i++){
		mem[i] = memtmp[i];
		memtmp[i] = 0;
	}
}

void prep(){
	int i;
	for(i = 1; i <= 99; i++){
		memtmp[i] = mem[i];
	}
}

int main(int argc, char* argv[]) {
	if(argc >= 2){
		printf("\nLittle Man Computer simulator v1.0\n");
		printf("All command line arguments trigger this help.\n");
        printf("\nWhen you start, you will get a ? prompt.\nEnter your data as:\n\n? ADDRESS DATA\n\nAddressess can be between 1 and 99, data can be between 0 and 999.");
		printf("\nTwo special editor commands exist, enter them in the ? prompt as:\n\n? COMMAND ARGUMENT\n\n");
		printf("100: Run program, enter any number as the argument (nescessary).\n");
		printf("101: Print address, enter the address as the argument. 0 prints all stored data.\n");
        printf("\nData stored in memory addresses are interpreted as commands if reached by the counter during runtime.");
		printf("\nThese commands are the fundamentals of the LMC computer, and are different than the previously mentioned editor commands.\n");
		printf("\nYou can store actual data in addresses after the 000 command.\n\n");
		printf("1XX: ADD: Add data from memory bank XX to calculator.\n");
		printf("2XX: SUB: Subtract data from memory bank XX from calculator.\n");
		printf("3XX: STO: Store data from calculator in memory bank XX.\n");
		printf("5XX: LDA: Load data from memory bank XX into calculator.\n");
		printf("6XX: BR:  Branch (jump) to memory bank XX.\n");
		printf("7XX: BRZ: Branch (jump) to memory bank XX when calculator is ZERO.\n");
		printf("8XX: BRP: Branch (jump) to memory bank XX when calculator is POSITIVE.\n");
		printf("901: IN:  Ask user for input to be set as calculator value.\n");
		printf("902: OUT: Output calculator value.\n");
		printf("000: ZZZ: Coffee break, end execution.\n\n");
		printf("When your program is running, input prompts triggered with 901 will appear as: *\n\n");
		return 0;
	}
	
    int address, data, i;
    while(1){
        printf("? ");
        scanf("%d %d", &address, &data);
        if(address == 100){
			prep();
            run(data);
			reset();
        }
        else if(address == 101){
			if(data == 0){
				for(i = 1; i <= 99; i++){
					if(mem[i] != 0){
						printf("%d:%d\n", i, mem[i]);
					}
				}
			}
			else{
				printf("%d:%d\n", data, mem[data]);
			}
        }
        else{
            mem[address] = data;
        }
    }
    return 0;
}
