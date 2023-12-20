#define TRIVAL_COFF 0
#define EASY_COFF 2
#define MEDIUM_COFF 1.5
#define HARD_COFF 1
#define EXTREME_COFF 0.5
#define MAX_GOLD 51

int main(){
    float coff;
    float num;
    float res;
    char dif;
    int gold;
    int item;
    float gold_lvl;
    int final_gold;
    int final_item;
    char opc = 'n';
    
    do{
            
            srand(time(NULL));
            gold = rand()%MAX_GOLD;  
    
    do{
    printf("Introduce the difficulty: ");
    scanf("%c", &dif);
    }while(dif != 'e' && dif != 'm' && dif != 'h' && dif != 't' && dif != 'x');
    
    switch(dif){
        case 'e':
            coff = EASY_COFF; 
            break;
        case 'm':
            coff = MEDIUM_COFF;
            break;
        case 't':
            coff = TRIVAL_COFF;
            break;
        case 'h':
            coff = HARD_COFF;
            break;
        case 'x':
            coff = EXTREME_COFF;
            break;
        }
    
    gold_lvl = gold * coff;
    final_gold = llround(gold_lvl);
    
    if(item == 1){
        final_item = item;
        }
    
    printf("Gold: %d \tItem: %d\n", gold, item);
    printf("\n");
    
    printf("%f\t", gold_lvl);
    printf("Gold_dif: %d \tItem. %d\n", final_gold, final_item);
    
    }while(opc == 'n' || opc == 'N');
    
    
    }