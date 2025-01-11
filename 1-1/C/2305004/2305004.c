#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int score=0;
int success=0;
char str1[]="listen";
char str2[]="earth";
char str3[]="binary";
char phrase1[]="There is a secret code";
char phrase2[]="Attack at dawn";
char phrase3[]="Meet me at the park";
char word1[]="program";
char word2[]="network";
char word3[]="science";

void show_menu(void);
void start(void);
void Anagram_Challenge(void);
void khatam(void);
void string_copy(char str[],char ptr[]);
int string_length(char str[]);
int string_is_same(char str[],char ptr[]);
void ScrambleString(char str[]);
void Caesar_Cipher_Challenge(void);
void caesar_encrypt(char str[],int n);
void caesar_decrypt(char str[],int n);
void Word_Guessing_Challenge(void);
int is_substring(char str[], char sub[]);
void scoring(int attempt);

int main(){
    srand(time(0));
    show_menu();
    khatam();
    return 0;
}

void show_menu(void){
    printf("Welcome to the Game World!\n1.Start Game\n2.Exit\nEnter your choice: ");
    int n;
    scanf("%d",&n);
    if(n==1)
        start();
    else if(n==2)
        return;
    return;
}

void start(void){
    Anagram_Challenge();
    Caesar_Cipher_Challenge();
    Word_Guessing_Challenge();
    return;
}

void Anagram_Challenge(void){
    printf("\nStarting Anagram Challenge...\n");
    int randString=rand()%3;
    char str[8];
    switch(randString){
        case 0:
           string_copy(str,str1);
           break;
        case 1:
           string_copy(str,str2);
           break;
        case 2:
           string_copy(str,str3);
           break; 
    }
    int attempt=0;
    char RealWord[10];
    string_copy(RealWord,str);
    ScrambleString(str);
    printf("Scrambled word: %s",str);
    int temp=0;
    while(attempt<3){
        char InputWord[100];
        printf("\nYour guess: ");
        scanf("%20s",InputWord);
        attempt++;
        if(string_is_same(RealWord,InputWord)){
            printf("Correct! You solved it in %d attempt(s).\n",attempt);
            scoring(attempt);
            success++;
            temp=1;
            break;
        }
        else if(attempt!=3)
            printf("Incorrect!Try again");
    }
    if(temp==0){
        printf("\nYou Failed! The correct answer is %s\n",RealWord);
    }
    return;
}

void Caesar_Cipher_Challenge(void){
    int RandShift=(rand()%25)+1;
    printf("\nStarting Caesar Cipher Challenge(Shift: %d)...\n",RandShift);
    getchar();
    int randPhrase=rand()%3;
    char phrase[25];
    switch(randPhrase){
        case 0:
           string_copy(phrase,phrase1);
           break;
        case 1:
           string_copy(phrase,phrase2);
           break;
        case 2:
           string_copy(phrase,phrase3);
           break; 
    }
    int attempt=0;
    //char RealPhrase[25];
    caesar_encrypt(phrase,RandShift);
    printf("Encrypted phrase: %s",phrase);
    //string_copy(RealPhrase,phrase);
    caesar_decrypt(phrase,RandShift);
    int temp=0;
    while(attempt<3){
        char InputPhrase[100];
        printf("\nYour guess: ");
        fgets(InputPhrase, 50, stdin);
        int length=string_length(InputPhrase);
        if(length>0 && InputPhrase[length-1]=='\n')
            InputPhrase[length-1]='\0';
        attempt++;
        if(string_is_same(phrase,InputPhrase)){
            printf("Correct! You decrypted it in %d attempt(s).\n",attempt);
            scoring(attempt);
            success++;
            temp=1;
            break;
        }
        else if(attempt!=3)
            printf("Incorrect!Try again");
    }
    if(temp==0){
        printf("\nYou Failed! The correct answer is %s\n",phrase);
    }
    return;
}

void caesar_encrypt(char str[],int n){
    for(int i=0;i<string_length(str);i++){
        if(str[i]>='a' && str[i]<='z')
            str[i]=((n+str[i]-'a')%26)+'a';
        else if(str[i]>='A' && str[i]<='Z')
            str[i]=((n+str[i]-'A')%26)+'A';
    }
    return;
}

