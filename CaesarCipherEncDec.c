#include <stdio.h>
#include <string.h> 
#include <ctype.h>

void encrypt(char alpha1[], char alpha2[]){

    char message[100];
    int shifts; 

    printf("\nEnter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    for(int i = 0; message[i] != '\0'; i++){
        message[i] = tolower(message[i]); 
    }

    printf("Enter the key: ");
    scanf("%d", &shifts);
    getchar();

    for(int i = 0; message[i] != '\0'; i++){

        if (message[i] == ' ') {
            continue; 
        }
        for(int j = 0; j < 26; j++){
            if (message[i] == alpha1[j]){
                message[i] = alpha2[((j + shifts) % 26)]; 
                break; 
            } 
        } 
    }
    printf("\nEncrypted Message: %s\n\n", message);

}

void decrypt(char alpha1[], char alpha2[]){

    char message[100]; 
    int shifts;

    printf("\nEnter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    for(int i = 0; message[i] != '\0'; i++){
        message[i] = tolower(message[i]); 
    }

    printf("Enter the key: ");
    scanf("%d", &shifts);
    getchar();

    for(int i = 0; message[i] != '\0'; i++){

        if (message[i] == ' ') {
            continue; 
        }
        for(int j = 0; j < 26; j++){
            if (message[i] == alpha1[j]){
                message[i] = alpha2[((j - shifts + 26) % 26)]; 
                break; 
            } 
        } 
    }
    printf("\nDecrypted Message: %s\n\n", message);
}

int main(){

    int option = 0;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
    char mirror[] = "abcdefghijklmnopqrstuvwxyz";

    while(option != 3){
        printf("############### Caesar Cipher Translator ###############\n\n1) Encrypt message\n2) Decrypt message\n3) Exit\n\n");
 
        scanf("%d", &option);
        getchar();

        switch (option){
            case 1:
                encrypt(alphabet, mirror);
                option = 0; 
                break; 

            case 2: 
                decrypt(alphabet, mirror);
                option = 0;
                break; 

            case 3:
                break;

            default:
                printf("\nInvalid option!\n\n");
                break;
        }
    }
    printf("\nProgram terminated!");
    return 0; 
}