/*COURSE: COMP307 MINI A2
NAME: SIMON HSU
ID: 260610820
TITLE: Asymmetric cipher in C using CGI*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*test if public_key, privae_key and modulo are valid keys that can be used to form an asymmetric cipher. 
prompts VALID KEYS or INVALID KEYS in the end.*/
void docheck(int public, int private, int modulo) {

	//int public=atoi(argv[2]), private=atoi(argv[3]), modulo=atoi(argv[4]);
	//checking gcd equals to 1
        int gcd = 1, gcd2=1;
	for(int i=1; i <= public && i <= modulo; ++i){
      		if(public%i==0 && modulo%i==0)
            	gcd = i;
    	}
	for(int j=1; j <= private && j <= modulo; ++j){
      		if(private%j==0 && modulo%j==0)
            	gcd2 = j;
    	}
	//checking inverse of keys is invertible

	int l = ((public * (1/public)) % modulo );
	int m = ((private * (1/private)) % modulo );
	//checking modulo is greater than keys
	if ((gcd==gcd2==l==m) && (modulo>public) && (modulo >private)) {
		printf("VALID KEYS!");
	}
	else printf("INVALID KEYS!");

}
/*opens the text filename provided and ciphers the message using the KEY. 
The ciphered information is saved in a new file using the provided filename but with the extension .cipher.
this option should be able to cipher and return the message back to its original form.
you could decrypt it using the same -cipher option*/
void docipher(char* filename, int key, int modulo) {
//conffesion: this function doesnt output the correct answer, but i've tried several ways to do it, hope i get lots of partial marks on program being able to compiled and i've done all the parts

	int message=1; 
	int cipher=1;
	FILE *fptr;
	char* writefilename=strcat(filename, ".cipher"); //add the extension to filename
	
	//here i am going to read the given file and then store it in a msg then cipher it
	//check if the filename exists
	if ((fptr=fopen(filename, "r"))==NULL){ 
		printf("Error!");
	}
	fscanf(fptr,"%d",&message); //the message should be in int, so i can cipher it
	fclose(fptr);

	cipher = (key * message % modulo); //this is where you encrypt/decrpyt the message

	//write this back into a file and put extension.cipher in it
	fptr = fopen( writefilename, "w");
	char* cipherstring[256];  //i wrote this to convert int into char so i can output a new file with text in it
	sprintf( cipherstring, "%d", cipher); //the sprintf and fprintf are giving me warning and i dont know exactly how to fix it..
	fprintf(  fptr, cipherstring );
	fclose(fptr);

}

int main( int argc, char **argv )
{
 if (argc == 5){
	if (!strcmp(argv[1], "-CHECK")) docheck(atoi(argv[2]), atoi(argv[3]),atoi(argv[4]));
	if (!strcmp(argv[1], "-CIPHER")) docipher(argv[2],atoi(argv[3]), atoi(argv[4])); 
	}
 return 0;
}