void caesar_decrypt(char str[],int n){
    n=26-(n%26);
    for(int i=0;i<string_length(str);i++){
        if(str[i]>='a' && str[i]<='z')
            str[i]=((n+str[i]-'a')%26)+'a';
        else if(str[i]>='A' && str[i]<='Z')
            str[i]=((n+str[i]-'A')%26)+'A';
    }
    return;
}

void Word_Guessing_Challenge(void){
    printf("\nStarting Word Guessing Challenge...\n");
    int randWord=rand()%3;
    char word[10];
    switch(randWord){
        case 0:
           string_copy(word,word1);
           break;
        case 1:
           string_copy(word,word2);
           break;
        case 2:
           string_copy(word,word3);
           break; 
    }
    int attempt=0;
    printf("Hint: ");
    for (int i = 0; i < 3 && i < string_length(word); i++) {
        printf("%c", word[i]);
    }
    for (int i = 3; i < string_length(word); i++) {
        printf("_");
    }
    int temp=0;
    int utility=0;
    int utility1=0;
    int utility2=0;
    while(attempt<3){
        printf("\nSelect an option: 1. Write Answer 2. Check Substring 3. Check Length\n");
        int option;
        scanf("%d",&option);
        getchar();
        while(option!=1){
            if(option==2){
                if(!utility1){
                    printf("Enter substring: ");
                    char substring[100];
                    scanf("%20s",substring);
                    if(is_substring(word,substring))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    utility++;
                    utility1=1;
                }
                else
                    printf("Error: Utility function already used.\n");
                scanf("%d",&option);
                getchar();
            }
            else if(option==3){
                if(!utility2){
                    printf("Enter length: ");
                    int InputLength;
                    scanf("%d",&InputLength);
                    if(InputLength==string_length(word))
                        printf("Yes\n");
                    else
                        printf("No\n");
                    utility++;
                    utility2=1;
                }
                else
                    printf("Error: Utility function already used.\n");
                scanf("%d",&option);
                getchar();
            }
            else{
                printf("Invalid Input. Give input again.\n");
                scanf("%d",&option);
            }
        }
        if(option==1){
            attempt++;
            char InputWord[100];
            printf("Enter your guess: ");
            scanf("%20s",InputWord);
            if(string_is_same(word,InputWord)){
                if(utility==1){
                    printf("Correct! You guessed it in %d attempt(s) using one utility functions.\n",attempt);
                    scoring(attempt);
                    score=score-2;
                }
                else if(utility==2){
                    printf("Correct! You guessed it in %d attempt(s) using two utility functions.\n",attempt);
                    scoring(attempt);
                    score=score-4;
                }
                else if(utility==0){
                    printf("Correct! You guessed it in %d attempt(s) using zero utility functions.\n",attempt);
                    scoring(attempt);
                }
                success++;
                temp=1;
                break;
            }
            else
                printf("Incorrect! Try Again\n");
        }
    }
    if(temp==0)
        printf("\nYou Failed! The correct answer is %s\n",word);
    return;
}

int is_substring(char str[],char sub[]){
    int lenStr=string_length(str);
    int lenSub=string_length(sub);
    if(lenSub>lenStr){
        return 0; 
    }
    for(int i=0;i<=(lenStr-lenSub);i++){
        int j=0;
        while(j<lenSub && str[i + j]==sub[j]){
            j++;
        }
        if(j==lenSub){
            return 1; 
        }
    }  
    return 0;
}

void string_copy(char str[],char ptr[]){
    int i;
    for(i=0;i<string_length(ptr);i++){
        str[i]=ptr[i];
    }
    str[i]='\0';
    return;
}

int string_length(char str[]){
    int count=0;
    while(str[count]!='\0'){
        count++;
    }  
    return count;
}

int string_is_same(char str[],char ptr[]){
    int i=0;
    while(str[i]!='\0' && ptr[i]!='\0'){
        if(str[i]!= ptr[i]) {
            return 0;
        }
        i++;
    }
    if(str[i]=='\0' && ptr[i]=='\0') 
        return 1;
    else
        return 0;
}

void ScrambleString(char str[]){
    int n=string_length(str);
    for(int i=0;i<n-1;i++){
        int j=i+rand()%(n-i);
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    return;
}

void scoring(int attempt){
    score=score+10+10*(3-attempt);
    return;
}

void khatam(void){
    if(success==3)
        score+=5;
    printf("\nGame Over!\nYour total score: %d points\n",score);
    return;
}
